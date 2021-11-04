//
// Created by Braiden Hook on 10/27/21.
//

#include "OriginCity.h"

OriginCity::OriginCity() {

}

OriginCity::OriginCity(string cityName) {

}
void OriginCity::addCity(DestinationCity city) {
    cityList.append(city);
}
string OriginCity::getName() {
    return name;
}

