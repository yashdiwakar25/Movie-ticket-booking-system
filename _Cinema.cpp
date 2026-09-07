#pragma once
#include <string>
#include <vector>
#include "_Screen.cpp"
using namespace std;

class Cinema {
private:
    string name;
    // [OOP Concept: Composition] Cinema physically owns its Screen objects
    vector<Screen> screens;

public:
    Cinema(string name) {
        this->name = name;
    }

    void addScreen(Screen screen) {
        this->screens.push_back(screen);
    }

    vector<Screen>& getScreens() { return this->screens; }
    string getCinemaName() { return this->name; }
};