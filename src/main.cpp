#include "header/animal.hpp"
#include <iostream>

using namespace std;

int main(){
    Animal A(0, "AAA", "Animal", 0, 0, 0);
    cout << A << endl;
    A.printInfo();
}