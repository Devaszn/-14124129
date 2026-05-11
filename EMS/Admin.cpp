#include "Admin.h"

Admin::Admin() : User() {
}

Admin::Admin(int id, string username, string password)
    : User(id, username, password) {
}

void Admin::displayMenu() {
    cout << "\n===== ADMIN MENU =====" << endl;
    cout << "1. Add Event" << endl;
    cout << "2. Remove Event" << endl;
    cout << "3. View Events" << endl;
    cout << "4. View Statistics" << endl;
    cout << "5. Logout" << endl;
}