#include "header/game.hpp"

using namespace std;

Game::Game(){
    shop = new Shop();
    mayor = nullptr;

    day = 0;
    winWealth = -1;
    winWeight = -1;

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

int Game::getPlayerAmount(){
    return playerOrder.size();
}

void Game::nextTurn(){
    currTurn++;
    if(currTurn == playerOrder.size()){
        currTurn = 0;
        day++;
    }
    for (int i = 0; i < farmers.size(); i++) {
        farmers[i].incrementPlantDuration();
    }
}

void Game::nextTurnIO(){
    if(currTurn != -1){
        cout << "Giliran " << getCurrentPlayer()->getUsername() << " berakhir.\n" << endl;
    }
    nextTurn();
    cout << "===== Giliran " << getCurrentPlayer()->getUsername() << " dimulai =====" << endl;
}

int Game::playerCommandIO(){
    string input;
    startTextGreen();
    cout << "> ";
    cin >> input;
    resetTextColor();  
    
    // change input to lower case
    std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c){ return std::tolower(c); });
     
    try{
        if(input == "exit" ){
            return 1;
            
        } else if(input == "next"){
            return 2;

        } else if(input == "help" ){
            printCommands();

        } else if(input == "simpan" ){
            saveGameIO();

        } else if(input == "cetak_penyimpanan" ){
            getCurrentPlayer()->printItemStorage();
        
        } else if(input == "pungut_pajak" ){
            if(getCurrentPlayer()->getUsername() == mayor->getUsername()){
                // TODO: Pungut Pajak
            } else{
                throw CommandWrongRole("PUNGUT_PAJAK hanya dapat dilakukan oleh Walikota.");
            }
        
        } else if(input == "cetak_ladang" ){
            Farmer* farmerPtr = dynamic_cast<Farmer*>(getCurrentPlayer());
            if (farmerPtr) {
                farmerPtr->getLadang().printStorage();
                farmerPtr->printLegend();
            } else {
                throw CommandWrongRole("CETAK_LADANG hanya dapat dilakukan oleh Petani.");
            }
        
        } else if(input == "cetak_peternakan" ){
            Cattleman* cattlemanPtr = dynamic_cast<Cattleman*>(getCurrentPlayer());
            if (cattlemanPtr) {
                cattlemanPtr->getFarm().printStorage();
                cattlemanPtr->printLegend();
            } else {
                throw CommandWrongRole("CETAK_PETERNAKAN hanya dapat dilakukan oleh Peternak.");
            }
        
        } else if(input == "tanam" ){
            Farmer* farmerPtr = dynamic_cast<Farmer*>(getCurrentPlayer());
            if (farmerPtr) {
                farmerPtr->tanam();
            } else {
                throw CommandWrongRole("TANAM hanya dapat dilakukan oleh Petani.");
            }
        
        } else if(input == "ternak" ){
            Cattleman* cattlemanPtr = dynamic_cast<Cattleman*>(getCurrentPlayer());
            if (cattlemanPtr) {
                // TODO: Ternak
            } else {
                throw CommandWrongRole("TERNAK hanya dapat dilakukan oleh Peternak.");
            }
        
        } else if(input == "bangun" ){
            if(getCurrentPlayer()->getUsername() == mayor->getUsername()){
                // TODO: Bangun
            } else{
                throw CommandWrongRole("BANGUN hanya dapat dilakukan oleh Walikota.");
            }
        
        } else if(input == "makan" ){
            getCurrentPlayer()->eatFromStorage();

        } else if(input == "kasih_makan" ){
            Cattleman* cattlemanPtr = dynamic_cast<Cattleman*>(getCurrentPlayer());
            if (cattlemanPtr) {
                // TODO: Kasih Makanan Hewan
            } else {
                throw CommandWrongRole("KASIH_MAKAN hanya dapat dilakukan oleh Peternak.");
            }

        } else if(input == "beli" ){
            // getCurrentPlayer()->buy();
        
        } else if(input == "jual" ){
            // getCurrentPlayer()->sell();
        
        } else if(input == "panen" ){
            if(getCurrentPlayer()->getUsername() == mayor->getUsername()){
                throw CommandWrongRole("PANEN tidak dapat dilakukan oleh walikota.");
            } else{
                Farmer* farmerPtr = dynamic_cast<Farmer*>(getCurrentPlayer());
                if (farmerPtr) {
                    farmerPtr->panen();
                } else {
                    Cattleman* cattlemanPtr = dynamic_cast<Cattleman*>(getCurrentPlayer());
                    // cattlemanPtr->panen();
                }
            }
        
        } else{
            startTextRed();
            cout << "Command: " << input << " tidak dikenal. Gunakan 'HELP' untuk menunjukan semua Perintah." << endl;
            resetTextColor();
        }
    } catch (CommandWrongRole e){
        cout << e.what() << endl << endl;
    }

    return 0;
}

