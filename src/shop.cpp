#include "header/shop.hpp"
#include "header/player.hpp"
using namespace std;



Shop::Shop(){
    item_number = 0;
    code = "";
    name = "";
    price = 0;
    isQtyInf = false;
    qty = 0;

}
    
Shop::Shop(string _code){
    item_number = ConfigItemsnumber[_code];
    code = _code;
    name = ConfigName[_code];
    price = ConfigPrice[_code];
    isQtyInf = ConfigItemsisQtyInf[_code];
    qty = ConfigItemsQty[_code];
}

Shop::Shop(const Shop& other){
    item_number = other.item_number;
    code = other.code;
    name = other.name;
    price = other.price;
    isQtyInf = other.isQtyInf;
    qty = other.qty;

}
Shop::~Shop(){}


    //**************** GETTER  *****************//

    /**
     * @brief Get the Code with item_number = item_number
     * 
     * @param int item_number 
     * @return string Code
     */
    string Shop::getCode (int _itemNumber){
        for(const auto& pair : ConfigItemsnumber){
            if (pair.second == item_number){
                return pair.first;
            }
        }
        
    }


    /**
     * @brief Get Price of the item with Code = CODE from Shop
     * 
     * @param string _code
     * 
     */
    int Shop::getPrice(string _code){
        return ConfigPrice[_code];

    }

    /**
     * @brief Get Name of the item with Code = code from Shop
     * 
     * @param code 
     * @return string 
     */
    string Shop::getName(string _code){
        return ConfigName[_code];

    }

    /**
     * @brief Get Qty of the item with Code = code from Shop
     * 
     * \note only access if not isQtyInf
     * @param code
     * 
     * @return 
     * 
     */
    int Shop::getQty(string _code){
        return ConfigItemsQty[_code];
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
        ConfigItemsQty[_code] = _Qty;
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
        return ConfigItemsisQtyInf[_code];
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
        cout << "Selamat Datang di Toko" << endl;
        cout << "Berikut adalah barang yang bisa anda beli" <<endl;

        //Format itemNumber. Nama - Price "Gulden" - Qty


    }

    /**
     * @brief Show Shop Inventory for Mayor Role
     * 
     * \note Show inventory for Mayor
     * 
     */
    void Shop::Show_Shop_Inventory_Mayor() const{
        cout << "Selamat Datang di Toko" <<endl;
        cout << "Beriku adalah barang yang bisa anda beli" <<endl;

        

    }

    ostream& operator<<(ostream& stream, const Shop& shop){
        stream << shop.item_number << " ";
        stream << shop.name << " ";
        stream << shop.price << " ";
        stream << shop.qty << " ";

        return stream;
    }

    void Shop::printInfo(){
        cout << this->item_number ;
        cout << ". ";
        cout<< this->name;
        cout<< " - ";
        cout << this->price;
        cout << " Gulden";
        if (!this->isQtyInf){
            cout << " - ";
            cout << this->qty;
        }


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
        return getName(_code) != "Building";
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
        return getName(_code) != "Building";
    }

    
    


    /*************** GET Data from other .hpp *************************/

     /**
     * @brief Get Code from other .hpp for initial value
     * 
     * 
     * @return string Code from other .hpp
     * 
     */
    vector<string> Shop::getCode_outer() const{
        vector<string> allCode, animalCode, plantCode, buildingCode, productCode;

        string MARK = "MARK";
        string Building = "Building";


        animalCode = Animal::getAnimalCodeConfig();plantCode = Plant::getPlantCodeListConfig();productCode = Product::getProductCodeListConfig();

        buildingCode ;

        allCode.insert(allCode.end(), buildingCode.begin(), buildingCode.end());

        //allCode.push_back();
        allCode.insert(allCode.end(), productCode.begin(), productCode.end());

        allCode.push_back(MARK);
        allCode.insert(allCode.end(), animalCode.begin(), animalCode.end());      

        allCode.insert(allCode.end(), plantCode.begin(), plantCode.end());    

        return allCode;      
    }

    template<typename key, typename value>
    void insertToAll(map<key,value> all, 
                    const map<key,value> building, 
                    const map<key,value> product, 
                    const map<key,value> animal, 
                    const map<key,value> plant){

        all.insert(building.begin(), building.end());
        all.insert(product.begin(), product.end());
        all.insert(animal.begin(), animal.end());
        all.insert(plant.begin(), plant.end());

        

    }

    /**
     * @brief Get Price from other .hpp for initial value
     * 
     * @return int Price from other .hpp
     * 
     */
    map<string,int> Shop::getPrice_outer() const{
        map<string, int> allPrice, animalPrice, plantPrice, buildingPrice, productPrice;

        animalPrice = Animal::getAnimalPriceConfig();
        plantPrice = Plant::getPlantPriceMapConfig();
        productPrice = Product::getProductPriceMapConfig();
        buildingPrice;

        insertToAll(allPrice, buildingPrice, productPrice, animalPrice, plantPrice);

        return allPrice;

    }

    map<string, string> getName_outer(){
        map<string,string> allName, animalName, plantName, buildingName, productName;

        animalName = Animal::getAnimalNameConfig();
        plantName = Plant::getPlantNameMapConfig();
        productName = Product::getProductNameMapConfig();
        buildingName;

        insertToAll(allName, buildingName, productName, animalName, plantName);

        return allName;
    }

    map<string, int> Shop::setItemNumber(){
        vector<string> allItemCode;
        map<string, int> mapCodeandItemNumber;
        vector<int> itemNumber(allItemCode.size());

        allItemCode = Shop::getCode_outer();

        allItemCode.erase(remove(allItemCode.begin(), allItemCode.end(), "MARK"), allItemCode.end());

        iota(itemNumber.begin(), itemNumber.end(), 1);

        transform(allItemCode.begin(), allItemCode.end(), itemNumber.begin(), inserter(mapCodeandItemNumber, mapCodeandItemNumber.end()), 
        [](const string& key, int value) {
            return make_pair(key,value);
        });

    }

    map<string, bool> Shop::setIsQtyInf(){
        vector<string> allItemCode;
        map<string, bool> mapCodeandIsINF;

        allItemCode = Shop::getCode_outer();

        bool isInf = false;

        auto isInfFunction = [&isInf](const string&code){
            if(code == "MARK"){
                isInf = true;
            }
            return isInf;
        };

        transform(allItemCode.begin(), allItemCode.end(), inserter(mapCodeandIsINF, mapCodeandIsINF.end()), isInfFunction);

        return mapCodeandIsINF;

    }

    map<string, int> Shop::setQty(){
        vector<string> allItemCode;
        map<string, int> mapCodeandQty;

        allItemCode = Shop::getCode_outer();

        auto markIter = find(allItemCode.begin(), allItemCode.end(), "MARK");

        transform(allItemCode.begin(), allItemCode.end(), inserter(mapCodeandQty, mapCodeandQty.end()),
        [isMarkFound = markIter != allItemCode.end()](const string& code){
            return make_pair(code, isMarkFound ? numeric_limits<int>::max(): 0);
        });

        mapCodeandQty.erase("MARK");

        return mapCodeandQty;

    }
    

    


