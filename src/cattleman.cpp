#include "header/cattleman.hpp"
#include "header/playerException.hpp"

Cattleman::Cattleman(string _username) : Player(_username){}

Cattleman::Cattleman(string _username, int _wealth, int _currWeight) 
    : Player(_username, _wealth, _currWeight){}

Cattleman::~Cattleman(){}

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
        cout << "Pilih petak tanah yang akan ditinggali" << endl;
        cout << endl;
        Farm.printStorage();
        try {
            cout << "Petak tanah: ";
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

    // Both inputs valid, do moving operation
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
    // Waiting for function to check if an animal can eat a certain food
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