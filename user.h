#ifndef USER_H
#define USER_H

#include <QString>

class User {
private:
    int userID;
    QString login;
    QString password;
    bool isAdmin;

public:
    User(int userID, QString login, QString password, bool isAdmin) {
        this->userID = userID;
        this->login = login;
        this->password = password;
        this->isAdmin = isAdmin;
    }

    QString getLogin() const;
    QString getPassword() const;
    int getID() const;
    bool getisAdmin() const;

    bool check_access(int content_id);
};

#endif // USER_H
