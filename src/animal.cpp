// File: animal.cpp
#include "header/animal.hpp"

/* CLASS Animal */

Animal::Animal(int _id, string _code, string _name, int _weightToHarvest, int _price, string _foodType, int _currWeight)
    : weightToHarvest(_weightToHarvest),
      price(_price),
      foodType(_foodType)
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
    stream << animal.foodType << " ";
    stream << animal.currWeight << " ";
    stream << animal.weightToHarvest << " ";
    stream << animal.price << endl;
    return stream;
}

void Animal::printInfo(){
    cout << "Animal :" << endl;
    cout << "  > id: " << this->id << endl;
    cout << "  > code: " << this->code << endl;
    cout << "  > name: " << this->name << endl;
    cout << "  > food type: " << this->foodType << endl;
    cout << "  > current weight: " << this->currWeight << endl;
    cout << "  > weight to harvest: " << this->weightToHarvest << endl;
    cout << "  > price: " << this->price << endl;
}



/* CLASS Herbivore */

Herbivore::Herbivore(int _id, string _code, string _name, int _weightToHarvest, int _price, int _currWeight) 
    : Animal(_id, _code, _name, _weightToHarvest, _price, "herbivore"){}

Herbivore::~Herbivore(){}

ostream& operator<<(ostream& stream, const Herbivore& herbivore){
    stream << herbivore.id << " ";
    stream << herbivore.code << " ";
    stream << herbivore.name << " ";
    stream << herbivore.foodType << " ";
    stream << herbivore.currWeight << " ";
    stream << herbivore.weightToHarvest << " ";
    stream << herbivore.price << endl;
    return stream;
}

void Herbivore::printInfo(){
    cout << "Herbivore :" << endl;
    cout << "  > id: " << this->id << endl;
    cout << "  > code: " << this->code << endl;
    cout << "  > name: " << this->name << endl;
    cout << "  > food type: " << this->foodType << endl;
    cout << "  > current weight: " << this->currWeight << endl;
    cout << "  > weight to harvest: " << this->weightToHarvest << endl;
    cout << "  > price: " << this->price << endl;
}



/* CLASS Carnivore */

Carnivore::Carnivore(int _id, string _code, string _name, int _weightToHarvest, int _price, int _currWeight) 
    : Animal(_id, _code, _name, _weightToHarvest, _price, "carnivore"){}

Carnivore::~Carnivore(){}

ostream& operator<<(ostream& stream, const Carnivore& carnivore){
    stream << carnivore.id << " ";
    stream << carnivore.code << " ";
    stream << carnivore.name << " ";
    stream << carnivore.foodType << " ";
    stream << carnivore.currWeight << " ";
    stream << carnivore.weightToHarvest << " ";
    stream << carnivore.price << endl;
    return stream;
}

void Carnivore::printInfo(){
    cout << "Carnivore :" << endl;
    cout << "  > id: " << this->id << endl;
    cout << "  > code: " << this->code << endl;
    cout << "  > name: " << this->name << endl;
    cout << "  > food type: " << this->foodType << endl;
    cout << "  > current weight: " << this->currWeight << endl;
    cout << "  > weight to harvest: " << this->weightToHarvest << endl;
    cout << "  > price: " << this->price << endl;
}



/* CLASS Omnivore */

Omnivore::Omnivore(int _id, string _code, string _name, int _weightToHarvest, int _price, int _currWeight) 
    : Animal(_id, _code, _name, _weightToHarvest, _price, "omnivore"){}

Omnivore::~Omnivore(){}

ostream& operator<<(ostream& stream, const Omnivore& omnivore){
    stream << omnivore.id << " ";
    stream << omnivore.code << " ";
    stream << omnivore.name << " ";
    stream << omnivore.foodType << " ";
    stream << omnivore.currWeight << " ";
    stream << omnivore.weightToHarvest << " ";
    stream << omnivore.price << endl;
    return stream;
}

void Omnivore::printInfo(){
    cout << "Omnivore :" << endl;
    cout << "  > id: " << this->id << endl;
    cout << "  > code: " << this->code << endl;
    cout << "  > name: " << this->name << endl;
    cout << "  > food type: " << this->foodType << endl;
    cout << "  > current weight: " << this->currWeight << endl;
    cout << "  > weight to harvest: " << this->weightToHarvest << endl;
    cout << "  > price: " << this->price << endl;
}
