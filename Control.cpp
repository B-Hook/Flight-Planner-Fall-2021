//
// Created by Braiden Hook on 11/5/21.
//

#include "Control.h"


Control::Control(char *flights, char *requestedFlights, char *outputFile) {
    // Adding all the requests to a LinkedList
    readInRequests(requestedFlights);
    // Making adjacency list
    AdjacencyList myList;
    myList.cityList(flights);

    allRequests.currToFront();
    // Backtrack each request and append the final itinerary to the completeItinerary
    for (int i = 0; i < numOfRequests; i++){
        Backtracking requestedItinerary(allRequests.getCurrVal(), myList);
        completeItinerary.append(requestedItinerary.getItinerary());
        allRequests.currToNext();
    }
    writeToFile(outputFile); // And finish with writing to the output file
}

void Control::readInRequests(char * requestsFile) {
    ifstream requests(requestsFile);
    string buffer;
    // Reading in number of requests
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
    // Printing to file the itinerary of each flight
    for (int i = 1; i <= numOfRequests; i++){
        string sort;
        if (allRequests.getCurrVal().getSort() == "T")
            sort = "Time";
        else
            sort = "Cost";

        // Header for each flight
        output << "Flight " << i << ": " << allRequests.getCurrVal().getDeparting() << ", "
        << allRequests.getCurrVal().getDestination() << " (" << sort << ")" << endl;

        bool possibleFlightExists = false;
        completeItinerary.getCurrVal().getTop3().currToFront();
        int itineraryNum = 1;
        // Loop for each itinerary
        while (!completeItinerary.getCurrVal().getTop3().isCurrNull()){
            // Itinerary header
            output << "  Itinerary " << itineraryNum << ":" << endl;

            completeItinerary.getCurrVal().getTop3().getCurrVal().getPath().currToBack();
            // Loop for each flight inside the itinerary
            while (!completeItinerary.getCurrVal().getTop3().getCurrVal().getPath().isCurrNull()){
                // One flight
                output << "    " <<
                completeItinerary.getCurrVal().getTop3().getCurrVal().getPath().getCurrVal().getOrigin() <<
                " -> " << completeItinerary.getCurrVal().getTop3().getCurrVal().getPath().getCurrVal().getName() <<
                " (" << completeItinerary.getCurrVal().getTop3().getCurrVal().getPath().getCurrVal().getCarrier() <<
                ")" << endl;
                completeItinerary.getCurrVal().getTop3().getCurrVal().getPath().currToPrev();
            }
            // Footnote
            output << "    Totals for Itinerary " << itineraryNum << ":  Time: " <<
            completeItinerary.getCurrVal().getTop3().getCurrVal().getTotalTime() << " Cost: " <<
            completeItinerary.getCurrVal().getTop3().getCurrVal().getTotalCost() << ".00" << endl;
            completeItinerary.getCurrVal().getTop3().currToNext();

            itineraryNum++;
            possibleFlightExists = true;
        }
        // If the loop did not happen that means there were no flights available
        if (!possibleFlightExists)
            output << "There are no possible flights for your request." << endl;
        output << endl;
        allRequests.currToNext();
        completeItinerary.currToNext();
    }
    output.close();
}