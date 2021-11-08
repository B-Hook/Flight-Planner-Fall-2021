//
// Created by Braiden Hook on 11/8/21.
//

#ifndef INC_21F_FLIGHT_PLANNER_REQUEST_H
#define INC_21F_FLIGHT_PLANNER_REQUEST_H

#include <string>
using namespace std;
// Contains the request details read in from the req-flights file
class Request {
private:
    string departing;
    string destination;
    string sort;
public:
    Request();
    Request(string, string, string);
    string getDeparting();
    string getDestination();
    string getSort();

};


#endif //INC_21F_FLIGHT_PLANNER_REQUEST_H
