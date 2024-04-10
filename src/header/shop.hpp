#ifndef _SHOP_HPP
#define _SHOP_HPP

#include <iostream>
#include <string>
#include <vector>
#include "game.hpp"
#include "player.hpp"
#include <any>

using namespace std;

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

    
    //**************** Quantity Modifier *****************//
    /**
     * @brief Modified the Qty of Item with ID = id 
     * 
     * @param int _id
     * @param int change        
     * @param Shop& shop        
     * @param bool isAdd 
     */

    void item_Qty_Modifier(int _id, int change, Shop& shop, bool isAdd);

    

    /**
     * @brief Get Data from a number selected by user 
     * 
     * @param int _id
     */

    any get_Data(int _id);

    /**
     * @brief Get Price of the item with ID = id
     * 
     * @param int _id
     * 
     */

    int get_Price(int _id);

    /**
     * @brief Get id from item code
     * 
     */
    int get_ID_from_code(string code);

    /**
     * @brief 
     * 
     */


    //*************** Show Inventory *******************//

    /**
     * @brief Show Shop Inventory Based on Role
     * 
     * @param string Role
     * 
     */
    void Show_Shop_Inventory(string Role) const;


   

private:
    /**
     * @brief Set the initial Qty of every object, Where Product and Building init Qty = 0, else Qty = infinite 
     * 
     * @param _Qty 
     */
    void set_Qty(int _Qty);

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



/*
player p

>> BELI

role = getRole(p) (?)

Show_Shop_Inventory(role)
***** Output
// Selamat datang di toko !
// Berikut adalah barang yg bisa diakses -> Pisah sesuai role sesuai spek
***** Format: Nama - Harga Gulden - Qty jika ada. Misal sudah ada yg jual product
// 1. Cow - 6 Gulden
// 2. Sheep - 5 Gulden
...
// 8. Teak Tree - 5 Gulden
...
// 16. Teak Wood - 9 Gulden - 0 (Tidak bisa dibeli)
// 17. Sandalwood Wood - 8 Gulden - 10
...

gulden_now = p -> getWealth()
***** contoh Output
Uang anda: 100 Gulden

empty_slot_now = storage.getNumElmt()
***** contoh Output
Slot penyimpanan tersedia: 10 slot

int itemNumber;
int quantity;

Validasi sekali/sampe bener ? 

if (Validate_buy(itemNumber, quantity) ){
    //Ubah Qty
    item_Qty_Modifier(itemNumber, quantity, shop(?), False)

    //Update uang player
    gulden_update = gulden_now - (getPrice(itemNumber)*quantity)
    setWealth(gulden_update)

     //Ambil data dengan itemNumber itu 
    T = get_Data(itemNumber).drop(ID).drop(Qty)

    output_update(gulden_update, quantity, T)


   
    -> Insert Elmt T
}
*/

/*

Player p

>> JUAL

role = getRole(p) (?)

p -> printItemStorage()

gulden_now = getWealth()

n = getNumElmt();

if n != 0 {
    Item coordinat = ...

        Data = ambil data per koordinat -> Code = getCode(Data) 

        item_id = get_id_from_code(Code)

        total += getPrice(item_id)
        item_Qty_Modifier(item_id, 1, shop(?), True)

    cout << total

    setWealth(gulden_now + total)

}

*/












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