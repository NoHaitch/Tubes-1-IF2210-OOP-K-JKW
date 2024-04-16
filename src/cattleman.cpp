#include "header/cattleman.hpp"

Cattleman::Cattleman(string _username) : Player(_username), Farm(){}

Cattleman::Cattleman(string _username, int _wealth, int _currWeight) 
    : Player(_username, _wealth, _currWeight), Farm(){}

Cattleman::~Cattleman(){}

Storage<Animal> Cattleman::getFarm(){
    return Farm;
}

Storage<Animal>* Cattleman::getFarmPointer(){
    return &Farm;
}

int Cattleman::calculateKKP(){
    int res = Player::calculateWealth();
    for (int i=0; i<Farm.getNumRow(); i++){
        for (int j=0; j<Farm.getNumCol(); j++){
            if (Farm.isEmpty(i, j)){
                continue;
            }
            Animal* a = Farm.getElmt(i,j);
            
            res += Animal::getAnimalPriceConfig()[a->getCode()];
        }
    }
    res -= 11; //KTKP
    return res;
}

void Cattleman::buy(Shop* shopPtr){
    // check if storage full, cancel this command
    if (ItemStorage.isStorageFull()){
        throw CommandCannotBeDoneException("Penyimpanan sudah penuh! tidak bisa membeli barang baru!");
    }

    // check if shopPtr is a black market object
    bool isBlackMarket;
    BlackMarket* BMPtr = dynamic_cast<BlackMarket*>(shopPtr);
    if(BMPtr == nullptr){
        isBlackMarket = false;
    } else {
        isBlackMarket = true;
    }

    cout << "Uang anda : " << wealth << endl;
    int availableSlot = ItemStorage.getNumRow() * ItemStorage.getNumCol() - ItemStorage.getNumElmt();
    cout << "Slot penyimpanan tersedia : " << availableSlot << endl;
    cout << endl;

    // Validate variables
    bool valid;
    int buySelection = -1, buyQuantity = -1, payment;
    string itemCode;

    // Validate selection input
    valid = false;
    while (!valid){
        try{
            cout << "Barang ingin dibeli : ";
            cin >> buySelection;
            if (buySelection < 1){
                throw InputInvalidException("Nomor barang kurang dari daftar diatas");
            } else {
                itemCode = shopPtr->getItemCodeFromIndex(buySelection);
                valid = true;
            }
        } catch(InputInvalidException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        }
    }

    // Validate quantity input
    valid = false;
    while (!valid){
        try{
            cout << "Kuantitas : ";
            cin >> buyQuantity;
            if (buyQuantity < 1 || buyQuantity > shopPtr->getItemQuantity(itemCode)){
                throw InputInvalidException("Kuantitas tidak sesuai dengan banyak stok di toko");
            } else {
                if (isBlackMarket){
                    payment = BMPtr->getPriceBlackMarket(itemCode, true) * buyQuantity;
                } else {
                    payment = shopPtr->getPriceFromCode(itemCode) * buyQuantity;
                }
                if (buyQuantity > availableSlot){
                    throw NotEnoughSlotException("Penyimpanan mu tidak cukup untuk memebeli barang sebanyak ini! Silahkan kurangi kuantitas");
                } else {
                    if (payment > wealth){
                        if (isBlackMarket){
                            throw NotEnoughMoneyException("Kamu tidak cukup kaya untuk berada di Black Market ini! Cepat keluar dari sini!");
                        } else {
                            throw NotEnoughMoneyException();
                        }
                    } else {
                        if (isBlackMarket){
                            if (!BMPtr->isInfinite(itemCode)){
                                BMPtr->decreaseQty(itemCode, buyQuantity);
                            }
                        } else {
                            if (!shopPtr->isInfinite(itemCode)){
                                shopPtr->decreaseQty(itemCode, buyQuantity);
                            }
                        }
                        wealth -= payment;
                        string itemName = shopPtr->getNameFromCode(itemCode);
                        cout << "Selamat Anda berhasil membeli " << buyQuantity <<" " << itemName <<". Uang Anda tersisa " << wealth << " gulden." << endl;
                        valid = true;
                    }
                }
            }
        } catch(InputInvalidException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        } catch(NotEnoughMoneyException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        } catch(NotEnoughSlotException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        }
    }

    // Simpan barang
    cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
    ItemStorage.printStorage();
    
    // Validasi input slot penyimpanan
    string inputSlots;
    valid = false;
    vector<string> slotVector;
    while (!valid){
        try{
            cout << "Petak slot: ";
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, inputSlots);
            cout << endl;
            slotVector = parseSlot(inputSlots);
            bool isPositionValid = true;
            if (slotVector.size() == buyQuantity){
                for (int i=0; i<slotVector.size(); i++){
                    cout << "TEST FARHAN1" << endl;
                    try {
                        pair<int, int>temp = ItemStorage.translatePositionCode(slotVector[i]);
                    } catch (PositionCodeInvalidException e) {
                        cout << e.what() << endl << endl;
                        isPositionValid = false;
                        break;
                    }
                    if (ItemStorage.isEmpty(slotVector[i])){
                        cout << "TEST FARHAN2" << endl;
                        ItemStorage.insertElmtAtPosition(slotVector[i], itemCode);
                    } else {
                        throw StorageSlotException("Slot sudah terisi, pilih slot lain yang kosong");
                    }
                }
                valid = true;
            } else {
                throw InputInvalidException("Banyaknya slot yang diinputkan tidak sesuai dengan banyak barang yang dibeli");
            }
        } catch(InputInvalidException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        } catch(PositionCodeInvalidException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        } catch(StorageSlotException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        }
    }
    cout << itemCode << " berhasil disimpan dalam penyimpanan!" << endl;
}

