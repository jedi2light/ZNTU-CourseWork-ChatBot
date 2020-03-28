#include "answermanager.h"

AnswerManager::AnswerManager(QString recipient, QString message) {
    this->recipient = recipient;
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
