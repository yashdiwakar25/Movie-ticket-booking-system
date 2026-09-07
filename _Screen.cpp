#pragma once
#include <string>
#include <vector>
#include "_Seat.cpp"
using namespace std;

class Screen {
private:
    int screenId;
    string screenName;
    // [OOP Concept: Composition] Screen physically owns its Seat objects
    vector<Seat> seats;

public:
    Screen(int screenId, string screenName) {
        this->screenId = screenId;
        this->screenName = screenName;
    }

    void addSeat(Seat seat) {
        this->seats.push_back(seat);
    }

    vector<Seat>& getSeats() { return this->seats; }
    string getScreenName() { return this->screenName; }
    int getScreenId() { return this->screenId; }
};