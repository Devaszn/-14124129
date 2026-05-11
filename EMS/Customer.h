#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"

class Customer : public User {
public:
    Customer();
    Customer(int id, string username, string password);

    void displayMenu() override;
};

#endif