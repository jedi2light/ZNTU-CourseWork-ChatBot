#ifndef DIASEASEPROCESSOR_H
#define DIASEASEPROCESSOR_H

#include <QList>
#include <QString>

class DiaseaseProcessor {
public:
    // Public API
    DiaseaseProcessor();
    void setSourceMessage(QString message);
    QString processAndGetProcessedMessage();
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
    bool isMatchingAddingFinishedInput();
    bool isMatchingToBeDoneInput();
    QStringList processUserSymptomInput();
    QStringList diaseasesList;
};

#endif // DIASEASEPROCESSOR_H