void Cattleman::sell(Shop* shopPtr){
    // Check if shopPtr is a black market object
    bool isBlackMarket;
    BlackMarket* BMPtr = dynamic_cast<BlackMarket*>(shopPtr);
    if(BMPtr == nullptr){
        isBlackMarket = false;
    } else {
        isBlackMarket = true;
    }

    // Interface
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    ItemStorage.printStorage();
    cout << endl;
    cout << "Silahkan pilih petak yang ingin Anda jual!";
    bool valid = false;
    string inputSlots;
    string* itemCodePtr, itemCode;
    vector<string> slotVector;
    while (!valid){
        try{
            cout << "Petak slot: ";
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, inputSlots);
            cout << endl;
            slotVector = parseSlot(inputSlots);
            if (slotVector.size() > 0){
                for (int i=0; i<slotVector.size(); i++){
                    if (!ItemStorage.isEmpty(slotVector[i])){
                        itemCodePtr = ItemStorage.getElmt(slotVector[i]);
                        itemCode = *itemCodePtr;
                        if (itemType(itemCodePtr)=="Building"){
                            throw IllegalActionException("Peternak tidak boleh menjual bangunan!");
                        } else {
                            valid = true;
                        }
                    } else {
                        throw StorageSlotException("Slot yang dimasukkan kosong, Silahkan masukkan slot yang telah terisi");
                    }
                }
            } else {
                throw InputInvalidException("Tidak ada slot yang diinputkan");
            }
        } catch(InputInvalidException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        }
        catch(PositionCodeInvalidException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        }catch(StorageSlotException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        }catch(IllegalActionException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        }
    }

    // Input already valid, do transaction
    int profit=0;
    for (int i=0; i<slotVector.size(); i++){
        itemCodePtr = ItemStorage.getElmt(slotVector[i]);
        itemCode = *itemCodePtr;
        ItemStorage.deleteElmtAtPosition(slotVector[i]);
        if (isBlackMarket){
            profit += BMPtr->getPriceBlackMarket(itemCode, false);
            if (!shopPtr->isInfinite(itemCode)){
                BMPtr->increaseQty(itemCode, 1);
            }
        } else {
            profit += shopPtr->getPriceFromCode(itemCode);
            if (!shopPtr->isInfinite(itemCode)){
                shopPtr->increaseQty(itemCode, 1);
            }
        }
    }
    wealth += profit;
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << profit << " gulden!" << endl;
}

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
            if (itemTypeAtIndex(i, j) == "Animal"){
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
                if (itemTypeAtIndex(storageCode) == "Animal"){
                    animalCode = *ItemStorage.getElmt(storageCode);
                    valid = true;
                } else {
                    throw NotAnimalException();
                }
            }
        } catch (NotAnimalException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        } catch (StorageSlotException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
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
        } catch (StorageSlotException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
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
    string animalCode, farmCode, storageCode, *productCode, foodCode;
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
                animalCode = (*Farm.getElmt(farmCode)).getCode();
                animalName = (*Farm.getElmt(farmCode)).getName();
                cout << "Kamu memilih " << animalName << " untuk diberi makan." << endl;
                valid = true;
            }
        } catch (StorageSlotException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        }
    }

    Animal tempAnimal(animalCode);

    // Check if no food for animal exists
    found = false;
    for (int i=0; i<ItemStorage.getNumRow(); i++){
        for (int j=0; j<ItemStorage.getNumCol(); j++){
            if (itemTypeAtIndex(i, j) == "Product"){ // Check if current Item is a product // Check if this animal can eat the product  
                productCode = ItemStorage.getElmt(i,j);
                if(productCode == nullptr){
                    continue;
                }

                if (tempAnimal.canEat(*productCode)){
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
                if (itemTypeAtIndex(storageCode) == "Product"){
                    foodCode = *ItemStorage.getElmt(storageCode);
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
        } catch (StorageSlotException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        } catch (InedibleProductException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        } catch (NotProductException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        }
    }

    // Both inputs are valid, do feeding procedure
    ItemStorage.deleteElmtAtPosition(storageCode);
    addWeight = Product::getProductAddedWeightMapConfig()[foodCode];
    newWeight = addWeight + (*Farm.getElmt(farmCode)).getCurrWeight();
    (*Farm.getElmt(farmCode)).setCurrWeight(newWeight);
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
                animalCode = (*Farm.getElmt(i,j)).getCode();
                retMap[animalCode].first++;
                if ((*Farm.getElmt(i,j)).isReadyToHarvest()){
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
                cout << " - " << Farm.translatePositionCode(i,j) << ": " << (*Farm.getElmt(i,j)).getName() << endl;
            }
        }
    }
    cout << endl;
}

