#include "header/product.hpp"

vector<string> Product::productCodeList;
map<string, int> Product::productIDMap;
map<string, string> Product::productTypeMap;
map<string, string> Product::productNameMap;
map<string, string> Product::productOriginMap;
map<string, int> Product::productAddedWeightMap;
map<string, int> Product::productPriceMap;


void Product::addProductConfig(int _id, std::string _code, std::string _type, std::string _name, std::string _origin,
                               int _addedWeight, int _price) {
    productCodeList.push_back(_code);
    productIDMap[_code] = _id;
    productTypeMap[_code] = _type;
    productNameMap[_code] = _name;
    productOriginMap[_code] = _origin;
    productAddedWeightMap[_code] = _addedWeight;
    productPriceMap[_code] = _price;
}


Product::Product() : addedWeight(0), price(0){
    id = 0;
    code = "";
    name = "";
    type = "";
    origin = "";
}

Product::Product(int _id, string _code, string _type, string _name, string _origin, int _addedWeight, int _price) : addedWeight(_addedWeight), price(_price){
    id = _id;
    code = _code;
    name = _name;
    type = _type;
    origin = _origin;
}

int Product::getAddedWeight() const{
    return addedWeight;
}

bool isEdible(Product& product){
    return product.addedWeight != 0;
}

bool isPlantProduct(Product& product){
    return product.type == DefaultProductTypeMaterialPlant || product.type == DefaultProductTypeEdiblePlant;
}

bool isAnimalProduct(Product& product){
    return product.type == DefaultProductTypeAnimal;
}

vector<string> getProductCodeListConfig(){
    return Product::productCodeList;
}

map<string, int> getProductIDMapConfig(){
    return Product::productIDMap;
}

map<string, string> getProductTypeMapConfig(){
    return Product::productTypeMap;
}

map<string, string> getProductNameMapConfig(){
    return Product::productNameMap;
}

map<string, string> getProductOriginMapConfig(){
    return Product::productOriginMap;
}

map<string, int> getProductAddedWeightMapConfig(){
    return Product::productAddedWeightMap;
}

map<string, int> getProductPriceMapConfig(){
    return Product::productPriceMap;
}

Product::~Product(){}