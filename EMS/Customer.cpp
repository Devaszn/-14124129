#include "Customer.h"

Customer::Customer() : User() {
}

Customer::Customer(int id, string username, string password)
    : User(id, username, password) {
}

void Customer::displayMenu() {
    cout << "\n===== CUSTOMER MENU =====" << endl;
    cout << "1. View Events" << endl;
    cout << "2. Reserve Ticket" << endl;
    cout << "3. Cancel Reservation" << endl;
    cout << "4. My Reservations" << endl;
    cout << "5. Logout" << endl;
}