#pragma once

// [OOP Concept: Abstraction] Pure virtual contract for payments
class Payment {
public:
    virtual ~Payment() = default;
    virtual bool pay(double amount) = 0;
};