#ifndef DOCTORPROCESSOR_H
#define DOCTORPROCESSOR_H

#include <QHash>
#include <QString>
#include <QStringList>
#include <QRandomGenerator>

class DoctorProcessor {
public:
    // Public API
    DoctorProcessor();
    void setSourceMessage(QString message);
    QString processAndGetProcessedMessage();
    // Internal API and related fields
    QString sourceMessage;
    QString withConvertedViewpoint(QString string);
    QStringList retrieveAnswerList(QString keyword);
};

#endif // DOCTORPROCESSOR_H
