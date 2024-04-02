#ifndef __PRODUCT_HPP__
#define __PRODUCT_HPP__

#include <iostream>
#include <string>
using namespace std;

/* Global Variables for Default Values */
const string DefaultProductTypeMaterialPlant = "PRODUCT_MATERIAL_PLANT";
const string DefaultProductTypeEdiblePlant = "PRODUCT_FRUIT_PLANT";
const string DefaultProductTypeAnimal = "PRODUCT_ANIMAL";

class Product {
    protected:
        int id;                 // Product id
        string code;            // Product code
        string name;            // Product name
        string type;            // Product type 
        string origin;          // Product origin
        const int addedWeight;  // Product added weight when eaten
        const int price;        // Product price
    
    public:
        Product();
        ~Product();

        /**
         * @brief Get product added weight
         * 
         * @return int added weight 
        */
        int getAddedWeight() const;
        
        /**
         * @brief Check if product is edible or not
         * 
         * @param Product 
         * @return true if product is edible
         * @return false if product is not edible
        */
        friend bool isEdible(Product& Product);

        /**
         * @brief Check if product is an plant product
         * 
         * @param Product 
         * @return true if product is an plant product
         * @return false if product is not an plant product
        */
        friend bool isPlantProduct(Product& Product);
        
        /**
         * @brief Check if product is an animal product
         * 
         * @param Product 
         * @return true if product is an animal product
         * @return false if product is not an animal product
        */
        friend bool isAnimalProduct(Product& Product);
};

#endif