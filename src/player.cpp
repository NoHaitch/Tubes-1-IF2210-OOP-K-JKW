#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
#include <sstream>

#include "header/utils.hpp"
#include "header/player.hpp"
#include "header/storage.hpp"
#include "header/product.hpp"
#include "header/building.hpp"
#include "header/playerException.hpp"

using namespace std;

int Player::numPlayer = 0;

Player::Player(string _userName) : Player(_userName, DefaultPlayerStartingWealth, DefaultPlayerStartingWeight){}

Player::Player(string _username, int _wealth, int _currWeight) :
    id(numPlayer),
    username(_username),
    wealth(_wealth),
    currWeight(_currWeight),
    ItemStorage()
    {
        Player::numPlayer++;
    }

Player::~Player(){}

int Player::getId() const{
    return this->id;
}

string Player::getUsername() const{
    return this->username;
}

int Player::getWealth() const{
    return this->wealth;
}

int Player::getCurrWeight() const{
    return this->currWeight;
}

Storage<string> Player::getItemStorage(){
    return this->ItemStorage;
}

void Player::setWealth(int _wealth){
    this->wealth = _wealth;
}

void Player::setCurrWeight(int _currWeight){
    this->currWeight = _currWeight;
}

void Player::printItemStorage(){
    this->ItemStorage.printStorage();
}

void Player::eatFromStorage(){
    // Validasi apakah ada makanan di penyimpanan
    if (ItemStorage.isStorageEmpty()){
        cout << "Penyimpanan kamu kosong. Kamu tidak bisa makan apa-apa" << endl << endl;
        return;
    }
    map<string, int> numberItemStorage = getNumberofItemStorage();
    int edible = 0;
    for (int i = 0; i < ItemStorage.getNumRow(); i++) {
        for (int j = 0; j < ItemStorage.getNumCol(); j++) {
            if (itemTypeAtIndex(i, j) == "Product") {
                Product P = Product(*ItemStorage.getElmt(i, j));
                if (Product::isEdible(P)) {
                    edible++;
                }
            }
        }
    }
    if (edible < 1) {
        cout << "Tidak ada makanan yang bisa dimakan dari penyimpanan!" << endl << endl;
        return;
    }

    cout << "Pilih makanan dari penyimpanan" << endl;
    cout << endl;
    printItemStorage();
    bool valid = false;
    string inputCode, selectedItem;
    while (!valid){
        try {
            cout << "Slot: ";
            cin >> inputCode;
            if (ItemStorage.isEmpty(inputCode)){
                throw StorageSlotException("Kamu mengambil harapan kosong dari penyimpanan. \n Silahkan masukan slot yang berisi makanan. \n"); 
            } else {
                selectedItem = *ItemStorage.getElmt(inputCode);
                if (itemTypeAtIndex(inputCode)=="Product"){
                    Product selectedProduct(selectedItem);
                    if (Product::isEdible(selectedProduct)){
                        ItemStorage.deleteElmtAtPosition(inputCode);
                        currWeight += selectedProduct.getAddedWeight();
                        valid = true;
                        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
                        cout << "Alhasil, berat badan kamu naik menjadi " << currWeight << endl;
                    } else {
                        throw InedibleProductException("Apa yang kamu lakukan?? !! Kamu mencoba untuk memakan itu?!! \n Silahkan masukan slot yang berisi makanan. \n");
                    }
                } else {
                    throw NotProductException("Benda tersebut bukan produk!! Bagaimana bisa kamu makan?? !! \n Silahkan masukan slot yang berisi makanan. \n");
                }
            }
        } catch (exception e){
            cout << e.what() << endl;
            cout << endl;
        }
    }
}

void Player::buy(Shop* shopPtr){}

void Player::sell(Shop* shopPtr){}

string Player::itemTypeAtIndex(string positionCode) {
    return itemType(ItemStorage.getElmt(positionCode));
}

string Player::itemTypeAtIndex(int y, int x) {
    return itemType(ItemStorage.getElmt(y, x));
}

int Player::calculateTax(int KKP){
    if (KKP <= 0){ //KKP = 0 hasil pajaknya juga 0
        return 0;
    } else {
        double div;
        int pajak;
        if (KKP <= 6){
            div = (double) KKP * 5 / 100;
        } else if (KKP > 6 && KKP <= 25){
            div = (double) KKP * 15 / 100;
        } else if (KKP > 25 && KKP <= 50){
            div = (double) KKP * 25 / 100;
        } else if (KKP > 50 && KKP <= 500){
            div = (double) KKP * 30 / 100;
        } else {
            div = (double) KKP * 35 / 100;
        }
        pajak = (int) ceil(div);
        return pajak;
    }
}

void Player::payTax(){
    int KKP = calculateKKP();
    int pajak = calculateTax(KKP);
    wealth = max(0, wealth - pajak);
}

int Player::calculateWealth(){
    int ans = wealth;
    for (int i=0; i<ItemStorage.getNumRow(); i++){
        for (int j=0; j<ItemStorage.getNumCol(); j++){
            if (ItemStorage.isEmpty(i, j)){
                continue;
            }
            string itemCode = *ItemStorage.getElmt(i, j);
            if (itemTypeAtIndex(i, j) == "Plant"){
                ans += Plant::getPlantPriceMapConfig()[itemCode];
            } else if (itemTypeAtIndex(i, j) == "Animal"){
                ans += Animal::getAnimalPriceConfig()[itemCode];
            } else if (itemTypeAtIndex(i, j) == "Product"){
                ans += Product::getProductPriceMapConfig()[itemCode];
            } else if (itemTypeAtIndex(i, j) == "Building"){
                ans += Building::getBuildingPriceMapConfig()[itemCode];
            }
        }
    }
    return ans;
}

int Player::calculateKKP(){return 0;}

void Player::insertItem(std::string itemCode) {
    ItemStorage.insertElmtAtEmptySlot(itemCode);
}

map<string, int> Player::getNumberofItemStorage() {
    map<string, int> temp;
    for (int i = 0; i < ItemStorage.getNumRow(); i++) {
        for (int j = 0; j < ItemStorage.getNumCol(); j++) {
            if (ItemStorage.getElmt(i, j) != nullptr) {
                string *code = ItemStorage.getElmt(i, j);
                if (temp.find(*code) == temp.end()) {
                    temp[*code] = 1;
                } else {
                    temp[*code]++;
                }
            }
        }
    }
    return temp;
}

vector<string> Player::parseSlot(string input){
    vector<string> vec;
    string temp="";
    int i = 0;
    int sz = input.size();
    while (i < sz){
        if (input[i]==','){
            vec.push_back(temp);
            i+=1;
            temp = "";
        } else {
            temp = temp + input[i];
        }
        i++;
    }
    vec.push_back(temp);
    return vec;
}