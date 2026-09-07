#pragma once
#include <iostream>
#include <vector>
#include "_Cinema.cpp"
#include "_Show.cpp"
#include "_ShowSeat.cpp"
#include "_Customer.cpp"
#include "_Booking.cpp"
#include "_Payment.cpp"
#include "_PriceCalculator.cpp"
#include "_TicketPrinter.cpp"
#include "_Snack.cpp"
using namespace std;

class BookingService {
private:
    Cinema* cinema;
    vector<Show*> shows;
    vector<Booking*> bookings;
    vector<Snack> snacksCatalog;

public:
    BookingService(Cinema* cinema) {
        this->cinema = cinema;
        this->snacksCatalog.push_back(Snack(1, "Popcorn", 200.0));
        this->snacksCatalog.push_back(Snack(2, "Coke", 80.0));
    }

    ~BookingService() {
        for (Booking* b : this->bookings) {
            delete b;
        }
        this->bookings.clear();
    }

    void addShow(Show* show) {
        this->shows.push_back(show);
    }

    Snack* getSnack(int id) {
        for (auto& s : this->snacksCatalog) {
            if (s.getSnackId() == id) return &s;
        }
        return nullptr;
    }

    Booking* bookSeat(int showIndex, Customer* customer, string seatNum, Payment* paymentMethod) {
        vector<SnackOrder> emptySnacks;
        return this->bookSeat(showIndex, customer, seatNum, paymentMethod, emptySnacks);
    }

    Booking* bookSeat(int showIndex, Customer* customer, string seatNum, Payment* paymentMethod, vector<SnackOrder> snacks) {
        if (showIndex < 0 || showIndex >= static_cast<int>(this->shows.size())) {
            cout << "[Error] Invalid show selection!\n";
            return nullptr;
        }

        Show* selectedShow = this->shows[showIndex];
        ShowSeat* targetSeat = selectedShow->getShowSeat(seatNum);

        if (targetSeat == nullptr) {
            cout << "[Error] Seat \"" << seatNum << "\" does not exist!\n";
            return nullptr;
        }

        if (!targetSeat->isAvailable()) {
            cout << "[Rejected] Seat " << seatNum << " is already BOOKED.\n";
            return nullptr;
        }

        vector<ShowSeat*> requestedSeats = { targetSeat };
        double amount = PriceCalculator::calculateTotal(requestedSeats, snacks);

        if (!paymentMethod->pay(amount)) {
            cout << "[Payment Failed] Seat " << seatNum << " remains AVAILABLE.\n";
            return nullptr;
        }

        targetSeat->book();

        Booking* newBooking = new Booking(selectedShow, customer);
        newBooking->addSeat(targetSeat);
        for (auto& so : snacks) {
            newBooking->addSnackOrder(so);
        }
        newBooking->setBookingAmount(amount);
        newBooking->confirm();

        this->bookings.push_back(newBooking);
        TicketPrinter::printTicket(newBooking);

        return newBooking;
    }

    bool cancelBooking(string bookingId) {
        for (auto* b : this->bookings) {
            if (b->getBookingId() == bookingId) {
                if (b->getStatus() == BookingStatus::CANCELLED) {
                    cout << "[Notice] Booking " << bookingId << " is already cancelled.\n";
                    return false;
                }
                b->cancel();
                for (auto* seat : b->getBookedSeats()) {
                    seat->release();
                }
                cout << "[Success] Booking " << bookingId << " cancelled.\n";
                return true;
            }
        }
        cout << "[Error] Booking ID " << bookingId << " not found!\n";
        return false;
    }
};