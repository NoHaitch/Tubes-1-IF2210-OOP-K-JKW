#ifndef __MAYOR__
#define __MAYOR__

#include "player.hpp"
#include "building.hpp"
#include "farmer.hpp"
#include "cattleman.hpp"
#include "product.hpp"
#include "game.hpp"
#include <vector>
#include <iostream>
using namespace std;

class Mayor : public Player {
protected :
    vector<Building> buildingForSale;
public:
    Mayor(string _username);
    Mayor(string _username, int _wealth, int _currWeight);
    ~Mayor();
    void pungutPajak();
    void bangunBangunan();
    void tambahPemain();
    void buy() override;
    void sell() override;
};


#endif