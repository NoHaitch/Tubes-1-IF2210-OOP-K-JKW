#include "header/mayor.hpp"

Mayor::Mayor(string _username) :
        Player(_username),
        buildingInCity(){}

Mayor::Mayor(string _username, int _wealth, int _currWeight) :
        Player(_username, _wealth, _currWeight),
        buildingInCity(){}

Mayor::~Mayor(){}

void Mayor::pungutPajak(vector<Farmer>* farmers, vector<Cattleman>* cattlemans){
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl;
    cout << endl << "Berikut adalah detil dari pemungutan pajak:" << endl;
    vector<string> player;
    vector<string> playerType;
    vector<int> tax;

    // Urutan player = urutan tax = urutan player type
    for (int i = 0; i < farmers->size(); i++){
        int pajak = farmers->at(i).calculateTax(farmers->at(i).calculateKKP());
        if (farmers->at(i).getWealth() < pajak) {
            pajak = farmers->at(i).getWealth();
        }
        player.push_back(farmers->at(i).getUsername());
        playerType.push_back("Petani");
        tax.push_back(pajak);
        farmers->at(i).payTax();
        wealth += pajak;
    }
    for (int i = 0; i < cattlemans->size(); i++) {
        int pajak = cattlemans->at(i).calculateTax(cattlemans->at(i).calculateKKP());
        if (cattlemans->at(i).getWealth() < pajak) {
            pajak = cattlemans->at(i).getWealth();
        }
        player.push_back(cattlemans->at(i).getUsername());
        playerType.push_back("Peternak");
        tax.push_back(pajak);
        cattlemans->at(i).payTax();
        wealth += pajak;
    }

    // Sorting berdasarkan besar pajak
    for (int i = 0; i < tax.size(); i++){
        for (int j = i+1; j < tax.size(); j++){
            if (tax[i] < tax[j]){
                swap(tax[i], tax[j]);
                swap(player[i], player[j]);
                swap(playerType[i], playerType[j]);
            }
        }
    }

    // Print detail pajak
    for (int i = 0; i < tax.size(); i++) {
        cout << i+1 << ". " << player[i] << " - " << playerType[i] << ": " << tax[i] << " gulden" << endl;
    }
}

int Mayor::calculateKKP(){
    return 0;
}

string Mayor::tambahPemain(vector<Farmer>* farmers, vector<Cattleman>* cattlemans){
    if (wealth<50){
        throw NotEnoughMoney("Uang tidak cukup untuk menambah pemain!");
    }
    else {
        string playerType, plName;
        // Periksa jenis pemain yg dimasukkan
        while (true) {
            cout << "Masukkan jenis pemain: ";
            cin >> playerType;
            if (!(playerType == "peternak" || playerType == "petani")) {
                cout << "Jenis pemain salah!" << endl;
                continue;
            } else {
                break;
            }
        }

        // Cek apakah nama pemain sudah ada
        while (true) {
            cout << "Masukkan nama pemain: ";
            cin >> plName;
            bool isExist = false;
            if (plName == username) {
                cout << "Nama pemain sudah ada!" << endl << endl;
                continue;
            } else if (plName.empty()) {
                cout << "Nama pemain tidak valid!" << endl << endl;
                continue;
            }
            // cek di farmers
            for (int i = 0; i < farmers->size(); i++) {
                if (plName == farmers->at(i).getUsername()) {
                    cout << "Nama pemain sudah ada!" << endl << endl;
                    isExist = true;
                    break;
                }
            }
            for (int i = 0; i < cattlemans->size(); i++) {
                if (plName == cattlemans->at(i).getUsername()) {
                    cout << "Nama pemain sudah ada!" << endl << endl;
                    isExist = true;
                    break;
                }
            }
            if (isExist) {
                continue;
            } else {
                break;
            }
        }


        if (playerType == "peternak"){
            Cattleman peternak(plName);
            cattlemans->push_back(peternak);
        }
        else {
            Farmer petani(plName);
            farmers->push_back(petani);
        }
        cout << "Pemain baru ditambahkan!\n"
                "Selamat datang \"" << plName << "\" di kota ini!" << endl << endl;
        wealth -= 50;
        return plName;
    }
}


