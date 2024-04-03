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
    startTextBlue();
    cout << "Reading Configuration ..." << endl;
    if(game.readConfig() == 1){
        cerr << "Config Reading Failed" << endl;
        return 0;
    }
    resetTextColor();

    // Initialize Program State
    if(game.getGameStateIO() == 1){
        return 0;
    }

    return 0;
}