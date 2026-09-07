#pragma once
#include <string>
using namespace std;

enum class SeatTier { SILVER, GOLD, PLATINUM };

// [OOP Concept: Encapsulation] Physical seat properties encapsulated
class Seat {
private:
    string seatNumber;
    SeatTier tier;

public:
    Seat(string seatNumber, SeatTier tier) {
        this->seatNumber = seatNumber;
        this->tier = tier;
    }

    string getSeatNumber() { return this->seatNumber; }
    SeatTier getTier() { return this->tier; }
};