#pragma once
#include <string>
using namespace std;

// [OOP Concept: Encapsulation] Attributes kept private, accessed only through getters
class Movie {
private:
    string title;
    string language;
    int durationMinutes;

public:
    // [OOP Concept: this Keyword] Resolving instance attributes from parameters
    Movie(string title, string language, int durationMinutes) {
        this->title = title;
        this->language = language;
        this->durationMinutes = durationMinutes;
    }

    // [OOP Concept: Compile-Time Polymorphism] Overloaded constructor
    Movie(string title) {
        this->title = title;
        this->language = "English";
        this->durationMinutes = 120;
    }

    string getTitle() { return this->title; }
    string getLanguage() { return this->language; }
    int getDurationMinutes() { return this->durationMinutes; }
};