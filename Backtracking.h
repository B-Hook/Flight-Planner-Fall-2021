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
    Backtracking(Request, AdjacencyList&);
    void setItinerary (Itinerary&);
    Itinerary getItinerary();

};


#endif //INC_21F_FLIGHT_PLANNER_BACKTRACKING_H
