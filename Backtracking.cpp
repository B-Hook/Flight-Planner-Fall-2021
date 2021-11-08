//
// Created by Braiden Hook on 11/7/21.
//

#include "Backtracking.h"

Backtracking::Backtracking(Request currentRequest, AdjacencyList& myList) {
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

    LinkedList<string> visitedCities; // Makes sure there are no duplicate
    visitedCities.append(currentRequest.getDeparting());

    Itinerary bestFlights; // stores the top 3 flights
    // This loop will backtrack through the adjacency list
    // and once the path is completed it will add it to the top 3.
    // If it is not good enough to be in the top 3 it will not be added.
    // If it is good enough it will be added and if the itinerary exceeds 3 it will remove the lowest
    while (!listStack.isEmpty()) {
        // Making sure there is one value in the path so I do not check/pop the path with nothing in it
        if (!currentPath.isEmpty()) {
            // If null that means there are no more possible destinations to get to from the list's origin city
            // Thus will pop it off the stack
            // The city on the current path is also removed as it represents the origin city
            // of the list that was just removed from the stack.
            if (listStack.peek().isCurrNull()) {
                listStack.pop();
                currentPath.pop();
                visitedCities.remove();
            }
            // Checking to see if the top value is the destination
            else if (listStack.peek().getCurrVal().getName() == currentRequest.getDestination()) {
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
                // Calculating the total cost/time of the flight path
                // This will then be compared to the top 3 and, if eligible, will enter the top 3
                Flight newFlight(flightPathList);
                newFlight.calculateCostTime();

                bestFlights.top3(newFlight, currentRequest.getSort());
                currentPath.pop(); // pop the last city on the stack path
                visitedCities.remove(); // remove it from the visitedCities
            }
            // If not null nor the destination
            else {
                bool cityExists = false;
                string currentCity = listStack.peek().getCurrVal().getName();
                visitedCities.currToFront();
                // Checking to see if the city has already been visited
                while (!visitedCities.isCurrNull()) {
                    if (currentCity == visitedCities.getCurrVal()) {
                        cityExists = true;
                        break;
                    }
                    visitedCities.currToNext();
                }
                if (!cityExists) {
                    // Pushes the city to the current path
                    currentPath.push(listStack.peek().getCurrVal());
                    visitedCities.append(currentCity);

                    listStack.peek().currToNext(); // Moves pointer forward so before pushing new list onto the stack
                    myList.getList().currToFront();
                    // Finding a list that matches the city that it being pushed onto the currentPath
                    while (!myList.getList().isCurrNull()) {
                        if (myList.getList().getCurrVal().getName() == currentCity) {
                            listStack.push(myList.getList().getCurrVal().getCityList());
                            listStack.peek().currToFront();
                            break;
                        }
                        myList.getList().currToNext();
                    }
                }
                else
                    listStack.peek().currToNext();
            }
        }
        // If listStackPeak is empty and currentPath is empty that means that there are no more options
        else if (listStack.peek().isCurrNull()) {
            listStack.pop();
            break;
        }
        // Enters when there is nothing on the currentPath, meaning this will be the first visit
        else {
            string currentCity = listStack.peek().getCurrVal().getName();
            currentPath.push(listStack.peek().getCurrVal());
            visitedCities.append(currentCity);
            // Checking to make sure the currentCity isn't the destination
            // This is so the listStack of the destination city won't be pushed onto the stack
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
    setItinerary(bestFlights); // Placing the best flights into the itinerary
}

void Backtracking::setItinerary(Itinerary &requestedItinerary) {
    this->requestedItinerary = requestedItinerary;
}

Itinerary Backtracking::getItinerary() {
    return this->requestedItinerary;
}
