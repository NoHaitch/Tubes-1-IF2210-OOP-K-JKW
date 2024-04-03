#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>
using namespace std;

class Building {
private :
    string buildingName;
    int price;
public :
    Building();
    Building(string buildingName, int price);
    ~Building();
    string getBuildingName();
    int getBuildingPrice();
};


#endif