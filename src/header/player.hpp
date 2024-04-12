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
        static int numPlayer;
        const int id;
        const string username;
        int wealth;
        int currWeight;
        Storage<string> ItemStorage;

        /* Default Variables */
        static const int DefaultPlayerStartingWealth = 50;
        static const int DefaultPlayerStartingWeight = 40;

    public:
        /**
         * @brief Default Player ctor
         * 
         * @param _username        Player username
        */
        Player(string _userName);

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
        void setWealth(int _wealth);

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
         * @brief Eat the requested food from storage, food eaten inputted by player, player weight increased
         * 
         * \note Food input isn't guaranteed to be valid
         * \note Throw exception if needed
         * 
         * 
        */
        void eatFromStorage();

        /**
         * @brief buy specified items with exact amount from the shop item list, then store in itemStorage
         * 
         * \note Validize whether the amount of money enough and storage slot sufficient
         * \note called from buy command
         * \note Throw exception if needed
         * 
         * 
        */
<<<<<<< HEAD
        void buyItems();
=======
        virtual void buy() = 0;
>>>>>>> 3b450cacce56933fd3b5a0025b56dd4fa3fad8cb

        /**
         * @brief sell specified items from storage into shops, players weight increase
         * 
         * \note Validize whether the item is available
         * \note called from sell command
         * \note Throw exception if needed
         * 
         * 
        */
        virtual void sell() = 0;

        /**
        * @brief check item type in a specified index
        *
        * \note index input is in string parameter
        * \note check whether index input is valid or not
        *
        * @param positionCode string signifies where is the postition of item to be checked
        * @return string item type
        */
        string itemType(string positionCode);


        /**
        * @brief check item type in a specified index
        *
        * \note index input is in string parameter
        * \note check whether index input is valid or not
        *
        * @param y int row position
        * @param x int column position
        * @return string item type
        */
        string itemType(int y, int x);

        /**
         * @brief calculate tax need to be paid by player
         * 
         * \note Mayor will return 0
        */
        virtual int calculateTax() = 0;

        /**
         * @brief pay the tax owed by player, wealth decreases by calculated tax
         * 
         * \note Mayor wealth increased, farmer/cattleman wealth decreased
        */
        virtual void payTax() = 0;

};

#endif 