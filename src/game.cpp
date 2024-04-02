// File: game.cpp
#include "header/game.hpp"
#include "header/gameException.hpp"
#include "header/animal.hpp"

using namespace std;

Game::Game(){}

Game::~Game(){}

void Game::readConfigAnimal(){
    ifstream configFile("config/animal.txt");
    if (!configFile.is_open()) {
        throw FileOpenFailedException("Failed to open animal.txt");
    }
    
    int id;               // Animal id
    string code;          // Animal code
    string name;          // Animal name
    int weightToHarvest;  // Animal minimum weight for animal to be harvested
    int price;            // Animal price
    string foodType;      // Animal Food type

    string line; 
    Animal temp; 
    while (getline(configFile, line)) {
        istringstream iss(line);
        iss >> id >> code >> name >> foodType >> weightToHarvest >> price;

        temp.AddAnimalConfig(id, code, name, foodType, weightToHarvest, price);
    }

    cout << "Finished Reading Animal Configuration" << endl;
    configFile.close();    
}

void Game::readConfigPlant(){
    ifstream configFile("config/plant.txt");
    if (!configFile.is_open()) {
        throw FileOpenFailedException("Failed to open plant.txt");
    }
    
    int id;                 // Plant id
    string code;            // Plant code
    string name;            // Plant name
    string type;            // Plant type
    int weightToHarvest;    // Plant minimum weight for plant to be harvested
    int price;              // Plant price

    string line; 
    while (getline(configFile, line)) {
        istringstream iss(line);
        iss >> id >> code >> name >> type >> weightToHarvest >> price;
        
        
        // TODO: STORE CONFIGURATION TO PLANT CLASS
    }
    
    cout << "Finished Reading Plant Configuration" << endl;
    configFile.close();    
}

void Game::readConfigProduct(){
    ifstream configFile("config/product.txt");
    if (!configFile.is_open()) {
        throw FileOpenFailedException("Failed to open product.txt");
    }
    
    int id;             // Product id
    string code;        // Product code
    string name;        // Product name
    string type;        // Product type
    string origin;      // Product type
    int addedWeight;    // Product added weight when eaten/feed
    int price;          // Product price

    string line; 
    while (getline(configFile, line)) {
        istringstream iss(line);
        iss >> id >> code >> name >> type >> origin >> addedWeight >> price;
        
        // TODO: STORE CONFIGURATION TO PLANT CLASS
    }
    
    cout << "Finished Reading Product Configuration" << endl;
    configFile.close();    
}

void Game::readConfigRecipe(){
    ifstream configFile("config/recipe.txt");
    if (!configFile.is_open()) {
        throw FileOpenFailedException("Failed to open recipe.txt");
    }
    
    // TODO: READ RECIPE CONFIGURATION 
    cout << "Warning: Recipe configuration is not been implemented" << endl;

    cout << "Finished Reading Recipe Configuration" << endl;
    configFile.close(); 
}

void Game::readConfigMisc(){
    ifstream configFile("config/misc.txt");
    if (!configFile.is_open()) {
        throw FileOpenFailedException("Failed to open misc.txt");
    }
    
    int winningLimit;                               // Jumlah uang pemain untuk menang
    int winningWeight;                              // Jumlah berat badan pemain untuk menang
    int storageWidth, storageHeight;                // Besaran penyimpanan
    int plantStorageWidth, plantStorageHeight;      // Besaran lahan
    int animalStorageWidth, animalStorageHeight;    // Besaran peternakan

    string line; 
    getline(configFile, line);
    istringstream iss(line);
    iss >> winningLimit;

    getline(configFile, line);
    iss = istringstream(line);
    iss >> winningWeight;

    getline(configFile, line);
    iss = istringstream(line);
    iss >> storageWidth >> storageHeight;

    getline(configFile, line);
    iss = istringstream(line);
    iss >> plantStorageHeight >> plantStorageWidth;
    
    getline(configFile, line);
    iss = istringstream(line);
    iss >> animalStorageWidth >> animalStorageHeight;

    // TODO: Store Variables To Class
    
    cout << "Finished Reading Misc Configuration" << endl;
    configFile.close();    
}

int Game::readConfig(){
    try{
        readConfigPlant();
        readConfigAnimal();
        readConfigProduct();
        readConfigRecipe();
        readConfigMisc();
        return 0;
        
    } catch (FileOpenFailedException e){
        cout << e.what() << endl;
        return 1;
    }
}