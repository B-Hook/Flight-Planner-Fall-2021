//
// Created by Braiden Hook on 11/7/21.
//

#include "Itinerary.h"

void Itinerary::top3(Flight newFlight, string sortingType) {

    if (top3Flights.checkEmpty()) {
        top3Flights.append(newFlight);
        count++;
    }
    else{
        bool inTop3 = false;
        if(sortingType == "C") {
            top3Flights.currToFront();
            while (!top3Flights.isCurrNull()) {
                if (newFlight.getTotalCost() < top3Flights.getCurrVal().getTotalCost() ||
                    (newFlight.getTotalCost() == top3Flights.getCurrVal().getTotalCost() &&
                     newFlight.getTotalTime() < top3Flights.getCurrVal().getTotalTime())) {
                    top3Flights.insert(newFlight);
                    count++;
                    inTop3 = true;
                    break;
                }
                top3Flights.currToNext();
            }
        }
        if(sortingType == "T") {
            top3Flights.currToFront();
            while (!top3Flights.isCurrNull()) {
                if (newFlight.getTotalTime() < top3Flights.getCurrVal().getTotalTime() ||
                    (newFlight.getTotalTime() == top3Flights.getCurrVal().getTotalTime() &&
                     newFlight.getTotalCost() < top3Flights.getCurrVal().getTotalCost())) {
                    top3Flights.insert(newFlight);
                    count++;
                    inTop3 = true;
                    break;
                }
                top3Flights.currToNext();
            }
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
}

LinkedList<Flight> &Itinerary::getTop3() {
    return top3Flights;
}
