#include "header/farmer.hpp"

Farmer::Farmer(string _username) : Player(_username) {
    Ladang = new Storage<Plant>();
}

Farmer::Farmer(string _username, int _wealth, int _currWeight) : Player(_username, _wealth, _currWeight) {
    Ladang = new Storage<Plant>();
}

Farmer::~Farmer() {
    delete Ladang;
}

bool Farmer::isLadangFull() {
    return Ladang->isStorageFull();
}

Storage<Plant> *Farmer::getLadang() {
    return Ladang;
}

bool Farmer::isLadangSlotEmpty(string idx) {
    return this->ItemStorage.isEmpty(idx);
}


void Farmer::tanam() {
    string positionCode;
    // Cek prekondisi apakah ada tanaman pada inventory
    int numPlant = 0;
    for (int i = 0; i < this->ItemStorage.getNumRow(); i++) {
        for (int j = 0; j < this->ItemStorage.getNumCol(); j++) {
            string pos = to_string(i) + to_string(j);
            if (this->itemType(i, j) == "Plant") {
                numPlant++;
            }
        }
    }
    if (numPlant == 0) {
        cout << "Tidak ada tanaman pada penyimpanan" << endl;
        return;
    }

    // Cek apakah ladang sudah penuh
    if (this->isLadangFull()) {
        cout << "Ladang sudah penuh" << endl;
        return;
    }

    cout << "Pilih tanaman dari penyimpanan" << endl;
    this->ItemStorage.printStorage();
    // Lakukan loop sampai item yang dipilih benar
    while (true) {
        cout << "Slot: ";
        cin >> positionCode;
        // Ambil tanaman dari slot penyimpanan
        if (this->ItemStorage.isEmpty(positionCode)) {
            cout << "Item tidak ditemukan di penyimpanan" << endl;
        } else {
            if (this->itemType(positionCode) != "Plant") {
                cout << "Item yang dipilih bukan tanaman" << endl;
            } else {
                Plant P = Plant(this->ItemStorage.getElmt(positionCode));
                cout << "Kamu memilih tanaman" << P.getPlantName() << endl;
                // Ambil posisi pada ladang untuk ditanam
                string positionLadang;
                while (true) {
                    cout << endl << "Petak tanah: ";
                    cin >> positionLadang;
                    // Cek apakah slot pada ladang kosong
                    if (!this->Ladang->isEmpty(positionLadang)) {
                        cout << "Slot pada ladang sudah terisi" << endl;
                    } else {
                        // Tanam tanaman pada ladang
                        this->Ladang->insertElmtAtPosition(positionLadang, P.getCode());
                        cout << "Cangkul, cangkul, cangkul yang dalam~!\n" << P.getPlantName() <<
                             " berhasil ditanam!" << endl;
                        this->ItemStorage.deleteElmtAtPosition(positionCode);
                        break;
                    }
                }
                break;
            }
        }
    }
}



//int main() {
//    Plant p("OOP");
//    Farmer f("Farmer");
//
//    f.tanam();
//    return 0;
//}