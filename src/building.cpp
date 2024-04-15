#include "header/building.hpp"

/* Configuration Variables */
vector<string> Building::configCode;
map<string, int> Building::configID;
map<string, string> Building::configName;
map<string, int> Building::configPrice;
map<string, map<string, int> > Building::configMaterial;

Building::Building() :
    id(0),
    code(""),
    name(""),
    price(0),
    materials(){}

Building::Building(string _code) :
    id(configID[_code]),
    code(_code),
    name(configName[_code]),
    price(configPrice[_code]),
    materials(configMaterial[_code]){}

Building::Building(const Building& other) :
    id(other.id),
    code(other.code),
    name(other.name),
    price(other.price){
        materials = other.materials;
    }

Building::Building(int _id, const string& _code, const string& _name, int _price) :
    id(_id),
    code(_code),
    name(_name),
    price(_price){}

Building::~Building(){}

void Building::addBuildingConfig(int _id, string _code, string _name, int _price){
    configCode.push_back(_code);
    configID[_code] = _id-1;
    configName[_code] = _name;
    configPrice[_code] = _price;
}

void Building::addMaterials(string _code, string material, int quantity){
    configMaterial[_code][material] = quantity;
}

int Building::getID() const{
    return id;
}
string Building::getCode() const{
return code;
}
string Building::getName() const{
    return name;
}
int Building::getPrice() const{
    return price;
}

bool operator==(Building a, Building b){
    return a.code == b.code && a.name == b.name;
}

vector<string> Building::getBuildingCodeListConfig(){
    return configCode;
}

map<string, int> Building::getBuildingPriceMapConfig(){
    return configPrice;
}

void Building::displayBuilding(){
    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    for (int i=0; i<configCode.size(); i++){
        cout << "   " << configID[configCode[i]] << ". " << configName[configCode[i]] << " (" << configPrice[configCode[i]] << " gulden, ";
        for (map<string, int>::iterator it = configMaterial[configCode[i]].begin(); it != configMaterial[configCode[i]].end(); ++it){
            cout << it->first << " " << it->second;
            if (it != configMaterial[configCode[i]].end()){
                cout << ", ";
            }
            else {
                cout << ")" << endl;
            }
        }
    }
}

map <string, string> Building::getBuildingNameConfig() {
    return configName;
}

map<string, map<string, int>> Building::getBuildingMaterialConfig(){
    return configMaterial;
}

map<string, int> Building::getBuildingMaterialMapConfig(string nameBuilding) {
    string codeBuilding = convertItemNameToCode(nameBuilding);
    return configMaterial[codeBuilding];
}