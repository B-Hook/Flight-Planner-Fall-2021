//
// Created by Braiden Hook on 11/8/21.
//

#include "Request.h"


Request::Request() {

}

Request::Request(string departing, string destination, string sort) {
    this->departing = departing;
    this->destination = destination;
    this->sort = sort;
}

string Request::getDeparting() {
    return this->departing;
}

string Request::getDestination() {
    return this->destination;
}

string Request::getSort() {
    return this->sort;
}
