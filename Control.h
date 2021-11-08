//
// Created by Braiden Hook on 11/5/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_CONTROL_H
#define INC_21F_FLIGHT_PLANNER_CONTROL_H

#include <fstream>
#include "LinkedList.h"
#include "DSStack.h"
#include "OriginCity.h"
#include "DestinationCity.h"
#include "AdjacencyList.h"
#include "Flight.h"
#include "Itinerary.h"
#include "Request.h"
#include "Backtracking.h"

class Control {
private:
    int numOfRequests;
    LinkedList<Request> allRequests;
    LinkedList<Itinerary> completeItinerary;

public:
    //void backtracking (char*, char*);
    Control(char*, char*, char*);
    void readInRequests(char*);
    void writeToFile(char*);



};

#endif //INC_21F_FLIGHT_PLANNER_CONTROL_H
