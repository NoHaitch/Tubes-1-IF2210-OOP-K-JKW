#include "header/animal.hpp"

/* Configuration Variables */
map<string, int> Animal::configID;           // Animal Configuration Key: name, Value: id. Id start from 0
vector<string> Animal::configCode;           // Animal Configuration Codes
vector<string> Animal::configName;           // Animal Configuration Names
vector<string> Animal::configFoodType;       // Animal Configuration Food Types
vector<int> Animal::configWeightToHarvest;   // Animal Configuration Weights To Harvest
vector<int> Animal::configPrice;             // Animal Configuration Prices

/* Global Variables for Default Values */
string Animal::DefaultAnimalFoodType = "ANY";
string Animal::DefaultAnimalFoodTypeHerbivore = "HERBIVORE";
string Animal::DefaultAnimalFoodTypeCarnivore = "CARNIVORE";
string Animal::DefaultAnimalFoodTypeOmnivore = "OMNIVORE";
string Animal::DefaultAnimalNameCow = "COW";
string Animal::DefaultAnimalNameSheep = "SHEEP";
string Animal::DefaultAnimalNameHorse = "HORSE";
string Animal::DefaultAnimalNameRabbit = "RABBIT";
string Animal::DefaultAnimalNameSnake = "SNAKE";
string Animal::DefaultAnimalNameChicken = "CHICKEN";
string Animal::DefaultAnimalNameDuck = "DUCK";
int Animal::DefaultAnimalStartingWeight = 0;

/* CLASS Animal */

Animal::Animal(): weightToHarvest(0), price(0){}

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

void Animal::AddAnimalConfig(int _id, string _code, string _name, string _foodtype, int _weightToHarvest, int _price){
    configID[_name] = _id - 1; // _id starts from 1, configID[] starts form 0
    configCode.push_back(_code);
    configName.push_back(_name);
    configFoodType.push_back(_foodtype);
    configWeightToHarvest.push_back(_weightToHarvest);
    configPrice.push_back(_price);
}

void Animal::feedFood(Product& food){
    if(isEdible(food)){
        currWeight += food.getAddedWeight();
    }
    // TODO: Delete Food
}

void Animal::harvest(){
    // TODO: Implement
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
        cout << setw(5) << i << setw(10) << configCode[i] << setw(20) << configName[i] 
            << setw(15) << configFoodType[i] << setw(25) << configWeightToHarvest[i] 
            << setw(10) << configPrice[i] << endl;
    }
    cout << "--------------------------------------------------------------------------------------" << endl;
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
Cow::Cow() : 
    Herbivore(configID[DefaultAnimalNameCow], configCode[configID[DefaultAnimalNameCow]], 
        DefaultAnimalNameCow ,configWeightToHarvest[configID[DefaultAnimalNameCow]],
        configPrice[configID[DefaultAnimalNameCow]]){}

Cow::Cow(int _currWeight)
   : Herbivore(configID[DefaultAnimalNameCow], configCode[configID[DefaultAnimalNameCow]], 
        DefaultAnimalNameCow ,configWeightToHarvest[configID[DefaultAnimalNameCow]],
        configPrice[configID[DefaultAnimalNameCow]], _currWeight){}

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

Sheep::Sheep() : 
    Herbivore(configID[DefaultAnimalNameSheep], configCode[configID[DefaultAnimalNameSheep]], 
        DefaultAnimalNameSheep ,configWeightToHarvest[configID[DefaultAnimalNameSheep]],
        configPrice[configID[DefaultAnimalNameSheep]]){}

Sheep::Sheep(int _currWeight)
   : Herbivore(configID[DefaultAnimalNameSheep], configCode[configID[DefaultAnimalNameSheep]], 
        DefaultAnimalNameSheep ,configWeightToHarvest[configID[DefaultAnimalNameSheep]],
        configPrice[configID[DefaultAnimalNameSheep]], _currWeight){}

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

Horse::Horse() : 
    Herbivore(configID[DefaultAnimalNameHorse], configCode[configID[DefaultAnimalNameHorse]], 
        DefaultAnimalNameHorse ,configWeightToHarvest[configID[DefaultAnimalNameHorse]],
        configPrice[configID[DefaultAnimalNameHorse]]){}

Horse::Horse(int _currWeight)
   : Herbivore(configID[DefaultAnimalNameHorse], configCode[configID[DefaultAnimalNameHorse]], 
        DefaultAnimalNameHorse ,configWeightToHarvest[configID[DefaultAnimalNameHorse]],
        configPrice[configID[DefaultAnimalNameHorse]], _currWeight){}

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

Rabbit::Rabbit() : 
    Herbivore(configID[DefaultAnimalNameRabbit], configCode[configID[DefaultAnimalNameRabbit]], 
        DefaultAnimalNameRabbit ,configWeightToHarvest[configID[DefaultAnimalNameRabbit]],
        configPrice[configID[DefaultAnimalNameRabbit]]){}

Rabbit::Rabbit(int _currWeight)
   : Herbivore(configID[DefaultAnimalNameRabbit], configCode[configID[DefaultAnimalNameRabbit]], 
        DefaultAnimalNameRabbit ,configWeightToHarvest[configID[DefaultAnimalNameRabbit]],
        configPrice[configID[DefaultAnimalNameRabbit]], _currWeight){}

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

Snake::Snake() : 
    Carnivore(configID[DefaultAnimalNameSnake], configCode[configID[DefaultAnimalNameSnake]], 
        DefaultAnimalNameSnake ,configWeightToHarvest[configID[DefaultAnimalNameSnake]],
        configPrice[configID[DefaultAnimalNameSnake]]){}

Snake::Snake(int _currWeight)
   : Carnivore(configID[DefaultAnimalNameSnake], configCode[configID[DefaultAnimalNameSnake]], 
        DefaultAnimalNameSnake ,configWeightToHarvest[configID[DefaultAnimalNameSnake]],
        configPrice[configID[DefaultAnimalNameSnake]], _currWeight){}

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

Chicken::Chicken() : 
    Omnivore(configID[DefaultAnimalNameChicken], configCode[configID[DefaultAnimalNameChicken]], 
        DefaultAnimalNameChicken ,configWeightToHarvest[configID[DefaultAnimalNameChicken]],
        configPrice[configID[DefaultAnimalNameChicken]]){}

Chicken::Chicken(int _currWeight) :
    Omnivore(configID[DefaultAnimalNameChicken], configCode[configID[DefaultAnimalNameChicken]], 
        DefaultAnimalNameChicken ,configWeightToHarvest[configID[DefaultAnimalNameChicken]],
        configPrice[configID[DefaultAnimalNameChicken]], _currWeight){}

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

Duck::Duck() : 
    Omnivore(configID[DefaultAnimalNameDuck], configCode[configID[DefaultAnimalNameDuck]], 
        DefaultAnimalNameDuck ,configWeightToHarvest[configID[DefaultAnimalNameDuck]],
        configPrice[configID[DefaultAnimalNameDuck]]){}

Duck::Duck(int _currWeight) :
    Omnivore(configID[DefaultAnimalNameDuck], configCode[configID[DefaultAnimalNameDuck]], 
        DefaultAnimalNameDuck ,configWeightToHarvest[configID[DefaultAnimalNameDuck]],
        configPrice[configID[DefaultAnimalNameDuck]], _currWeight){}

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