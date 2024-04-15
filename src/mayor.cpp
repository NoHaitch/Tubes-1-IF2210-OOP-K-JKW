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



int Mayor::calculateKKP(){
    return 0;
}

void Mayor::bangunBangunan(){
    Building::displayBuilding();
}

void Mayor::buy(){
    
}

void Mayor::sell(){
    
}