#ifndef ANSWERMANAGER_H
#define ANSWERMANAGER_H

#include <QString>

class AnswerManager {
public:
    AnswerManager(QString recipient, QString message);
    QString appropriateMessage();
private:
    QString whenMedicinesOrder();
    QString whenGuessYourDiasease();
    QString whenLiveConsultationWithDoctor();
    QString recipient;
    QString message;
};

#endif // ANSWERMANAGER_H
