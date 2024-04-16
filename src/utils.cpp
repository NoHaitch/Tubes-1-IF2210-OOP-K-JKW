#include <vector>
#include <random>

#include "header/utils.hpp"
#include "header/printColor.hpp"
#include "header/plant.hpp"
#include "header/animal.hpp"
#include "header/building.hpp"

using namespace std;

bool isNumber(const std::string& s) {
    string::const_iterator it = s.begin();

    while (it != s.end() && isdigit(*it)){
        ++it;
    } 
    
    return !s.empty() && it == s.end();
}

void printTitle(){
    startTextCyan();
    cout << " /$$$$$$$  /$$$$$$$  /$$$$$$$        /$$   /$$ /$$$$$$$$ /$$$$$$$   /$$$$$$     /$$$$$  /$$$$$$   /$$$$$$  /$$   /$$\n"
            "| $$__  $$| $$__  $$| $$__  $$      | $$  /$$/| $$_____/| $$__  $$ /$$__  $$   |__  $$ /$$__  $$ /$$__  $$| $$$ | $$\n"
            "| $$  \\ $$| $$  \\ $$| $$  \\ $$      | $$ /$$/ | $$      | $$  \\ $$| $$  \\ $$      | $$| $$  \\ $$| $$  \\ $$| $$$$| $$\n"
            "| $$  | $$| $$$$$$$/| $$$$$$$/      | $$$$$/  | $$$$$   | $$$$$$$/| $$$$$$$$      | $$| $$$$$$$$| $$$$$$$$| $$ $$ $$\n"
            "| $$  | $$| $$____/ | $$__  $$      | $$  $$  | $$__/   | $$__  $$| $$__  $$ /$$  | $$| $$__  $$| $$__  $$| $$  $$$$\n"
            "| $$  | $$| $$      | $$  \\ $$      | $$\\  $$ | $$      | $$  \\ $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$\\  $$$\n"
            "| $$$$$$$/| $$      | $$  | $$      | $$ \\  $$| $$$$$$$$| $$  | $$| $$  | $$|  $$$$$$/| $$  | $$| $$  | $$| $$ \\  $$\n"
            "|_______/ |__/      |__/  |__/      |__/  \\__/|________/|__/  |__/|__/  |__/ \\______/ |__/  |__/|__/  |__/|__/  \\__/" << endl;
    resetTextColor();
}

string itemType(string* itemCode){
    if (itemCode == nullptr){
        return "";
    }
    for (int i = 0; i < Plant::getPlantCodeListConfig().size(); i++) {
        if (*itemCode == Plant::getPlantCodeListConfig()[i]) {
            return "Plant";
        }
    }
    for (int i = 0; i < Animal::getAnimalCodeConfig().size(); i++) {
        if (*itemCode == Animal::getAnimalCodeConfig()[i]) {
            return "Animal";
        }
    }
    for (int i = 0; i < Product::getProductCodeListConfig().size(); i++) {
        if (*itemCode == Product::getProductCodeListConfig()[i]) {
            return "Product";
        }
    }
    for (int i = 0; i < Building::getBuildingCodeListConfig().size(); i++) {
        if (*itemCode == Building::getBuildingCodeListConfig()[i]) {
            return "Building";
        }
    }
    return "";
}

string convertItemNameToCode(string itemName) {
    // Cek pada product
    map<string, string> temp = Product::getProductNameMapConfig();
    for (map <string, string>::iterator it = temp.begin(); it != temp.end(); it++) {
        if (it->second == itemName) {
            return it->first;
        }
    }

    // Cek pada plant
    temp = Plant::getPlantNameMapConfig();
    for (map <string, string>::iterator it = temp.begin(); it != temp.end(); it++) {
        if (it->second == itemName) {
            return it->first;
        }
    }

    // Cek pada building
    temp = Building::getBuildingNameConfig();
    for (map <string, string>::iterator it = temp.begin(); it != temp.end(); it++) {
        if (it->second == itemName) {
            return it->first;
        }
    }

    // Cek pada animal
    temp = Animal::getAnimalNameToCodeConfig();
    for (map <string, string>::iterator it = temp.begin(); it != temp.end(); it++) {
        if (it->first == itemName) {
            return it->second;
        }
    }

    return "";
}

int rng(int min, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(min, max);
    return 0;
}

string convertItemCodeToName(string itemCode) {
    // Cek pada product
    map<string, string> temp = Product::getProductNameMapConfig();
    for (map <string, string>::iterator it = temp.begin(); it != temp.end(); it++) {
        if (it->first == itemCode) {
            return it->second;
        }
    }

    // Cek pada plant
    temp = Plant::getPlantNameMapConfig();
    for (map <string, string>::iterator it = temp.begin(); it != temp.end(); it++) {
        if (it->first == itemCode) {
            return it->second;
        }
    }

    // Cek pada building
    temp = Building::getBuildingNameConfig();
    for (map <string, string>::iterator it = temp.begin(); it != temp.end(); it++) {
        if (it->first == itemCode) {
            return it->second;
        }
    }

    // Cek pada animal
    temp = Animal::getAnimalNameToCodeConfig();
    for (map <string, string>::iterator it = temp.begin(); it != temp.end(); it++) {
        if (it->second == itemCode) {
            return it->first;
        }
    }

    return "";
}