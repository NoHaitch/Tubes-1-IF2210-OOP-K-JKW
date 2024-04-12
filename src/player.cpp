#include <iostream>
#include <iomanip>
#include <string>

#include "header/player.hpp"
#include "header/storage.hpp"
#include "header/product.hpp"

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

void Player::setWealth(int _wealth){
    this->wealth = _wealth;
}

void Player::setCurrWeight(int _currWeight){
    this->currWeight = _currWeight;
}

void Player::printItemStorage(){
    this->ItemStorage.printStorage();
}

string Player::itemType(string positionCode) {
    string itemCode = this->ItemStorage.getElmt(positionCode);
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