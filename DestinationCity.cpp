//
// Created by Braiden Hook on 10/27/21.
//

#include "DestinationCity.h"

DestinationCity::DestinationCity() {
    //name = "";
    //cost = 0;
    //time = 0;
    //carrier = "";
}
DestinationCity::DestinationCity(string name, int cost, int time, string carrier) {
    this->name = name;
    this->cost = cost;
    this->time = time;
    this->carrier = carrier;
}

string DestinationCity::getName() {
    return name;
}

