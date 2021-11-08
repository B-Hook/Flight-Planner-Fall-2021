//
// Created by Braiden Hook on 11/7/21.
//

#include "Itinerary.h"

void Itinerary::top3(Flight newFlight, string sortingType) {
    // The new flight is the first it will become the #1 flight
    if (top3Flights.checkEmpty()) {
        top3Flights.append(newFlight);
        count++;
    }
    // If not then it will check to see if it can be in the top 3.
    // If it is in the top 3 it will be placed before the flight where they found themselves better.
    // An example would be if flight 1 has a cost of $100 and flight 2 at #2 had a cost of $120,
    // flight 1 would become #2 and flight 2 would be #3.
    // Also checks what to sort by and what happens in case of a tie
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
        // if there are not enough in the top 3 then it will be added unless it already has
        if (count < 3 && !inTop3){
            top3Flights.append(newFlight);
            count ++;
        }
        // if there are too many in the top 3, meaning when a flight was added previous else statement
        // then it will discard the one at #4
        else if (count > 3 && inTop3){
            top3Flights.remove();
            count --;
        }
    }
}

LinkedList<Flight> &Itinerary::getTop3() {
    return top3Flights;
}
