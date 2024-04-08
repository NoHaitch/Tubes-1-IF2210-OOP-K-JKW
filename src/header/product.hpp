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
        // Global variable, diambil dari file config
        static vector <string> productCodeList; // Digunakan code 3 char karena parameter unik
        static map <string, int> productIDMap; // <code, map>
        static map <string, string> productTypeMap; // <code, productType>
        static map <string, string> productNameMap; // <code, productName>
        static map <string, string> productOriginMap; // <code, productOrigin>
        static map <string, int> productAddedWeightMap; // <code, addedWeight>
        static map <string, int> productPriceMap; // <code, price>


        int id;                 // Product id
        string code;            // Product code
        string name;            // Product name
        string type;            // Product type 
        string origin;          // Product origin
        const int addedWeight;  // Product added weight when eaten
        const int price;        // Product price
    
    public:
        /**
         * @brief Add product configuration dari file
         * @param _id
         * @param _code
         * @param _type
         * @param _name
         * @param _origin
         * @param _addedWeight
         * @param _price
         */
        static void addProductConfig(int _id, string _code, string _type, string _name, string _origin, int _addedWeight, int _price);


        /**
         * @brief Default ctor product
         * @note hanya untuk inisialisasi parse config file
         */
        Product();

        /**
         * @brief ctor product
         * @param _id Product id
         * @param _code 3 characters product code
         * @param _type Product type
         * @param _name Product name
         * @param _origin Product origin
         * @param _addedWeight Product added weight
         * @param _price Product price
         */
        Product(int _id, string _code, string _type, string _name, string _origin, int _addedWeight, int _price);


        /**
         * @brief dtor produk
         */
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
         * @return false if product is not edible (addedWeight = 0)
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

        /**
         * @brief Get Config : Product Code List
         * @return vector<string> productCodeList
         */
        friend vector <string> getProductCodeListConfig();

         /**
          * @brief Get Config : Product ID Map
          * @return map<string, int> productIDMap, <code, id>
          */
        friend map <string, int> getProductIDMapConfig();

        /**
         * @brief Get Config : Product Type Map, <code, productType>
         * @return map<string, string> productTypeMap
         */
        friend map <string, string> getProductTypeMapConfig();

        /**
         * @brief Get Config : Product Name Map, <code, productName>
         * @return map<string, string> productNameMap
         */
        friend map <string, string> getProductNameMapConfig();

        /**
         * @brief Get Config : Product Origin Map, <code, productOrigin>
         * @return map<string, string> productOriginMap
         */
        friend map <string, string> getProductOriginMapConfig();

        /**
         * @brief Get Config : Product Added Weight Map, <code, addedWeight>
         * @return map<string, int> productAddedWeightMap
         */
        friend map <string, int> getProductAddedWeightMapConfig();

        /**
         * @brief Get Config : Product Price Map, <code, price>
         * @return map<string, int> productPriceMap
         */
        friend map <string, int> getProductPriceMapConfig();
};

#endif