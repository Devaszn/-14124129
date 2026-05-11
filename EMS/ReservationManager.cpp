#include "ReservationManager.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

bool eventExists(int searchedEventId);
void showAvailableEvents();
int getEventCapacity(int searchedEventId);
int getReservedTickets(int searchedEventId);

int readReservationInt(string message) {
    int value;
    while (true) {
        cout << message;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input! Please enter a NUMBER.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int readReservationId() {
    ifstream file("data/reservations.txt");
    string line;
    int maxId = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;

        size_t position = line.find("|");
        if (position == string::npos) continue;

        try {
            int id = stoi(line.substr(0, position));
            if (id > maxId) maxId = id;
        } catch (...) {
            continue;
        }
    }

    file.close();
    return maxId + 1;
}

bool eventExists(int searchedEventId) {
    ifstream file("data/events.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        size_t position = line.find("|");
        if (position == string::npos) continue;

        try {
            int eventId = stoi(line.substr(0, position));
            if (eventId == searchedEventId) {
                file.close();
                return true;
            }
        } catch (...) {
            continue;
        }
    }

    file.close();
    return false;
}

void showAvailableEvents() {
    ifstream file("data/events.txt");
    string line;

    cout << "\n===== AVAILABLE EVENTS =====\n";

    while (getline(file, line)) {
        if (line.empty()) continue;

        vector<string> parts;
        string temp = "";

        for (char c : line) {
            if (c == '|') { parts.push_back(temp); temp = ""; }
            else { temp += c; }
        }
        parts.push_back(temp);

        if (parts.size() < 6) continue;

        cout << "ID: " << parts[0]
             << " | Title: " << parts[1]
             << " | Date: " << parts[2]
             << endl;
    }

    file.close();
}

int getEventCapacity(int searchedEventId) {
    ifstream file("data/events.txt");
    string line;

    while (getline(file, line)) {
        vector<string> parts;
        string temp = "";

        for (char c : line) {
            if (c == '|') { parts.push_back(temp); temp = ""; }
            else { temp += c; }
        }
        parts.push_back(temp);

        if (parts.size() < 5) continue;

        int eventId = stoi(parts[0]);
        if (eventId == searchedEventId) {
            file.close();
            return stoi(parts[4]);
        }
    }

    file.close();
    return 0;
}

int getReservedTickets(int searchedEventId) {
    ifstream file("data/reservations.txt");
    string line;
    int totalReserved = 0;

    while (getline(file, line)) {
        vector<string> parts;
        string temp = "";

        for (char c : line) {
            if (c == '|') { parts.push_back(temp); temp = ""; }
            else { temp += c; }
        }
        parts.push_back(temp);

        if (parts.size() < 4) continue;

        int eventId = stoi(parts[1]);
        int ticketCount = stoi(parts[3]);

        if (eventId == searchedEventId) {
            totalReserved += ticketCount;
        }
    }

    file.close();
    return totalReserved;
}

void ReservationManager::reserveTicket() {
    int reservationId;
    int eventId;
    string customerName;
    int ticketCount;

    reservationId = readReservationId();
    cout << "\nGenerated Reservation ID: " << reservationId << endl;

    showAvailableEvents();

    eventId = readReservationInt("Enter Event ID: ");

    while (!eventExists(eventId)) {
        cout << "Event with this ID does not exist!\n";
        eventId = readReservationInt("Enter valid Event ID: ");
    }

    int capacity = getEventCapacity(eventId);
    int reserved = getReservedTickets(eventId);
    int availableSeats = capacity - reserved;

    if (availableSeats <= 0) {
        cout << "\nThis event is SOLD OUT!\n";
        return;
    }

    cout << "\nAvailable seats: " << availableSeats << endl;

    cout << "Enter customer name: ";
    getline(cin, customerName);

    ticketCount = readReservationInt("Enter number of tickets: ");
    while (ticketCount <= 0 || ticketCount > availableSeats) {
        if (ticketCount <= 0) {
            cout << "\nTicket count must be greater than 0!\n";
        } else {
            cout << "\nNot enough available seats! Available: " << availableSeats << endl;
        }
        ticketCount = readReservationInt("Enter valid number of tickets: ");
    }

    ofstream file("data/reservations.txt", ios::app);

    file << reservationId << "|"
         << eventId << "|"
         << customerName << "|"
         << ticketCount << endl;

    file.close();
    cout << "\nReservation completed successfully!\n";
}

void ReservationManager::viewReservations() {

    ifstream file("data/reservations.txt");

    string line;

    cout << "\n=====================================================================================\n";

    cout << left
         << setw(20) << "RESERVATION ID"
         << setw(15) << "EVENT ID"
         << setw(25) << "CUSTOMER"
         << setw(15) << "TICKETS"
         << endl;

    cout << "=====================================================================================\n";

    while (getline(file, line)) {

        if (line.empty())
            continue;

        vector<string> parts;
        string temp = "";

        for (char c : line) {

            if (c == '|') {
                parts.push_back(temp);
                temp = "";
            }
            else {
                temp += c;
            }
        }

        parts.push_back(temp);

        if (parts.size() < 4)
            continue;

        cout << left
             << setw(20) << parts[0]
             << setw(15) << parts[1]
             << setw(25) << parts[2]
             << setw(15) << parts[3]
             << endl;
    }

    cout << "=====================================================================================\n";

    file.close();
}

void ReservationManager::cancelReservation() {
    int cancelId = readReservationInt("\nEnter Reservation ID to cancel: ");

    ifstream inputFile("data/reservations.txt");
    ofstream tempFile("data/temp_reservations.txt");

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        if (line.empty()) continue;

        vector<string> parts;
        string temp = "";

        for (char c : line) {
            if (c == '|') { parts.push_back(temp); temp = ""; }
            else { temp += c; }
        }
        parts.push_back(temp);

        if (parts.size() < 4) continue;

        int reservationId = stoi(parts[0]);

        if (reservationId == cancelId) {
            found = true;
            continue;
        }

        tempFile << line << endl;
    }

    inputFile.close();
    tempFile.close();

    remove("data/reservations.txt");
    rename("data/temp_reservations.txt", "data/reservations.txt");

    if (found) {
        cout << "\nReservation cancelled successfully!\n";
    } else {
        cout << "\nReservation with this ID was not found.\n";
    }
}