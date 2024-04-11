#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <ctype.h>

#include <fstream>
#include <sstream>
#include <filesystem>

#include "gameException.hpp"
#include "animal.hpp"
#include "plant.hpp"
#include "printColor.hpp"
#include "utils.hpp"
#include "product.hpp"
#include "player.hpp"
#include "shop.hpp"

using namespace std;

class Game{
    private:
        Shop shop;
        int currTurn;
        vector<string> playerUsernames;
        map<string, int> convertToId;
        // Mayor mayor;
        // vector<Farmer> farmers;
        // vector<Cattleman> cattlemans;

    public:
        /**
         * @brief ctor
         * \note Print to cout "Game Started"
         * 
        */
        Game();

        /**
         * @brief dtor
         * 
        */
        ~Game();

        /**
         * @brief Read all configuration
         * 
        */
        int readConfig();

        /**
         * @brief Read/Load a Game state
         * 
         * @param path to a save file
        */
        void readGameState(string path);

        /**
         * @brief Initilize new Game State
         * 
        */
        void initGameState();

        /**
         * @brief Ask for game state with menu
         * \note Options:
         * \note 1. New Game
         * \note 2. Load Game
         * \note 3. Exit
         * 
        */
        void getGameStateIO();

        /**
         * @brief Save game state
         * \note Doesn't check if the new save overwrite an older save
         * 
         * @param path 
        */
        void saveGame(string path);

        /**
         * @brief Save game state with Input Output
         * \note will ask for file path
         * 
         * @param path 
        */
        void saveGameIO();

    private:
        /**
         * @brief Create the directory, but not the file for the path
         * 
         * @param path 
        */
        void makeDirectory(string path);

                /**
         * @brief Read plant configuration
         * 
        */
        void readConfigPlant();

        /**
         * @brief Read animal configuration
         * 
        */
        void readConfigAnimal();

        /**
         * @brief Read product configuration
         * 
        */
        void readConfigProduct();

        /**
         * @brief Read recipe configuration
         * 
        */
        void readConfigRecipe();

        /**
         * @brief Read misc configuration
         * 
        */
        void readConfigMisc();
};

#endif