#include "header/shop.hpp"
#include "header/player.hpp"
#include "header/printColor.hpp"
#include "header/playerException.hpp"

#include <iostream>
#include <string>


using namespace std;

map<string, int> Shop::ShopItems;
map<string, int> Shop::ShopBuildings;
vector<string> Shop::ShopConfigCode;
map<string, int> Shop::ShopConfigItemsQty;
map<string, int> Shop::ShopConfigBuildingsQty;

Shop::Shop(){}

Shop::Shop(map<string, int> _ShopItems, map<string, int> _ShopBuildings){
    ShopItems = _ShopItems;
    ShopBuildings = _ShopBuildings;
}
    
Shop::~Shop(){}

map<string, int> Shop::getShopItems (){
    return ShopItems;
}

map<string, int> Shop::getShopBuildings (){
    return ShopBuildings;
}

int Shop::getItemQuantity (string _itemCode){
    if (itemType(&_itemCode) == "Building"){
        return ShopBuildings[_itemCode];
    } else {
        return ShopItems[_itemCode];
    }
}

vector<string> Shop::getShopConfigCode(){
    return Shop::ShopConfigCode;
}
    
map<string, int> Shop::getShopConfigItemsQty(){
    return Shop::ShopConfigItemsQty;
}

map<string, int> Shop::getShopConfigBuildingsQty(){
    return Shop::ShopConfigBuildingsQty;
}

void Shop::SetShopItems(map<string, int> _ShopItems){
    ShopItems = _ShopItems;
}

void Shop::SetShopBuilding(map<string, int> _ShopBuildings){
    ShopBuildings = _ShopBuildings;
}

void Shop::increaseQty(string code, int change){
    if (itemType(&code) == "Building"){
        ShopBuildings[code] += change;
    } else {
        ShopItems[code] += change;
    }
}

void Shop::decreaseQty(string code, int change){
    if (itemType(&code) == "Building"){
        ShopBuildings[code] -= change;
    } else {
        ShopItems[code] -= change;
    }
}

string Shop::getNameFromCode(string itemCode){
    if (itemType(&itemCode)=="Plant"){
        return Plant::getPlantNameMapConfig()[itemCode];
    } else if (itemType(&itemCode)=="Animal"){
        return Animal::getAnimalNameConfig()[itemCode];
    } else if (itemType(&itemCode)=="Product"){
        return Product::getProductNameMapConfig()[itemCode];
    } else if (itemType(&itemCode)=="Building"){
        return Building::getBuildingNameConfig()[itemCode];
    }
    return "";
}

int Shop::getPriceFromCode(string itemCode){
    if (itemType(&itemCode)=="Plant"){
        return Plant::getPlantPriceMapConfig()[itemCode];
    } else if (itemType(&itemCode)=="Animal"){
        return Animal::getAnimalPriceConfig()[itemCode];
    } else if (itemType(&itemCode)=="Product"){
        return Product::getProductPriceMapConfig()[itemCode];
    } else if (itemType(&itemCode)=="Building"){
        return Building::getBuildingPriceMapConfig()[itemCode];
    }
    return -1;
}

void Shop::showShopNonBuildings(){
    int i=1;
    map<string, int>::iterator it;
    string tempCode;
    string tempName;
    int tempPrice;
    it = ShopItems.begin();
    while (it != ShopItems.end()){
        if (it->second > 0){
            cout << i << ". ";
            tempCode = it->first;
            tempName = getNameFromCode(tempCode);
            tempPrice = getPriceFromCode(tempCode);
            cout << tempName;
            cout << " - ";
            cout << tempPrice;
            if (it->second==INFINITEQUANTITY){
                cout << endl;
            } else {
                cout << " (";
                cout << ShopItems[tempCode];
                cout << ")" << endl;
            }
            i++;
        }
        ++it;
    }
    // cout << i << endl;
}

void Shop::showShopBuildings(int prevNumber){
    int i = 1 + prevNumber;
    map<string, int>::iterator it;
    string tempCode;
    string tempName;
    int tempPrice;
    it = ShopBuildings.begin();
    while (it != ShopBuildings.end()){
        if (it->second > 0){
            cout << i << ". ";
            tempCode = it->first;
            tempName = Building::getBuildingNameConfig()[tempCode];
            tempPrice = Building::getBuildingPriceMapConfig()[tempCode];
            cout << tempName;
            cout << " - ";
            cout << tempPrice;
            cout << " (";
            cout << ShopBuildings[tempCode];
            cout << ")" << endl;
            i++;
        }
        ++it;
    }
    cout << endl;
}

void Shop::showShopTitle(bool isBuy){
    cout << "Selamat datang di toko!!" << endl;
    cout << "Silahkan pilih barang yang akan Anda jual" << endl;
    cout << endl;
}
    
void Shop:: setupPlantAnimalItems(){
    vector<string> AV = Animal::getAnimalCodeConfig();
    vector<string> PV = Plant::getPlantCodeListConfig();
    for (int i=0; i<AV.size(); i++){
        this->ShopItems[AV[i]] = INFINITEQUANTITY;
    }for (int i=0; i<PV.size(); i++){
        this->ShopItems[PV[i]] = INFINITEQUANTITY;
    }
}

