#ifndef __PRODUCT_HPP__
#define __PRODUCT_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "plant.hpp"
#include "animal.hpp"
using namespace std;

/* Global Variables for Default Values */
const string DefaultProductTypeMaterialPlant = "PRODUCT_MATERIAL_PLANT";
const string DefaultProductTypeEdiblePlant = "PRODUCT_FRUIT_PLANT";
const string DefaultProductTypeAnimal = "PRODUCT_ANIMAL";

/**
 * @brief Kelas product
 * @param id int Product id
 * @param code string Product code
* @param name string Product name
*   @param type string Product type 
*   @param origin string Product origin, use 3 char code of origin
*   @param addedWeight const int Product added weight when eaten
*  @param price const int Product price
*/
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
        static map <string, vector<string>> productOriginToCode; // <origin code, vector of product code>

        int id;                 // Product id
        string code;            // Product code
        string name;            // Product name
        string type;            // Product type 
        string origin;          // Product origin, use 3 char code of origin
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
     * @brief ctor berdasarkan code
     */
    Product(string _code);

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
     * @brief Get Product Type
     * 
     * @return string 
    */
    string getType() const;

    /**
     * @brief return code of product
     * @return code string of product
     */
    string getCode();

    /**
     * @brief ctor product dengan input code origin (code bahan pembuat product)
     * @param _origin origin of product, code
     * @return vector of code of product
    */
    static vector<string> convertToProductCode(string _origin);


    /**
     * @brief Get product origin code
     * @param product
     * @return product origin's code
    */
    static string getOriginCode(Product& product);

    /**
     * @brief Check if product is edible or not
     * 
     * @param Product 
     * @return true if product is edible
     * @return false if product is not edible (addedWeight = 0)
    */
    static bool isEdible(Product& Product);

    /**
     * @brief Check if product is an plant product
     * 
     * @param Product 
     * @return true if product is an plant product
     * @return false if product is not an plant product
    */
    static bool isPlantProduct(Product& Product);
    
    /**
     * @brief Check if product is an animal product
     * 
     * @param Product 
     * @return true if product is an animal product
     * @return false if product is not an animal product
    */
    static bool isAnimalProduct(Product& Product);

    /**
     * @brief Get Config : Product Code List
     * @return vector<string> productCodeList
     */
    static vector <string> getProductCodeListConfig();

    /**
     * @brief Get Config : Product ID Map
     * @return map<string, int> productIDMap, <code, id>
     */
    static map <string, int> getProductIDMapConfig();

    /**
     * @brief Get Config : Product Type Map, <code, productType>
     * @return map<string, string> productTypeMap
     */
    static map <string, string> getProductTypeMapConfig();

    /**
     * @brief Get Config : Product Name Map, (code, productName)
     * @return map<string code, string name> productNameMap
     */
    static map <string, string> getProductNameMapConfig();

    /**
     * @brief Get Config : Product Origin Map, <code, productOrigin>
     * @return map<string, string> productOriginMap
     */
    static map <string, string> getProductOriginMapConfig();

    /**
     * @brief Get Config : Product Added Weight Map, <code, addedWeight>
     * @return map<string, int> productAddedWeightMap
     */
    static map <string, int> getProductAddedWeightMapConfig();

    /**
     * @brief Get Config : Product Price Map, <code, price>
     * @return map<string, int> productPriceMap
     */
    static map <string, int> getProductPriceMapConfig();

    /**
     * @brief Get Config : Product Origin to Code, <origin code, vector of product code>
     * @return map<string, vector<string>> productOriginToCode, map berisi <origin code, vector of product code>
     */
    static map <string, vector<string>> getProductOriginToCode();

    /** 
     * @brief Checker apakah product sudah di-parse semuanya
    */
    static void printParsedConfig();

    /**
     * @brief mengubah string nama item menjadi string code, baik untuk animal maupun plant
     * @param name string nama, plant atau animal
     * @return code item, plant atau animal
     */
    static string convertNameToCode(string name);
};

#endif