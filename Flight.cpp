//
// Created by Braiden Hook on 11/7/21.
//

#include "Flight.h"

Flight::Flight() {

}

Flight::Flight(LinkedList<DestinationCity>& path) {
    this->path = path;
    this->totalCost = 0;
    this->totalTime = 0;
}

void Flight::calculateCostTime() {
    int count = 0;
    path.currToBack();
    string prevCarrier;
    // Goes through each path, if there is a change in character or
    // if there is multiple stop points, additional minutes will be added
    while (!path.isCurrNull()){
        if (count > 0) {
            totalCost += 23;
            totalTime += 43;
            if (path.getCurrVal().getCarrier() != prevCarrier)
                totalTime += 27;
        }
        totalCost += path.getCurrVal().getCost();
        totalTime += path.getCurrVal().getTime();
        prevCarrier = path.getCurrVal().getCarrier();
        count ++;
        path.currToPrev();
    }


}

int Flight::getTotalCost() {
    return this->totalCost;
}

int Flight::getTotalTime() {
    return this->totalTime;
}

LinkedList<DestinationCity> &Flight::getPath() {
    return this->path;
}
