#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#include "header/player.hpp"
#include "header/storage.hpp"
#include "header/product.hpp"
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
                selectedItem = ItemStorage.getElmt(inputCode);
                if (itemType(inputCode)=="Product"){
                    Product selectedProduct(selectedItem);
                    if (Product::isEdible(selectedProduct)){
                        ItemStorage.deleteElmtAtPosition(inputCode);
                        currWeight += selectedProduct.getAddedWeight();
                        valid = true;
                        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
                        cout << "Alhasil, berat badan kamu naik menjadi " << currWeight << endl;
                    } else {
                        throw InedibleProductException("Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!! \n Silahkan masukan slot yang berisi makanan. \n");
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

void Player::buy(){}

void Player::sell(){}

string Player::itemType(string positionCode) {
    string itemCode = this->ItemStorage.getElmt(positionCode);
    vector <string>::iterator it;

    // Find in Plant
    it = find(Plant::getPlantCodeListConfig().begin(), Plant::Plant::getPlantCodeListConfig().end(), itemCode);
    if (it != Plant::getPlantCodeListConfig().end()) {
        return "Plant";
    } else {
        // Find in Animal
        it = find(Animal::getAnimalCodeConfig().begin(), Animal::Animal::getAnimalCodeConfig().end(), itemCode);
        if (it != Animal::getAnimalCodeConfig().end()) {
            return "Animal";
        } else {
            it = find(Product::getProductCodeListConfig().begin(), Product::Product::getProductCodeListConfig().end(), itemCode);
            if (it != Product::getProductCodeListConfig().end()) {
                return "Product";
            } else {
                return "Building";
            }
        }
    }
}

string Player::itemType(int y, int x) {
    string itemCode = this->ItemStorage.getElmt(y, x);
    vector <string>::iterator it;

    // Find in Plant
    it = find(Plant::getPlantCodeListConfig().begin(), Plant::Plant::getPlantCodeListConfig().end(), itemCode);
    if (it != Plant::Plant::getPlantCodeListConfig().end()) {
        return "Plant";
    } else {
        // Find in Animal
        it = find(Animal::getAnimalCodeConfig().begin(), Animal::Animal::getAnimalCodeConfig().end(), itemCode);
        if (it != Animal::Animal::getAnimalCodeConfig().end()) {
            return "Animal";
        } else {
            it = find(Product::getProductCodeListConfig().begin(), Product::Product::getProductCodeListConfig().end(), itemCode);
            if (it != Product::Product::getProductCodeListConfig().end()) {
                return "Product";
            } else {
                // TODO : implement search building
                return "";
            }
        }
    }
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
            string itemCode = ItemStorage.getElmt(i, j);
            if (itemType(i, j) == "Plant"){
                ans += Plant::getPlantPriceMapConfig()[itemCode];
            } else if (itemType(i, j) == "Animal"){
                ans += Animal::getAnimalPriceConfig()[itemCode];
            } else if (itemType(i, j) == "Product"){
                ans += Product::getProductPriceMapConfig()[itemCode];
            } else if (itemType(i, j) == "Building"){
                // TODO : implement case for building
            }
        }
    }
    return ans;
}

int Player::calculateKKP(){}