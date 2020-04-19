#ifndef ANSWERMANAGER_H
#define ANSWERMANAGER_H

#include <QString>

#include "medicinesorderprocessor.h"
#include "diaseaseprocessor.h"
#include "doctorprocessor.h"

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
    MedicinesOrderProcessor mrProcessor;
    DiaseaseProcessor diProcessor;
    DoctorProcessor drProcessor;
};

#endif // ANSWERMANAGER_H
