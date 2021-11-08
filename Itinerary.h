//
// Created by Braiden Hook on 11/7/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_ITINERARY_H
#define INC_21F_FLIGHT_PLANNER_ITINERARY_H


#include "LinkedList.h"
#include "Flight.h"

class Itinerary {

private:
    LinkedList <Flight> top3Flights; // Stores the top 3 flights patterns
    int count = 0; // To keep track of the amount of flights

public:
    void top3 (Flight, string); // Calculates if the new flight is eligible to join the top 3
    LinkedList <Flight>& getTop3(); // Returns the top 3
};


#endif //INC_21F_FLIGHT_PLANNER_ITINERARY_H
