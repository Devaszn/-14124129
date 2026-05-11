#include <iostream>

#include "AuthenticationManager.h"
#include "EventManager.h"
#include "ReservationManager.h"
#include "StatisticsManager.h"

using namespace std;

void adminMenu() {

    int choice;

    do {

        cout << "\n========== ADMIN MENU ==========\n";

        cout << "1. Add Event\n";
        cout << "2. Delete Event\n";
        cout << "3. View Events\n";
        cout << "4. Search Events\n";
        cout << "5. View Reservations\n";
        cout << "6. View Statistics\n";
        cout << "7. Logout\n";

        cout << "Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                EventManager::addEvent();
                break;

            case 2:
                EventManager::deleteEvent();
                break;

            case 3:
                EventManager::viewEvents();
                break;

            case 4:
                EventManager::searchEvents();
                break;

            case 5:
                ReservationManager::viewReservations();
                break;

            case 6:
                StatisticsManager::viewStatistics();
                break;
        }

    } while(choice != 7);
}

void customerMenu() {

    int choice;

    do {

        cout << "\n========== CUSTOMER MENU ==========\n";

        cout << "1. View Events\n";
        cout << "2. Search Events\n";
        cout << "3. Reserve Ticket\n";
        cout << "4. Cancel Reservation\n";
        cout << "5. Logout\n";

        cout << "Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                EventManager::viewEvents();
                break;

            case 2:
                EventManager::searchEvents();
                break;

            case 3:
                ReservationManager::reserveTicket();
                break;

            case 4:
                ReservationManager::cancelReservation();
                break;
        }

    } while(choice != 5);
}

int main() {

    int choice;

    do {

        cout << "\n===== EVENT MANAGEMENT SYSTEM =====\n";

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {

            AuthenticationManager::registerUser();
        }

        else if (choice == 2) {

            string username;
            string password;

            cout << "\nEnter username: ";
            cin >> username;

            cout << "Enter password: ";
            cin >> password;

            string role =
                AuthenticationManager::login(username, password);

            if (role == "ADMIN") {
                adminMenu();
            }

            else if (role == "CUSTOMER") {
                customerMenu();
            }
        }

    } while(choice != 3);

    return 0;
}