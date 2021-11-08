//
// Created by Braiden Hook on 10/27/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_DESTINATIONCITY_H
#define INC_21F_FLIGHT_PLANNER_DESTINATIONCITY_H
#include <string>

using namespace std;

class DestinationCity {
private:
    string name;
    int cost;
    int time;
    string carrier;
    string origin;
public:
    DestinationCity();
    DestinationCity(string, int, int, string, string);
    string getName();
    int getCost();
    int getTime();
    string getCarrier();
    string getOrigin();

};


#endif //INC_21F_FLIGHT_PLANNER_DESTINATIONCITY_H
