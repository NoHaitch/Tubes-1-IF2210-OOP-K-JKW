#ifndef _SHOP_HPP
#define _SHOP_HPP

#include <iostream>
#include <string>
#include <vector>
#include "animal.hpp"
#include "plant.hpp"
#include "building.hpp"
#include "product.hpp"
#include "player.hpp"

// #include "Yang ngurus inventori"
// #include "Player"

//
class Shop{

protected:

    

    
    /* Configuration Data 
    vector<Animal> animals;         // All Animals info from config
    vector<Plant> plants;           // 
    vector<Product> products;
    vector<Building> buildings;
    */
    
    

public:
    
    /**
     * @brief Shop ctor
     * 
     * 
    */
    Shop();
    //Ada inventori shop. 
    //Qty Tanaman dan Hewan = infinite
    //Baca config tanaman -> ambil ALL kecuali ID -> Masukin array 
    //Baca config hewan -> ambil ALL Kecuali ID -> append array 
    //Qty bangunan and Product = 0
    //Baca config product -> ambil ALL kecuali ID, Qty = 0 -> append array
    //Baca config building -> ambil ALL kecuali ID, Qty = 0 -> append.a
    

    /**
     * @brief Shop dtor
     * 
     * 
    */
    ~Shop();

    

    /**
     * @brief Add Qty of a specific item
     * 
     * @param 
     * 
     */

    void Add_item_Qty();

    /**
     * @brief Decrease Qty of a specific item. Check if Qty > 0
     * 
     * @param 
     */


    void Dec_item_Qty();

    /**
     * @brief Get Data from a number selected by user
     * 
     * @param int index
     */

    void get_Data();

    //*************** Show Inventory *******************//

    /**
     * @brief Show Shop Inventory Based on Role
     * 
     * @param string Role
     * 
     */
    void Show_Shop_Inventory(string Role) const;


    /**
     * @brief Show the needed Animal's vector data
     * 
     * \note only show Num. Name - Price
     * 
     * @param ?
     */
    void Show_Animal_Inventory();

    /**
     * @brief Show the needed Plant's vector data
     * 
     * \note only show Num. Name - Price
     * 
     * @param ?
     */
    void Show_Plant_Inventory();

    /**
     * @brief Show the needed Product's vector data
     * 
     * \note only show Num. Name - Price - Qty
     * 
     * @param ?
     */
    void Show_Product_Inventory();

    /**
     * @brief Show the needed Building's vector data
     * 
     * \note only show Num. Name - Price - Qty
     * 
     * @param ?
     */
    void Show_Building_Inventory();


private:
    /**
     * @brief Set the initial Qty of every object, Where Product and Building init Qty = 0, else Qty = infinite 
     * 
     * @param _Qty 
     */
    void set_Qty(int _Qty);












/*

Shop. 

Di dalam shop ada inventory, yang berisi data semua item yg tersedia dalam game - Baca Config + Qty yang tersedia

PR = How bisa ambil data semua item ? 

Sementara: 
Dalam inventory ada 4 vektor, yaitu vector<Animal>, vector<Plant>, vector<Product + Qty>, dan vector<Building + Qty>

dan set Qty = 0






*/
    

    /*
    void Jual(Player p);
    //update inventori dari shop. Cek role ! -> Jika role = Petani atau Peternak gk bisa jual bangunan. 
    //Terima role 
    //Buka Inventori + Cetak open_inventori()
    //Minta user untuk select koordinat inventori yg mau dijual dengan memastikan role. Jika role = Petani atau Peternak gk bisa jual bangunan. 
    //Validasi koordinat apakah ada atau gk. Kalau 

    void Beli(player p);
    //BELI
    //Player: update status inventori dan gulden nya role. 
    //Shop: Keluarin barang dari inventori. Cek role ! -> Jika role = Walikota gk bisa akses menu bangunan. 
    // Terima data player. 
    // Cek role, tampilkan data sesuai role
    // Show_Shop()
    // Print out berapa gulden dan slot kosong nya player
    // Gulden anda : "Gulden"
    // Slot kosong : "Slot"
    // if Slot == 0 or Gulden == 0 -> Gak bisa beli krn slot/Gulden == 0
    // else -> Minta input barang apa + kuantitas
    // input kuantitas. Jika slot kosong >= kuantitas DAN kuantitas*harga barang <= total gulden -> Valid. If salah satu gk terpenuhi, ulang lagi (LOOP).
    // if valid, update nSlot dan Gulden player. -> Print gulden
    // input_inventori_player()

    void Show_Shop(string role);
    //Menampilkan inventori toko, nama barang - kuantitas
    //Terima role player -> Tampilkan data sesuai role. 
    // Format : 
    // Nama Barang - Harga G - Qty

    virtual void Show_Shop_Menu();
    //Menapilkan menu
    
    */



};


/*
//Child dari Shop, Tugas sama seperti shop tapi harga lebih rendah 30%(?) dan hanya ada tiap 4 turn
class Black_Market : public Shop{

    void Show_Shop_Menu() override;


};

*/


class BlackMarket: public Shop{

};


/*

Black Market

Kelas Turunan dari Shop. 

Inventory Black Market ambil dari Inventory

Sementara: 
Dalam inventory ada 4 vektor, yaitu vector<Animal+Qty_BM_1>, vector<Plant+Qty_BM_1>, vector<Product+Qty + Qty_BM>, dan vector<Building+Qty + Qty_BM>

dan set Qty_BM_1 = rand(min_qty,max_qty) dan set Qty_BM = min(Qty, rand(min_qty, max_qty))

Untuk methode semua inheritance dari Shop. 







*/



#endif