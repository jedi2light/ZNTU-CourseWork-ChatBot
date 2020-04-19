#include "diaseaseprocessor.h"

#include <QDebug>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QSet>

// Public API

DiaseaseProcessor::DiaseaseProcessor() {
    this->stageValid = false;
    this->newStage = "S_FIN";
}

void DiaseaseProcessor::setSourceMessage(QString message) {
    this->sourceMessage = message;
}

QString DiaseaseProcessor::processAndGetProcessedMessage() {
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

bool DiaseaseProcessor::retrieveStage() {
    QSqlQuery query("SELECT stage FROM Stage WHERE topic = 'diasease'");
    if(!query.exec()) {
        qWarning() << "Unable to retrieve stage from DB: " << query.lastError();
        return false;
    } else {
        query.first();
        this->currenntStage = query.value(0).toString();
        return true;
    }
}

void DiaseaseProcessor::setResult(bool valid, QString message, QString stage) {
    this->stageValid = valid;
    this->processedMesage = message;
    if(stage != NULL) this->newStage = stage;
}

bool DiaseaseProcessor::isValidForStage() {
    return this->stageValid;
}

bool DiaseaseProcessor::isFinalStage() {
    return this->currenntStage == "S_FIN";
}

bool DiaseaseProcessor::updateStage() {
    QSqlQuery query(QString("UPDATE Stage SET stage = '%1' WHERE topic = 'diasease'").arg(this->newStage));
    if (!query.exec()) {
        qWarning() << "Unable to update stage in DB: " << query.lastError();
        return false;
    } else {
        return true;
    }
}

bool DiaseaseProcessor::resetStage() {
    QSqlQuery query(QString("UPDATE Stage SET stage = 'S_INIT' WHERE topic = 'diasease'"));
    if (!query.exec()) {
        qWarning() << "Unable to reset stage in DB: " << query.lastError();
        return false;
    } else {
        return true;
    }
}

bool DiaseaseProcessor::currentStage(QString stage) {
    return this->currenntStage == stage;
}

bool DiaseaseProcessor::containsKeyWords(QStringList keywords) {
    QRegularExpression re(keywords.join("|"), QRegularExpression::CaseInsensitiveOption);
    return re.match(this->sourceMessage).hasMatch();
}

// Specific API

void DiaseaseProcessor::processMessage() {
    if(isMatchingInitInput() && currentStage("S_INIT")) {
        // On S_INIT stage ...
        setResult(true, "Ok, please send me name of first symptom.\n"
                        "When you'll going to finish, just let me know :)", "S_ADDING");
        return;
    } else if(!isMatchingAddingFinishedInput() && currentStage("S_ADDING")) {
        this->diaseasesList += processUserSymptomInput();
        setResult(true, "Got it! Send me a next symptom.", "S_ADDING");
        return;
    } else if(isMatchingAddingFinishedInput() && currentStage("S_ADDING")) {
        // On S_ADDING stage ...
        setResult(true, "Ok! I`ve processed all your inputs.\n"
                        "And here is a list of possible deaseases.\n"
                  + this->diaseasesList.toSet().toList().join(" "), "S_FIN");
        return;
    } else if(isMatchingToBeDoneInput() && currentStage("S_FIN")) {
        // On S_FIN stage ...
        setResult(true, "Ok. It was so great to help you! See you later!");
        return;
    } else return;
}

QStringList DiaseaseProcessor::processUserSymptomInput() {
    QString symptom = this->sourceMessage;
    QStringList returned;
    QSqlQuery query(QString("SELECT DiaseasesItems.name FROM Diaseases "
                            "INNER JOIN DiaseasesSymptoms ON DiaseasesSymptoms.id = Diaseases.diasease_symptom_id "
                            "INNER JOIN DiaseasesItems ON DiaseasesItems.id = Diaseases.diasease_item_id "
                            "WHERE DiaseasesSymptoms.name LIKE UPPER('\%%1\%')").arg(symptom));
    if (!query.exec()) {
        qWarning() << "Unable to retrieve diasease from DB: " << query.lastError();
        return returned;
    }
    while(query.next()) {
        returned.append(query.value(0).toString());
    }
    return returned;
}

bool DiaseaseProcessor::isMatchingInitInput() {
    return containsKeyWords(QStringList {"hello", "start", "sick"});
}

bool DiaseaseProcessor::isMatchingAddingFinishedInput() {
    return containsKeyWords(QStringList {"done", "finished", "enough"});
}

bool DiaseaseProcessor::isMatchingToBeDoneInput() {
    return containsKeyWords(QStringList {"thank"});
}
