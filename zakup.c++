#include "zakup.h"
#include "user.h"

#include <qdebug.h>
#include <qsqlerror.h>
#include <qsqlquery.h>

zakup::zakup() {}

void zakup::kup(Content content, User user){
    QSqlQuery query;
    query.prepare("INSERT INTO UserContent (user_id, content_id) VALUES (:user_id, :content_id)");
    query.bindValue(":user_id", user.getID());
    query.bindValue(":content_id", content.getContentId());

    if (!query.exec()) {
        qDebug() << "Błąd wykonania zapytania: " << query.lastError().text();
    } else {
        qDebug() << "Zawartość została dodana do bazy danych!";
    }
}

void zakup::subskrybuj(User user) {
    QSqlQuery selectQuery;
    selectQuery.prepare("SELECT content_id FROM Content");

    if (!selectQuery.exec()) {
        qDebug() << "Błąd pobierania content_id: " << selectQuery.lastError().text();
        return;
    }

    QStringList values;
    while (selectQuery.next()) {
        int content_id = selectQuery.value(0).toInt();
        values.append(QString("(%1, %2)").arg(user.getID()).arg(content_id));
    }

    if (values.isEmpty()) {
        qDebug() << "Brak zawartości do subskrypcji.";
        return;
    }

    QString insertQueryStr = "INSERT IGNORE INTO UserContent (user_id, content_id) VALUES " + values.join(", ");
    QSqlQuery insertQuery;

    if (!insertQuery.exec(insertQueryStr)) {
        qDebug() << "Błąd dodawania do UserContent: " << insertQuery.lastError().text();
    } else {
        qDebug() << "Wszystkie zawartości zostały przypisane użytkownikowi!";
    }
}

void zakup::wypozycz(Content content, User user){
    QSqlQuery query;
    query.prepare("INSERT INTO UserContent (user_id, content_id) VALUES (:user_id, :content_id)");
    query.bindValue(":user_id", user.getID());
    query.bindValue(":content_id", content.getContentId());

    if (!query.exec()) {
        qDebug() << "Błąd wykonania zapytania: " << query.lastError().text();
    } else {
        qDebug() << "Zawartość została dodana do bazy danych!";
    }
}
