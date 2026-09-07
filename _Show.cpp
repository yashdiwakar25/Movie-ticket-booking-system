#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "_Movie.cpp"
#include "_Screen.cpp"
using namespace std;

class ShowSeat;

class Show {
private:
    int showId;
    string startTime;
    // [OOP Concept: Aggregation] Show refers to Movie; Movie exists independently
    Movie* movie;
    // [OOP Concept: Aggregation] Show refers to Screen; Screen exists independently
    Screen* screen;
    // [OOP Concept: Composition] Show creates and owns its real-time ShowSeat instances
    vector<ShowSeat*> showSeats;

public:
    Show(int showId, string startTime, Movie* movie, Screen* screen);
    ~Show();

    void displaySeatLayout();
    ShowSeat* getShowSeat(string seatNum);

    Movie* getMovie() { return this->movie; }
    Screen* getScreen() { return this->screen; }
    string getStartTime() { return this->startTime; }
};