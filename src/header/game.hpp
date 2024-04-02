// File: game.hpp
#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Game{
    public:
        Game();
        ~Game();

        void readConfigPlant();
        void readConfigAnimal();
        void readConfigProduct();
        void readConfigRecipe();
        void readConfigMisc();
        int readConfig();

        void save();
        void load();
};

#endif