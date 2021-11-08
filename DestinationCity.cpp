//
// Created by Braiden Hook on 10/27/21.
//

#include "DestinationCity.h"

DestinationCity::DestinationCity() {

}
DestinationCity::DestinationCity(string name, int cost, int time, string carrier, string origin) {
    this->name = name;
    this->cost = cost;
    this->time = time;
    this->carrier = carrier;
    this->origin = origin;
}

string DestinationCity::getName() {
    return this->name;
}

int DestinationCity::getCost() {
    return this->cost;
}

int DestinationCity::getTime() {
    return this->time;
}

string DestinationCity::getCarrier() {
    return this->carrier;
}

string DestinationCity::getOrigin() {
    return this->origin;
}

