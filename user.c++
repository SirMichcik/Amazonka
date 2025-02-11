#include "user.h"

#include <QSqlQuery>

QString User::getLogin() const {
    return login;
}

QString User::getPassword() const {
    return password;
}

int User::getID() const{
    return userID;
}

bool User::getisAdmin() const {
    return isAdmin;
}

bool User::check_access(int content_id){
    QSqlQuery query;
    query.prepare("SELECT 1 FROM UserContent WHERE user_id = :user_id AND content_id = :content_id");
    query.bindValue(":user_id", this->userID);
    query.bindValue(":content_id", content_id);

    if (query.exec() && query.next()) {
        return true;
    }
    return false;
}
