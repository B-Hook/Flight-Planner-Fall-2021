//
// Created by Braiden Hook on 10/27/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_DESTINATIONCITY_H
#define INC_21F_FLIGHT_PLANNER_DESTINATIONCITY_H
#include <string>

using namespace std;
// Destination city is what is in each node on the right side of the adjacency list
// Seems pretty self-explanatory.
class DestinationCity {
private:
    string name; // name of Destination City
    int cost;
    int time;
    string carrier;
    string origin; // name of the Origin city the destination city belongs to
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
