#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctype.h>

#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include <fstream>
#include <sstream>
#include <filesystem>

#include "animal.hpp"
#include "plant.hpp"
#include "storage.hpp"
#include "player.hpp"
#include "mayor.hpp"
#include "farmer.hpp"
#include "cattleman.hpp"
#include "product.hpp"
#include "printColor.hpp"
#include "utils.hpp"
#include "building.hpp"
#include "shop.hpp"
#include "gameException.hpp"

using namespace std;

class Farmer; // For compiler reason. This makes the compiler think that Farmer exist thus not giving an error.
class Mayor; // For compiler reason. This makes the compiler think that Mayor exist thus not giving an error.

class Game{
    private:
        Shop *shop;                     // Shop
        BlackMarket *blackMarket;       // Black Market
        int currTurn = -1;              // current Turn, -1 means the game just started
        vector<string> playerOrder;     // Player Username sorted lexicographicly

        Mayor* mayor;                   // Mayor reference               
        vector<Farmer> farmers;         // Farmer objects
        vector<Cattleman> cattlemans;   // Cattleman objects

        int winWealth;                  // Winning Condition for wealth
        int winWeight;                  // Winning Condition for weight           
        int day;     

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
         * @brief Get the amount of current player 
         * 
         * @return int amount of current player
         */
        int getPlayerAmount();

        /**
         * @brief Change player turn 
         * 
        */
        void nextTurn();

        /**
         * @brief Change player turn with Input Output 
         * 
        */
        void nextTurnIO();
        
        /**
         * @brief Print all Commands  
         * 
        */
        void printCommands();

        /**
         * @brief Player Command 
         * 
         * \note return 1, for exit 
         * \note return 2, for next 
         * \note return 0, for other commands
        */
        int playerCommandIO();

        /**
         * @brief Get Player object pointer
         * 
         */
        Player* getCurrentPlayer();

        /**
         * @brief Get Player object pointer
         * 
         */
        Player* getPlayer(string playerUsername);

        /**
         * @brief Check Current Player for Winning Condition 
         * 
        */
        bool checkWinningCondition();

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
         * @brief Read/Load a Game state
         * 
         * @param path to a save file
        */
        void readGameState(string path);

        /**
         * @brief Read all configuration
         * 
        */
        int readConfig();

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
    
        /**
         * @brief print the game winner
         * 
        */
        void printWinner();

        /**
         * @brief debugging
         * 
        */
        void printPlayerTurnOrder();

        /**
         * @brief Print Player Info
         * 
         * @param player 
         */
        void printInfo(Player *player);

        /**
         * @brief Get Player Role
         * 
         * @param player 
         * @return string 
         */
        string getPlayerRole(Player* player);

        /**
         * @brief Print All Player and their Role
         * 
         */
        void printPlayers();

    private:
        /**
         * @brief Add Player to The Turn Order
         * 
         * @param playerName 
        */
        void addPlayerToTurnOrder(string playerName);

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

        /**
         * @brief Reset Game State
         * 
         */
        void resetGameState();

};

#endif