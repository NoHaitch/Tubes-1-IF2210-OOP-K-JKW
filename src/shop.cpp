#include "header/shop.hpp"
#include "header/player.hpp"
using namespace std;



Shop::Shop(){
    item_number = 0;
    code = "";
    name = "";
    Price = 0;
    isQtyInf = false;
    Qty = 0;

}
    
Shop::Shop(int _itemNumber, string _code, string _name, int _Price, bool _isQtyInf, float _Qty){
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
     * @brief Get Name of the item with Code = code from Shop
     * 
     * @param code 
     * @return string 
     */
    string Shop::getName(string _code){
        if(this->code == _code){
            return this->name;
        }

    }

    /**
     * @brief Get Qty of the item with Code = code from Shop
     * 
     * @param code
     * 
     * @return 
     * 
     */
    int Shop::getQty(string _code){

    }

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
     * @brief Get isQtyInf of the item with Code = code from Shop
     * 
     * @param code
     * 
     * @return bool
     * 
     */
    bool Shop::getIsQtyInf(string _code){
        if(this->code == _code){
            return this-> isQtyInf;
        }
    }

    /**
     * @brief Update the Qty of the items with code = code
     * 
     * \note Access if buy Valid
     * 
     * @param string code 
     * @param int change 
     * @param bool isAdd. if True than Qty += change otherwise Qty -= change
     */
    void Shop::updateQty(string _code, int change, bool isAdd){
        if(getIsQtyInf(_code)){}
        else{
            int Qty = getQty(_code);
            if(isAdd){
                setQty(_code, Qty+change);
            }
            else{
                setQty(_code, Qty-change);
            }
        }
    }
    

    //*************** Show Shop Inventory *******************//

    /**
     * @brief Show Shop Inventory for Non Mayor Role
     * 
     * \note Show inventory for Cattleman and Farmer
     * 
     */
    void Shop::Show_Shop_Inventory_NonMayor() const{

    }

    /**
     * @brief Show Shop Inventory for Mayor Role
     * 
     * \note Show inventory for Mayor
     * 
     */
    void Shop::Show_Shop_Inventory_Mayor() const{

    }



    //**************** Validator *****************//

    /**
     * @brief Check if player has enough money and empty inv slot and Qty >= Quantity
     * 
     * User Inputed
     * @param item_number 
     * @param Quantity      
     * 
     * @return true if enough
     * @return false otherwise
     */
    bool Shop::isBuyValid (int item_number, int Quantity, int nEmptySlot, int player_money){
        string _code = getCode(item_number);
        bool isPlayerReadyBuy = (nEmptySlot >= Quantity) && (player_money >= getPrice(_code));

        if(getIsQtyInf(_code)){
            return isPlayerReadyBuy;
        }
        else{
            return isPlayerReadyBuy && (getQty(_code)>=Quantity);
        }
    }

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
    bool Shop::isBuyLegal (string _code){
        if (this->code == _code){
            return(getName(_code) != "Building");
        }
    }


    /**
     * @brief Check if the item that player want to sell is Legal
     * 
     * @param item code 
     * 
     * \note Only Can Be Access by non-Mayor
     * 
     * @return true if Legal
     * @return false if not Legal (Non Mayor want to sell buildings)
     */
    bool Shop::isSaleLegal (string _code){
        if (this->code == _code){
            return(getName(_code) != "Building");
        }
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





