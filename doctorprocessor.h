#ifndef DOCTORPROCESSOR_H
#define DOCTORPROCESSOR_H

#include <QString>
#include <QStringList>

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
