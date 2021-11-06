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

class Control {
private:
    //LinkedList<OriginCity> passedList;
    DSStack<DestinationCity> myStack;
    AdjacencyList myList;

public:
    void backtracking (char*, char*);


};

#endif //INC_21F_FLIGHT_PLANNER_CONTROL_H
