#include "EventManager.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int readInt(string message) {
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

double readDouble(string message) {
    double value;
    while (true) {
        cout << message;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input! Please enter a valid price.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int generateEventId() {
    ifstream file("data/events.txt");
    string line;
    int maxId = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;

        size_t position = line.find("|");
        if (position == string::npos) continue;

        int currentId = stoi(line.substr(0, position));
        if (currentId > maxId) {
            maxId = currentId;
        }
    }

    file.close();
    return maxId + 1;
}

void EventManager::addEvent() {
    ofstream file("data/events.txt", ios::app);

    int id = generateEventId();
    string title, date, location;
    int capacity;
    double price;

    cout << "\nGenerated Event ID: " << id << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter title: ";
    getline(cin, title);

    cout << "Enter date: ";
    getline(cin, date);

    cout << "Enter location: ";
    getline(cin, location);

    capacity = readInt("Enter capacity: ");
    price = readDouble("Enter price: ");

    char confirm;

    cout << "\n===== EVENT SUMMARY =====\n";

    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Date: " << date << endl;
    cout << "Location: " << location << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Price: " << price << endl;

    cout << "\nConfirm event creation? (Y/N): ";
    cin >> confirm;

        if (toupper(confirm) != 'Y') {
            cout << "\nEvent creation cancelled.\n";
        return;
}

    file << id << "|"
         << title << "|"
         << date << "|"
         << location << "|"
         << capacity << "|"
         << price << endl;

    file.close();
    cout << "\nEvent added successfully!\n";
}

void EventManager::viewEvents() {

    ifstream file("data/events.txt");

    string line;

    cout << "\n=================================================================================================\n";

    cout << left
         << setw(10) << "ID"
         << setw(25) << "TITLE"
         << setw(20) << "DATE"
         << setw(20) << "LOCATION"
         << setw(10) << "CAPACITY"
         << setw(10) << "PRICE"
         << endl;

    cout << "=================================================================================================\n";

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

        if (parts.size() < 6)
            continue;

        cout << left
             << setw(10) << parts[0]
             << setw(25) << parts[1]
             << setw(20) << parts[2]
             << setw(20) << parts[3]
             << setw(10) << parts[4]
             << setw(10) << parts[5]
             << endl;
    }

    cout << "=================================================================================================\n";

    file.close();
}

    void EventManager::deleteEvent() {

        viewEvents();
        
        int deleteId;
        
    while (true) {

    deleteId = readInt("\nEnter Event ID to delete: ");

    ifstream checkFile("data/events.txt");

    string line;
    bool exists = false;

    while (getline(checkFile, line)) {

        if (line.empty())
            continue;

        size_t position = line.find("|");

        if (position == string::npos)
            continue;

        int eventId = stoi(line.substr(0, position));

        if (eventId == deleteId) {
            exists = true;
            break;
        }
    }

        checkFile.close();

        if (exists)
        break;

    cout <<"\n Invalid Id.\n";
    return;
}

    char confirm;

    cout <<"\n Are you sure you want to delete this file (Y/N): ";
    cin >> confirm;

    if(toupper(confirm) !='Y') {
        cout << "\n Event deletion stopped\n";
        return;
    }

    ifstream inputFile("data/events.txt");
    ofstream tempFile("data/temp.txt");

        string line;

        while (getline(inputFile, line)) {

            if (line.empty())
            continue;

            size_t position = line.find("|");

            if (position == string::npos)
            continue;

            int eventId = stoi(line.substr(0, position));

            if (eventId == deleteId)
                continue;
            tempFile << line << endl;
        }

    
    

    inputFile.close();
    tempFile.close();

    remove("data/events.txt");
    rename("data/temp.txt", "data/events.txt");

        cout << "\nEvent deleted successfully\n";

}

void EventManager::searchEvents() {

    ifstream file("data/events.txt");

    string keyword;

    cout << "\nEnter keyword to search: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, keyword);

    string line;
    bool found = false;

    cout << "\n===== SEARCH RESULTS =====\n";

    while (getline(file, line)) {

        if (line.empty())
            continue;

        if (line.find(keyword) != string::npos) {

            cout << line << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No matching events found.\n";
    }

    file.close();
}