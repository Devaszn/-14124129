#include "AuthenticationManager.h"

void AuthenticationManager::registerUser() {

    ofstream file("data/users.txt", ios::app);

    int id;
    string username;
    string password;
    string role;

    cout << "\nEnter ID: ";
string input;
while (true) {
    cin >> input;
    try {
        id = stoi(input);
        break;
    } catch (...) {
        cout << "\nInvalid input! Please enter a NUMBER: ";
    }
}

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    cout << "Enter role (ADMIN/CUSTOMER): ";
    cin >> role;

    file << id << " "
         << username << " "
         << password << " "
         << role << endl;

    file.close();

    cout << "\nUser registered successfully!\n";
}

string AuthenticationManager::login(string username, string password) {

    ifstream file("data/users.txt");

    int id;
    string fileUsername;
    string filePassword;
    string role;

    while (file >> id >> fileUsername >> filePassword >> role) {

        if (username == fileUsername &&
            password == filePassword) {

            file.close();

            cout << "\nLogin successful!\n";
            cout << "Role: " << role << endl;

            return role;
        }
    }

    file.close();

    cout << "\nInvalid username or password.\n";

    return "";
}