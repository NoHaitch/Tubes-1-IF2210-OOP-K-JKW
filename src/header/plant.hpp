#ifndef TANAMAN
#define TANAMAN

#include <string>

class Plant {
protected:
    int id;                         // plant ID
    string code;                    // 3 characters plant code
    const string plantType;         // Plant type (Material Plant, Food Plant)
    string plantName;               // Plant name
    int currentDuration = 0;            // Durasi saat ini sebelum bisa di-harvest, default 0
    const int harvestDuration;      // Durasi yang dibutuhkan untuk bisa di-harvest
    const int price;                // Harga jual tanaman

public:
    /**
     * @brief ctor plant
     * @param _id    Plant id, static, auto generated
     * @param _code  3 characters plant code
     * @param _plantType Plant type
     * @param _plantName Plant name
     * @param _harvestDuration Durasi yang dibutuhkan untuk bisa di-harvest
     * @param _price Harga jual tanaman
     */
    Plant(int _id, string _code, string _plantType, string _plantName, int _harvestDuration, int _price);

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
     * @brief Setter set plant type
     * @param _plantType plant type (Material Plant, Food Plant)
     */
    void setPlantType(string _plantType);

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
     * @brief Setter set harvest duration
     * @param _harvestDuration time needed to harvest
     */
    void setHarvestDuration(int _harvestDuration);

    /**
     * @brief Setter set price
     * @param _price plant price
     */
    void setPrice(int _price);

    /**
     * @brief print all information about plant
     */
    virtual void printInfo();
};

/**
 * @brief Class of Material Plant, type of Plant
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
     */
    MaterialPlant(int _id, string _code, string _plantName, int _harvestDuration, int _price);

    /**
     * @brief dtor Material Plant
     */
    ~MaterialPlant();

    /**
     * @brief print all information about material plant
     */
     virtual void printInfo() override;
};

/**
 * @brief Class of Food Plant, type of Plant
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
     */
    FoodPlant(int _id, string _code, string _plantName, int _harvestDuration, int _price);

    /**
     * @brief dtor Food Plant
     */
    ~FoodPlant();

    /**
     * @brief print all information about food plant
     */
    virtual void printInfo() override;
};


/**
 * @brief Class of Teak Tree, derived from Material Plant
 * */
class TeakTree : public MaterialPlant {
public:
    /**
     * @brief ctor Teak Tree
     * @param _id    Plant id
     * @param _code  3 characters plant code
     * @param _plantName Plant name
     * @param _harvestDuration Durasi yang dibutuhkan untuk bisa di-harvest
     * @param _price Harga jual tanaman
     */
    TeakTree(int _id, string _code, string _plantName, int _harvestDuration, int _price);

    /**
     * @brief dtor Teak Tree
     */
    ~TeakTree();

    /**
     * @brief print all information about teak tree
     */
     void printInfo() override;
};


/**
 * @brief Class of Sandalwood Tree, derived from Material Plant
 */
class SandalwoodTree : public MaterialPlant {
public:
    /**
     * @brief ctor Sandalwood Tree
     * @param _id    Plant id
     * @param _code  3 characters plant code
     * @param _plantName Plant name
     * @param _harvestDuration Durasi yang dibutuhkan untuk bisa di-harvest
     * @param _price Harga jual tanaman
     */
    SandalwoodTree(int _id, string _code, string _plantName, int _harvestDuration, int _price);

    /**
     * @brief dtor Sandalwood Tree
     */
    ~SandalwoodTree();

    /**
     * @brief print all information about sandalwood tree
     */
     void printInfo() override;
};

class AloeTree : public MaterialPlant {
public:
    /**
     * @brief ctor Aloe Tree
     * @param _id    Plant id
     * @param _code  3 characters plant code
     * @param _plantName Plant name
     * @param _harvestDuration Durasi yang dibutuhkan untuk bisa di-harvest
     * @param _price Harga jual tanaman
     */
    AloeTree(int _id, string _code, string _plantName, int _harvestDuration, int _price);

    /**
     * @brief dtor Aloe Tree
     */
    ~AloeTree();

    /**
     * @brief print all information about aloe tree
     */
    void printInfo() override;
};

/**
 * @brief Class of Ironwood Tree, derived from Material Plant
 */
class IronwoodTree : public MaterialPlant {
    
};
#endif