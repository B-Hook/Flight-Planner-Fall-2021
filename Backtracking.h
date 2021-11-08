//
// Created by Braiden Hook on 11/7/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_BACKTRACKING_H
#define INC_21F_FLIGHT_PLANNER_BACKTRACKING_H

#include <fstream>
#include "LinkedList.h"
#include "DSStack.h"
#include "OriginCity.h"
#include "DestinationCity.h"
#include "AdjacencyList.h"
#include "Flight.h"
#include "Itinerary.h"
#include "Request.h"

class Backtracking {
private:
    Itinerary requestedItinerary;
public:
    // Backtracks the adjacency list and creates an itinerary of the top 3 best options
    Backtracking(Request, AdjacencyList&);
    // Placing the 3 best flights into an itinerary
    void setItinerary (Itinerary&);
    // Getting the 3 best flights
    Itinerary getItinerary();

};


#endif //INC_21F_FLIGHT_PLANNER_BACKTRACKING_H
