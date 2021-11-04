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

void AdjacencyList::addCityDestination(OriginCity oCity, DestinationCity dCity) {
    list.currToFront();
    // Iterating through the origin cities until there is a match
    while (list.getCurrVal().getName() != oCity.getName()){
        list.currToNext();
    }
    // TODO Need to check to make sure the destination is not already there.
    //  If it is maybe add anyway as it is probably a different flight
    list.getCurrVal().addCity(dCity); // add Destination city to the end of the list
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
        OriginCity reverseOrigin;
        reverseOrigin.setName(destination);
        DestinationCity reverseDestination (origin, cost, minutes, airline);
        //DestinationCity dCity (destination, cost, minutes, airline);
        // Initially I didn't want to add a destination city to the list in origin city,
        // but attempted to do so while debugging
        //oCity.addCity(dCity);
        // checking to see if list is empty,
        // if it is it will go ahead and append the origin city object onto the list
        /*if (list.checkEmpty()){
            // Adds origin to origin list, adds destination to the origin
            list.append(oCity);
            list.currToFront();
            ////DestinationCity dCity (destination, cost, minutes, airline);
            list.getCurrVal().addCity(dCity);
            // adds vice versa
            ////OriginCity reverseOrigin;
            ////reverseOrigin.setName(destination);
            list.append(reverseOrigin);
            list.currToNext(); // Pointing to the second origin which is a destination of the first origin
            ////DestinationCity reverseDestination (origin, cost, minutes, airline);
            list.getCurrVal().addCity(reverseDestination);
        }*/
        //else {
            bool doesExist = false;
            list.currToFront();
            while (!list.isCurrNull()){
                if (list.getCurrVal().getName() == oCity.getName()){
                    ////DestinationCity dCity (destination, cost, minutes, airline);
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

            // Doing so in reverse
            doesExist = false;
            while (!list.isCurrNull()){
                if (list.getCurrVal().getName() == reverseOrigin.getName()){
                    list.getCurrVal().addCity(reverseDestination);
                    doesExist = true;
                    break;
                }
                list.currToNext();
            }
            if (!doesExist){
                list.append(reverseOrigin);
                list.getTailVal().addCity(reverseDestination);
            }

            // iterate through list, check to see if origin city exists
            // if it does add destination to origin city
            // if it does not add new origin city and destination
            //TODO: Do not forget to add destination to origin city list
            // and put the original origin city as a destination
        //}

        //while ()
            //if (list.getCurrVal().getName() != origin)




    }

    int i = 2;
    // Check list for Origin name
    // if not add origin name

    // check if destination exists in origin list
    // add destination to the origin
    // check to see if destination is an origin as well
    // if not add to origin list
    // add origin name to the destination name which is now apart of the origin list
}
