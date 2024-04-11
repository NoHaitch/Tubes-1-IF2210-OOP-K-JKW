#ifndef __FARMER__
#define __FARMER__

#include <iostream>
#include <vector>
#include <string>
#include "plant.hpp"
#include "player.hpp"
#include "product.hpp"
#include "storage.hpp"
using namespace std;

class Farmer : public Player {
private:
    Storage<Plant> *Ladang;

public:
    /**
    * @brief Default Farmer Ctor
    */
    Farmer(string _username);

    /**
    * @brief User Defined Farmer Ctor
    */
    Farmer(string _username, int _wealth, int _currWeight);

    /**
     * @brief Farmer Dtor
     */
    ~Farmer();

    /**
     * @return true jika ladang tidak memiliki slot kosong
     */
    bool isLadangFull();

    /**
     * @brief Get Ladang
     */
    Storage<Plant> *getLadang();

    /**
     * @brief menanam tanaman di ladang
     */
    void tanam();

    /**
     * @brief memanen tanaman dari ladang dan menyimpannya ke storage inventory ItemStorage
     */
    void panen();

    /**
     * @brief cek apakah slot pada ladang di titik tersebut kosong atau terisi
     * @return true jika slot pada ladang terisi
     */
    bool isLadangSlotEmpty(string idx);

    /**
     * @brief override getItem() untuk mengambil tanaman dari penyimpanan ladang
     * @return tanaman yang diambil
     */
    Plant* getItem(string idx);

};

#endif