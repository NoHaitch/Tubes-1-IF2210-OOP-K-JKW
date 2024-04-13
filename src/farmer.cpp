#include "header/farmer.hpp"

Farmer::Farmer(string _username) : Player(_username), Ladang(){
    numberOfHarvestablePlant = map<string, int>();
    for (int i = 0; i < Plant::getPlantCodeListConfig().size(); i++) {
        numberOfHarvestablePlant[Plant::getPlantCodeListConfig()[i]] = 0;
    }
}

Farmer::Farmer(string _username, int _wealth, int _currWeight) : Player(_username, _wealth, _currWeight), Ladang() {
    numberOfHarvestablePlant = map<string, int>();
    for (int i = 0; i < Plant::getPlantCodeListConfig().size(); i++) {
        numberOfHarvestablePlant[Plant::getPlantCodeListConfig()[i]] = 0;
    }
}

Farmer::~Farmer() {
    
}

bool Farmer::isLadangFull() {
    return Ladang.isStorageFull();
}

Storage<Plant> Farmer::getLadang() {
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
                this->Ladang.printStorage();
                while (true) {
                    cout << endl << "Petak tanah: ";
                    cin >> positionLadang;
                    // Cek apakah slot pada ladang kosong
                    if (!this->Ladang.isEmpty(positionLadang)) {
                        cout << "Slot pada ladang sudah terisi" << endl;
                    } else {
                        // Tanam tanaman pada ladang
                        this->Ladang.insertElmtAtPosition(positionLadang, P.getCode());
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


Plant Farmer::getItem(string idx) {
    return this->Ladang.getElmt(idx);
}


void Farmer::panen() {
    string positionCode;
    // Validasi apakah ada tanaman di ladang
    if (this->Ladang.getNumElmt() == 0) {
        startTextRed();
        cout << "Tidak ada tanaman pada ladang. Tidak dapat melakukan panen" << endl;
        resetTextColor();
        return;
    }

    map<string, int> plantReadyToHarvest; // <plant code, number of plants>
    // Validasi apakah ada tanaman di ladang yang siap panen
    int readyForHarvest = 0;
    for (int i = 0; i < this->Ladang.getNumRow(); i++) {
        for (int j = 0; j < this->Ladang.getNumCol(); j++) {
            string pos = to_string(i) + to_string(j);
            if (!this->Ladang.isEmpty(pos)) {
                if (this->Ladang.getElmt(i, j).isReadyToHarvest()) {
                    readyForHarvest++;
                    this->numberOfHarvestablePlant[this->Ladang.getElmt(i, j).getCode()]++;
                }
            }
        }
    }
    // Validasi minimal ada tanaman yang bisa dipanen
    if (readyForHarvest == 0) {
        cout << "Tidak ada tanaman yang siap dipanen" << endl;
        return;
    }

    this->Ladang.printStorage();
    int num = 1;
    cout << "Pilih tanaman siap panen yang kamu miliki" << endl;
    map<int, string> penomoran;
    for (map<string, int>::iterator it = this->numberOfHarvestablePlant.begin(); it != this->numberOfHarvestablePlant.end(); ++it) {
        if (it->second > 0) {
            penomoran[num] = it->first;
            cout << num << ". " << it->first << " (" << it->second << " petak siap panen)" << endl;
            num++;
        }
    }
    int choosenPlant, numOfPlantChoosen;
    while (true) {
        cout << "Nomor tanaman yang ingin dipanen: ";
        try {
            cin >> choosenPlant;

        } catch (exception &e) {
            cout << "Input harus berupa angka" << endl;
            continue;
        }
        try {
            cout << "Berapa petak yang ingin dipanen: ";
            cin >> numOfPlantChoosen;
            // Cek apakah jumlah tanaman yang dipilih valid
            if (numOfPlantChoosen > this->numberOfHarvestablePlant[penomoran[choosenPlant]]) {
                cout << "Jumlah tanaman yang dipilih melebihi tanaman yang bisa dipanen!" << endl;
                continue;
            }
            // Cek apakah storage cukup untuk menyimpan hasil panen
            if (this->ItemStorage.getNumElmt() + numOfPlantChoosen > this->ItemStorage.getNumRow() * this->ItemStorage.getNumCol()) {
                cout << "Jumlah penyimpanan tidak cukup!" << endl;
                continue;
            }
        } catch (exception &e) {
            cout << "Input harus berupa angka" << endl;
        }
        break;
    }

    // Semua validasi sudah selesai
    string pos;
    vector <string> choosenPosition;
    cout << "Pilih petak yang ingin dipanen:" << endl;
    for (int i = 0; i < numOfPlantChoosen; i++) {
        while (true) {
            cout << "Petak ke-" << i + 1 << ": ";
            cin >> pos;
            try {
                pair<int, int> position = this->Ladang.translatePositionCode(pos);
            } catch (PositionCodeInvalidException &e) {
                cout << "Petak tidak valid!" << endl;
                continue;
            }
            if (this->Ladang.getElmt(pos).getCode() == penomoran[choosenPlant]) {
                this->ItemStorage.insertElmtAtEmptySlot(this->Ladang.getElmt(pos).getCode());
                this->Ladang.deleteElmtAtPosition(pos);
                choosenPosition.push_back(pos);
                break;
            } else {
                cout << "Tanaman yang dipilih tidak sesuai" << endl;
            }
        }
    }

    cout << numOfPlantChoosen << " petak tanaman pada";
    for (int i = 0; i< choosenPosition.size(); i++) {
        cout << choosenPosition[i];
        if (i != choosenPosition.size() - 1) {
            cout << ", ";
        }
    }
    cout << " telah dipanen!" << endl;

}

void Farmer::buy() {
    // TODO implement buy
}

void Farmer::sell() {
    // TODO implement sell
}

void Farmer::incrementPlantDuration() {
    for (int i = 0; i < this->Ladang.getNumRow(); i++) {
        for (int j = 0; j < this->Ladang.getNumCol(); j++) {
            if (!this->Ladang.isEmpty(i, j)) {
                this->Ladang.getElmt(i, j).incrementCurrentDuration();
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
            Plant a = Ladang.getElmt(i,j);
            res += Plant::getPlantPriceMapConfig()[a.getCode()];
        }
    }
    res -= 13; //KTKP
    return res;
}