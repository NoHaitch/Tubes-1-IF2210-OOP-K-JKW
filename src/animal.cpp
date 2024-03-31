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
    : Animal(_id, _code, _name, _weightToHarvest, _price, DefaultAnimalFoodTypeHerbivore){}

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
    : Animal(_id, _code, _name, _weightToHarvest, _price, DefaultAnimalFoodTypeCarnivore){}

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
    : Animal(_id, _code, _name, _weightToHarvest, _price, DefaultAnimalFoodTypeOmnivore){}

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


/* CLASS Cow */

Cow::Cow(int _id, string _code, int _weightToHarvest, int _price, int _currWeight)
   : Herbivore(_id, _code, DefaultAnimalNameCow, _weightToHarvest, _price){}

Cow::~Cow(){}

ostream& operator<<(ostream& stream, const Cow& cow){
    stream << cow.id << " ";
    stream << cow.code << " ";
    stream << cow.name << " ";
    stream << cow.foodType << " ";
    stream << cow.currWeight << " ";
    stream << cow.weightToHarvest << " ";
    stream << cow.price << endl;
    return stream;
}

void Cow::printInfo(){
    cout << "Cow :" << endl;
    cout << "  > id: " << this->id << endl;
    cout << "  > code: " << this->code << endl;
    cout << "  > name: " << this->name << endl;
    cout << "  > food type: " << this->foodType << endl;
    cout << "  > current weight: " << this->currWeight << endl;
    cout << "  > weight to harvest: " << this->weightToHarvest << endl;
    cout << "  > price: " << this->price << endl;
}


/* CLASS Sheep */

Sheep::Sheep(int _id, string _code, int _weightToHarvest, int _price, int _currWeight)
   : Herbivore(_id, _code, DefaultAnimalNameSheep, _weightToHarvest, _price){}

Sheep::~Sheep(){}

ostream& operator<<(ostream& stream, const Sheep& sheep){
    stream << sheep.id << " ";
    stream << sheep.code << " ";
    stream << sheep.name << " ";
    stream << sheep.foodType << " ";
    stream << sheep.currWeight << " ";
    stream << sheep.weightToHarvest << " ";
    stream << sheep.price << endl;
    return stream;
}

void Sheep::printInfo(){
    cout << "Sheep :" << endl;
    cout << "  > id: " << this->id << endl;
    cout << "  > code: " << this->code << endl;
    cout << "  > name: " << this->name << endl;
    cout << "  > food type: " << this->foodType << endl;
    cout << "  > current weight: " << this->currWeight << endl;
    cout << "  > weight to harvest: " << this->weightToHarvest << endl;
    cout << "  > price: " << this->price << endl;
}


/* CLASS Horse */

Horse::Horse(int _id, string _code, int _weightToHarvest, int _price, int _currWeight)
   : Herbivore(_id, _code, DefaultAnimalNameHorse, _weightToHarvest, _price){}

Horse::~Horse(){}

ostream& operator<<(ostream& stream, const Horse& horse){
    stream << horse.id << " ";
    stream << horse.code << " ";
    stream << horse.name << " ";
    stream << horse.foodType << " ";
    stream << horse.currWeight << " ";
    stream << horse.weightToHarvest << " ";
    stream << horse.price << endl;
    return stream;
}

void Horse::printInfo(){
    cout << "Horse :" << endl;
    cout << "  > id: " << this->id << endl;
    cout << "  > code: " << this->code << endl;
    cout << "  > name: " << this->name << endl;
    cout << "  > food type: " << this->foodType << endl;
    cout << "  > current weight: " << this->currWeight << endl;
    cout << "  > weight to harvest: " << this->weightToHarvest << endl;
    cout << "  > price: " << this->price << endl;
}


/* CLASS Rabbit */

Rabbit::Rabbit(int _id, string _code, int _weightToHarvest, int _price, int _currWeight)
   : Herbivore(_id, _code, DefaultAnimalNameRabbit, _weightToHarvest, _price){}

Rabbit::~Rabbit(){}

