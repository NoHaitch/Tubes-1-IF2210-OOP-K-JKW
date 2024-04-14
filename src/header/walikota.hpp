#ifndef WALIKOTA
#define WALIKOTA
#include "player.hpp"
#include "building.hpp"
// #include

class Mayor : public Player {
protected :

public :
    Mayor();
    ~Mayor();
    void tagihPajak();
    void addPetani();
    void addPeternak();
    
};



#endif