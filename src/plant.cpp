#include "header/plant.hpp"

// Declaration of static variable
vector <string> Plant::plantCodeList; // Digunakan code 3 char karena parameter unik
map <string, int> Plant::plantIDMap; // <code, map>
map <string, string> Plant::plantTypeMap; // <code, plantType>
map <string, string> Plant::plantNameMap; // <code, plantName>
map <string, int> Plant::plantHarvestDurationMap; // <code, harvestDuration>
map <string, int> Plant::plantPriceMap; // <code, price>
map <string, string> Plant::plantNameToCode; // <plantName, code>

Plant::Plant() : price(0), harvestDuration(0), plantType(""){
    this->id = 0;
    this->code = "";
    this->plantName = "";
    this->currentDuration = 0;
    this->isEdible = false;
}

Plant::Plant(string _code) : 
    id(plantIDMap[_code]), 
    code(_code),
    plantType(plantTypeMap[_code]), 
    plantName(plantNameMap[_code]), 
    harvestDuration(plantHarvestDurationMap[_code]),
    price(plantPriceMap[_code]),
    currentDuration(0){}

Plant::Plant(int _id, string _code, string _plantType, string _plantName, int _harvestDuration,
             int _price) : price(_price), harvestDuration(_harvestDuration), plantType(_plantType) {
    this->id = _id;
    this->code = _code;
    this->plantName = _plantName;
    this->currentDuration = 0;
    this->isEdible = false;
}

Plant::Plant(Plant &other) : price(other.price), harvestDuration(other.harvestDuration), plantType(other.plantType) {
    this->id = other.id;
    this->code = other.code;
    this->plantName = other.plantName;
    this->currentDuration = other.currentDuration;
    this->isEdible = false;
}

Plant::~Plant() {}

void Plant::printInfo() {
    cout << "Tanaman: " << endl;
    cout << "   > ID: " << id << endl;
    cout << "   > code: " << code << endl;
    cout << "   > type: : " << plantType << endl;
    cout << "   > name: " << plantName << endl;
    cout << "   > duration to harvest: " << harvestDuration << endl;
    cout << "   > current duration: " << currentDuration << endl;
    cout << "   > price: " << price << endl;
}

void Plant::addPlantConfig(int _id, std::string _code, std::string _plantType, std::string _plantName,
                           int _harvestDuration, int _price) {
    plantCodeList.push_back(_code);
    plantIDMap[_code] = _id;
    plantTypeMap[_code] = _plantType;
    plantNameMap[_code] = _plantName;
    plantHarvestDurationMap[_code] = _harvestDuration;
    plantPriceMap[_code] = _price;
    plantNameToCode[_plantName] = _code;
}

void Plant::setID(int _id) {this->id = _id;}
void Plant::setCode(string _code) {this->code = _code;}
void Plant::setPlantName(string _plantName) {this->plantName = _plantName;}
void Plant::setCurrentDuration(int _currentDuration) {this->currentDuration = _currentDuration;}

int Plant::getID() {return this->id;}
string Plant::getCode() {return this->code;}
string Plant::getPlantType() {return this->plantType;}
string Plant::getPlantName() {return this->plantName;}
int Plant::getCurrentDuration() {return this->currentDuration;}
int Plant::getHarvestDuration() {return this->harvestDuration;}
int Plant::getPrice() {return this->price;}
bool Plant::getEdible() {return this->isEdible;}

bool Plant::isReadyToHarvest() {
    return this->currentDuration >= this->harvestDuration;
}

bool Plant::empty(){
    return this->code==""; 
}

vector <string> Plant::getPlantCodeListConfig() {
    return Plant::plantCodeList;
}

map<string, int> Plant::getPlantIDMapConfig() {
    return plantIDMap;
}

map<string, string> Plant::getPlantTypeMapConfig() {
    return plantTypeMap;
}

map<string, string> Plant::getPlantNameMapConfig() {
    return plantNameMap;
}

map<string, int> Plant::getPlantHarvestDurationMapConfig() {
    return plantHarvestDurationMap;
}

map<string, int> Plant::getPlantPriceMapConfig() {
    return plantPriceMap;
}

map<string, string> Plant::getPlantNameToCodeConfig(){
    return plantNameToCode;
}

void Plant::printParsedConfig() {
    for (int i = 0; i < Plant::plantCodeList.size(); i++) {
        cout << Plant::plantCodeList[i] << " ";
    }
}

void Plant::incrementCurrentDuration() {
    this->currentDuration++;
}

MaterialPlant::MaterialPlant(int _id, string _code, std::string _plantName, int _harvestDuration, int _price) :
    Plant(_id, _code, "MATERIAL_PLANT", _plantName, _harvestDuration, _price) {
    this->isEdible = false;
}

MaterialPlant::~MaterialPlant() {}

FoodPlant::FoodPlant(int _id, string _code, std::string _plantName, int _harvestDuration, int _price) :
    Plant(_id, _code, "FRUIT_PLANT", _plantName, _harvestDuration, _price){
    this->isEdible = true;
}

FoodPlant::~FoodPlant() {}



