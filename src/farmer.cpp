#include "header/farmer.hpp"

Farmer::Farmer(string _username) : Player(_username), Ladang(){

}

Farmer::Farmer(string _username, int _wealth, int _currWeight) : Player(_username, _wealth, _currWeight), Ladang() {

}

Farmer::~Farmer() {
    
}

bool Farmer::isLadangFull() {
    return Ladang.isStorageFull();
}

Storage<Plant> Farmer::getLadang() {
    return Ladang;
}

Storage<Plant>* Farmer::getLadangPointer() {
    return &Ladang;
}

bool Farmer::isLadangSlotEmpty(string idx) {
    return ItemStorage.isEmpty(idx);
}


void Farmer::tanam() {
    string positionCode;
    // Cek prekondisi apakah ada tanaman pada inventory
    int numPlant = 0;
    for (int i = 0; i < ItemStorage.getNumRow(); i++) {
        for (int j = 0; j < ItemStorage.getNumCol(); j++) {
            if (itemTypeAtIndex(i, j) == "Plant") {
                numPlant++;
            }
        }
    }
    if (numPlant == 0) {
        cout << "Tidak ada tanaman pada penyimpanan" << endl;
        return;
    }

    // Cek apakah ladang sudah penuh
    if (isLadangFull()) {
        cout << "Ladang sudah penuh" << endl;
        return;
    }

    cout << "Pilih tanaman dari penyimpanan" << endl;
    ItemStorage.printStorage();
    // Lakukan loop sampai item yang dipilih benar
    while (true) {
        cout << "Petak: ";
        cin >> positionCode;
        try {
            // Ambil tanaman dari slot penyimpanan
            if (ItemStorage.isEmpty(positionCode)) {
                cout << "Item tidak ditemukan di penyimpanan" << endl;
                continue;
            } else {
                if (itemTypeAtIndex(positionCode) != "Plant") {
                    cout << "Item yang dipilih bukan tanaman" << endl;
                } else {
                    Plant P = Plant(*ItemStorage.getElmt(positionCode));
                    cout << "Kamu memilih tanaman " << P.getPlantName() << endl;
                    // Ambil posisi pada ladang untuk ditanam
                    string positionLadang;
                    Ladang.printStorage();
                    while (true) {
                        cout << endl << "Petak tanah: ";
                        cin >> positionLadang;
                        // Cek apakah slot pada ladang kosong
                        if (!Ladang.isEmpty(positionLadang)) {
                            cout << "Slot pada ladang sudah terisi" << endl;
                        } else {
                            // Tanam tanaman pada ladang
                            Ladang.insertElmtAtPosition(positionLadang, P.getCode());
                            
                            cout << "Cangkul, cangkul, cangkul yang dalam~!\n" << P.getPlantName() <<
                                 " berhasil ditanam!" << endl;
                            ItemStorage.deleteElmtAtPosition(positionCode);
                            break;
                        }
                    }
                    break;
                }
            }
        } catch (PositionCodeInvalidException e) {
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
            continue;
        } catch (InputInvalidException e) {
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
            continue;
        }
    }
}


Plant* Farmer::getItem(string idx) {
    return Ladang.getElmt(idx);
}

void Farmer::printLegend(){
    map<string, int> numMap;
    string plantCode;
    for (int i = 0; i < Plant::getPlantCodeListConfig().size(); i++) {
        numMap[Plant::getPlantCodeListConfig()[i]] = 0;
    }
    for (int i=0; i<Ladang.getNumRow(); i++){
        for (int j=0; j<Ladang.getNumCol(); j++){
            if (!Ladang.isEmpty(i,j)){
                plantCode = (*Ladang.getElmt(i,j)).getCode();
                numMap[plantCode]++;
            }
        }
    }
    for (int i = 0; i < Plant::getPlantCodeListConfig().size(); i++) {
        plantCode = Plant::getPlantCodeListConfig()[i];
        if (numMap[plantCode] > 0){
            cout << " - " << plantCode << ": " << Plant::getPlantNameMapConfig()[plantCode] << endl;
        }
    }
    cout << endl;
}

