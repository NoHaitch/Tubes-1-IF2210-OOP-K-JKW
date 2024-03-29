#include "header/animal.hpp"
#include <iostream>

using namespace std;

int main(){
    Animal A(1, "AAA", "Animal-1", 10, 5);
    Herbivore H(2, "HHH", "Herbivore-1", 20, 12);
    Carnivore C(3, "CCC", "Carnivore-1", 17, 17);
    Omnivore O(4, "OOO", "Omnivore-1", 9, 5);
    
    cout << A << H << C << O << endl;

    A.printInfo();
    H.printInfo();
    C.printInfo();
    O.printInfo();
    
    Animal Href = H;
    Href.printInfo();
}