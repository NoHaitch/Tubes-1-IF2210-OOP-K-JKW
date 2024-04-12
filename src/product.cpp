#include "header/product.hpp"

vector<string> Product::productCodeList;
map<string, int> Product::productIDMap;
map<string, string> Product::productTypeMap;
map<string, string> Product::productNameMap;
map<string, string> Product::productOriginMap;
map<string, int> Product::productAddedWeightMap;
map<string, int> Product::productPriceMap;
map<string, string> Product::productOriginToCode;


void Product::addProductConfig(int _id, std::string _code, std::string _type, std::string _name, std::string _origin,
                               int _addedWeight, int _price) {
    productCodeList.push_back(_code);
    productIDMap[_code] = _id;
    productTypeMap[_code] = _type;
    productNameMap[_code] = _name;
    productOriginMap[_code] = _origin;
    productAddedWeightMap[_code] = _addedWeight;
    productPriceMap[_code] = _price;
    productOriginToCode[_origin] = _code;
}


Product::Product() : addedWeight(0), price(0){
    id = 0;
    code = "";
    name = "";
    type = "";
    origin = "";
}

Product::Product(string _code) :
    id(productIDMap[_code]),
    code(_code),
    name(productNameMap[_code]),
    type(productTypeMap[_code]),
    origin(productOriginMap[_code]),
    addedWeight(productAddedWeightMap[_code]),
    price(productPriceMap[_code]){}

Product::Product(int _id, string _code, string _type, string _name, string _origin, int _addedWeight, int _price) : addedWeight(_addedWeight), price(_price){
    id = _id;
    code = _code;
    name = _name;
    type = _type;
    origin = _origin;
}

Product convertToProduct(string _origin) {
    string productCode = Product::productOriginToCode[_origin];
    return Product(Product::productIDMap[productCode], productCode, Product::productNameMap[productCode],
    Product::productTypeMap[productCode], _origin, Product::productAddedWeightMap[productCode], Product::productPriceMap[productCode]);
}

int Product::getAddedWeight() const{
    return addedWeight;
}

string getOriginCode(Product& product) {
    return product.origin;
}

bool isEdible(Product& product){
    return product.addedWeight != 0;
}

bool isPlantProduct(Product& product){
    for (int i = 0; i < Plant::getPlantCodeListConfig().size(); i++) {
        if (product.origin == Plant::getPlantCodeListConfig()[i]) {
            return true;
        }
    }
    return false;
}

bool isAnimalProduct(Product& product){
    for (int i = 0; i < Animal::getAnimalCodeConfig().size(); i++) {
        if (product.origin == Animal::getAnimalCodeConfig()[i]) {
            return true;
        }
    }
    return false;
}

vector<string> Product::getProductCodeListConfig(){
    return Product::productCodeList;
}

map<string, int> Product::getProductIDMapConfig(){
    return Product::productIDMap;
}

map<string, string> Product::getProductTypeMapConfig(){
    return Product::productTypeMap;
}

map<string, string> Product::getProductNameMapConfig(){
    return Product::productNameMap;
}

map<string, string> Product::getProductOriginMapConfig(){
    return Product::productOriginMap;
}

map<string, int> Product::getProductAddedWeightMapConfig(){
    return Product::productAddedWeightMap;
}

map<string, int> Product::getProductPriceMapConfig(){
    return Product::productPriceMap;
}

Product::~Product(){}

void Product::printParsedConfig() {
    for (int i = 0; i < Product::productCodeList.size(); i++) {
        cout << Product::productCodeList[i] << " ";
    }
}