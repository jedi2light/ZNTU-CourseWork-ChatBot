#include "doctorprocessor.h"

#include <QDebug>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

DoctorProcessor::DoctorProcessor() {
    this->sourceMessage = "";
}

void DoctorProcessor::setSourceMessage(QString message) {
    this->sourceMessage = message;
}

QStringList DoctorProcessor::retrieveAnswerList(QString keyword) {
    QStringList returned;
    QSqlQuery query(QString("SELECT Answers.phrase FROM Answers "
                            "INNER JOIN Keywords ON Answers.keyword_id = Keywords.id "
                            "WHERE Keywords.name = '%1'").arg(keyword));
    if (!query.exec()) {
        qDebug() << query.lastQuery();
        qWarning() << "Unable to retrieve answer list from DB: " << query.lastError();
        return returned;
    }
    while(query.next()) {
        returned.append(query.value(0).toString());
    }
    return returned;
}

QString DoctorProcessor::processAndGetProcessedMessage() {
    QRegularExpression re("(?P<before>.*)(?P<key>[Hh]ello|I want|[Ii]f|[Nn]o|I was|I feel|I felt|[Bb]ye)(?P<after>.*)");
    QRegularExpressionMatch match = re.match(this->sourceMessage);
    if (!match.captured("key").isEmpty() || !match.captured("after").isEmpty()) {
//        QStringList answerList = dictionary[match.captured("key").toLower()];
        QStringList answerList = retrieveAnswerList(match.captured("key").toLower());
        QString answer = answerList.at(qrand() % answerList.size());
        return answer.arg(withConvertedViewpoint(match.captured("after")));
    }
    return "What are you talking about?";
}

QString DoctorProcessor::withConvertedViewpoint(QString string) {
    return string
            .replace("I", "you")
            .replace("you", "I")
            .replace("me", "you")
            .replace("am", "are")
            .replace("was", "were")
            .replace("were", "was");
}
