#include "User.h"

User::User() {
    id = 0;
    username = "";
    password = "";
}

User::User(int id, string username, string password) {
    this->id = id;
    this->username = username;
    this->password = password;
}

User::~User() {
}

int User::getId() const {
    return id;
}

string User::getUsername() const {
    return username;
}

string User::getPassword() const {
    return password;
}

void User::setUsername(string username) {
    this->username = username;
}

void User::setPassword(string password) {
    this->password = password;
}