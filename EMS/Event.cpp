#include "Event.h"

Event::Event() {
    id = 0;
    title = "";
    date = "";
    location = "";
    capacity = 0;
    price = 0;
}

Event::Event(
    int id,
    string title,
    string date,
    string location,
    int capacity,
    double price
) {

    this->id = id;
    this->title = title;
    this->date = date;
    this->location = location;
    this->capacity = capacity;
    this->price = price;
}

int Event::getId() const {
    return id;
}

string Event::getTitle() const {
    return title;
}

string Event::getDate() const {
    return date;
}

string Event::getLocation() const {
    return location;
}

int Event::getCapacity() const {
    return capacity;
}

double Event::getPrice() const {
    return price;
}

void Event::displayEvent() const {

    cout << "\n===== EVENT =====" << endl;

    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Date: " << date << endl;
    cout << "Location: " << location << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Price: " << price << endl;
}