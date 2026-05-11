#include "StatisticsManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void StatisticsManager::viewStatistics() {

    ifstream eventsFile("data/events.txt");
    ifstream reservationsFile("data/reservations.txt");

    string line;

    int totalEvents = 0;
    int totalReservations = 0;
    int totalTicketsSold = 0;
    double totalRevenue = 0.0;

    vector <int> eventIds;
    vector <string> eventTitles;
    vector <double> eventPrices;
    vector <int> soldTickets;

    while (getline(eventsFile, line)) {
        if (line.empty()) 
        continue;

        vector<string> parts;
        string temp = "";

        for (char c : line) {
            if (c == '|') {
                parts.push_back(temp); 
                temp = ""; }
            else {
                temp += c; 
            }
        }

        parts.push_back(temp);

        if (parts.size() < 6 )
        continue;

        totalEvents++;
        eventIds.push_back(stoi(parts[0]));
        eventTitles.push_back(parts[1]);
        eventPrices.push_back(stod(parts[5]));
        soldTickets.push_back(0);
    }

        eventsFile.close();

        while (getline(reservationsFile, line)) {
            if (line.empty())
                continue;

            vector<string> parts;
            string temp = "";

            for (char c : line) {
                if (c == '|') {
                    parts.push_back(temp);
                    temp = "";
                } else {
                    temp += c;
                }
            }

            parts.push_back(temp);
            if (parts.size() < 4)
                continue;

            totalReservations++;
            int eventId = stoi(parts[1]);
            int tickets = stoi(parts[3]);

            totalTicketsSold += tickets;

            for (int i = 0; i < eventIds.size(); i++) {
                if (eventIds[i] == eventId) {
                    soldTickets[i] += tickets;
                    totalRevenue += tickets * eventPrices[i];
                    break;
                }
            }
        }

        reservationsFile.close();

            int maxtickets = 0;
            string mostpopularEvent = "None";

            for (int i = 0; i < eventIds.size(); i++) {
                if (soldTickets[i] > maxtickets) {
                    maxtickets = soldTickets[i];
                    mostpopularEvent = eventTitles[i];
                }
            }

            cout << "\n===== STATISTICS =====\n";

            cout << "Total Events: " 
                << totalEvents << endl;

            cout << "Total Reservations: " 
                << totalReservations << endl;

            cout << "Total Tickets Sold: "
                << totalTicketsSold << endl;
            
            cout << "Total Revenue: $"
                << totalRevenue << endl;
            
            cout << "Most Popular Event: "
                << mostpopularEvent << endl;
            
            cout << "Tickets Sold for Most Popular Event: "
                << maxtickets << endl;
}
