#ifndef __MAYOR__
#define __MAYOR__

#include "player.hpp"

class Mayor : public Player {
    public:
        Mayor(string _username);
        Mayor(string _username, int _wealth, int _currWeight);
        ~Mayor();
};


#endif