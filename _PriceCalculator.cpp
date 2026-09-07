#pragma once
#include <vector>
#include "_ShowSeat.cpp"
#include "_Snack.cpp"
using namespace std;

class PriceCalculator {
public:
    static double getPrice(SeatTier tier) {
        switch (tier) {
            case SeatTier::SILVER:   return 150.0;
            case SeatTier::GOLD:     return 250.0;
            case SeatTier::PLATINUM: return 400.0;
            default:                 return 0.0;
        }
    }

    static double calculateTotal(vector<ShowSeat*> seats, vector<SnackOrder> snacks) {
        double total = 0.0;
        for (auto* s : seats) {
            total += getPrice(s->getTier());
        }
        for (auto& so : snacks) {
            total += so.getSubtotal();
        }
        return total;
    }

    static double calculateTotal(SeatTier tier) {
        return getPrice(tier);
    }
};