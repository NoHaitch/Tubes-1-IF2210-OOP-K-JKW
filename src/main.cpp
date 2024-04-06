#include "header/animal.hpp"
#include "header/game.hpp"
#include "header/product.hpp"
#include "header/printColor.hpp"
#include <iostream>

using namespace std;
    
int main(){
    // Starting a Game
    Game game;

    // Reading Configuration
    if(game.readConfig() == 1){
        cerr << "Config Reading Failed" << endl;
        return 0;
    }
    resetTextColor();

    game.getGameStateIO();
    
    return 0;
}