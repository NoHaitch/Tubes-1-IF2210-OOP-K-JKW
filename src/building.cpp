#include "header/building.hpp"

Building::Building(){
    buildingName = "";
    price = 0;
}

Building::Building(string buildingName, int price){
    this->buildingName = buildingName;
    this->price = price;
}

Building::~Building(){}

string Building::getBuildingName(){
    return buildingName;
}

int Building::getBuildingPrice(){
    return price;
}

