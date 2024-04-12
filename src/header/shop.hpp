#ifndef _SHOP_HPP
#define _SHOP_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "game.hpp"
#include "player.hpp"
#include "storage.hpp"
#include <any>

using namespace std;

/**
 * @brief Class Shop used by All Player
 * 
 * \note - Childern: BlackMarket
 * 
 */
class Shop{

protected:

    int item_number;         // Item's item_number number / Item number
    string code;    // Item's Code
    string name;    // Item's Name
    int Price;      // Item's Price
    bool isQtyInf;  // Bool Checker for Qty
    float Qty;      // Qty Float to facilitate INFINITY
    

public:
    
    /**
     * @brief Shop ctor
     * 
     * \note if item came from Animal or Plant then isQtyInf = True, Qty = INFINITY else isQtyInf = False, Qty = 0
    */
    Shop();
    // [[item_number, code, Price, isQtyInf, Qty]]

    /**
     * @brief 
     * 
     */
    Shop(int _id, string _code, string _name,int _Price, bool isQtyInf, float _Qty);
    

    /**
     * @brief Shop dtor
     * 
     * 
    */
    ~Shop();


    //**************** GETTER  *****************//

    /**
     * @brief Get the Code with item_number = item_number
     * 
     * @param int item_number 
     * @return string Code
     */
    string getCode (int item_number);


    /**
     * @brief Get Price of the item with Code = CODE from Shop
     * 
     * @param string _code
     * 
     */
    int getPrice(string code);

    /**
     * @brief Get the Name of the item with Code = code from Shop
     * 
     * @param code 
     * @return string 
     */
    string getName(string code);

     /**
     * @brief Get Qty of the item with Code = code from Shop
     * 
     * @param code
     * 
     * @return 
     * 
     */
    int Shop::getQty(string _code);

    /**
     * @brief Get isQtyInf of the item with Code = code from Shop
     * 
     * @param code
     * 
     * @return bool
     * 
     */
    bool Shop::getIsQtyInf(string _code);

    /**
     * @brief Set Qty of the item with Code = code with Qty = _Qty
     * 
     * \note Only Access if isQtyInf = false
     * 
     * @param code
     * @param _Qty
     */
    void Shop::setQty(string _code, int _Qty){
        if(this->code == _code){
            this->Qty = _Qty;
        }
    }

    /**
     * @brief Update the Qty of the items with code = code
     * 
     * @param string code 
     * @param int change 
     * @param bool isAdd. if True than Qty += change otherwise Qty -= change
     */
    void updateQty(string code, int change, bool isAdd);
    

    //*************** Show Shop Inventory *******************//

    /**
     * @brief Show Shop Inventory for Non Mayor Role
     * 
     * \note Show inventory for Cattleman and Farmer
     * 
     */
    void Shop::Show_Shop_Inventory_NonMayor() const;

    /**
     * @brief Show Shop Inventory for Mayor Role
     * 
     * \note Show inventory for Mayor
     * 
     */
    void Shop::Show_Shop_Inventory_Mayor() const;



    //**************** Validator *****************//

    /**
     * @brief Check if player has enough money and empty inv slot
     * 
     * @param item_number 
     * @param Quantity 
     * @param nEmptySlot        // Amount of Player's Empty Slot
     * @param player_money
     * 
     * @return true if enough
     * @return false otherwise
     */
    bool isBuyValid (int item_number, int Quantity, int nEmptySlot, int player_money);

    /**
     * @brief Check if the item that player want to buy is Legal
     * 
     * @param item code 
     * 
     * \note Only Can Be Access by Mayor
     * 
     * @return true if Legal
     * @return false if not Legal (Mayor want to buy buildings)
     */
    bool isBuyLegal (string code);

    /**
     * @brief Check if the item that player sell is valid according to their role
     * 
     * @param item code 
     * 
     * @return true if valid 
     * @return false if not valid (Non Mayor want to sell buildings)
     */
    bool isSaleLegal (string code);

    
    

private:

    /*************** GET Data from other .hpp *************************/

     /**
     * @brief Get Code from other .hpp for initial value
     * 
     * 
     * @return string Code from other .hpp
     * 
     */
    string getCode_outer() const;

    /**
     * @brief Get Price from other .hpp for initial value
     * 
     * @return int Price from other .hpp
     * 
     */
    int getPrice_outer() const;

    /*************** SET Data to cotr *************************/

    /**
     * @brief Set the item_number from 1 to the last elmt 
     * 
     * @param int current item_number
     * 
     */
    void set_ItemNumber(int _itemNumber);

    /**
     * @brief Set the Code into the ctor ?
     * 
     * @param string code
     */
    void set_Code(string code);

    /**
     * @brief Set the Price into the ctor ?
     * 
     * @param int Price
     */
    void set_Price(int Price);

    /**
     * @brief Set the Qty into the ctor ?
     * 
     * \note for Animal and Plant, Qty = INFINITY
     * \note for else, Qty = 0
     * 
     * @param int Qty
     */
    void set_Code(int Qty);



};


      


/*
player p

>> BELI

role = getRole(p) (?)   // Game.hpp

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
    T = get_Data(itemNumber).drop(item_number).drop(Qty)

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





class BlackMarket: public Shop{
    protected:

    public:
        /**
         * @brief ctor user defined
         * 
         * @param Black Market Qty
         * 
         */
        BlackMarket(int Qty_BM);

        
        //**************** GETTER SETTER *****************//

        /**
         * @brief Get the Black Market Qty of item with Code = code
         * 
         * @param string code
         * 
         * @return int Qty
         */
        int GetQtyBM(string code);


        //*************** Show Black Market Inventory *******************//

        /**
         * @brief Show limited BlackMarket Inventory Based on Role
         * 
         * @param string Role
         * 
         */
        void Show_Shop_Inventory(string Role, int BMList) const;


    private:
        /**
         * @brief Set a Random number for Black Market Qty of item with Code = code
         * 
         * \note QtyBM = min(Qty, rand(1,10))
         * 
         * @param code 
         * @return int 
         */
        int SetQtyBM(string code);

        /**
         * @brief Get a list of random number
         * 
         */


};



#endif