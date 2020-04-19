#ifndef MEDICINESORDERPROCESSOR_H
#define MEDICINESORDERPROCESSOR_H

#include <QList>
#include <QString>

class MedicinesOrderProcessor {
public:
    // Public API
    MedicinesOrderProcessor();
    void setSourceMessage(QString message);
    QString processAndGetProcessedMessage();
private:
    // Internal API and related fields
    QString previousSourceMessage;
    QString sourceMessage;
    QString processedMesage;
    QString currenntStage;
    QString newStage;
    bool stageValid;
    bool retrieveStage();
    void setResult(bool valid, QString msg, QString stage=NULL);
    bool isValidForStage();
    bool isFinalStage();
    bool updateStage();
    bool resetStage();
    bool currentStage(QString stage);
    bool containsKeyWords(QStringList keywords);
    // Specific API and related fields
    void processMessage();
    bool isMatchingInitInput();
    bool isMatchingAddingVerifyPositiveAnswer();
    bool isMatchingAddingFinishedInput();
    bool isMatchingToBeDoneInput();
    QString processUserDrugInfoInput();
    QStringList processedDrugStringList;
};

#endif // MEDICINESORDERPROCESSOR_H
