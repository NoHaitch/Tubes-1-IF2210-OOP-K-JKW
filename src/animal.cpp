#include "header/animal.hpp"

/* Default Variables */
const int Animal::DefaultAnimalStartingWeight = 0;
const string Animal::DefaultAnimalFoodTypeHerbivore = "HERBIVORE";
const string Animal::DefaultAnimalFoodTypeCarnivore = "CARNIVORE";
const string Animal::DefaultAnimalFoodTypeOmnivore = "OMNIVORE";

/* Configuration Variables */
vector<string> Animal::configCode;               // Animal Configuration Codes
map<string, int> Animal::configID;               // Animal Configuration Key: Code, Value: Animal Id, Id starts from 1.
map<string, string> Animal::configNameToCode;    // Convert Animal Name to Animal Code
map<string, string> Animal::configName;          // Animal Configuration Names
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

Animal::Animal(string _code)     
    : id(configID[_code]),
    code(_code),
    name(configName[_code]),
    weightToHarvest(configWeightToHarvest[_code]), 
    price(configPrice[_code]),
    foodType(configFoodType[_code]),
    currWeight(0){}

Animal::Animal(string _code, string _foodType, int _currWeight)     
    : id(configID[_code]),
    code(_code),
    name(configName[_code]),
    weightToHarvest(configWeightToHarvest[_code]), 
    price(configPrice[_code]),
    foodType(_foodType)
{
    currWeight = _currWeight;
}

Animal::Animal(const Animal& other)
    : id(other.id),
    code(other.code),
    name(other.name),
    weightToHarvest(other.weightToHarvest), 
    price(other.price),
    foodType(other.foodType)
{
    currWeight = other.currWeight;
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

bool Animal::canEat(string productCode){
    string productType = Product::getProductTypeMapConfig()[productCode];
    if(productType == "PRODUCT_MATERIAL_PLANT"){
        return false;
    } else if(foodType == DefaultAnimalFoodTypeOmnivore){
        return true;
    } else if(foodType == DefaultAnimalFoodTypeCarnivore && productType == "PRODUCT_ANIMAL"){
        return true;
    } else if(foodType == DefaultAnimalFoodTypeHerbivore && productType == "PRODUCT_FRUIT_PLANT"){
        return true;
    }
    return false;   
}

bool Animal::empty(){
    return this->code == "";
}

void Animal::AddAnimalConfig(int _id, string _code, string _name, string _foodtype, int _weightToHarvest, int _price){
    configCode.push_back(_code);
    configID[_code] = _id - 1; // _id starts from 1, configID[] starts form 0
    configName[_code] = _name;
    configFoodType[_code] = _foodtype;
    configWeightToHarvest[_code] = _weightToHarvest;
    configPrice[_code] = _price;
    configNameToCode[_name] = _code;
}

vector<string> Animal::getAnimalCodeConfig(){
    return configCode;
}

map<string, int> Animal::getAnimalIDConfig(){
    return configID;
}

map<string, string> Animal::getAnimalNameConfig(){
    return configName;
}

map<string, string> Animal::getAnimalNameToCodeConfig(){
    return configNameToCode;
}

map<string, string> Animal::getAnimalFoodTypeConfig(){
    return configFoodType;
}

map<string, int> Animal::getAnimalWeightToHarvestConfig(){
    return configWeightToHarvest;
}

map<string, int> Animal::getAnimalPriceConfig(){
    return configPrice;
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
        string animalCode = configCode[i];
        cout << setw(5) << i << setw(10) << animalCode << setw(20) << configName[animalCode] 
            << setw(15) << configFoodType[animalCode] << setw(25) << configWeightToHarvest[animalCode] 
            << setw(10) << configPrice[animalCode] << endl;
    }
    cout << "--------------------------------------------------------------------------------------" << endl;
}

string Animal::convertNameToCode(string name){
    return configNameToCode[name];
}

bool operator==(const Animal& A, const Animal& B){
    return A.code == B.code && A.currWeight == B.currWeight;
}


/* CLASS Herbivore */

Herbivore::Herbivore(string code, int _currWeight) 
    : Animal(code, DefaultAnimalFoodTypeHerbivore, currWeight){}

Herbivore::Herbivore(const Herbivore& other) 
    : Animal(other.code, other.foodType, other.currWeight){}

Herbivore::~Herbivore(){}

bool Herbivore::canEat(string productCode){
    return Product::getProductTypeMapConfig()[productCode] == "PRODUCT_FRUIT_PLANT";
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

Carnivore::Carnivore(string code, int _currWeight) 
    : Animal(code, DefaultAnimalFoodTypeCarnivore, currWeight){}

Carnivore::Carnivore(const Carnivore& other) 
    : Animal(other.code, other.foodType, other.currWeight){}

Carnivore::~Carnivore(){}

bool Carnivore::canEat(string productCode){
    return Product::getProductTypeMapConfig()[productCode] == "PRODUCT_ANIMAL";
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

Omnivore::Omnivore(string code, int _currWeight) 
    : Animal(code, DefaultAnimalFoodTypeOmnivore, currWeight){}

Omnivore::Omnivore(const Omnivore& other) 
    : Animal(other.code, other.foodType, other.currWeight){}

Omnivore::~Omnivore(){}

bool Omnivore::canEat(string productCode){
    return Product::getProductTypeMapConfig()[productCode] == "PRODUCT_ANIMAL" || Product::getProductTypeMapConfig()[productCode] == "PRODUCT_FRUIT_PLANT";
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