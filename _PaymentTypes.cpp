#pragma once
#include <iostream>
#include <string>
#include "_Payment.cpp"
using namespace std;

// [OOP Concept: Inheritance & Runtime Polymorphism]
class UpiPayment : public Payment {
private:
    string upiId;
    bool simulateSuccess;

public:
    UpiPayment(string upiId, bool simulateSuccess = true) {
        this->upiId = upiId;
        this->simulateSuccess = simulateSuccess;
    }

    bool pay(double amount) override {
        if (!this->simulateSuccess) {
            cout << "[UPI Gateway] Error: Payment timed out/failed for UPI ID: " << this->upiId << "\n";
            return false;
        }
        cout << "[UPI Gateway] Authorized Rs. " << amount << " from VPA: " << this->upiId << "\n";
        return true;
    }
};

class CardPayment : public Payment {
private:
    string cardNumber;

public:
    CardPayment(string cardNumber) {
        this->cardNumber = cardNumber;
    }

    bool pay(double amount) override {
        cout << "[Card Gateway] Charged Rs. " << amount << " to Card ending ****" 
             << this->cardNumber.substr(this->cardNumber.length() - 4) << "\n";
        return true;
    }
};

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "[Counter] Collected cash: Rs. " << amount << "\n";
        return true;
    }
};