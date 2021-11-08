//
// Created by Braiden Hook on 10/27/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_ORIGINCITY_H
#define INC_21F_FLIGHT_PLANNER_ORIGINCITY_H

#include <string>
#include "DestinationCity.h"
#include "LinkedList.h"

using namespace std;

// OriginCity contains a linkedList of the Destination Cities
// Mainly used for the adjacency list
class OriginCity {
private:
    string name; // Name of origin city
    LinkedList<DestinationCity> cityList; // Cities one can get to from the origin
public:
    void addCity(DestinationCity); // Adds a destination city to the list
    LinkedList<DestinationCity>& getCityList(); // returning the list
    void setName(string);
    string getName();


};


#endif //INC_21F_FLIGHT_PLANNER_ORIGINCITY_H
