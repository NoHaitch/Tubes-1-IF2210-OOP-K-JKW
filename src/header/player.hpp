#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "storage.hpp"
#include "product.hpp"

using namespace std;

/**
 * @brief Class Player
 * 
 * \note - Childrens : Mayor, Cattleman, Farmer
 *
*/
class Player{
    protected:
        /* Attributes */
        const int id;
        const string username;
        int wealth;
        int currWeight;
        Storage<string> ItemStorage;

        /* Configuration Variables */
        /* -- TODO : HANDLE CONFIGURATION FROM STATE.TXT -- */

        /* Default Variables */
        static const int DefaultPlayerStartingWealth = 50;
        static const int DefaultPlayerStartingWeight = 40;

    public:
        /**
         * @brief Default Player ctor
         * 
         * @param _username        Player username
        */
        Player(string _username);

        /**
         * @brief Player ctor user defined.
         * 
         * @param _username        Player username
         * @param _wealth          Player Wealth
         * @param _currWeight      Starting Weight
        */
        Player(string _username, int _wealth, int _currWeight);

        /**
        * @brief Player dtor
        */
        ~Player();

        /**
         * @brief Get Player id
         * 
         * @return int Player id 
        */
        int getId() const;

        /**
         * @brief Get Player username
         * 
         * @return string Player username 
        */
        string getUsername() const;

        /**
         * @brief Get Player wealth
         * 
         * @return int Player wealth 
        */
        int getWealth() const;

        /**
         * @brief Get Player current weight
         * 
         * @return int Player current weight 
        */
        int getCurrWeight() const;

        /**
         * @brief Set Player wealth
         * 
         * @param _wealth new wealth
        */
        void setWealth();

        /**
         * @brief Set Player current weight
         * 
         * @param _currWeight new current weight
         * 
        */
        void setCurrWeight(int _currWeight);

        /**
         * @brief Print player's item storage
        */
        void printItemStorage();

        /**
         * @brief Eat the requested food from storage, player weight increased
         * 
         * \note Food isn't guaranteed to be valid
         * \note Throw exception if needed
         * 
         * @param positionCode string signifies where is the food to be eaten from storage
         * 
        */
        void eatFromStorage(string positionCode);

        /**
         * @brief buy specified items with exact amount from the shop item list, then store in itemStorage
         * 
         * \note Validize whether the amount of money enough and storage slot sufficient
         * \note Throw exception if needed
         * 
         * 
        */
        void buyItems();

        /**
         * @brief sell specified items from storage into shops, players weight increase
         * 
         * \note Validize whether the item is available
         * \note Throw exception if needed
         * 
         * @param positionCode string signifies where is the postition of item to be sold
         * 
        */
        void sellItems(string positionCode);
};

#endif __PLAYER_HPP__