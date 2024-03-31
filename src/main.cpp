#include "header/animal.hpp"
#include <iostream>

using namespace std;

int main(){
    Animal A(1, "AAA", "Animal-1", 10, 5);
    Herbivore H(2, "HHH", "Herbivore-1", 20, 12);
    Carnivore C(3, "CCC", "Carnivore-1", 17, 17);
    Omnivore O(4, "OOO", "Omnivore-1", 9, 5);
    Cow a(1, "COW", 15, 12);
    Sheep b(2, "SHP", 13, 10);
    Horse c(3, "HRS", 21, 18);
    Rabbit d(4, "RBT", 12, 9);
    Snake e(5, "SNK", 11, 11);
    Chicken f(6, "CHK", 9, 5);
    Duck g(6, "DCK", 10, 7);

    cout << "ANIMALS: " << endl;
    cout << A << H << C << O << endl;
    cout << a << b << c << d << e << f << g << endl;

    Animal Href = e;
    Href.printInfo();
}