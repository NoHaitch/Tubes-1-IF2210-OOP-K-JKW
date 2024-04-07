#include "header/game.hpp"
#include "header/gameException.hpp"
#include "header/animal.hpp"
#include "header/plant.hpp"
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

int Game::readConfig(){
    startTextYellow();
    cout << "Reading Configuration ..." << endl;
    resetTextColor();

    try{
        readConfigPlant();
        readConfigAnimal();
        readConfigProduct();
        readConfigRecipe();
        readConfigMisc();

        startTextBlue();
        cout << "Reading Configuration Succesfull\n" << endl;
        resetTextColor();
        return 0;
        
    } catch (FileNotFoundException e){
        startTextRed();
        cout << e.what() << endl;
        resetTextColor();
        return 1;
    }
}

void Game::readGameState(string path){
    ifstream saveFile(path);
    if(!saveFile.is_open()){
        throw FileNotFoundException();
    }

    int amountOfPlayer = -1;

    string line; 
    getline(saveFile, line);
    istringstream iss(line);
    iss >> amountOfPlayer;

    if(amountOfPlayer < 3){
        throw FileReadingFailedException();
    }

    for(int player = 0; player < amountOfPlayer; player++){
        // cout << "PLAYER " << player + 1 << ": " << endl;
        string playerUsername;
        string playerRole;
        int playerWeight = -1;
        int playerMoney = -1;
        
        getline(saveFile, line);
        iss = istringstream(line);
        iss >> playerUsername >> playerRole >> playerWeight >> playerMoney;

        if(playerWeight < 0 | playerMoney < 0){
            throw FileReadingFailedException();
        }


        int playerItemCount = -1;
        
        getline(saveFile, line);
        iss = istringstream(line);
        iss >> playerItemCount;

        if(playerItemCount < 0){
            throw FileReadingFailedException();
        }

        // cout << "> Player Username: " << playerUsername << endl;
        // cout << "> Player Role: " << playerRole << endl;
        // cout << "> Player Weight: " << playerWeight << endl;
        // cout << "> Player Money: " << playerMoney << endl;
        // cout << "> Items (" << playerItemCount << "): "<< endl;

        for(int item = 0; item < playerItemCount; item++){
            string itemName = "";
            getline(saveFile, line);
            iss = istringstream(line);
            iss >> itemName;

            if(itemName == ""){
                throw FileReadingFailedException();
            }

            // cout << "  - " << itemName << endl;
        }

        int playerRoleStorage = -1;
        
        getline(saveFile, line);
        iss = istringstream(line);
        iss >> playerRoleStorage;

        if(playerRoleStorage < 0){
            throw FileReadingFailedException();
        }

        // cout << "> Content in Role Storage (" << playerRoleStorage << "): " << endl;

        if(player < amountOfPlayer - 1){
            for(int item = 0; item < playerRoleStorage; item++){
                string location = "";
                string itemName = "";
                int progress = -1;

                getline(saveFile, line);
                iss = istringstream(line);
                iss >> location >> itemName >> progress;

                if(location == "" || itemName == "" || progress < 0){
                    throw FileReadingFailedException();
                }

                // cout << "  - " << location << ": " << itemName << ", progress: " << progress << endl;
            }

        } else{
            for(int item = 0; item < playerRoleStorage; item++){
                // For Mayor
                string itemName = "";
                int itemAmount = -1;

                getline(saveFile, line);
                iss = istringstream(line);
                iss >> itemName >> itemAmount;

                if(itemName == "" || itemAmount < 1){
                    throw FileReadingFailedException();
                }

                // cout << "  - " << itemName << ": " << itemAmount << endl;
            }
        }
    }

    saveFile.close();    
}

// TODO initialize Game
void Game::initGameState(){
    
}

// TODO initilize Players
void Game::getGameStateIO(){
    string input;
    int choice = 0;
    while(1){
        cout << setfill('=') << setw(21);

        cout << " Menu "; 
        resetTextColor();
        cout << setw(15) << "" << endl << setfill(' ');
        cout << "Choose the menu number:" << endl;
        cout << "1. New Game State" << endl;
        cout << "2. Load Game State" << endl;
        cout << "3. Exit" << endl;
        
        startTextGreen();
        cout << "> ";
        cin >> input;
        resetTextColor();

        if(isNumber(input)){
            choice = stoi(input);
        }

        if(choice == 1){
            initGameState();
            break;
        } else if(choice == 2){
            string path;

            cout << "Masukkan lokasi berkas state: ";
            startTextGreen();
            cin >> path;
            resetTextColor();
            try{
                readGameState(path);
                break;
            } catch( FileNotFoundException e){
                startTextRed();
                cout << "Berkas tidak ditemukan, pastikan lokasi benar!" << endl;
                resetTextColor();
            } catch( FileReadingFailedException e){
                startTextRed();
                cout << "Gagal membaca berkas, pastikan isi berkas benar!" << endl;
                resetTextColor();
            }
        } else if(choice == 3){
            break;
        } else{
            cout << "Please input a valid menu number\n" << endl;
        }
    }
}

