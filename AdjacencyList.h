//
// Created by Braiden Hook on 10/27/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_ADJACENCYLIST_H
#define INC_21F_FLIGHT_PLANNER_ADJACENCYLIST_H

#include <fstream>
#include <sstream>
#include <iostream>
#include "LinkedList.h"
#include "OriginCity.h"
#include "DestinationCity.h"

class AdjacencyList {
private:
    LinkedList<OriginCity> list;

public:
    void addToList (OriginCity, DestinationCity);
    void cityList(char*);
    LinkedList<OriginCity>& getList();

};


#endif //INC_21F_FLIGHT_PLANNER_ADJACENCYLIST_H