void Farmer::panen() {
    string positionCode;
    // Validasi apakah ada tanaman di ladang
    if (Ladang.getNumElmt() == 0) {
        cout << "Tidak ada tanaman pada ladang. Tidak dapat melakukan panen\n" << endl;
        return;
    }

    map<string, int> plantReadyToHarvest; // <plant code, number of plants>
    for (int i = 0; i < Plant::getPlantCodeListConfig().size(); i++) {
        plantReadyToHarvest[Plant::getPlantCodeListConfig()[i]] = 0;
    }
    // Validasi apakah ada tanaman di ladang yang siap panen
    int readyForHarvest = 0;
    for (int i = 0; i < Ladang.getNumRow(); i++) {
        for (int j = 0; j < Ladang.getNumCol(); j++) {
            if (!Ladang.isEmpty(i, j)) {
                if ((*Ladang.getElmt(i, j)).isReadyToHarvest()) {
                    readyForHarvest++;
                    plantReadyToHarvest[(*Ladang.getElmt(i, j)).getCode()]++;
                }
            }
        }
    }
    // Validasi minimal ada tanaman yang bisa dipanen
    if (readyForHarvest == 0) {
        cout << "Tidak ada tanaman yang siap dipanen" << endl;
        return;
    }

    Ladang.printStorage();
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
        cout << "Nomor tanaman yang ingin dipanen: ";
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
                pair<int, int> position = Ladang.translatePositionCode(pos);
            } catch (PositionCodeInvalidException &e) {
                cout << "Petak tidak valid!\n" << endl;
                continue;
            }
            if(Ladang.isEmpty(pos)){
                cout << "Petak yang dipilih kosong!\n" << endl;
                continue;
            }

            if ((*Ladang.getElmt(pos)).getCode() == penomoran[choosenPlant]) {
                vector <string> convertedProductCodes = Product::convertToProductCode((*Ladang.getElmt(pos)).getPlantName());
                for (int j = 0; j < convertedProductCodes.size(); j++) {
                    Product P = Product(convertedProductCodes[j]);
                    ItemStorage + P.getCode();
                    Ladang.deleteElmtAtPosition(pos);
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

void Farmer::buy(Shop* shopPtr) {
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
    int buySelection, buyQuantity, payment;
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
            if (slotVector.size() == buyQuantity){
                for (int i=0; i<slotVector.size(); i++){
                    if (ItemStorage.isEmpty(slotVector[i])){
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
        }
        catch(PositionCodeInvalidException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        }catch(StorageSlotException e){
            startTextRed();
            cout << e.what() << endl;
            resetTextColor();
        }
    }
    cout << itemCode << " berhasil disimpan dalam penyimpanan!" << endl;
}

void Farmer::sell(Shop* shopPtr) {
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
                            throw IllegalActionException("Petani tidak boleh menjual bangunan!");
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
            cout << e.what() << endl;
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

void Farmer::incrementPlantDuration() {
    for (int i = 0; i < Ladang.getNumRow(); i++) {
        for (int j = 0; j < Ladang.getNumCol(); j++) {
            if (!Ladang.isEmpty(i, j)) {
                (*Ladang.getElmt(i, j)).incrementCurrentDuration();
            }
        }
    }
}

int Farmer::calculateKKP() {
    int res = Player::calculateWealth();
    for (int i=0; i<Ladang.getNumRow(); i++){
        for (int j=0; j<Ladang.getNumCol(); j++){
            if (Ladang.isEmpty(i, j)){
                continue;
            }
            Plant a = *Ladang.getElmt(i,j);
            res += Plant::getPlantPriceMapConfig()[a.getCode()];
        }
    }
    res -= 13; //KTKP
    return res;
}