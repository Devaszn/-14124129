#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>

using namespace std;

class Reservation {

private:
    int reservationId;
    int eventId;
    string customerName;
    int ticketCount;

public:
    Reservation();

    Reservation(
        int reservationId,
        int eventId,
        string customerName,
        int ticketCount
    );

    int getReservationId() const;
    int getEventId() const;
    string getCustomerName() const;
    int getTicketCount() const;

    void displayReservation() const;
};

#endif