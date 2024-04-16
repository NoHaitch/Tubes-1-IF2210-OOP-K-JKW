#ifndef _SHOP_HPP
#define _SHOP_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "animal.hpp"
#include "plant.hpp"
#include "building.hpp"
#include "product.hpp"
#include "utils.hpp"


using namespace std;

/**
 * @brief Class Shop used by All Player
 * 
 * \note - Childern: BlackMarket
 * 
 */
class Shop{

protected:

    /* ATTRIBUTES */
    map<string, int> ShopItems; // <itemCode, quantity>
    map<string, int> ShopBuildings; // <itemCode, buildings>

    /* CONFIG ATTRIBUTES */
    vector<string> ShopConfigCode;
    map<string, int > ShopConfigItemsQty;
    map<string, int > ShopConfigBuildingsQty;
    
    /* CONSTANT */
    static const int INFINITEQUANTITY = 9999;

public:
    /* CTOR & DTOR */

    /**
     * @brief shop ctor
    */
    Shop();

    /**
     * @brief Shop config ctor
     * 
     * \note if item came from Animal or Plant then quantity is INFINITEQUANTITY
     * 
     * \param _ShopItems map<string, int> of ShopItems to be constructed
    */
    Shop(map<string, int> _ShopItems, map<string, int> _ShopBuildings);

    /**
     * @brief Shop dtor
    */
    ~Shop();

    /* GETTER */

    /**
     * @brief Get the ShopItems map
     */
    map<string, int> getShopItems ();

    /**
     * @brief Get the ShopBuildings map
     */
    map<string, int> getShopBuildings ();

    /**
     * @brief Get the quantity of item
     * 
     * @param _itemCode string code for item
     */
    int getItemQuantity (string _itemCode);

    /* SETTER */
    /**
     * @brief Set the current ShopItems
     * 
     * @param _ShopItems map<string, int> of new ShopItems
    */

    void SetShopItems(map<string, int> _ShopItems);

    /**
     * @brief Set the current ShopItems
     * 
     * @param _ShopItems map<string, int> of new ShopItems
    */

    void SetShopBuilding(map<string, int> _ShopBuilding);

    /**
     * @brief increase the Qty of the items with code = code
     * 
     * @param string code 
     * @param int change 
     */
    void increaseQty(string code, int change);

    /**
     * @brief decrease the Qty of the items with code = code
     * 
     * @param string code 
     * @param int change 
     */
    void decreaseQty(string code, int change);
    

    //*************** Show Shop Inventory *******************//

    /**
     * @brief Show Shop Inventory for Non Building items
     */
    virtual void showShopNonBuildings();

    /**
     * @brief Show Shop Inventory for Building
     */
    virtual void showShopBuildings(int prevNumber);

    /**
     * @brief Show Shop Inventory title
     */
    virtual void showShopTitle();

    /* OTHER METHODS */
    void setupPlantAnimalItems();

    string getNameFromCode(string itemCode);

    int getPriceFromCode(string itemCode);

    int numItemQuantityPositive();
};




class BlackMarket: public Shop{
    protected:
        static constexpr float BMPRICECHANGEPERCENTAGE = 0.3;

    public:
        /**
         * @brief ctor user defined
         */
        BlackMarket();

        /**
         * @brief dtor
         * 
         */
        ~BlackMarket();

        
        //**************** GETTER SETTER *****************//

        /**
         * @brief Get the Black Market Qty of item with Code = code
         * 
         * @param string code
         * @param isBuy is it for buy case
         * 
         * @return int Qty
         */
        int getPriceBlackMarket(string code, bool isBuy);

        //*************** Show Black Market Inventory *******************//

        void showShopNonBuildings() override;

        void showShopBuildings(int prevNumber) override;

        /**
         * @brief Show Black Market Inventory title
         */
        void showShopTitle() override;
};



#endif