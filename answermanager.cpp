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
    if (this->message == "test-one")
        return "You just activated my secret card! Medicines!";
    return "Yes, take these masks already!";
}

QString AnswerManager::whenGuessYourDiasease() {
    if (this->message == "test-one")
        return "You just activated my secret card! Diasease!";
    return "I think you`ve got COVID-19";
}

QString AnswerManager::whenLiveConsultationWithDoctor() {
    if (this->message == "test-one")
        return "You just activated my secret card! Doctor!";
    return "Please stay at home! And do not forget to wash your hands.";
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
