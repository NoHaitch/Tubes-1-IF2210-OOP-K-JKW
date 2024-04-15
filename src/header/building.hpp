#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>
#include <map>
#include <vector>
using namespace std;

class Building {
protected :
    const int id;                      // Building ID
    const string code;                 // Building code
    const string name;                 // Building name
    const int price;                   // Building price
    map<string, int> materials;  // Building materials Key : material, Value : quantity of material

    /* Configuration Variables */
    static vector<string> configCode;
    static map<string, int> configID;
    static map<string, string> configName;
    static map<string, int> configPrice;
    static map<string, map<string, int>> configMaterial;

public :
    Building();
    Building(string _code);
    Building(int _id, const string& _code, const string& _name, int _price);
    Building(const Building& other);
    ~Building();
    int getID() const;
    string getCode() const;
    string getName() const;
    int getPrice() const;
    static void addBuildingConfig(int _id, string _code, string _name, int _price);
    static void addMaterials(string _code, string _material, int _quantity);
    static vector<string> getBuildingCodeListConfig();
    static map<string, int> getBuildingPriceMapConfig();
    /**
     * @brief Operator overloading untuk assignment apakah kedua bangunan sama.
     * @brief Kedua bangunan sama jika memiliki nama dan tipe yang sama.
     * @param a bangunan
     * @param b bangunan
     * @return true jika bangunan a dan b memiliki nama dan tipe yang sama
     */
    friend bool operator==(Building a, Building b);
};

#endif