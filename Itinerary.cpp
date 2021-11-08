//
// Created by Braiden Hook on 11/7/21.
//

#include "Itinerary.h"

void Itinerary::top3(Flight newFlight, string sortingType, int highestCost, int highestTime) {

    if (top3Flights.checkEmpty()) {
        top3Flights.append(newFlight);
        count++;
    }
    else{
        bool inTop3 = false;
        top3Flights.currToFront();
        while (!top3Flights.isCurrNull()){
            if (newFlight.getTotalCost() < top3Flights.getCurrVal().getTotalCost() ||
            (newFlight.getTotalCost() == top3Flights.getCurrVal().getTotalCost() &&
            newFlight.getTotalTime() < top3Flights.getCurrVal().getTotalTime())){
                top3Flights.insert(newFlight);
                count++;
                inTop3 = true;
                break;
            }
            /*else if (newFlight.getTotalCost() == top3Flights.getCurrVal().getTotalCost() &&
            newFlight.getTotalTime() < top3Flights.getCurrVal().getTotalTime()){
                top3Flights.insert(newFlight);
                count++;
                inTop3 = true;
                break;
            }*/
            top3Flights.currToNext();
        }
        if (count < 4 && !inTop3){
            top3Flights.append(newFlight);
            count ++;
        }
        else if (count > 3 && inTop3){
            top3Flights.remove();
            count --;
        }
    }











    /*int bestVal = 0;
    allFlights.currToFront();
    while (!allFlights.isCurrNull()){

        if ()

    }





    int count = 0;
    Flight bestValueFlight;
    int flightInList [] = {-1, -1, -1};
    while (count < 3){
        allFlights.currToFront();
        top3Flights.append(allFlights.getCurrVal());
        int bestValCost = highestCost + 1;
        int bestValTime = highestTime + 1;
        int location = 0;
        flightInList[count] = 0;
        //allFlights.currToNext();
        while (!allFlights.isCurrNull()){
            if (location != flightInList[0] && location != flightInList[1] && location != flightInList[2]) {
                if (bestValCost > allFlights.getCurrVal().getTotalCost()) {
                    top3Flights.remove();
                    top3Flights.append(allFlights.getCurrVal());
                    bestValCost = allFlights.getCurrVal().getTotalCost();
                    bestValTime = allFlights.getCurrVal().getTotalTime();
                    flightInList[count] = location;
                } else if (bestValCost == allFlights.getCurrVal().getTotalCost()) {
                    if (bestValTime > allFlights.getCurrVal().getTotalTime()) {
                        top3Flights.remove();
                        top3Flights.append(allFlights.getCurrVal());
                        bestValCost = allFlights.getCurrVal().getTotalCost();
                        bestValTime = allFlights.getCurrVal().getTotalTime();
                        flightInList[count] = location;
                    }
                } /*else if (bestValCost == -1){
                    top3Flights.remove();
                    top3Flights.append(allFlights.getCurrVal());
                    bestValCost = allFlights.getCurrVal().getTotalCost();
                    bestValTime = allFlights.getCurrVal().getTotalTime();
                    flightInList[count] = location;
                }
            }
            allFlights.currToNext();
            location ++;
        }
        count ++;
    }
    int i = 2;*/
}

LinkedList<Flight> &Itinerary::getTop3() {
    return top3Flights;
}
