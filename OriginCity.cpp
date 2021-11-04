//
// Created by Braiden Hook on 10/27/21.
//

#include "OriginCity.h"

void OriginCity::addCity(DestinationCity city) {
    cityList.append(city);
}
void OriginCity::setName(string name) {
    this->name = name;
}
string OriginCity::getName() {
    return name;
}
