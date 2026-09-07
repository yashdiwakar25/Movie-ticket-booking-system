#pragma once
#include <string>
#include <vector>
#include "_Show.cpp"
#include "_ShowSeat.cpp"
#include "_Customer.cpp"
#include "_Snack.cpp"
using namespace std;

enum class BookingStatus { CONFIRMED, CANCELLED, FAILED };

class Booking {
private:
    static int nextBookingId;

    string bookingId;
    Show* show;
    Customer* customer;
    vector<ShowSeat*> bookedSeats;
    vector<SnackOrder> snackOrders;
    double bookingAmount;
    BookingStatus status;

public:
    Booking(Show* show, Customer* customer) {
        this->bookingId = "BMS-" + to_string(++nextBookingId);
        this->show = show;
        this->customer = customer;
        this->bookingAmount = 0.0;
        this->status = BookingStatus::FAILED;
    }

    void addSeat(ShowSeat* seat) { this->bookedSeats.push_back(seat); }
    void addSnackOrder(SnackOrder order) { this->snackOrders.push_back(order); }
    void setBookingAmount(double amount) { this->bookingAmount = amount; }
    void confirm() { this->status = BookingStatus::CONFIRMED; }
    void cancel() { this->status = BookingStatus::CANCELLED; }

    string getBookingId() { return this->bookingId; }
    BookingStatus getStatus() { return this->status; }
    Show* getShow() { return this->show; }
    Customer* getCustomer() { return this->customer; }
    vector<ShowSeat*>& getBookedSeats() { return this->bookedSeats; }
    vector<SnackOrder>& getSnackOrders() { return this->snackOrders; }
    double getBookingAmount() { return this->bookingAmount; }
};

int Booking::nextBookingId = 1000;