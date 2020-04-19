#include "medicinesorderprocessor.h"

#include <QDebug>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

// Public API

MedicinesOrderProcessor::MedicinesOrderProcessor() {
    this->stageValid = false;
    this->newStage = "S_FIN";
}

void MedicinesOrderProcessor::setSourceMessage(QString message) {
    this->sourceMessage = message;
}

QString MedicinesOrderProcessor::processAndGetProcessedMessage() {
    if(!retrieveStage()) return "Sorry, an error occured in my core "
                                "and I can not remember point where we stopped at.";
    processMessage();
    if (!isValidForStage()) return "Sorry, I do not understand you.";
    else {
        if(!isFinalStage()) {
            if(!updateStage()) return "Sorry, an error occured in my core and we can not proceed.";
        } else if (!resetStage()) return "Sorry, an error occured in my core and we can not begin from scratch.";
        return this->processedMesage;
    }
}

// Internal API

bool MedicinesOrderProcessor::retrieveStage() {
    QSqlQuery query("SELECT stage FROM Stage WHERE topic = 'medicinesorder'");
    if(!query.exec()) {
        qWarning() << "Unable to retrieve stage from DB: " << query.lastError();
        return false;
    } else {
        query.first();
        this->currenntStage = query.value(0).toString();
        return true;
    }
}

void MedicinesOrderProcessor::setResult(bool valid, QString message, QString stage) {
    this->stageValid = valid;
    this->processedMesage = message;
    if(stage != NULL) this->newStage = stage;
}

bool MedicinesOrderProcessor::isValidForStage() {
    return this->stageValid;
}

bool MedicinesOrderProcessor::isFinalStage() {
    return this->currenntStage == "S_FIN";
}

bool MedicinesOrderProcessor::updateStage() {
    QSqlQuery query(QString("UPDATE Stage SET stage = '%1' WHERE topic = 'medicinesorder'").arg(this->newStage));
    if (!query.exec()) {
        qWarning() << "Unable to update stage in DB: " << query.lastError();
        return false;
    } else {
        return true;
    }
}

bool MedicinesOrderProcessor::resetStage() {
    QSqlQuery query(QString("UPDATE Stage SET stage = 'S_INIT' WHERE topic = 'medicinesorder'"));
    if (!query.exec()) {
        qWarning() << "Unable to reset stage in DB: " << query.lastError();
        return false;
    } else {
        return true;
    }
}

bool MedicinesOrderProcessor::currentStage(QString stage) {
    return this->currenntStage == stage;
}

bool MedicinesOrderProcessor::containsKeyWords(QStringList keywords) {
    QRegularExpression re(keywords.join("|"), QRegularExpression::CaseInsensitiveOption);
    return re.match(this->sourceMessage).hasMatch();
}

// Specific API

void MedicinesOrderProcessor::processMessage() {
    if(isMatchingInitInput() && currentStage("S_INIT")) {
        // On S_INIT stage ...
        setResult(true, "Ok, please send me name of first medicament.\n"
                        "As example: Medicine Name Amount[P].\n"
                        "You can edit your requests on any stage if needed.\n"
                        "When you'll going to finish, just let me know :)", "S_ADDING");
        return;
    } else if(!isMatchingAddingFinishedInput() && currentStage("S_ADDING")) {
        // Store current user input because we will use it on the next stage
        this->previousSourceMessage = this->sourceMessage;
        // On S_ADDING stage ...
        setResult(true, "Sure? Can i remember and process your input?", "S_ADDING_VERIFY");
        return;
    } else if(currentStage("S_ADDING_VERIFY")) {
        // On S_ADDING_VERIFY stage ...
        if(isMatchingAddingVerifyPositiveAnswer()) {
            this->processedDrugStringList.append(processUserDrugInfoInput());
            setResult(true, "Got it! Send me a next medicine.", "S_ADDING");
            return;
        } else {
            setResult(true, "Don`t worry, just end me a correct item.", "S_ADDING");
            return;
        }
    } else if(isMatchingAddingFinishedInput() && currentStage("S_ADDING")) {
        // On S_ADDING stage ...
        setResult(true, "Ok! I`ve processed all your inputs.\n"
                        "And here is a list of providers "
                        "which currently provide required "
                        "medicines for the most lowest cost!\n"
                  + this->processedDrugStringList.join("\n"), "S_FIN");
        return;
    } else if(isMatchingToBeDoneInput() && currentStage("S_FIN")) {
        // On S_FIN stage ...
        setResult(true, "Ok. It was so great to help you! See you later!");
        return;
    } else return;
}

QString MedicinesOrderProcessor::processUserDrugInfoInput() {
    QRegularExpression re("([a-z\\.A-Z\\W?\\d?\\s]+)\\s(\\d+)");
    QRegularExpressionMatch match = re.match(this->previousSourceMessage);
    QSqlQuery query(QString("SELECT MedicinesProviders.name, MedicinesItems.name, MIN(Medicines.popc) FROM Medicines "
                            "INNER JOIN MedicinesProviders ON MedicinesProviders.id = Medicines.medicineprovider_id "
                            "INNER JOIN MedicinesItems ON MedicinesItems.id = Medicines.medicine_id "
                            "WHERE MedicinesItems.name = '%1'").arg(match.captured(1)));
    if (!query.exec()) {
        qWarning() << "Unable to retrieve medicine from DB: " << query.lastError();
        return QString("Sorry, an error occured in my core "
                       "and I can not retrieve info about").arg(match.captured(1));
    }
    query.first();
    if (query.value(0).toString() == "") {
        return QString("Found nothing for %1. Impossible... Maybe my database is incomplete?").arg(match.captured(1));
    }
    return QString("%1: (%2 - %3)").arg(
                query.value(0).toString(),
                query.value(1).toString(),
                QString::number(query.value(2).toInt() * match.captured(2).toInt()));
}

bool MedicinesOrderProcessor::isMatchingInitInput() {
    return containsKeyWords(QStringList {"hello", "start", "want", "order"});
}

bool MedicinesOrderProcessor::isMatchingAddingVerifyPositiveAnswer() {
    return containsKeyWords(QStringList {"yes", "yep", "yeah", "sure"});
}

bool MedicinesOrderProcessor::isMatchingAddingFinishedInput() {
    return containsKeyWords(QStringList {"done", "finished", "enough"});
}

bool MedicinesOrderProcessor::isMatchingToBeDoneInput() {
    return containsKeyWords(QStringList {"thank"});
}
