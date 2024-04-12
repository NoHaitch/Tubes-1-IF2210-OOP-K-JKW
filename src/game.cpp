#include "header/game.hpp"

using namespace std;

Game::Game(){
    shop = new Shop();
    mayor = nullptr;
    cout << endl;
    cout << setfill('=') << setw(50)  << "" << endl << setfill(' ');
    startTextBlue();
    cout << setw(32) << "Game Started" << endl;
    resetTextColor();
    cout << setfill('=') << setw(50)  << "" << endl << endl << setfill(' ');
}

Game::~Game(){
    if(mayor != nullptr){
        delete mayor;
    }

    delete shop;

    cout << endl;
    cout << setfill('=') << setw(50)  << "" << endl << setfill(' ');
    startTextRed();
    cout << setw(31) << "Game Exited" << endl;
    resetTextColor();
    cout << setfill('=') << setw(50)  << "" << endl << endl << setfill(' ');
}

void Game::nextTurn(){
    currTurn++;
    if(currTurn == playerOrder.size()){
        currTurn = 0;
    }
}

Player* Game::getPlayer(int playerId){
    int currPlayerId = playerOrder[currTurn];
    if(mayor->getId() == currPlayerId){
        return mayor;
    } else {
        for(int i = 0; i < farmers.size(); i++){
            if(farmers[i].getId() == currPlayerId){
                return &farmers[i];
            }
        }

        for(int i = 0; i < cattlemans.size(); i++){
            if(cattlemans[i].getId() == currTurn){
                return &cattlemans[i];
            }
        }

        throw PlayerNotFound();
    }
}

Player* Game::getCurrentPlayer(){
    return getPlayer(playerOrder[currTurn]);
}

void Game::initGameState(){
    mayor = new Mayor("Walikota", 50, 40);

    farmers = vector<Farmer>();
    farmers.push_back(Farmer("Petani1", 50, 40));
    
    cattlemans = vector<Cattleman>();
    cattlemans.push_back(Cattleman("Peternak1", 50, 40));

    addPlayerToTurnOrder("Walikota", (*mayor).getId());
    addPlayerToTurnOrder("Petani1", farmers.back().getId());
    addPlayerToTurnOrder("Peternak1", cattlemans.back().getId());
}

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

// TODO: Read Items
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

        if(playerRole == "Walikota"){
            mayor = new Mayor(playerUsername, playerMoney, playerWeight);
            addPlayerToTurnOrder(playerUsername, (*mayor).getId());

        } else if(playerRole == "Petani"){
            farmers = vector<Farmer>();
            farmers.push_back(Farmer(playerUsername, playerMoney, playerWeight));
            addPlayerToTurnOrder(playerUsername, farmers.back().getId());

        } else{ // Peternak
            cattlemans = vector<Cattleman>();
            cattlemans.push_back(Cattleman(playerUsername, playerMoney, playerWeight));
            addPlayerToTurnOrder(playerUsername, cattlemans.back().getId());
        }

        int playerItemCount = -1;
        
        getline(saveFile, line);
        iss = istringstream(line);
        iss >> playerItemCount;

        if(playerItemCount < 0){
            throw FileReadingFailedException();
        }

        // TODO: Player Items

        for(int item = 0; item < playerItemCount; item++){
            string itemName = "";
            getline(saveFile, line);
            iss = istringstream(line);
            iss >> itemName;

            if(itemName == ""){
                throw FileReadingFailedException();
            }
        }

        int playerRoleStorage = -1;
        
        getline(saveFile, line);
        iss = istringstream(line);
        iss >> playerRoleStorage;

        if(playerRoleStorage < 0){
            throw FileReadingFailedException();
        }

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

            }
        }
    }

    saveFile.close();    
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

void Game::addPlayerToTurnOrder(string playerName, int id){
    if(playerNames.empty()){
        playerOrder.push_back(id);
        playerNames.push_back(playerName);
    } else{
        int i = 0;
        int size = playerNames.size();
        for(; i < size; i++){
            if(playerName == playerNames[i] ){
                throw PlayerNameIsTakken();
                break;
            } else if(playerName < playerNames[i]){
                playerNames.insert(playerNames.begin() + i, playerName);
                playerOrder.insert(playerOrder.begin() + i, id);
                break;
            }
        }

        if(i == size){
            playerOrder.push_back(id);
            playerNames.push_back(playerName);
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
    while (getline(configFile, line)) {
        istringstream iss(line);
        iss >> id >> code >> name >> foodType >> weightToHarvest >> price;

        Animal::AddAnimalConfig(id, code, name, foodType, weightToHarvest, price);
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
    while (getline(configFile, line)) {
        istringstream iss(line);
        iss >> id >> code >> name >> type >> durationToHarvest >> price;
        
        Plant::addPlantConfig(id, code, type, name, durationToHarvest, price);
    }
    // Plant::printParsedConfig();
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
        
        Product::addProductConfig(id, code, type, name, origin, addedWeight, price);
    }
    // Product::printParsedConfig();

    cout << " > Finished Reading Product Configuration" << endl;
    configFile.close();    
}

void Game::readConfigRecipe(){
    ifstream configFile("config/recipe.txt");
    if (!configFile.is_open()) {
        throw FileNotFoundException("Failed to open recipe.txt");
    }
     

    string line; 
    while (getline(configFile, line)) {
        int id;
        string code;
        string name;
        int price;
        vector<string> material;
        vector<int> materialAmount;

        istringstream iss(line);
        iss >> id >> code >> name >> price;
        
        string materialName;
        int amount;
        while(true){
            materialName = "";
            amount = -1;
            iss >> materialName >> amount;
            if(materialName == "" || amount < 0){
                break;
            } else{
                material.push_back(materialName);
                materialAmount.push_back(amount);
            }
        }

        // Bangunan::addProductConfig(id, code, name, price, material, materialAmount);
    }

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
    iss >> storageHeight >> storageWidth ;

    getline(configFile, line);
    iss = istringstream(line);
    iss >> plantStorageHeight >> plantStorageWidth;
    
    getline(configFile, line);
    iss = istringstream(line);
    iss >> animalStorageHeight >> animalStorageWidth;

    Storage<string>::readConfigDefaultSize(make_pair(storageHeight, storageWidth));
    Storage<Animal>::readConfigDefaultSize(make_pair(animalStorageHeight, animalStorageWidth));
    Storage<Plant>::readConfigDefaultSize(make_pair(plantStorageHeight, plantStorageWidth));
    
    cout << " > Finished Reading Misc Configuration" << endl;
    configFile.close();    
}

void Game::printPlayerNames(){
    cout << "Player Names: " << endl;
    for(int i = 0; i < playerNames.size(); i++){
        cout << i + 1 << " " << playerNames[i] << endl;
    }
}

void Game::printPlayerTurnOrder(){
    cout << "Player Order: " << endl;
    for(int i = 0; i < playerOrder.size(); i++){
        cout << i + 1 << " " << getPlayer(playerOrder[i])->getUsername() << endl;
    }
}
