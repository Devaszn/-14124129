#ifndef AUTHENTICATIONMANAGER_H
#define AUTHENTICATIONMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "User.h"

using namespace std;

class AuthenticationManager {
public:
    static void registerUser();
    static string login(string username, string password);
};

#endif