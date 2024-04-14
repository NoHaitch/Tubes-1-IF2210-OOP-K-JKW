#include "header/cattleman.hpp"

Cattleman::Cattleman(string _username) : Player(_username), Farm(){}

Cattleman::Cattleman(string _username, int _wealth, int _currWeight) 
    : Player(_username, _wealth, _currWeight), Farm(){}

Cattleman::~Cattleman(){}

Storage<Animal> Cattleman::getFarm(){
    return Farm;
}

int Cattleman::calculateKKP(){
    int res = Player::calculateWealth();
    for (int i=0; i<Farm.getNumRow(); i++){
        for (int j=0; j<Farm.getNumCol(); j++){
            if (Farm.isEmpty(i, j)){
                continue;
            }
            Animal a = Farm.getElmt(i,j);
            res += Animal::getAnimalPriceConfig()[a.getCode()];
        }
    }
    res -= 11; //KTKP
    return res;
}

// TODO: buy() and sell()

void Cattleman::farming(){
    // Check if Farm is full
    if (Farm.isStorageFull()){
        throw CommandCannotBeDoneException("Command tidak dapat dijalankan karena Peternakan sudah penuh!");
        return;
    }
    // Check if there is no animal in ItemStorage
    bool found = false;
    for (int i=0; i<ItemStorage.getNumRow(); i++){
        for (int j=0; j<ItemStorage.getNumCol(); j++){
            if (itemType(i, j) == "Animal"){
                found = true;
                break;
            }
        }
        if (found){
            break;
        }
    }
    if (!found){
        throw CommandCannotBeDoneException("Command tidak dapat dijalankan karena kamu tidak punya binatang!");
        return;
    }

    // Command can be done
    bool valid = false;
    string animalCode, farmCode, storageCode;

    // storageCode validation
    while (!valid){
        cout << "Pilih hewan dari penyimpanan" << endl;
        cout << endl;
        ItemStorage.printStorage();
        try {
            cout << "Slot: ";
            cin >> storageCode;
            cout << endl;
            if (ItemStorage.isEmpty(storageCode)){
                throw StorageSlotException("Slot yang dipilih kosong! \n Silahkan pilih slot yang berisi binatang \n");
            } else {
                if (itemType(storageCode) == "Animal"){
                    animalCode = ItemStorage.getElmt(storageCode);
                    valid = true;
                } else {
                    throw NotAnimalException();
                }
            }
        } catch (exception e){
            cout << e.what() << endl;
        }
    }

    // farmCode validation
    valid = false;
    while (!valid){
        cout << "Pilih petak kandang yang akan ditinggali" << endl;
        cout << endl;
        Farm.printStorage();
        try {
            cout << "Petak kandang: ";
            cin >> farmCode;
            cout << endl;
            if (Farm.isEmpty(farmCode)){
                valid = true;
            } else {
                throw StorageSlotException("Petak yang dipilih sudah terisi! \n Silahkan pilih petak yang masih kosong \n");
            }
        } catch (exception e){
            cout << e.what() << endl;
        }
    }

    // Both inputs valid, do farming procedure
    Farm.insertElmtAtPosition(farmCode, animalCode);
    ItemStorage.deleteElmtAtPosition(storageCode);
    string animalName = Animal::getAnimalNameConfig()[animalCode];
    cout << "Dengan hati-hati, kamu meletakkan seekor " << animalName << " di kandang." << endl;
    cout << endl;
    cout << animalName << " telah menjadi peliharaanmu sekarang!" << endl;
    cout << endl;
    return;
}

