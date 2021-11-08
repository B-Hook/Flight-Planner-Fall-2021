//
// Created by Braiden Hook on 11/5/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_CONTROL_H
#define INC_21F_FLIGHT_PLANNER_CONTROL_H

#include <fstream>
#include "LinkedList.h"
#include "AdjacencyList.h"
#include "Itinerary.h"
#include "Request.h"
#include "Backtracking.h"

class Control {
private:
    int numOfRequests;
    LinkedList<Request> allRequests;
    LinkedList<Itinerary> completeItinerary; // Stores final Itineraries

public:
    // Overload Constructor, walks through each step in program
    Control(char*, char*, char*);
    void readInRequests(char*); // req-flights
    void writeToFile(char*); // Output
};

#endif //INC_21F_FLIGHT_PLANNER_CONTROL_H