void Mayor::operator+(Building B) {
    buildingInCity.push_back(B);
    ItemStorage.insertElmtAtEmptySlot(B.getCode());
}

void Mayor::bangunBangunan(){
    while (true){
        Building::displayBuilding();
        string namaBangunan;
        cout << endl << "Bangunan yang ingin dibangun: ";
        cin >> namaBangunan;

        // Cek apakah input jenis bangunan valid
        map<string, string> buildingNameConfig = Building::getBuildingNameConfig();
        bool found = false;
        for (map<string, string>::iterator it = buildingNameConfig.begin(); it != buildingNameConfig.end(); it++){
            if (it->second == namaBangunan){
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Resep bangunan tidak ditemukan!" << endl << endl;
        }

        // Cek apakah bahan cukup
        string codeBuilding = convertItemNameToCode(namaBangunan);
        map<string, int> materials = Building::getCertainBuildingMaterialConfig(codeBuilding);
        bool isEnough = true;
        map<string, int> playerStorage = getNumberofItemStorage();
        map<string, int> kurangItem;
        for (map<string, int>::iterator it = materials.begin(); it != materials.end(); it++){
            if (playerStorage.find(it->first) == playerStorage.end()) {
                kurangItem[it->first] = it->second;
                isEnough = false;
            }
            if (playerStorage[it->first] < it->second){
                kurangItem[it->first] = it->second - playerStorage[it->first];
                isEnough = false;
            }
        }

        if (!isEnough) {
            cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";
            for (map<string, int>::iterator it = kurangItem.begin(); it != kurangItem.end(); it++){
                cout << it->second << " " << convertItemCodeToName(it->first);
                if (next(it) != kurangItem.end()){
                    cout << ", ";
                }
                else {
                    cout << "!" << endl << endl;
                }
            }
            continue;
        } else {
            // Kurangi bahan, sudah pasti cukup
            for (map<string, int>::iterator it = materials.begin(); it != materials.end(); it++){
                for (int i = 0; i < it->second; i++){
                    for (int j = 0; j < ItemStorage.getNumRow(); j++){
                        for (int k = 0; k < ItemStorage.getNumCol(); k++){
                            if (ItemStorage.getElmt(j, k) != nullptr && *ItemStorage.getElmt(j, k) == it->first){
                                ItemStorage.deleteElmtAtPosition(ItemStorage.translatePositionCode(j, k));
                                break;
                            }
                        }
                    }
                }
            }
            Building B(codeBuilding);
            *this + B;
            cout << namaBangunan << " berhasil dibangun dan telah menjadi milik walikota!" << endl << endl;
            break;
        }
    }
}

void Mayor::buy(){
    int emptySlot = (this->ItemStorage.getNumCol()*this->ItemStorage.getNumRow()) - this->ItemStorage.getNumElmt();
    if (emptySlot == 0){
        cout << "Tidak bisa membeli barang! Penyimpanan sudah penuh" << endl;
        return;
    }


    // TODO tampilkan semua item yang bisa dibeli

    cout << "Uang Anda: " << this->wealth << endl;
    cout << "Slot penyimpanan tersedia: " << emptySlot << endl;
    int choice;

    while (true){
        try {
            cout << endl << "Barang ingin dibeli: ";
            cin >> choice;

            // TODO cek apakah choice valid
            if (choice != 1){ // choice invalid
                cout << "Pilihan barang tidak ada!" << endl;
                continue;
            }
            else {
                int kuantitas;
                cout << "Kuantitas: ";
                cin >> kuantitas;
                if (kuantitas > emptySlot){
                    cout << "Penyimpanan tidak cukup untuk membeli " << kuantitas << "barang" << endl;
                    continue;
                }

            }
        } catch (PositionCodeInvalidException e){
            cout << e.what() << endl;
        } catch (exception e){
            cout << "Pilihan tidak tersedia" << endl;
        }
    }
}

void Mayor::sell(){

}