void Cattleman::feeding(){
    // Check if farm is empty 
    bool found = false;
    for (int i=0; i<Farm.getNumRow(); i++){
        for (int j=0; j<Farm.getNumCol(); j++){
            if (!Farm.isEmpty(i, j)){ 
                found = true;
                break;
            }
        }
        if (found){
            break;
        }
    }
    if (!found){
        throw CommandCannotBeDoneException("Command tidak dapat dijalankan karena kamu tidak memiliki hewan di peternakan");
        return;
    }

    // Local Variable
    bool valid;
    string animalCode, farmCode, storageCode, productCode, foodCode;
    string animalName;
    int newWeight, addWeight;

    // farmCode Validation
    valid = false;
    while (!valid){
        cout << "Pilih binatang yang ingin diberi pangan" << endl;
        cout << endl;
        Farm.printStorage();
        try {
            cout << "Petak kandang: ";
            cin >> farmCode;
            cout << endl;
            if (Farm.isEmpty(farmCode)){
                throw StorageSlotException("Petak yang dipilih kosong! \n Silahkan pilih petak yang berisi binatang\n");
            } else {
                animalCode = Farm.getElmt(farmCode).getCode();
                animalName = Farm.getElmt(farmCode).getName();
                cout << "Kamu memilih " << animalName << " untuk diberi makan." << endl;
                valid = true;
            }
        } catch (exception e){
            cout << e.what() << endl;
        }
    }

    Animal tempAnimal(animalCode);

    // Check if no food for animal exists
    found = false;
    for (int i=0; i<ItemStorage.getNumRow(); i++){
        for (int j=0; j<ItemStorage.getNumCol(); j++){
            if (itemType(i, j) == "Product"){ // Check if current Item is a product // Check if this animal can eat the product  
                productCode = ItemStorage.getElmt(i,j);
                if (tempAnimal.canEat(productCode)){
                    found = true;
                    break;
                }
            }
        }
        if (found){
            break;
        }
    }
    if (!found){
        throw CommandCannotBeDoneException("Command tidak dapat dijalankan karena tidak ada makanan untuk hewan ini");
        return;
    }

    // Validate foodCode
    valid = false;
    while (!valid){
        cout << "Pilih pangan yang akan diberikan:" << endl;
        cout << endl;
        ItemStorage.printStorage();
        try {
            cout << "Slot: ";
            cin >> storageCode;
            cout << endl;
            if (ItemStorage.isEmpty(storageCode)){
                throw StorageSlotException("Slot yang dipilih kosong! \n Silahkan pilih slot yang berisi produk makanan \n");
            } else {
                if (itemType(storageCode) == "Product"){
                    foodCode = ItemStorage.getElmt(storageCode);
                    if (tempAnimal.canEat(foodCode)){
                        cout << "Kamu memilih makanan " << Product::getProductNameMapConfig()[foodCode] << endl;
                        valid = true;
                    } else {
                        throw InedibleProductException("Hewan tidak bisa memakan produk ini!");
                    }
                } else {
                    throw NotProductException();
                }
            }
        } catch (exception e){
            cout << e.what() << endl;
        }
    }

    // Both inputs are valid, do feeding procedure
    ItemStorage.deleteElmtAtPosition(storageCode);
    addWeight = Product::getProductAddedWeightMapConfig()[foodCode];
    newWeight = addWeight + Farm.getElmt(farmCode).getCurrWeight();
    Farm.getElmt(farmCode).setCurrWeight(newWeight);
    cout << animalName << " sudah diberi makan dan beratnya menjadi " << newWeight << endl;
    return;
}

map<string, pair<int,int>> Cattleman::countAnimalsAndHarvestable(){
    map<string, pair<int,int>> retMap;

    // Initialize map
    for (int i = 0; i < Animal::getAnimalCodeConfig().size(); i++) {
        retMap[Animal::getAnimalCodeConfig()[i]] = make_pair(0,0);
    }

    // Loop through all Animals on storage
    string animalCode;
    for (int i=0; i<Farm.getNumRow(); i++){
        for (int j=0; j<Farm.getNumCol(); j++){
            if (!Farm.isEmpty(i,j)){
                animalCode = Farm.getElmt(i,j).getCode();
                retMap[animalCode].first++;
                if (Farm.getElmt(i,j).isReadyToHarvest()){
                    retMap[animalCode].second++;
                }
            }
        }
    }
    return retMap;
}  

void Cattleman::printLegend(){
    for(int i=0; i<Farm.getNumRow(); i++){
        for(int j=0; j<Farm.getNumCol(); j++){
            if (!Farm.isEmpty(i,j)){
                cout << " - " << Farm.translatePositionCode(i,j) << ": " << Farm.getElmt(i,j).getName() << endl;
            }
        }
    }
    cout << endl;
}

