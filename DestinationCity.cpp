//
// Created by Braiden Hook on 10/27/21.
//

#include "DestinationCity.h"

DestinationCity::DestinationCity() {

}
DestinationCity::DestinationCity(string name, int cost, int time, string carrier) {
    this->name = name;
    this->cost = cost;
    this->time = time;
    this->carrier = carrier;
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

