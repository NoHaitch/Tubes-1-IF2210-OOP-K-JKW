#include "header/printColor.hpp"
#include <iostream>

using namespace std;

void startTextRed(){
    cout << "\033[1;31m";
}

void startTextGreen(){
    cout << "\033[1;32m";
}

void startTextYellow(){
    cout << "\033[1;33m";
}

void resetTextColor(){
    cout << "\033[0m";
}