void Cattleman::harvestAnimal(){
    bool found;

    // Check if Storage is full
    if (ItemStorage.isStorageFull()){
        throw CommandCannotBeDoneException("Command tidak dapat dijalankan karena storage sudah penuh");
        return;
    }

    // Check if farm is empty 
    found = false;
    for (int i=0; i<Farm.getNumRow(); i++){
        for (int j=0; j<Farm.getNumCol(); j++){
            if (!Farm.isEmpty(i, j)){ 
                found = true;
                break;
            }
        }
        if (found){
            break;
        }
    }
    if (!found){
        throw CommandCannotBeDoneException("Command tidak dapat dijalankan karena kamu tidak memiliki hewan di peternakan");
        return;
    }

    // Print farm
    cout << endl;
    Farm.printStorage();
    printLegend();

    // Print Harvestable Animal List
    cout << "Pilih hewan siap panen yang kamu miliki" << endl;
    map<string, pair<int,int>> numMap = countAnimalsAndHarvestable();
    map<string, pair<int,int>>::iterator it = numMap.begin();
    int idx = 1;
    vector<string> harvestableCodes;
    harvestableCodes.push_back("");
    while (it != numMap.end()){
        if (it->second.second > 0){
            harvestableCodes.push_back(it->first);
            cout << "    " << idx << ". " << it->first << " (" << it->second.second << " petak siap panen)" << endl;
            idx++;
        }
        ++it;
    }
    cout << endl;

    // Validation variables
    bool valid;
    int indexInput, numToHarvestInput, numHarvestable;
    string animalCode;

    // Validate index number
    valid = false;
    while (!valid){
        try {
            cout << "Nomor hewan yang ingin dipanen: ";
            cin >> indexInput;
            cout << endl;
            if (indexInput >= 1 && indexInput <= idx){
                animalCode = harvestableCodes[indexInput];
                numHarvestable = numMap[animalCode].second;
                valid = true;
            } else {
                throw InputInvalidException("Nomor hewan tidak sesuai daftar diatas");
            }
        } catch (exception e){
            cout << e.what() << endl;
        }
    }

    // Validate index number
    valid = false;
    while (!valid){
        try {
            cout << "Berapa petak yang ingin dipanen: ";
            cin >> numToHarvestInput;
            cout << endl;
            if (numToHarvestInput >= 1 && numToHarvestInput <= numHarvestable){
                if (ItemStorage.getNumElmt() + numToHarvestInput <= ItemStorage.getNumRow() * ItemStorage.getNumCol()){
                    valid = true;
                } else {
                    ItemStorage.printStorage();
                    throw NotEnoughSlotException("Jumlah penyimpanan tidak cukup!");
                }
            } else {
                throw InputInvalidException("Banyak petak yang ingin dipanen tidak sesuai dengan banyaknya hewan yang bisa dipanen");
            }
        } catch (exception e){
            cout << e.what() << endl;
        }
    }

    // Validate & Harvest postionCode
    int doneHarvested = 1;
    string farmPositionCode, productCode;
    vector<string> selectionList;
    cout << "Pilih petak yang ingin dipanen: " << endl;
    while (doneHarvested <= numToHarvestInput){
        valid = false;
        while (!valid){
            try {
                cout << "Petak ke-" << doneHarvested << ": ";
                cin >> farmPositionCode;
                cout << endl;
                if (Farm.getElmt(farmPositionCode).getCode() == animalCode){
                    if (Farm.getElmt(farmPositionCode).isReadyToHarvest()){

                        // Inputs are valid, Do Harvesting process
                        Product newProduct = Product::convertToProduct(animalCode);
                        productCode = newProduct.getCode();
                        ItemStorage.insertElmtAtEmptySlot(productCode);
                        Farm.deleteElmtAtPosition(farmPositionCode);
                        selectionList.push_back(farmPositionCode);
                    } else {
                        throw NotHarvestableException("Binatang pada kode posisi tersebut tidak dapat dipanen");
                    }
                } else {
                    throw InputInvalidException("Binatang pada kode posisi tersebut berbeda dari jenis yang dipilih");
                }
                valid = true;
            } catch (exception e){
                cout << e.what() << endl;
            }
        }
        doneHarvested++;
    }
    cout << numToHarvestInput << " petak hewan " << animalCode << " pada petak ";
    cout << selectionList[0];
    for (int i=1; i<numToHarvestInput; i++){
        cout << ", " << selectionList[i];
    }
    cout << " telah dipanen!" << endl;
    return;
}