void Cattleman::harvestAnimal(){
    string positionCode;
    // Validasi apakah ada tanaman di Farm
    if (Farm.getNumElmt() == 0) {
        cout << "Tidak ada tanaman pada Farm. Tidak dapat melakukan panen\n" << endl;
        return;
    }

    map<string, int> plantReadyToHarvest; // <plant code, number of plants>
    for (int i = 0; i < Animal::getAnimalCodeConfig().size(); i++) {
        plantReadyToHarvest[Animal::getAnimalCodeConfig()[i]] = 0;
    }
    // Validasi apakah ada tanaman di Farm yang siap panen
    int readyForHarvest = 0;
    for (int i = 0; i < Farm.getNumRow(); i++) {
        for (int j = 0; j < Farm.getNumCol(); j++) {
            if (!Farm.isEmpty(i, j)) {
                cout << Farm.getElmt(i, j)->getCode() << endl;
                cout << Farm.getElmt(i, j)->getCurrWeight() << endl;
                cout << Farm.getElmt(i, j)->getWeightToHarvest() << endl;
                if ((*Farm.getElmt(i, j)).getCurrWeight() >= (*Farm.getElmt(i, j)).getWeightToHarvest()) {
                    readyForHarvest++;
                    plantReadyToHarvest[(*Farm.getElmt(i, j)).getCode()]++;
                }
            }
        }
    }
    // Validasi minimal ada tanaman yang bisa dipanen
    if (readyForHarvest == 0) {
        cout << "Tidak ada hewan yang siap dipanen" << endl;
        return;
    }

    Farm.printStorage();
    int num = 0;
    cout << "Pilih tanaman siap panen yang kamu miliki: " << endl;
    map<int, string> penomoran;
    for (map<string, int>::iterator it = plantReadyToHarvest.begin(); it != plantReadyToHarvest.end(); it++) {
        if (it->second > 0) {
            penomoran[num + 1] = it->first;
            cout << " " << num + 1 << ". " << it->first << " (" << it->second << " petak siap panen)" << endl;
            num++;
        }
    } cout << endl;

    int choosenPlant = -1, numOfPlantChoosen = -1;
    while (true) {
        cout << "Nomor hewan yang ingin dipanen: ";
        cin >> choosenPlant;
        if(choosenPlant <= 0 || choosenPlant > num){
            cout << "Jumlah tidak valid\n" << endl;
            continue;
        }

        cout << "Berapa petak yang ingin dipanen: ";
        cin >> numOfPlantChoosen;

        if(numOfPlantChoosen <= 0){
            cout << "Jumlah petak tidak valid\n" << endl;
            continue;
        }

        // Cek apakah jumlah tanaman yang dipilih valid
        if (numOfPlantChoosen > plantReadyToHarvest[penomoran[choosenPlant]]) {
            cout << "Jumlah tanaman yang dipilih melebihi tanaman yang bisa dipanen!" << endl;
            continue;
        }
        // Cek apakah storage cukup untuk menyimpan hasil panen
        if (ItemStorage.getNumElmt() + numOfPlantChoosen > ItemStorage.getNumRow() * ItemStorage.getNumCol()) {
            cout << "Jumlah penyimpanan tidak cukup!" << endl;
            continue;
        }

        break;
    }

    // Semua validasi sudah selesai
    string pos;
    vector <string> choosenPosition;
    cout << "Pilih petak yang ingin dipanen:" << endl;
    for (int i = 0; i < numOfPlantChoosen; i++) {
        while (true) {
            cout << " - Petak ke-" << i + 1 << ": ";
            cin >> pos;
            try {
                pair<int, int> position = Farm.translatePositionCode(pos);
            } catch (PositionCodeInvalidException &e) {
                cout << "Petak tidak valid!\n" << endl;
                continue;
            }
            if(Farm.isEmpty(pos)){
                cout << "Petak yang dipilih kosong!\n" << endl;
                continue;
            }

            if ((*Farm.getElmt(pos)).getCode() == penomoran[choosenPlant]) {
                cout << "masuk" << endl;
                vector <string> convertedProductCodes = Product::convertToProductCode((*Farm.getElmt(pos)).getName());
                cout << convertedProductCodes.size() << endl;
                for (int j = 0; j < convertedProductCodes.size(); j++) {
                    Product P = Product(convertedProductCodes[j]);
                    cout << "convert" << endl;
                    ItemStorage + P.getCode();
                    cout << "add" << endl;
                    Farm.deleteElmtAtPosition(pos);
                    cout << "delete" << endl;
                    choosenPosition.push_back(pos);
                }
                break;
            } else {
                cout << "Tanaman yang dipilih tidak sesuai" << endl;
            }
        }
    }

    cout << endl << numOfPlantChoosen << " petak tanaman " << penomoran[choosenPlant] << " pada petak ";
    for (int i = 0; i < choosenPosition.size(); i++) {
        cout << choosenPosition[i];
        if (i != choosenPosition.size() - 1) {
            cout << ", ";
        }
    }
    cout << " telah dipanen!" << endl;

}