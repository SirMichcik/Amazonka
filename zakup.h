#ifndef ZAKUP_H
#define ZAKUP_H

#include "content.h"
#include "user.h"

class zakup
{
public:
    zakup();

    void subskrybuj(User user);
    void kup(Content content, User user);
    void wypozycz(Content content, User user);
};

#endif // ZAKUP_H
