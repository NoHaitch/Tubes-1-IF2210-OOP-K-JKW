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