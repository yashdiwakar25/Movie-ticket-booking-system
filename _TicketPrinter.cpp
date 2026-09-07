#pragma once
#include <iostream>
#include <iomanip>
#include "_Booking.cpp"
using namespace std;

class TicketPrinter {
public:
    static void printTicket(Booking* b) {
        cout << "\n=========================================\n";
        cout << "           BOOKMYSHOW RECEIPT            \n";
        cout << "=========================================\n";
        cout << "Booking ID : " << b->getBookingId() << "\n";
        cout << "Customer   : " << b->getCustomer()->getName() 
             << " (" << b->getCustomer()->getPhone() << ")\n";
        cout << "Movie      : " << b->getShow()->getMovie()->getTitle() << "\n";
        cout << "Time       : " << b->getShow()->getStartTime() << "\n";
        cout << "Auditorium : " << b->getShow()->getScreen()->getScreenName() << "\n";
        cout << "Seats      : ";
        for (auto* s : b->getBookedSeats()) {
            cout << s->getSeatNumber() << " ";
        }
        cout << "\nSnacks     : ";
        if (b->getSnackOrders().empty()) {
            cout << "None";
        } else {
            for (auto& so : b->getSnackOrders()) {
                cout << so.getSnack()->getName() << " (x" << so.getQuantity() << ") ";
            }
        }
        cout << "\nTotal Paid : Rs. " << fixed << setprecision(2) << b->getBookingAmount() << "\n";
        cout << "Status     : CONFIRMED\n";
        cout << "=========================================\n\n";
    }
};