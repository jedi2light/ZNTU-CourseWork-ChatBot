#include <QDebug>

#include "answermanager.h"

AnswerManager::AnswerManager() {
    this->recipient = "";
    this->message = "";
}

void AnswerManager::setRecipient(QString recipient) {
    this->recipient = recipient;
}

void AnswerManager::setMessage(QString message) {
    this->message = message;
}

QString AnswerManager::whenMedicinesOrder() {
    mrProcessor.setSourceMessage(this->message);
    return mrProcessor.processAndGetProcessedMessage();
}

QString AnswerManager::whenGuessYourDiasease() {
    diProcessor.setSourceMessage(this->message);
    return diProcessor.processAndGetProcessedMessage();
}

QString AnswerManager::whenLiveConsultationWithDoctor() {
    // drProcessor.setSourceMessage(this->message);
    // return processor.getProcessedMessage();
    return "I will be smart doctor";
}

QString AnswerManager::appropriateMessage() {
    if (this->recipient == "Medicines Order") {
        return whenMedicinesOrder();
    } else if (this->recipient == "Guess your diasease") {
        return whenGuessYourDiasease();
    } else if (this->recipient == "Live Consultation with Doctor") {
        return whenLiveConsultationWithDoctor();
    } else return "Unable to give appropriate message";
}
