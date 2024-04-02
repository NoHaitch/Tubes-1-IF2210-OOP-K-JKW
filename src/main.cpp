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
    cout << endl;

    Cow a;
    Sheep b;
    Horse c;
    Rabbit d;
    Snake e;
    Chicken f;
    Duck g;
    cout << a << b << c << d << e << f << g;

    return 0;
}