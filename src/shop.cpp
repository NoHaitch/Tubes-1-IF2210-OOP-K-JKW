#include "header/shop.hpp"
#include "header/player.hpp"
using namespace std;



Shop::Shop(){


}
    
Shop::Shop(int _itemNumber, string _code, int _Price, bool _isQtyInf, float _Qty){
    item_number = _itemNumber;
    code = _code;
    Price = _Price;
    isQtyInf = _isQtyInf;
    Qty = _Qty;
}
    
Shop::~Shop(){
    
}


    //**************** GETTER  *****************//

    /**
     * @brief Get the Code with item_number = item_number
     * 
     * @param int item_number 
     * @return string Code
     */
    string Shop::getCode (int _itemNumber){
        if (this -> item_number == _itemNumber){
            return this->code;
        }

    }


    /**
     * @brief Get Price of the item with Code = CODE from Shop
     * 
     * @param string _code
     * 
     */
    int Shop::getPrice(string _code){
        if(this -> code == _code ){
            return this->Price;
        }

    }

    /**
     * @brief Get the Name of the item with Code = code from Shop
     * 
     * @param code 
     * @return string 
     */
    string Shop::getName(string _code){
        if(this->code == _code){
            
        }

    }

    /**
     * @brief Update the Qty of the items with code = code
     * 
     * @param string code 
     * @param int change 
     * @param bool isAdd. if True than Qty += change otherwise Qty -= change
     */
    void Shop::updateQty(string code, int change, bool isAdd){

    }
    

    //*************** Show Shop Inventory *******************//

    /**
     * @brief Show Shop Inventory Based on Role
     * 
     * @param string Role
     * 
     */
    void Shop::Show_Shop_Inventory(string Role) const{

    }



    //**************** Validator *****************//

    /**
     * @brief Check if player has enough money and empty inv slot
     * 
     * @param item_number 
     * @param Quantity 
     * 
     * @return true if enough
     * @return false otherwise
     */
    bool Shop::isBuyValid (int item_number, int Quantity){

    }

    /**
     * @brief Check if the item that player sell is valid according to their role
     * 
     * @param item code 
     * @param player role 
     * 
     * @return true if valid 
     * @return false if not valid (Non Mayor want to sell buildings)
     */
    bool Shop::isSalevalid (string code, string role){

    }

    
    


    /*************** GET Data from other .hpp *************************/

     /**
     * @brief Get Code from other .hpp for initial value
     * 
     * 
     * @return string Code from other .hpp
     * 
     */
    string Shop::getCode_outer() const{

    }

    /**
     * @brief Get Price from other .hpp for initial value
     * 
     * @return int Price from other .hpp
     * 
     */
    int Shop::getPrice_outer() const{

    }

    /*************** SET Data to cotr *************************/

    /**
     * @brief Set the item_number from 1 to the last elmt 
     * 
     * @param int current item_number
     * 
     */
    void Shop::set_ItemNumber(int _itemNumber){

    }

    /**
     * @brief Set the Code into the ctor ?
     * 
     * @param string code
     */
    void Shop::set_Code(string code){

    }

    /**
     * @brief Set the Price into the ctor ?
     * 
     * @param int Price
     */
    void Shop::set_Price(int Price){

    }

    /**
     * @brief Set the Qty into the ctor ?
     * 
     * \note for Animal and Plant, Qty = INFINITY
     * \note for else, Qty = 0
     * 
     * @param int Qty
     */
    void Shop::set_Code(int Qty){

    }





