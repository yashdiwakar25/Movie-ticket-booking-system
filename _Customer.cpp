#pragma once
#include <string>
using namespace std;

// [OOP Concept: Encapsulation] Customer data protected from direct modification
class Customer {
private:
    string name;
    string phone;

public:
    Customer(string name, string phone) {
        this->name = name;
        this->phone = phone;
    }

    string getName() { return this->name; }
    string getPhone() { return this->phone; }
};