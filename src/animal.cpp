// File: animal.cpp
#include "header/animal.hpp"

Animal::Animal(int _id, string _code, string _name, int _weightToHarvest, int _price, int _currWeight)
    : weightToHarvest(_weightToHarvest),
      price(_price)
{
    id = _id;
    code = _code;
    name = _name;
    currWeight = _currWeight;
}

Animal::~Animal(){}

int Animal::getId() const{ return id;}
string Animal::getCode() const{ return code;}
string Animal::getName() const{ return name;}
int Animal::getPrice() const{ return price;}
int Animal::getWeightToHarvest() const{ return price;}
int Animal::getCurrWeight() const{ return currWeight;}

void Animal::setCurrWeight(int _weight){ currWeight = _weight;}

ostream& operator<<(ostream& stream, const Animal& animal){
    stream << animal.id << " ";
    stream << animal.code << " ";
    stream << animal.name << " ";
    stream << animal.currWeight << " ";
    stream << animal.weightToHarvest << " ";
    stream << animal.price << " ";
    stream << endl;
    return stream;
}

void Animal::printInfo(){
    cout << "Animal :" << endl;
    cout << "  > id: " << this->id << endl;
    cout << "  > code: " << this->code << endl;
    cout << "  > name: " << this->name << endl;
    cout << "  > current weight: " << this->currWeight << endl;
    cout << "  > weight to harvest: " << this->weightToHarvest << endl;
    cout << "  > price: " << this->price << endl;
}
