//
// Created by Braiden Hook on 11/7/21.
//

#include "Backtracking.h"

Backtracking::Backtracking(Request currentRequest, AdjacencyList& myList) {

    // Making adjacency list
    //AdjacencyList myList;
    //myList.cityList(flights);

    //LinkedList<Flight> itinerary [numOfRequests]; // saves each itinerary

    //Itinerary requestedInfo [numOfRequests];

    //int count = 0;
        // Stack that can store the linked list of each origin city
    DSStack<LinkedList<DestinationCity>> listStack;

    myList.getList().currToFront();
    // Pushing the list of the requested origin (departing) city onto the stack
    while (!myList.getList().isCurrNull()) {
        // if match is found
        if (myList.getList().getCurrVal().getName() == currentRequest.getDeparting()) {
            listStack.push(myList.getList().getCurrVal().getCityList());
            listStack.peek().currToFront(); // Setting the pointer to the front of the list on the stack
            myList.getList().currToFront(); // Resetting the pointer
            break;
        }
        myList.getList().currToNext();
    }

    // Stack keeping track of the flight path
    DSStack<DestinationCity> currentPath;

    // Stores the current path once it reaches the destination
    //LinkedList<Flight> allPossibleFlights;

    LinkedList<string> visitedCities; // Makes sure there are no duplicate
    visitedCities.append(currentRequest.getDeparting());

    Itinerary bestFlights;

    while (!listStack.isEmpty()) {

        // Making sure there is one value in the path so I do not check the path with nothing in it
        if (!currentPath.isEmpty()) {
            // Checking to see if the top value is the destination
            if (listStack.peek().isCurrNull()) {
                listStack.pop();
                currentPath.pop();
                visitedCities.remove();
            } else if (listStack.peek().getCurrVal().getName() == currentRequest.getDestination()) {
                // Creating a copy of the stack
                bool cityExists = false;
                visitedCities.currToFront();
                // Checking to see if the destination is already on the current path stack
                // A situation where the destination would be on the stack is if it is the first value on the stack
                while (!visitedCities.isCurrNull()) {
                    if (listStack.peek().getCurrVal().getName() == visitedCities.getCurrVal()) {
                        cityExists = true;
                        break;
                    }
                    visitedCities.currToNext();
                }
                // Pushing the destination onto the stack
                if (!cityExists) {
                    currentPath.push(listStack.peek().getCurrVal());
                    visitedCities.append(currentPath.peek().getName());
                }
                listStack.peek().currToNext();
                DSStack<DestinationCity> flightPathStack = currentPath; // creating a copy of the stack
                LinkedList<DestinationCity> flightPathList;
                // storing the flight path onto a linked list
                while (!flightPathStack.isEmpty()) {
                    flightPathList.append(flightPathStack.peek());
                    flightPathStack.pop();

                }
                Flight newFlight(flightPathList);
                newFlight.calculateCostTime();

                bestFlights.top3(newFlight, currentRequest.getSort());

                //allPossibleFlights.append(newFlight); // storing flight
                currentPath.pop(); // pop the last city on the stack path
                visitedCities.remove(); // remove it from the visitedCities
            } else {
                bool cityExists = false;
                string currentCity = listStack.peek().getCurrVal().getName();
                visitedCities.currToFront();
                while (!visitedCities.isCurrNull()) {
                    if (currentCity == visitedCities.getCurrVal()) {
                        cityExists = true;
                        break;
                    }
                    visitedCities.currToNext();
                }
                if (!cityExists) {
                    currentPath.push(listStack.peek().getCurrVal());
                    visitedCities.append(currentCity);
                    listStack.peek().currToNext();
                    myList.getList().currToFront();
                    while (!myList.getList().isCurrNull()) {
                        if (myList.getList().getCurrVal().getName() == currentCity) {
                            listStack.push(myList.getList().getCurrVal().getCityList());
                            listStack.peek().currToFront();
                            break;
                        }
                        myList.getList().currToNext();
                    }
                } else
                    listStack.peek().currToNext();
            }
        } else if (listStack.peek().isCurrNull()) {
            listStack.pop();
            break;
        } else {
            string currentCity = listStack.peek().getCurrVal().getName();
            currentPath.push(listStack.peek().getCurrVal());
            visitedCities.append(currentCity);

            if (currentCity != currentRequest.getDestination()) {
                listStack.peek().currToNext();
                myList.getList().currToFront();
                while (!myList.getList().isCurrNull()) {
                    if (myList.getList().getCurrVal().getName() == currentCity) {
                        listStack.push(myList.getList().getCurrVal().getCityList());
                        listStack.peek().currToFront();
                        break;
                    }
                    myList.getList().currToNext();
                }
            }
        }
    }
    //requestedInfo[count] = bestFlights;
    setItinerary(bestFlights);
}

void Backtracking::setItinerary(Itinerary &requestedItinerary) {
    this->requestedItinerary = requestedItinerary;
}

Itinerary Backtracking::getItinerary() {
    return this->requestedItinerary;
}
