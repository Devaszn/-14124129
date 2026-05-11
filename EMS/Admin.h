#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {
public:
    Admin();
    Admin(int id, string username, string password);

    void displayMenu() override;
};

#endif