void Game::printCommands(){
    cout << "Daftar Perintah: " << endl;
    cout << " - HELP" << endl;
    cout << " - EXIT" << endl;
    cout << " - NEXT" << endl;
    cout << " - SIMPAN" << endl;
    cout << " - CETAK_PENYIMPANAN" << endl;
    cout << " - PUNGUT_PAJAK" << endl;
    cout << " - CETAK_LADANG" << endl;
    cout << " - CETAK_PETERNAKAN" << endl;
    cout << " - TANAM" << endl;
    cout << " - TERNAK" << endl;
    cout << " - BANGUN" << endl;
    cout << " - MAKAN" << endl;
    cout << " - KASIH_MAKAN" << endl;
    cout << " - BELI" << endl;
    cout << " - JUAL" << endl;
    cout << " - PANEN\n" << endl;
}

Player* Game::getPlayer(string playerUsername){
    if(mayor->getUsername() == playerUsername){
        return mayor;
    } else {
        for(int i = 0; i < farmers.size(); i++){
            if(farmers[i].getUsername() == playerUsername){
                return &farmers[i];
            }
        }

        for(int i = 0; i < cattlemans.size(); i++){
            if(cattlemans[i].getUsername() == playerUsername){
                return &cattlemans[i];
            }
        }

        throw PlayerNotFound();
    }
}

bool Game::checkWinningCondition(){
    Player* player = getCurrentPlayer();
    return player->getWealth() >= winWealth && player->getCurrWeight() >= winWeight;
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

    addPlayerToTurnOrder("Walikota");
    addPlayerToTurnOrder("Petani1");
    addPlayerToTurnOrder("Peternak1");
}

