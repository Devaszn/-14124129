#include "Reservation.h"

Reservation::Reservation() {
    reservationId = 0;
    eventId = 0;
    customerName = "";
    ticketCount = 0;
}

Reservation::Reservation(
    int reservationId,
    int eventId,
    string customerName,
    int ticketCount
) {

    this->reservationId = reservationId;
    this->eventId = eventId;
    this->customerName = customerName;
    this->ticketCount = ticketCount;
}

int Reservation::getReservationId() const {
    return reservationId;
}

int Reservation::getEventId() const {
    return eventId;
}

string Reservation::getCustomerName() const {
    return customerName;
}

int Reservation::getTicketCount() const {
    return ticketCount;
}

void Reservation::displayReservation() const {

    cout << "\n===== RESERVATION =====" << endl;

    cout << "Reservation ID: " << reservationId << endl;
    cout << "Event ID: " << eventId << endl;
    cout << "Customer: " << customerName << endl;
    cout << "Tickets: " << ticketCount << endl;
}