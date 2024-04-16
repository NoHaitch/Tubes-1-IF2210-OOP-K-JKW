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
            cout << e.what() << endl;
            continue;
        } catch (exception e) {
            cout << "Input posisi tidak valid!" << endl;
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

void Farmer::buy() {
    int emptySlot = (ItemStorage.getNumCol() * ItemStorage.getNumRow()) - ItemStorage.getNumElmt();
    if (emptySlot == 0) {
        cout << "Tidak bisa membeli barang! Penyimpanan sudah penuh" << endl;
        return;
    }
    cout << "Selamat datang di toko!" << endl << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    cout << "Uang Anda: " << wealth << endl;
    cout << "Slot penyimpanan tersedia: " << emptySlot << endl;
    int choice;
    while (true) {
        try {
            cout << endl << "Barang ingin dibeli: ";
            cin >> choice;
            // TODO validasi apakah choice ada di pilihan
            if (choice != 0) {
                continue;
            } else {
                int kuantitas;
                cout << "Kuantitas: ";
                cin >> kuantitas;
                if (kuantitas > emptySlot) {
                    cout << "Penyimpanan tidak cukup untuk membeli " << kuantitas << " barang" << endl;
                    continue;
                }
                else {

                }
            }
        } catch (PositionCodeInvalidException e) {
            cout << e.what() << endl;
        } 
        
        catch (exception e) {
            cout << "Pilihan tidak tersedia!" << endl;
        }
    }
}

void Farmer::sell() {
    if (ItemStorage.getNumElmt() == 0) {
        cout << "Penyimpanan tidak cukup untuk membeli barang" << endl;
        return;
    }
    bool notAllDone = true;
    while (notAllDone) {
        cout << "Berikut penyimpanan Anda" << endl;
        ItemStorage.printStorage();

        cout << "Silahkan pilih petak yang ingin Anda jual" << endl;
        string positionCode;
        cin >> positionCode;
        vector <string> position;
        string temp;
        // Kemungkinan bisa pilih lebih dari 1 petak
        for (int i = 0; i < positionCode.size(); i++) {
            if (positionCode[i] == ',') {
                position.push_back(temp);
                continue;
            } else if (positionCode[i] == ' ') {
                continue;
            } else {
                temp += positionCode[i];
            }
        }
        if (position.size() < ItemStorage.getNumElmt()) {
            cout << "Pilihan tidak valid" << endl;
            continue;
        }
        // Cek terlebih dahulu apakah salah satu posisi dari input valid
        try {
            for (int i = 0; i < position.size(); i++) {
                if (ItemStorage.isEmpty(position[i])) {
                    cout << "Item pada posisi " << position[i] << " kosong!" << endl;
                    notAllDone = true; // Masuk loop lagi
                    break;
                }
                if (Player::itemTypeAtIndex(position[i]) == "Building") {
                    cout << "Tidak bisa menjual bangunan pada petak" << position[i] << endl;
                    notAllDone = true;
                    break;
                } else {
                    string itemCode = (*ItemStorage.getElmt(positionCode));
                    // TODO : implementasi ke shop
                    cout << "Item " << itemCode << " berhasil dijual" << endl;
                    if (i == position.size() - 1) {
                        notAllDone = false;
                    }
                }
            }
            if (!notAllDone) {
                break;
            }
        } catch (PositionCodeInvalidException e) {
            cout << e.what() << endl;
            return;
        } catch (exception e) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }
    }
}

void Farmer::buyBlackMarket() {
    int emptySlot = (ItemStorage.getNumCol() * ItemStorage.getNumRow()) - ItemStorage.getNumElmt();
    if (emptySlot == 0) {
        cout << "Tidak bisa membeli barang! Penyimpanan sudah penuh" << endl;
        return;
    }
}

void Farmer::sellBlackMarket() {
    if (ItemStorage.getNumElmt() == 0) {
        startTextRed();
        cout << "Tidak ada barang untuk dijual!" << endl;
        resetTextColor();
        return;
    }
    bool notAllDone = true;
    while (notAllDone) {
        cout << "Berikut penyimpanan Anda" << endl;
        ItemStorage.printStorage();

        cout << "Silahkan pilih petak yang ingin Anda jual" << endl;
        string positionCode;
        cin >> positionCode;
        vector <string> position;
        string temp;
        // Kemungkinan bisa pilih lebih dari 1 petak
        for (int i = 0; i < positionCode.size(); i++) {
            if (positionCode[i] == ',') {
                position.push_back(temp);
                continue;
            } else if (positionCode[i] == ' ') {
                continue;
            } else {
                temp += positionCode[i];
            }
        }
        if (position.size() < ItemStorage.getNumElmt()) {
            cout << "Pilihan tidak valid" << endl;
            continue;
        }
        // Cek terlebih dahulu apakah salah satu posisi dari input valid
        try {
            for (int i = 0; i < position.size(); i++) {
                if (ItemStorage.isEmpty(position[i])) {
                    cout << "Item pada posisi " << position[i] << " kosong!" << endl;
                    notAllDone = true; // Masuk loop lagi
                    break;
                }
                if (Player::itemTypeAtIndex(position[i]) == "Building") {
                    cout << "Tidak bisa menjual bangunan pada petak" << position[i] << endl;
                    notAllDone = true;
                    break;
                } else {
                    string itemCode = *ItemStorage.getElmt(positionCode);
                    // TODO : implementasi ke shop
                    cout << "Item " << itemCode << " berhasil dijual" << endl;
                    if (i == position.size() - 1) {
                        notAllDone = false;
                    }
                }
            }
            if (!notAllDone) {
                break;
            }
        } catch (PositionCodeInvalidException e) {
            cout << e.what() << endl;
            return;
        } catch (exception e) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }
    }

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