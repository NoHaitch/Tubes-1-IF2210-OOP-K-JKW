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
    Storage<Plant> Ladang;
    map<string, int> numberOfHarvestablePlant;

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
    Storage<Plant> getLadang();

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
    Plant getItem(string idx);


    /**
     * @brief print khusus ladang
     * \note - hanya menampilkan kode tanaman
     * \note - warna hijau menandakan tanaman yang sudah siap panen
     * \note - warna merah menandakan tanaman yang belum siap panen
     */
    void printLadang();

    /**
     * @brief menghitung pajak yang harus dibayarkan
     * @return pajak int yang harus dibayarkan
     */
    int calculateTax();

    /**
     * @brief fungsi untuk membayar pajak
     * \note mengambil nilai besar pajak yang dibutuhkan dari fungsi counTax()
     */
    void payTax();

    /**
     * @brief menghitung total kekayaan
     * @return total kekayaan
     * \note
     */
    int countWealth();

    void buy() override;

    void sell() override;
};

#endif