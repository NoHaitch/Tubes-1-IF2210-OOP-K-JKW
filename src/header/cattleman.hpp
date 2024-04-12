#ifndef __CATTLEMAN_HPP__
#define __CATTLEMAN_HPP__

#include "player.hpp"

class Cattleman : public Player{
    public:
        Cattleman(string _username);
        Cattleman(string _username, int _wealth, int _currWeight);
        ~Cattleman();
};

#endif