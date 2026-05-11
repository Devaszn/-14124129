#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

using namespace std;

class Event {

private:
    int id;
    string title;
    string date;
    string location;
    int capacity;
    double price;

public:
    Event();

    Event(
        int id,
        string title,
        string date,
        string location,
        int capacity,
        double price
    );

    int getId() const;
    string getTitle() const;
    string getDate() const;
    string getLocation() const;
    int getCapacity() const;
    double getPrice() const;

    void displayEvent() const;
};

#endif