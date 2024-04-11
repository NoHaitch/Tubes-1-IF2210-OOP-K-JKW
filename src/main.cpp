#include "header/animal.hpp"
#include "header/game.hpp"
#include "header/product.hpp"
#include "header/printColor.hpp"
#include "header/storage.hpp"
#include "header/utils.hpp"
#include <iostream>
#include <string>

using namespace std;
    
int main(){
    // Print title
    printTitle();

    // Starting a Game
    Game game;

    // Reading Configuration
    if(game.readConfig() == 1){
        cerr << "Config Reading Failed" << endl;
        return 0;
    }
    resetTextColor();

    Storage<string> s;
    s.insertElmtAtEmptySlot("COW");
    s.insertElmtAtEmptySlot("BNT");
    s.printStorage();

    game.getGameStateIO();
    
    return 0;
}