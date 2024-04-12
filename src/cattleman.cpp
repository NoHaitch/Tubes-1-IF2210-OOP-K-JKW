#include "header/cattleman.hpp"

Cattleman::Cattleman(string _username) : Player(_username){}

Cattleman::Cattleman(string _username, int _wealth, int _currWeight) 
    : Player(_username, _wealth, _currWeight){}

Cattleman::~Cattleman(){}

int Cattleman::calculateKKP(){
    int res = Player::calculateWealth();
    for (int i=0; i<Farm.getNumRow(); i++){
        for (int j=0; j<Farm.getNumCol(); j++){
            if (Farm.isEmpty(i, j)){
                continue;
            }
            Animal a = Farm.getElmt(i,j);
            res += Animal::getAnimalPriceConfig()[a.getCode()];
        }
    }
    res -= 11; //KTKP
    return res;
}