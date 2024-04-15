#include <vector>

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

string itemType(char* itemCode){
    if (itemCode == nullptr){
        return "";
    }
    vector <string>::iterator it;
    it = find(Plant::getPlantCodeListConfig().begin(), Plant::getPlantCodeListConfig().end(), itemCode);
    if (it != Plant::getPlantCodeListConfig().end()) {
        return "Plant";
    } else {
        // Find in Animal
        it = find(Animal::getAnimalCodeConfig().begin(), Animal::getAnimalCodeConfig().end(), itemCode);
        if (it != Animal::getAnimalCodeConfig().end()) {
            return "Animal";
        } else {
            it = find(Product::getProductCodeListConfig().begin(), Product::getProductCodeListConfig().end(), itemCode);
            if (it != Product::getProductCodeListConfig().end()) {
                return "Product";
            } else {
                it = find(Building::getBuildingCodeListConfig().begin(), Building::getBuildingCodeListConfig().end(), itemCode);
                if (it != Building::getBuildingCodeListConfig().end()){
                    return "Building";
                } else {
                    return "";
                }
            }
        }
    }
}