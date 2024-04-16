#include "header/mayor.hpp"

Mayor::Mayor(string _username) :
    Player(_username),
    buildingForSale(){}

Mayor::Mayor(string _username, int _wealth, int _currWeight) :
    Player(_username, _wealth, _currWeight),
    buildingForSale(){}

Mayor::~Mayor(){}

void Mayor::pungutPajak(){
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl;
    cout << endl << "Berikut adalah detil dari pemungutan pajak:" << endl;

}

int Mayor::calculateKKP(){
    return 0;
}

void Mayor::tambahPemain(){
    if (wealth<50){
        cout << "Uang tidak cukup!" << endl;
    }
    else {
        string playerType, plName;
        cout << "Masukkan jenis pemain: ";
        cin >> playerType;
        if (!(playerType == "peternak" || playerType == "petani")){
            cout << "Jenis pemain salah!" << endl;
            return;
        }
        cout << "Masukkan nama pemain: ";
        cin >> plName;
        // periksa apakah nama sudah digunakan

        if (playerType == "peternak"){
            Cattleman peternak(plName);
            // pushback peternak ke vector cattleman di game
        }
        else {
            Farmer petani(plName);
            // pushback petani ke vector farmer di game
        }
    }
}




void Mayor::bangunBangunan(){
    while (true){
        Building::displayBuilding();
        string jenisBangunan;
        cout << endl << "Bangunan yang ingin dibangun: ";
        cin >> jenisBangunan;
        

        map<string, string> buildingNameConfig = Building::getBuildingNameConfig();
        auto it = buildingNameConfig.find(jenisBangunan);
        if (it == buildingNameConfig.end()){
            cout << "Kamu tidak punya resep bangunan tersebut!" << endl;
            continue;
        }

        


    }
}

void Mayor::buy(){
    int emptySlot = (this->ItemStorage.getNumCol()*this->ItemStorage.getNumRow()) - this->ItemStorage.getNumElmt();
    if (emptySlot == 0){
        cout << "Tidak bisa membeli barang! Penyimpanan sudah penuh" << endl;
        return;
    }
    cout << "Selamat datang di toko!" << endl << "Berikut merupakan hal yang dapat Anda Beli" << endl;
   
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