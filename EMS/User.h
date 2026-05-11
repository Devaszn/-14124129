#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User {
protected:
    int id;
    string username;
    string password;

public:
    User();
    User(int id, string username, string password);

    virtual ~User();

    int getId() const;
    string getUsername() const;
    string getPassword() const;

    void setUsername(string username);
    void setPassword(string password);

    virtual void displayMenu() = 0;
};

#endif