#ifndef TANAMAN
#define TANAMAN

#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Plant {
protected:
    // Global variable, diambil dari file config
    static vector <string> plantCodeList; // Digunakan code 3 char karena parameter unik
    static map <string, int> plantIDMap; // <code, map>
    static map <string, string> plantTypeMap; // <code, plantType>
    static map <string, string> plantNameMap; // <code, plantName>
    static map <string, int> plantHarvestDurationMap; // <code, harvestDuration>
    static map <string, int> plantPriceMap; // <code, price>

    int id;                         // plant ID
    string code;                    // 3 characters plant code
    const string plantType;         // Plant type (Material Plant, Food Plant)
    string plantName;               // Plant name
    int currentDuration = 0;        // Durasi saat ini sebelum bisa di-harvest, default 0
    const int harvestDuration;      // Durasi yang dibutuhkan untuk bisa di-harvest
    const int price;                // Harga jual tanaman

public:
    /**
     * @brief default ctor plant
     * @note hanya untuk inisialisasi parse config file
     */
    Plant();

    /**
     * @brief ctor plant based on code
     * @param _code  3 characters plant code
     */
    Plant(string _code);

    /**
     * @brief ctor plant
     * @param _id    Plant id
     * @param _code  3 characters plant code
     * @param _plantType Plant type
     * @param _plantName Plant name
     * @param _harvestDuration Durasi yang dibutuhkan untuk bisa di-harvest
     * @param _price Harga jual tanaman
     */
    Plant(int _id, string _code, string _plantType, string _plantName, int _harvestDuration, int _price);

    /**
     * @brief cctor plant
     * @param other the other plant to be copied
    */
    Plant(Plant &other);

    /**
     * @brief dtor plant
     */
    ~Plant();

    /**
     * @brief Getter get plant ID
     * @return plant ID
     */
    int getID();

    /**
     * @brief Getter get plant code
     * @return 3 character plant code
     */
    string getCode();

    /**
     * @brief Getter get plant type
     * @return plant type (Material Plant, Food Plant)
     */
    string getPlantType();

    /**
     * @brief Getter get plant name
     * @return plant name
     */
    string getPlantName();

    /**
     * @brief Getter get current duration
     * @return current duration before harvest
     */
    int getCurrentDuration();

    /**
     * @brief Getter get harvest duration
     * @return harvest duration, time needed to harvest
     */
    int getHarvestDuration();

    /**
     * @brief Getter get price
     * @return plant price
     */
    int getPrice();

    /**
     * @brief Setter set plant ID
     * @param _id plant ID
     */
    void setID(int _id);

    /**
     * @brief Setter set plant code
     * @param _code 3 character plant code
     */
    void setCode(string _code);

    /**
     * @brief Setter set plant name
     * @param _plantName plant name
     */
    void setPlantName(string _plantName);

    /**
     * @brief Setter set current duration
     * @param _currentDuration current duration before harvest
     */
    void setCurrentDuration(int _currentDuration);

    /**
     * @brief print print semua informasi mengenai plant
     */
    void printInfo();

    /**
     * @brief melakukan parsing config dari file, dan menyimpannya di static variabel kelas
     */
     void static addPlantConfig(int _id, string _code, string _plantType, string _plantName, int _harvestDuration, int _price);

     /**
      * @brief usia tanaman bertambah 1
      */
     void grow();

     /**
      * @brief Cek apakah tanaman sudah bisa di-harvest atau belum
      * return true, currentDuration >= harvestDuration
      */
     bool isReadyToHarvest();

     /**
      * @brief Cek apakah object plant kosong
      * \note Definisi plant kosong adalah apabila code=""
      */
     bool empty();

    /**
    * @brief Get Config: vector of plant code (main key)
    * @return vector of plant code (string)
    */
    static vector<string> getPlantCodeListConfig();

    /**
     * @brief Get Config: map of plant ID, <code, id>
     * @return map of plant ID
     */
    static map<string, int> getPlantIDMapConfig();

    /**
     * @brief Get Config: map of plant type, <code, plantType>
     * @return map of plant type
     */
    static map<string, string> getPlantTypeMapConfig();

    /**
     * @brief Get Config: map of plant name, <code, plantName>
     * @return map of plant name
     */
    static map<string, string> getPlantNameMapConfig();

    /**
     * @brief Get Config: map of plant harvest duration, <code, harvestDuration>
     * @return map of plant harvest duration
     */
    static map<string, int> getPlantHarvestDurationMapConfig();

    /**
     * @brief Get Config: map of plant price, <code, price>
     * @return map of plant price
     */
    static map<string, int> getPlantPriceMapConfig();

    /**
     * @brief Print all config variables
     * \note For debugging only
    */
   static void printParsedConfig();
};

/**
 * @brief Kelas dari Material Plant, type of Plant
 */
class MaterialPlant : public Plant {
public:
    /**
     * @brief ctor Material Plant
     * @param _id    Plant id
     * @param _code  3 characters plant code
     * @param _plantName Plant name
     * @param _harvestDuration Durasi yang dibutuhkan untuk bisa di-harvest
     * @param _price Harga jual tanaman
     * Memiliki berat untuk digunakan di product
     */
    MaterialPlant(int _id, string _code, string _plantName, int _harvestDuration, int _price);

    /**
     * @brief dtor Material Plant
     */
    ~MaterialPlant();
};

/**
 * @brief Kelas dari Food Plant, type of Plant
 */
class FoodPlant : public Plant {
public:
    /**
     * @brief ctor Food Plant
     * @param _id    Plant id
     * @param _code  3 characters plant code
     * @param _plantName Plant name
     * @param _harvestDuration Durasi yang dibutuhkan untuk bisa di-harvest
     * @param _price Harga jual tanaman
     * Tidak memiliki berat. PlantType FoodPlant
     */
    FoodPlant(int _id, string _code, string _plantName, int _harvestDuration, int _price);

    /**
     * @brief dtor Food Plant
     */
    ~FoodPlant();
};

#endif