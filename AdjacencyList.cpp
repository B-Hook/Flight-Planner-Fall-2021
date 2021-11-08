//
// Created by Braiden Hook on 10/27/21.
//

#include "AdjacencyList.h"

void AdjacencyList::addToList(OriginCity oCity, DestinationCity dCity) {
    bool doesExist = false;
    list.currToFront();
    // Checking to see if the origin city already exists
    while (!list.isCurrNull()){
        // If it does it will add the destination city to the list of the origin city
        if (list.getCurrVal().getName() == oCity.getName()){
            list.getCurrVal().addCity(dCity);
            doesExist = true;
            break;
        }
        list.currToNext();
    }
    // If the origin city does not already exist it will add the new origin to the origin city list
    // and the destination to that list of the new origin city
    if (!doesExist){
        list.append(oCity);
        list.getTailVal().addCity(dCity);
    }

}

void AdjacencyList::cityList(char* data) {

    ifstream flights(data); // flight data
    string num; // for the amount of rows
    getline(flights, num, '\n');
    stringstream lineSS(num);
    int numOfFlights;
    lineSS >> numOfFlights;
    // Looping through all of the flights and appending them to the adjacency list
    for (int i = 0; i < numOfFlights; i++){
        string line, origin, destination, airline, space;
        int cost, minutes;

        getline(flights, line, '\n'); // Reading in one line of the file
        stringstream stream (line);
        getline(stream, origin, ' ');
        getline(stream, destination, ' ');
        stream >> cost >> minutes;
        //stream >> minutes;
        getline (stream, space, ' ');
        getline(stream, airline, '\n');
        // adding the origin city and its destination to the list
        OriginCity oCity;
        oCity.setName(origin);
        DestinationCity dCity (destination, cost, minutes, airline, origin);
        addToList(oCity, dCity);
        // Making it so it adds the flight from the destination to the origin to the list as well
        OriginCity reverseOrigin;
        reverseOrigin.setName(destination);
        DestinationCity reverseDestination (origin, cost, minutes, airline, destination);
        addToList(reverseOrigin, reverseDestination);
    }

    /*list.currToFront();
    while(!list.isCurrNull()){
        cout << list.getCurrVal().getName() << " : ";
        list.getCurrVal().getCityList().currToFront();
        while(!list.getCurrVal().getCityList().isCurrNull()){
            cout << list.getCurrVal().getCityList().getCurrVal().getName() << " (" <<
                list.getCurrVal().getCityList().getCurrVal().getCarrier() << ") -> ";
            list.getCurrVal().getCityList().currToNext();
        }
        cout << endl;
        list.currToNext();
    }*/

}

LinkedList<OriginCity> &AdjacencyList::getList() {
    return list;
}
