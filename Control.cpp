//
// Created by Braiden Hook on 11/5/21.
//

#include "Control.h"

void Control::backtracking(char* flights, char* requestsFile) {

    ifstream requests(requestsFile);

    // Reading in first line indicating amount of requests
    string buffer;
    int numOfRequests;
    getline(requests, buffer, '\n');
    stringstream requestStream (buffer);
    requestStream >> numOfRequests;

    string departing, destination, sort;
    // Reading in the first request
    getline(requests, departing, ' ');
    getline(requests, destination, ' ');
    getline(requests, sort, '\n');


    DSStack<LinkedList<DestinationCity>> listStack;
    LinkedList<DestinationCity> destinationList; // goes in list stack
    myList.cityList(flights); // making adjacency list
    myList.getList().currToFront();
    while (!myList.getList().isCurrNull()){
        if (myList.getList().getCurrVal().getName() == departing){
            destinationList = myList.getList().getCurrVal().getCityList();
            //destinationList.currToFront();
            listStack.push(destinationList); // getting the list of possible routes from the departing city
            listStack.peek().currToFront();
            myList.getList().currToFront();
            break;
        }
    }
    //LinkedList<DestinationCity> destinationList = myList.getList().getCurrVal().getCityList();
    //listStack.push(destinationList);
    DSStack<DestinationCity> currentPath;
    //currentPath.push(listStack.peek().getCurrVal());
    //DSStack<DestinationCity> flightPath = currentPath;

    LinkedList<LinkedList<DestinationCity>> allPossiblePaths;
    LinkedList<string> visitedCities;
    //std::cout << flightPath.peek().getName() << std:: endl;
    while (!listStack.isEmpty()){
        //std::cout << departing << std:: endl;
        //flightPath.push(listStack.peek().getCurrVal());
        // Making sure there is one value in the path so I do not check the path with nothing in it
        if (!currentPath.isEmpty()){
            // Checking to see if the top value is the destination
            if (listStack.peek().isCurrNull()){
                listStack.pop();
                currentPath.pop();
                visitedCities.remove();
            }
            else if (listStack.peek().getCurrVal().getName() == destination){
                // Creating a copy of the stack
                bool cityExists = false;
                while (!visitedCities.isCurrNull()){
                    if (listStack.peek().getCurrVal().getName() == visitedCities.getCurrVal()) {
                        cityExists = true;
                        break;
                    }
                }
                if (!cityExists) {
                    currentPath.push(listStack.peek().getCurrVal());
                    visitedCities.append(currentPath.peek().getName());
                }
                listStack.peek().currToNext();
                DSStack<DestinationCity> flightPathStack = currentPath;
                LinkedList<DestinationCity> flightPathList;
                while (!flightPathStack.isEmpty()){
                    flightPathList.append(flightPathStack.peek());
                    flightPathStack.pop();
                }
                allPossiblePaths.append(flightPathList); // storing flight
                currentPath.pop(); // pop the last city on the stack path
                visitedCities.remove(); // remove it from the visitedCities
            }
            else {
                bool cityExists = false;
                string currentCity = listStack.peek().getCurrVal().getName();
                visitedCities.currToFront();
                while (!visitedCities.isCurrNull()){
                    if ( currentCity == visitedCities.getCurrVal()) {
                        cityExists = true;
                        break;
                    }
                }
                if (!cityExists) {
                    currentPath.push(listStack.peek().getCurrVal());
                    visitedCities.append(currentCity);
                    listStack.peek().currToNext();
                    myList.getList().currToFront();
                    while (!myList.getList().isCurrNull()){
                        if (myList.getList().getCurrVal().getName() == currentCity){
                            listStack.push(myList.getList().getCurrVal().getCityList());
                            listStack.peek().currToFront();
                        }
                    }
                }
                else
                    listStack.peek().currToNext();
            }
        }
        else if (!listStack.peek().isCurrNull()){
            listStack.pop();
            break;
        }
        else{
            string currentCity = listStack.peek().getCurrVal().getName();
            currentPath.push(listStack.peek().getCurrVal());
            visitedCities.append(currentCity);
            /*if (listStack.peek().getCurrVal().getName() == destination){
                DSStack<DestinationCity> flightPathStack = currentPath;
                LinkedList<DestinationCity> flightPathList;
                while (!flightPathStack.isEmpty()){
                    flightPathList.append(flightPathStack.peek());
                    flightPathStack.pop();
                }
                allPossiblePaths.append(flightPathList); // storing flight
                if (listStack.peek().isCurrNull()){
                    listStack.pop();
                    currentPath.pop();
                    visitedCities.remove();
                    break;
                }
                else{
                    currentPath.pop(); // pop the last city on the stack path
                    visitedCities.remove(); // remove it from the visitedCities
                }
            }
            else {*/
            if (myList.getList().getCurrVal().getName() != destination){
                listStack.peek().currToNext();
                myList.getList().currToFront();
                while (!myList.getList().isCurrNull()) {
                    if (myList.getList().getCurrVal().getName() == currentCity &&
                        (myList.getList().getCurrVal().getName() == destination)) {
                        listStack.push(myList.getList().getCurrVal().getCityList());
                        listStack.peek().currToFront();
                    }
                }
            }
            //add to current path stack, most likely this will be the curr dCity on the departing city/oCity
        }

        //// When adding to current path store into linked list to avoid of duplicates
        //if (listStack.peek()

        //break;


    }





}
