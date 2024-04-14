#ifndef _SHOP_HPP
#define _SHOP_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <numeric>
#include "game.hpp"
#include "player.hpp"
#include "animal.hpp"
#include "plant.hpp"
#include "building.hpp"
#include "product.hpp"
#include "storage.hpp"


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
    int price;      // Item's Price
    bool isQtyInf;  // Bool Checker for Qty
    int qty;        // Item's Qty

    vector<string> ConfigCode;
    map<string, int> ConfigItemsnumber;
    map<string, string> ConfigName;
    map<string, int> ConfigPrice;
    map<string, bool> ConfigItemsisQtyInf;
    map<string, int > ConfigItemsQty;
    

public:
    
    /**
     * @brief Shop ctor
     * 
     * \note if item came from Animal or Plant then isQtyInf = True, Qty = INFINITY else isQtyInf = False, Qty = 0
    */
    Shop();
    

    /**
     * @brief 
     * 
     */
    Shop(string _code);
    
    Shop(int item_number, string code, string name, int price, bool isQtyInf, int qty);
    /**
     * @brief Shop cctor
     * 
     */
    Shop(const Shop& other);

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
    void Shop::setQty(string _code, int _Qty);

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
    vector<string> getCode_outer() const;

    /**
     * @brief Get Price from other .hpp for initial value
     * 
     * @return int Price from other .hpp
     * 
     */
    map<string,int> getPrice_outer() const;

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
     * \note Check isQtyInf. If True then Qty = INFINITY else Qty = 0
     *
     * 
     * @param int Qty
     */
    void set_Qty(string code);

    /**
     * @brief Set the Item Number object
     * 
     * @return map<string, int> 
     */
    map<string, int> setItemNumber();
    
    /**
     * @brief Set the Is Qty Inf object
     * 
     * @return map<string, bool> 
     */
    map<string, bool> setIsQtyInf();

    /**
     * @brief Set the Qty object@
     * 
     * @return map<string, int> 
     */
    map<string, int> setQty();

     /**
         * @brief Output Format: <id> <code> <name> <foodType> <currWeight> <weightToHarvest> <price>
         * 
         * @param os        output stream
         * @param animal    animal reference
         * 
         * @return Reference to the output stream.
        */
        friend ostream& operator<<(ostream& stream, const Shop& shop);
        
    /**
     * @brief 
     * 
     */
    void printInfo();

};




class BlackMarket: public Shop{
    protected:
        bool isBuy;

    public:
        /**
         * @brief ctor user defined
         * 
         * @param Black Market Qty
         * 
         */
        BlackMarket(int Qty_BM, int Price_BM, bool isBuy);

        /**
         * @brief cctor
         * 
         */
        BlackMarket(const BlackMarket& other);

        
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


    
        /**
         * @brief Set a Random number for Black Market Qty of item with Code = code
         * 
         * \note QtyBM = min(Qty, rand(1,10))
         * 
         * @param code 
         * @return int 
         */
        int MakeQtyBM(string code);

        /**
         * @brief Get a random number
         * 
         * @param int Max; int Min
         * 
         * @return int
         */
        int getRandomInt(int Min, int Max);

        /**
         * @brief Make the Price for Black Market
         * 
         * @param _code 
         * @param isBuy 
         * @return int 
         */
        int MakePriceBM (string _code, bool isBuy);


        /**
         * @brief Update the Price List for Black market
         * 
         * @param isBuy 
         * @return map<string, int> 
         */
        map<string, int> BlackMarket::Make_BMPriceList(bool isBuy);
       
};



#endif