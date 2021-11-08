//
// Created by Braiden Hook on 11/7/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_FLIGHT_H
#define INC_21F_FLIGHT_PLANNER_FLIGHT_H


#include "DestinationCity.h"
#include "LinkedList.h"

class Flight {

private:
    int totalCost;
    int totalTime;
    LinkedList<DestinationCity> path;
public:
    Flight();
    Flight(LinkedList<DestinationCity>&);
    void calculateCostTime();
    int getTotalCost();
    int getTotalTime();
    LinkedList<DestinationCity>& getPath();


};


#endif //INC_21F_FLIGHT_PLANNER_FLIGHT_H
