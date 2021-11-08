//
// Created by Braiden Hook on 11/5/21.
//

#include "Control.h"


Control::Control(char *flights, char *requestedFlights, char *outputFile) {
    readInRequests(requestedFlights);
    // Making adjacency list
    AdjacencyList myList;
    myList.cityList(flights);
    allRequests.currToFront();
    for (int i = 0; i < numOfRequests; i++){
        Backtracking requestedItinerary(allRequests.getCurrVal(), myList);
        completeItinerary.append(requestedItinerary.getItinerary());
        allRequests.currToNext();
    }
    writeToFile(outputFile);
}

void Control::readInRequests(char * requestsFile) {
    ifstream requests(requestsFile);
    string buffer;
    getline(requests, buffer, '\n');
    stringstream requestStream(buffer);
    requestStream >> numOfRequests;

    int count = 0;
    // Backtracking loop which will backtrack myList based on the amount of requests
    while (count < numOfRequests) {
        string departing, destination, sort;
        // Reading in one request
        getline(requests, departing, ' ');
        getline(requests, destination, ' ');
        getline(requests, sort, '\n');
        Request newRequest(departing, destination, sort);
        allRequests.append(newRequest);
        count++;
    }
}

void Control::writeToFile(char *outputFile) {

    ofstream output (outputFile);
    allRequests.currToFront();
    completeItinerary.currToFront();
    for (int i = 1; i <= numOfRequests; i++){
        string sort;
        if (allRequests.getCurrVal().getSort() == "T")
            sort = "Time";
        else
            sort = "Cost";
        output << "Flight " << i << ": " << allRequests.getCurrVal().getDeparting() << ", "
        << allRequests.getCurrVal().getDestination() << " (" << sort << ")" << endl;

        completeItinerary.getCurrVal().getTop3().currToFront();
        int itineraryNum = 1;
        while (!completeItinerary.getCurrVal().getTop3().isCurrNull()){
            output << "  Itinerary " << itineraryNum << ":" << endl;
            completeItinerary.getCurrVal().getTop3().getCurrVal().getPath().currToBack();
            while (!completeItinerary.getCurrVal().getTop3().getCurrVal().getPath().isCurrNull()){
                output << "    " <<
                completeItinerary.getCurrVal().getTop3().getCurrVal().getPath().getCurrVal().getOrigin() <<
                " -> " << completeItinerary.getCurrVal().getTop3().getCurrVal().getPath().getCurrVal().getName() <<
                " (" << completeItinerary.getCurrVal().getTop3().getCurrVal().getPath().getCurrVal().getCarrier() <<
                ")" << endl;
                completeItinerary.getCurrVal().getTop3().getCurrVal().getPath().currToPrev();
            }
            output << "    Totals for Itinerary " << itineraryNum << ":  Time: " <<
            completeItinerary.getCurrVal().getTop3().getCurrVal().getTotalTime() << " Cost: " <<
            completeItinerary.getCurrVal().getTop3().getCurrVal().getTotalCost() << ".00" << endl;
            completeItinerary.getCurrVal().getTop3().currToNext();
            itineraryNum++;
        }
        output << endl;
        allRequests.currToNext();
        completeItinerary.currToNext();
    }
    output.close();
}


/*void Control::backtracking(char* flights, char* requestsFile) {

    ifstream requests(requestsFile);

    // Reading in first line indicating amount of requests
    string buffer;
    int numOfRequests;
    getline(requests, buffer, '\n');
    stringstream requestStream (buffer);
    requestStream >> numOfRequests;

    // Making adjacency list
    AdjacencyList myList;
    myList.cityList(flights);

    //LinkedList<Flight> itinerary [numOfRequests]; // saves each itinerary

    Itinerary requestedInfo [numOfRequests];

    int count = 0;
    // Backtracking loop which will backtrack myList based on the amount of requests
    while (count < numOfRequests) {

        string departing, destination, sort;
        // Reading in one request
        getline(requests, departing, ' ');
        getline(requests, destination, ' ');
        getline(requests,  sort, '\n');

        // Stack that can store the linked list of each origin city
        DSStack<LinkedList<DestinationCity>> listStack;

        myList.getList().currToFront();
        // Pushing the list of the requested origin (departing) city onto the stack
        while (!myList.getList().isCurrNull()) {
            // if match is found
            if (myList.getList().getCurrVal().getName() == departing) {
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
        LinkedList<Flight> allPossibleFlights;

        LinkedList<string> visitedCities; // Makes sure there are no duplicate
        visitedCities.append(departing);

        Itinerary bestFlights;

        while (!listStack.isEmpty()) {

            // Making sure there is one value in the path so I do not check the path with nothing in it
            if (!currentPath.isEmpty()) {
                // Checking to see if the top value is the destination
                if (listStack.peek().isCurrNull()) {
                    listStack.pop();
                    currentPath.pop();
                    visitedCities.remove();
                } else if (listStack.peek().getCurrVal().getName() == destination) {
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

                    bestFlights.top3(newFlight, sort);

                    allPossibleFlights.append(newFlight); // storing flight
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

                if (currentCity != destination) {
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
        requestedInfo[count] = bestFlights;
        /*LinkedList<Flight> finalOptions = requestedInfo[count].getTop3();
        finalOptions.currToFront();
        while (!finalOptions.isCurrNull()) {
            finalOptions.getCurrVal().getPath().currToFront();
            while (!finalOptions.getCurrVal().getPath().isCurrNull()) {
                std::cout << finalOptions.getCurrVal().getPath().getCurrVal().getName() << " (" <<
                          finalOptions.getCurrVal().getPath().getCurrVal().getCarrier() << ") <- ";
                finalOptions.getCurrVal().getPath().currToNext();
            }
            std::cout << departing << " " << finalOptions.getCurrVal().getTotalTime() << " : "
            << finalOptions.getCurrVal().getTotalCost()<< "\n" << std::endl;
            finalOptions.currToNext();
        }
        count++;
    }

}*/