void Game::saveGame(string path){ 
    if (path.find("//") != string::npos || path.find("//") == 0) {
        throw FileBadPathException();
    }

    // Check if the path ends with ".txt"
    if (path.size() < 4 || path.substr(path.size() - 4) != ".txt") {
        throw FileFormatException("File must be in .txt format");
    }

    // Check if directory exists
    bool hasDirectory = (path.find("/") != string::npos || path.find("\\") != string::npos);
    if (hasDirectory) {
        string directoryPath = path.substr(0, path.find_last_of("/\\"));
        if (!filesystem::exists(directoryPath)) {
            throw DirectoryNotFoundException("Lokasi berkas tidak ditemukan");
        }
    }

    // Saving Game State
    ofstream saveFile(path);

    saveFile << "TEST SAVING";
    
    saveFile.close();
}

void Game::saveGameIO(){ 
    string path;
    cout << "Masukkan lokasi berkas state: ";
    startTextGreen();
    cin >> path;
    resetTextColor();

    try{
        saveGame(path);
        cout << "State berhasil disimpan" << endl;
    } catch (FileBadPathException e){
        startTextRed();
        cout << e.what() << endl;
        resetTextColor();
    } catch (FileFormatException e){
        startTextRed();
        cout << e.what() << endl;
        resetTextColor();
    } catch (DirectoryNotFoundException e){
        startTextRed();
        cout << e.what() << endl;
        resetTextColor();

        string input;
        cout << "\nApakah Anda ingin membuat folder secara otomatis (y/n)? ";
        startTextGreen();
        cin >> input;
        resetTextColor();
        if(input == "y"){
            try{
                makeDirectory(path);
                saveGame(path);
                cout << "State berhasil disimpan" << endl;
            } catch (DirectoryCreationFailedException e1){
                startTextRed();
                cout << e1.what() << endl;
                resetTextColor();
            }
        } else{
            cout << "Perintah Save Dibatalkan" << endl;
        }
    }


}

void Game::makeDirectory(string path){
    string directoryPath = path.substr(0, path.find_last_of("/\\"));

    try {
        string directoryPath = path.substr(0, path.find_last_of("/\\"));
        
        filesystem::create_directories(directoryPath);

    } catch (const exception& e) {
        throw DirectoryCreationFailedException();
    }
}

void Game::readConfigAnimal(){
    ifstream configFile("config/animal.txt");
    if (!configFile.is_open()) {
        throw FileNotFoundException("Failed to open animal.txt");
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
    cout << " > Finished Reading Animal Configuration" << endl;
    configFile.close();    
}

void Game::readConfigPlant(){
    ifstream configFile("config/plant.txt");
    if (!configFile.is_open()) {
        throw FileNotFoundException("Failed to open plant.txt");
    }
    
    int id;                 // Plant id
    string code;            // Plant code
    string name;            // Plant name
    string type;            // Plant type
    int durationToHarvest;  // Plant minimum weight for plant to be harvested
    int price;              // Plant price
    string line;

    Plant temp;
    while (getline(configFile, line)) {
        istringstream iss(line);
        iss >> id >> code >> name >> type >> durationToHarvest >> price;
        
        temp.addPlantConfig(id, code, type, name, durationToHarvest, price);
        // Tidak perlu try catch karena config pasti valid
    }
    
    cout << " > Finished Reading Plant Configuration" << endl;
    configFile.close();    
}

void Game::readConfigProduct(){
    ifstream configFile("config/product.txt");
    if (!configFile.is_open()) {
        throw FileNotFoundException("Failed to open product.txt");
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
    
    cout << " > Finished Reading Product Configuration" << endl;
    configFile.close();    
}

void Game::readConfigRecipe(){
    ifstream configFile("config/recipe.txt");
    if (!configFile.is_open()) {
        throw FileNotFoundException("Failed to open recipe.txt");
    }
    
    // TODO: READ RECIPE CONFIGURATION 
    resetTextColor();
    cout << "Warning: Recipe configuration is not been implemented" << endl;

    cout << " > Finished Reading Recipe Configuration" << endl;
    configFile.close(); 
}

void Game::readConfigMisc(){
    ifstream configFile("config/misc.txt");
    if (!configFile.is_open()) {
        throw FileNotFoundException("Failed to open misc.txt");
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
    
    cout << " > Finished Reading Misc Configuration" << endl;
    configFile.close();    
}