int Shop::numItemQuantityPositive(){
    int ans = 0;
    map<string, int>::iterator iterat;
    iterat = ShopItems.begin();
     while (iterat != ShopItems.end()){
        if (iterat->second > 0){
            ans++;
        }
        ++iterat;
    }
    return ans;
}

string Shop::getItemCodeFromIndex(int idx){
    int numItem = numItemQuantityPositive();
    if (idx > numItem){
        // Building
        idx -= numItem;
        map<string, int>::iterator iterat;
        iterat = ShopBuildings.begin();
        while (iterat != ShopBuildings.end()){
            if (iterat->second > 0){
                idx--;
                if (idx==0){
                    return iterat->first;
                }
            }
            ++iterat;
        }
        if (idx > 0){
            throw InputInvalidException("Nomor barang melebihi daftar diatas");
            return "";
        }
    } else { 
        // Non Building
        map<string, int>::iterator iterat;
        iterat = ShopItems.begin();
        while (iterat != ShopItems.end()){
            if (iterat->second > 0){
                idx--;
                if (idx==0){
                    return iterat->first;
                }
            }
            ++iterat;
        }
    }
    return "";
}

bool Shop::isInfinite(string itemCode){
    return getItemQuantity(itemCode)==INFINITEQUANTITY;
}

void Shop::insertItemNonBuilding(string itemCode, int amount){
    ShopItems[itemCode] = amount;
}

void Shop::insertItemBuilding(string itemCode, int amount){
    ShopBuildings[itemCode] = amount;
}

BlackMarket::BlackMarket() : Shop(){}

BlackMarket::~BlackMarket(){}

int BlackMarket::getPriceBlackMarket(string code, bool isBuy){
    float multiplier;
    if (isBuy){
        multiplier = 1 - BMPRICECHANGEPERCENTAGE;
    } else {
        multiplier = 1 + BMPRICECHANGEPERCENTAGE;
    }
    return Shop::getPriceFromCode(code) * multiplier;
}

void BlackMarket::showShopNonBuildings(){
    int i=1;
    map<string, int>::iterator it;
    string tempCode;
    string tempName;
    int tempPrice;
    it = ShopItems.begin();
    while (it != ShopItems.end()){
        if (it->second > 0){
            cout << i << ". ";
            tempCode = it->first;
            tempName = getNameFromCode(tempCode);
            tempPrice = getPriceBlackMarket(tempCode, true);
            cout << tempName;
            cout << " - ";
            cout << tempPrice;
            if (it->second==INFINITEQUANTITY){
                cout << endl;
            } else {
                cout << " (";
                cout << ShopItems[tempCode];
                cout << ")" << endl;
            }
            i++;
        }
        ++it;
    }
}

void BlackMarket::showShopBuildings(int prevNumber){
    int i = 1 + prevNumber;
    map<string, int>::iterator it;
    string tempCode;
    string tempName;
    int tempPrice;
    it = ShopBuildings.begin();
    while (it != ShopBuildings.end()){
        if (it->second > 0){
            cout << i << ". ";
            tempCode = it->first;
            tempName = Building::getBuildingNameConfig()[tempCode];
            tempPrice = Building::getBuildingPriceMapConfig()[tempCode] * (1-BMPRICECHANGEPERCENTAGE);
            cout << tempName;
            cout << " - ";
            cout << tempPrice;
            cout << " (";
            cout << ShopBuildings[tempCode];
            cout << ")" << endl;
            i++;
        }
        ++it;
    }
    cout << endl;
}

void BlackMarket::showShopTitle(bool isBuy){
    startTextBlue();
    cout << "     .-.      ___ _         _     __  __          _       _   " << endl;
    cout << "    (0.0)    | _ ) |__ _ __| |__ |  \\/  |__ _ _ _| |_____| |_ " << endl;
    cout << "  '=.|m|.='  | _ \\ / _` / _| / / | |\\/| / _` | '_| / / -_)  _|" << endl;
    cout << "  .='`\"``=.  |___/_\\__,_\\__|_\\_\\ |_|  |_\\__,_|_| |_\\_\\___|\\__|" << endl;
    if (rng(0, 3) == 0){
        cout << " Selamat Datang di Black Market... Jangan sampai pak walikota tau tentang kami!" << endl;
    } else if (rng(0, 3) == 1) {
        cout << " Selamat Datang di Black Market... Pastikan kamu tidak diikuti pak walikota" << endl;
    } else if (rng(0, 3) == 2){
        cout << " Selamat Datang di Black Market... Mari turunkan rezim pak walikota dengan menghancurkan ekonomi!" << endl;
    } else {
        cout << " Selamat Datang di Black Market... You are my sunshine... My only sunshine..." << endl;
    }
    if (isBuy){
        cout << " Pilih barang yang mau anda beli... Cepat! waktu kami tidak banyak" << endl;
    } else {
        cout << " Apa yang bisa anda tawarkan kepada kami... Cepat! waktu kami tidak banyak" << endl;
    }
    cout << endl;
    resetTextColor();
}