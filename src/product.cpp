#include "header/product.hpp"

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