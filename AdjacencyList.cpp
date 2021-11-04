//
// Created by Braiden Hook on 10/27/21.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "AdjacencyList.h"

//void AdjacencyList::addOriginCity(OriginCity city) {
  //  list.append(city);
//}

void AdjacencyList::addToList(OriginCity oCity, DestinationCity dCity) {
    bool doesExist = false;
    list.currToFront();
    while (!list.isCurrNull()){
        if (list.getCurrVal().getName() == oCity.getName()){
            list.getCurrVal().addCity(dCity);
            doesExist = true;
            break;
        }
        list.currToNext();
    }
    if (!doesExist){
        list.append(oCity);
        list.getTailVal().addCity(dCity);
    }

}

void AdjacencyList::cityList(char* data) {

    ifstream flights(data);
    string num;
    getline(flights, num, '\n');
    stringstream lineSS(num);
    int numOfFlights;
    lineSS >> numOfFlights;

    for (int i = 0; i < numOfFlights; i++){
        string line, origin, destination, airline, space;
        int cost, minutes;

        getline(flights, line, '\n');
        stringstream stream (line);
        getline(stream, origin, ' ');
        getline(stream, destination, ' ');
        stream >> cost >> minutes;
        //stream >> minutes;
        getline (stream, space, ' ');
        getline(stream, airline, '\n');

        cout << origin << " " << destination << " " << cost << " " << minutes << " " << airline << endl;

        OriginCity oCity;
        oCity.setName(origin);
        DestinationCity dCity (destination, cost, minutes, airline);
        addToList(oCity, dCity);

        OriginCity reverseOrigin;
        reverseOrigin.setName(destination);
        DestinationCity reverseDestination (origin, cost, minutes, airline);
        addToList(reverseOrigin, reverseDestination);
    }
}
