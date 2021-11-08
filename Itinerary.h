//
// Created by Braiden Hook on 11/7/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_ITINERARY_H
#define INC_21F_FLIGHT_PLANNER_ITINERARY_H


#include "LinkedList.h"
#include "Flight.h"

class Itinerary {

private:
    LinkedList <Flight> top3Flights;
    int count = 1;

public:
    void top3 (Flight, string);
    LinkedList <Flight>& getTop3();
};


#endif //INC_21F_FLIGHT_PLANNER_ITINERARY_H