void Game::getGameStateIO(){
    string input;
    int choice = 0;
    while(1){
        cout << setfill('=') << setw(21);

        cout << " Menu "; 
        resetTextColor();
        cout << setw(15) << "" << endl << setfill(' ');
        cout << "Pilih Opsi Menu:" << endl;
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

    cout << "Berhasil membuat game state.\n" << endl;
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

    farmers = vector<Farmer>();
    cattlemans = vector<Cattleman>();

    for(int player = 0; player < amountOfPlayer; player++){
        string playerUsername;
        string playerRole;
        int playerWeight = -1;
        int playerWealth = -1;
        
        getline(saveFile, line);
        iss = istringstream(line);
        iss >> playerUsername >> playerRole >> playerWeight >> playerWealth;

        if(playerWeight < 0 | playerWealth < 0){
            throw FileReadingFailedException();
        }

        if(playerRole == "Walikota"){
            mayor = new Mayor(playerUsername, playerWealth, playerWeight);
            addPlayerToTurnOrder(playerUsername);

        } else if(playerRole == "Petani"){
            farmers.push_back(Farmer(playerUsername, playerWealth, playerWeight));
            addPlayerToTurnOrder(playerUsername);

        } else{ // Peternak
            cattlemans.push_back(Cattleman(playerUsername, playerWealth, playerWeight));
            addPlayerToTurnOrder(playerUsername);
        }

        int playerItemCount = -1;
        
        getline(saveFile, line);
        iss = istringstream(line);
        iss >> playerItemCount;

        if(playerItemCount < 0){
            throw FileReadingFailedException();
        }

        // TODO: Player Items

        Player* playerPointer = getPlayer(playerUsername);
        for(int item = 0; item < playerItemCount; item++){
            string itemName = "";
            getline(saveFile, line);
            iss = istringstream(line);
            iss >> itemName;

            if(itemName == ""){
                throw FileReadingFailedException();
            } else {
                playerPointer->getItemStorage().insertElmtAtEmptySlot(itemName);
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
            Farmer* farmerPtr = dynamic_cast<Farmer*>(getPlayer(playerUsername));
            if (farmerPtr) {
                for(int item = 0; item < playerRoleStorage; item++){
                    string location = "";
                    string itemName = "";
                    int progress = -1;

                    getline(saveFile, line);
                    iss = istringstream(line);
                    iss >> location >> itemName >> progress;

                    if(location == "" || itemName == "" || progress < 0){
                        throw FileReadingFailedException();
                    } else {
                        string plantCode = Plant::getPlantNameToCodeConfig()[itemName];
                        Plant* plantPtr = new Plant(plantCode);
                        plantPtr->setCurrentDuration(progress);
                        farmerPtr->getLadang().insertElmtAtPosition(location, plantPtr);
                    }
                }
            } else {
                Cattleman* cattlemanPtr = dynamic_cast<Cattleman*>(getPlayer(playerUsername));
                for(int item = 0; item < playerRoleStorage; item++){
                    string location = "";
                    string itemName = "";
                    int progress = -1;

                    getline(saveFile, line);
                    iss = istringstream(line);
                    iss >> location >> itemName >> progress;

                    if(location == "" || itemName == "" || progress < 0){
                        throw FileReadingFailedException();
                    } else {
                        string animalCode = Animal::getAnimalNameToCodeConfig()[itemName];
                        Animal* animalPtr = new Animal(animalCode);
                        animalPtr->setCurrWeight(progress);
                        cattlemanPtr->getFarm().insertElmtAtPosition(location, animalPtr);
                    }
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

    // TODO : Read Toko Configuration

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

// TODO: Save Items
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

    saveFile << getPlayerAmount() << endl;

    // Save Cattlemans
    for(int i = 0; i < cattlemans.size(); i++){
        saveFile << cattlemans[i].getUsername() << " Peternak "<< cattlemans[i].getCurrWeight() << " " << cattlemans[i].getWealth() << endl;
    }

    // Save Farmers
    for(int i = 0; i < farmers.size(); i++){
        saveFile << farmers[i].getUsername() << " Petani "<< farmers[i].getCurrWeight() << " " << farmers[i].getWealth() << endl;
    }

    // Save Mayor
    saveFile << mayor->getUsername() << " Walikota " << mayor->getCurrWeight() << " " << mayor->getWealth() << endl;

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

void Game::addPlayerToTurnOrder(string playerName){
    if(playerOrder.empty()){
        playerOrder.push_back(playerName);
    } else{
        int i = 0;
        int size = playerOrder.size();
        for(; i < size; i++){
            if(playerName == playerOrder[i] ){
                throw PlayerNameIsTakken();
                break;
            } else if(playerName < playerOrder[i]){
                playerOrder.insert(playerOrder.begin() + i, playerName);
                break;
            }
        }

        if(i == size){
            playerOrder.push_back(playerName);
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
    
    int id;                         // Building ID
    string code;                    // Building code
    string name;                    // Building name
    int price;                      // Building price
    int quantity;                   // Material quantity
    string material;                // Material name
    vector<Building> building;      // Vector of building

    string line;
    Building tempBuilding;
    while (getline(configFile, line)){
        istringstream iss(line);
        if (!(iss >> id >> code >> name >> price)) {
            throw FileFormatException();
        }
        tempBuilding.addBuildingConfig(id, code, name, price);

        while (iss >> material >> quantity){
            tempBuilding.addMaterials(code, material, quantity);
        }

        building.push_back(tempBuilding);

    cout << " > Finished Reading Recipe Configuration" << endl;
    configFile.close(); 
    }
}

void Game::readConfigMisc(){
    ifstream configFile("config/misc.txt");
    if (!configFile.is_open()) {
        throw FileNotFoundException("Failed to open misc.txt");
    }
    
    int winningWealth;                               // Jumlah uang pemain untuk menang
    int winningWeight;                              // Jumlah berat badan pemain untuk menang
    int storageWidth, storageHeight;                // Besaran penyimpanan
    int plantStorageWidth, plantStorageHeight;      // Besaran lahan
    int animalStorageWidth, animalStorageHeight;    // Besaran peternakan

    string line; 
    getline(configFile, line);
    istringstream iss(line);
    iss >> winningWealth;

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
    winWealth = winningWealth;
    winWeight = winningWeight;

    cout << " > Finished Reading Misc Configuration" << endl;
    configFile.close();    
}

void Game::printWinner(){
    Player* player = getCurrentPlayer();
    cout << "Permainan telah dimenangkan!" << endl;
    startTextGreen();
    cout << player->getUsername() << " menang!" << endl;
    resetTextColor();
}

void Game::printPlayerTurnOrder(){
    cout << "Player Order: " << endl;
    for(int i = 0; i < playerOrder.size(); i++){
        cout << i + 1 << " " << playerOrder[i] << endl;
    }
}
