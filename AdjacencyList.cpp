//
// Created by Braiden Hook on 10/27/21.
//

#include "AdjacencyList.h"

void AdjacencyList::addOriginCity(OriginCity city) {
    list.append(city);
}

void AdjacencyList::addCityDestination(DestinationCity city) {
    list.currToFront();
    while (list.getCurrVal().getName() != city.getName()){
        list.currToNext();
    }
    list.getCurrVal().addCity(city);
}

void AdjacencyList::cityList() {
    // Check list for Origin name
    // if not add origin name

    // check if destination exists in origin list
    // add destination to the origin
    // check to see if destination is an origin as well
    // if not add to origin list
    // add origin name to the destination name which is now apart of the origin list
}
