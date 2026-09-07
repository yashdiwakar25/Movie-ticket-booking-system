#pragma once
#include <string>
using namespace std;

// [OOP Concept: Encapsulation] Concession item attributes
class Snack {
private:
    int snackId;
    string name;
    double unitPrice;

public:
    Snack(int snackId, string name, double unitPrice) {
        this->snackId = snackId;
        this->name = name;
        this->unitPrice = unitPrice;
    }

    int getSnackId() { return this->snackId; }
    string getName() { return this->name; }
    double getUnitPrice() { return this->unitPrice; }
};

// [OOP Concept: Encapsulation & Aggregation] Line item for food orders
class SnackOrder {
private:
    Snack* snack;
    int quantity;

public:
    SnackOrder(Snack* snack, int quantity) {
        this->snack = snack;
        this->quantity = quantity;
    }

    Snack* getSnack() { return this->snack; }
    int getQuantity() { return this->quantity; }
    double getSubtotal() { 
        return (this->snack != nullptr) ? (this->snack->getUnitPrice() * this->quantity) : 0.0; 
    }
};