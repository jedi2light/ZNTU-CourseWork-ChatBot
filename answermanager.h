#ifndef ANSWERMANAGER_H
#define ANSWERMANAGER_H

#include <QString>

class AnswerManager {
public:
    AnswerManager();
    QString appropriateMessage();
    void setRecipient(QString recipient);
    void setMessage(QString message);
private:
    QString whenMedicinesOrder();
    QString whenGuessYourDiasease();
    QString whenLiveConsultationWithDoctor();
    QString recipient;
    QString message;
};

#endif // ANSWERMANAGER_H
