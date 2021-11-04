//
// Created by Braiden Hook on 10/27/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_ORIGINCITY_H
#define INC_21F_FLIGHT_PLANNER_ORIGINCITY_H

#include <string>
#include "DestinationCity.h"
#include "LinkedList.h"

using namespace std;
class OriginCity {
private:
    string name;
    LinkedList<DestinationCity> cityList; // Some issue here not being initialized to null
public:
    //OriginCity();
    //OriginCity(string);
    void addCity(DestinationCity);
    void setName(string);
    string getName();

};


#endif //INC_21F_FLIGHT_PLANNER_ORIGINCITY_H
