#include "header/animal.hpp"
#include "header/game.hpp"
#include "header/product.hpp"
#include <iostream>

using namespace std;

int main(){
    Game game;
    if(game.readConfig() == 1){
        cerr << "Config Reading Failed" << endl;
        return 0;
    }

    Animal temp;
    temp.printConfig();
    return 0;
}