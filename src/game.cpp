#include "header/game.hpp"
#include "header/gameException.hpp"
#include "header/animal.hpp"
#include "header/printColor.hpp"
#include "header/utils.hpp"

using namespace std;

Game::Game(){
    cout << endl;
    cout << setfill('=') << setw(50)  << "" << endl << setfill(' ');
    startTextBlue();
    cout << setw(32) << "Game Started" << endl;
    resetTextColor();
    cout << setfill('=') << setw(50)  << "" << endl << endl << setfill(' ');
}

Game::~Game(){
    cout << endl;
    cout << setfill('=') << setw(50)  << "" << endl << setfill(' ');
    startTextRed();
    cout << setw(31) << "Game Exited" << endl;
    resetTextColor();
    cout << setfill('=') << setw(50)  << "" << endl << endl << setfill(' ');
}

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
    startTextGreen();
    cout << " > Finished Reading Animal Configuration" << endl;
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
    int durationToHarvest;  // Plant minimum weight for plant to be harvested
    int price;              // Plant price

    string line; 
    while (getline(configFile, line)) {
        istringstream iss(line);
        iss >> id >> code >> name >> type >> durationToHarvest >> price;
        
        
        // TODO: STORE CONFIGURATION TO PLANT CLASS
    }
    
    startTextGreen();
    cout << " > Finished Reading Plant Configuration" << endl;
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
    
    startTextGreen();
    cout << " > Finished Reading Product Configuration" << endl;
    configFile.close();    
}

void Game::readConfigRecipe(){
    ifstream configFile("config/recipe.txt");
    if (!configFile.is_open()) {
        throw FileOpenFailedException("Failed to open recipe.txt");
    }
    
    // TODO: READ RECIPE CONFIGURATION 
    resetTextColor();
    cout << "Warning: Recipe configuration is not been implemented" << endl;

    startTextGreen();
    cout << " > Finished Reading Recipe Configuration" << endl;
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
    
    startTextGreen();
    cout << " > Finished Reading Misc Configuration" << endl;
    configFile.close();    
}

int Game::readConfig(){
    try{
        readConfigPlant();
        readConfigAnimal();
        readConfigProduct();
        readConfigRecipe();
        readConfigMisc();
        cout << endl;
        return 0;
        
    } catch (FileOpenFailedException e){
        startTextRed();
        cout << e.what() << endl;
        resetTextColor();
        return 1;
    }
}

int Game::getGameStateIO(){
    string input;
    int choice = 0;
    while(1){
        cout << setfill('=') << setw(21);
        startTextBlue();
        cout << " Menu "; 
        resetTextColor();
        cout << setw(15) << "" << endl << setfill(' ');
        cout << "Choose the menu number:" << endl;
        cout << "1. New Game" << endl;
        cout << "2. Load Save" << endl;
        cout << "3. Exit" << endl;
        startTextGreen();
        cout << "> ";
        cin >> input;
        resetTextColor();

        if(isNumber(input)){
            choice = stoi(input);
        }

        if(choice == 1 || choice == 2 || choice == 3){
            break;
        } else{
            cout << "Please input a valid menu number\n" << endl;
        }
    }
    
    if(choice == 1){
        // TODO: New Game
    } else if(choice == 2){
        // TODO: Load Save
    } else{
        return 1;
    }

    return 0;
}