ostream& operator<<(ostream& stream, const Rabbit& rabbit){
    stream << rabbit.id << " ";
    stream << rabbit.code << " ";
    stream << rabbit.name << " ";
    stream << rabbit.foodType << " ";
    stream << rabbit.currWeight << " ";
    stream << rabbit.weightToHarvest << " ";
    stream << rabbit.price << endl;
    return stream;
}

void Rabbit::printInfo(){
    cout << "Rabbit :" << endl;
    cout << "  > id: " << this->id << endl;
    cout << "  > code: " << this->code << endl;
    cout << "  > name: " << this->name << endl;
    cout << "  > food type: " << this->foodType << endl;
    cout << "  > current weight: " << this->currWeight << endl;
    cout << "  > weight to harvest: " << this->weightToHarvest << endl;
    cout << "  > price: " << this->price << endl;
}


/* CLASS Snake */

Snake::Snake(int _id, string _code, int _weightToHarvest, int _price, int _currWeight)
   : Carnivore(_id, _code, DefaultAnimalNameSnake, _weightToHarvest, _price){}

Snake::~Snake(){}

ostream& operator<<(ostream& stream, const Snake& snake){
    stream << snake.id << " ";
    stream << snake.code << " ";
    stream << snake.name << " ";
    stream << snake.foodType << " ";
    stream << snake.currWeight << " ";
    stream << snake.weightToHarvest << " ";
    stream << snake.price << endl;
    return stream;
}

void Snake::printInfo(){
    cout << "Snake :" << endl;
    cout << "  > id: " << this->id << endl;
    cout << "  > code: " << this->code << endl;
    cout << "  > name: " << this->name << endl;
    cout << "  > food type: " << this->foodType << endl;
    cout << "  > current weight: " << this->currWeight << endl;
    cout << "  > weight to harvest: " << this->weightToHarvest << endl;
    cout << "  > price: " << this->price << endl;
}


/* CLASS Chicken */

Chicken::Chicken(int _id, string _code, int _weightToHarvest, int _price, int _currWeight)
   : Omnivore(_id, _code, DefaultAnimalNameChicken, _weightToHarvest, _price){}

Chicken::~Chicken(){}

ostream& operator<<(ostream& stream, const Chicken& chicken){
    stream << chicken.id << " ";
    stream << chicken.code << " ";
    stream << chicken.name << " ";
    stream << chicken.foodType << " ";
    stream << chicken.currWeight << " ";
    stream << chicken.weightToHarvest << " ";
    stream << chicken.price << endl;
    return stream;
}

void Chicken::printInfo(){
    cout << "Chicken :" << endl;
    cout << "  > id: " << this->id << endl;
    cout << "  > code: " << this->code << endl;
    cout << "  > name: " << this->name << endl;
    cout << "  > food type: " << this->foodType << endl;
    cout << "  > current weight: " << this->currWeight << endl;
    cout << "  > weight to harvest: " << this->weightToHarvest << endl;
    cout << "  > price: " << this->price << endl;
}


/* CLASS Duck */

Duck::Duck(int _id, string _code, int _weightToHarvest, int _price, int _currWeight)
   : Omnivore(_id, _code, DefaultAnimalNameDuck, _weightToHarvest, _price){}

Duck::~Duck(){}

ostream& operator<<(ostream& stream, const Duck& duck){
    stream << duck.id << " ";
    stream << duck.code << " ";
    stream << duck.name << " ";
    stream << duck.foodType << " ";
    stream << duck.currWeight << " ";
    stream << duck.weightToHarvest << " ";
    stream << duck.price << endl;
    return stream;
}

void Duck::printInfo(){
    cout << "Duck :" << endl;
    cout << "  > id: " << this->id << endl;
    cout << "  > code: " << this->code << endl;
    cout << "  > name: " << this->name << endl;
    cout << "  > food type: " << this->foodType << endl;
    cout << "  > current weight: " << this->currWeight << endl;
    cout << "  > weight to harvest: " << this->weightToHarvest << endl;
    cout << "  > price: " << this->price << endl;
}