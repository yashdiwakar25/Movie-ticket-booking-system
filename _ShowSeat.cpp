#pragma once
#include <string>
#include "_Seat.cpp"
#include "_Show.cpp"
using namespace std;

// [OOP Concept: Encapsulation] seatStatus is private and modified only via book() / release()
class ShowSeat {
private:
    string seatNumber;
    SeatTier tier;
    bool isBooked;

public:
    ShowSeat(string seatNumber, SeatTier tier) {
        this->seatNumber = seatNumber;
        this->tier = tier;
        this->isBooked = false;
    }

    bool book() {
        if (!this->isBooked) {
            this->isBooked = true;
            return true;
        }
        return false;
    }

    void release() {
        this->isBooked = false;
    }

    bool getIsBooked() { return this->isBooked; }
    bool isAvailable() { return !this->isBooked; }
    string getSeatNumber() { return this->seatNumber; }
    SeatTier getTier() { return this->tier; }
};

inline Show::Show(int showId, string startTime, Movie* movie, Screen* screen) {
    this->showId = showId;
    this->startTime = startTime;
    this->movie = movie;
    this->screen = screen;
    for (auto& s : screen->getSeats()) {
        this->showSeats.push_back(new ShowSeat(s.getSeatNumber(), s.getTier()));
    }
}

inline Show::~Show() {
    for (ShowSeat* ss : this->showSeats) {
        delete ss;
    }
    this->showSeats.clear();
}

inline void Show::displaySeatLayout() {
    cout << "\n=== Seat Layout for " << this->movie->getTitle() 
         << " (" << this->startTime << ") ===\n";
    for (auto* ss : this->showSeats) {
        cout << "[" << ss->getSeatNumber() 
             << (ss->isAvailable() ? " : AVAILABLE" : " : BOOKED") << "] ";
    }
    cout << "\n=====================================================\n";
}

inline ShowSeat* Show::getShowSeat(string seatNum) {
    for (auto* ss : this->showSeats) {
        if (ss->getSeatNumber() == seatNum) {
            return ss;
        }
    }
    return nullptr;
}