/* Class Black Market*/

BlackMarket::BlackMarket(int Qty_BM, int Price_BM, bool isBuy) : Shop(item_number, code, name, Price_BM, false, Qty_BM), isBuy(isBuy){}


int BlackMarket::MakeQtyBM(string _code){
    int Shop_Qty = Shop::getQty(_code); 
    bool isInf = Shop::getIsQtyInf(_code);

    int Min = 1;
    int Max = 10;
    int rand = getRandomInt(1,10);

    if (isInf){
        return rand;
    }
    else{
        return min(Shop_Qty, rand);
    }
}

int BlackMarket::getRandomInt(int Min, int Max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(Min, Max);

    return distribution(gen);
}

int BlackMarket::MakePriceBM (string _code, bool isBuy){
    int Price = Shop::getPrice(_code);

    int Percentage = 30;

    float Difference = Price*Percentage*0.01;

    if (isBuy){
        Price = ceil(Price+Difference);
    }
    else{
        Price = floor(Price-Difference);
    }

    return Price;

}

map<string, int> BlackMarket::Make_BMPriceList(bool isBuy){

    map<string,int> BlackMarketPriceMap = Shop::ConfigPrice;

    for (auto& pair : BlackMarketPriceMap){
        pair.second = MakePriceBM(pair.first, isBuy);
    }

    return BlackMarketPriceMap;

}