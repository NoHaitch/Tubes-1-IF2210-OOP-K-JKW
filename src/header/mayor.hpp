#ifndef __MAYOR__
#define __MAYOR__

#include "player.hpp"
#include "building.hpp"
#include "farmer.hpp"
#include "cattleman.hpp"
#include "product.hpp"
#include "shop.hpp"
#include "playerException.hpp"
#include <vector>
#include <iostream>
using namespace std;

class Mayor : public Player {
private :
    vector<Building> buildingInCity;
public:
    Mayor(string _username);
    Mayor(string _username, int _wealth, int _currWeight);
    ~Mayor();
    void pungutPajak(vector<Farmer>* farmers, vector<Cattleman>* cattlemans);
    void bangunBangunan();

    /**
     * @brief add new player to the game. taking the vectors of players from Game and return the username added
     * @param farmers pointer to vector of farmers, get from Game
     * @param cattlemans pointer to vector of cattlemans, get from Game
     * @return string username of new player added
     */
    string tambahPemain(vector<Farmer>* farmers, vector<Cattleman>* cattlemans);
    void buy() override;
    void sell() override;
    int calculateKKP() override;

    void operator+(Building B);
};


#endif