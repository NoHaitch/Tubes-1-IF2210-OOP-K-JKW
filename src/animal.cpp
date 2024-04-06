#include "header/animal.hpp"

/* Default Variables */
const int Animal::DefaultAnimalStartingWeight = 0;
const string Animal::DefaultAnimalFoodTypeHerbivore = "HERBIVORE";
const string Animal::DefaultAnimalFoodTypeCarnivore = "CARNIVORE";
const string Animal::DefaultAnimalFoodTypeOmnivore = "OMNIVORE";

/* Configuration Variables */
vector<string> Animal::configName;               // Animal Configuration Names
map<string, int> Animal::configID;               // Animal Configuration Key: Name, Value: Animal Id, Id starts from 1.
map<string, string> Animal::configCode;          // Animal Configuration Codes
map<string, string> Animal::configFoodType;      // Animal Configuration Food Types
map<string, int> Animal::configWeightToHarvest;  // Animal Configuration Weights To Harvest
map<string, int> Animal::configPrice;            // Animal Configuration Prices

/* CLASS Animal */

Animal::Animal()
    : id(0),
    code(""),
    name(""),
    weightToHarvest(0), 
    price(0),
    foodType(""){}

Animal::Animal(string _name, string _foodType, int _currWeight)     
    : id(configID[_name]),
    code(configCode[_name]),
    name(_name),
    weightToHarvest(configWeightToHarvest[_name]), 
    price(configPrice[_name]),
    foodType(_foodType)
{
    currWeight = _currWeight;
}

Animal::~Animal(){}

int Animal::getId() const{ return id;}
string Animal::getCode() const{ return code;}
string Animal::getName() const{ return name;}
int Animal::getPrice() const{ return price;}
int Animal::getWeightToHarvest() const{ return price;}
string Animal::getFoodType() const{return foodType;}
int Animal::getCurrWeight() const{ return currWeight;}

void Animal::setCurrWeight(int _weight){ 
    currWeight = _weight;
}

void Animal::addWeight(int weight){
    currWeight += weight;
}

bool Animal::isReadyToHarvest(){
    return currWeight >= weightToHarvest;
}

void Animal::AddAnimalConfig(int _id, string _code, string _name, string _foodtype, int _weightToHarvest, int _price){
    configName.push_back(_name);
    configID[_name] = _id - 1; // _id starts from 1, configID[] starts form 0
    configCode[_name] = _code;
    configFoodType[_name] = _foodtype;
    configWeightToHarvest[_name] = _weightToHarvest;
    configPrice[_name] = _price;
}

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

void Animal::printConfig(){
    cout << "ANIMAL CONFIGURATION" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << setw(5) << "ID" << setw(10) << "Code" << setw(20) << "Name" << setw(15) << "Type" << setw(25) << "Weight to Harvest" << setw(10) << "Price" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < configID.size(); i++){
        string animalName = configName[i];
        cout << setw(5) << i << setw(10) << configCode[animalName] << setw(20) << animalName 
            << setw(15) << configFoodType[animalName] << setw(25) << configWeightToHarvest[animalName] 
            << setw(10) << configPrice[animalName] << endl;
    }
    cout << "--------------------------------------------------------------------------------------" << endl;
}

/* CLASS Herbivore */

Herbivore::Herbivore(string name, int _currWeight) 
    : Animal(name, DefaultAnimalFoodTypeHerbivore, currWeight){}

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

Carnivore::Carnivore(string name, int _currWeight) 
    : Animal(name, DefaultAnimalFoodTypeCarnivore, currWeight){}

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

Omnivore::Omnivore(string name, int _currWeight) 
    : Animal(name, DefaultAnimalFoodTypeOmnivore, currWeight){}

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