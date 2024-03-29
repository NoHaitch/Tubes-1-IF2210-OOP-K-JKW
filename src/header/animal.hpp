// File: animal.hpp
#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>
#include <string>
using namespace std;

/**
 * Base Class Animal yang digunakan oleh Class Peternak 
 * 
 * Childrens : Herbivore, Carnivore, Omnivore
 *
*/
class Animal{
    protected:
        int id;                     // Animal id
        string code;                // Animal code
        string name;                // Animal name
        int currWeight;             // Animal current weight 
        const int weightToHarvest;  // Animal minimum weight for animal to be harvested
        const int price;            // Animal price
        
    public:
        /**
         * @brief ctor user defined.
         * 
         * @param _id               animal id
         * @param _code             animal code
         * @param _name             animal name
         * @param _weightToHarvest  minimum weight for animal to be harvested
         * @param _price            price when sold/buy
         * @param _currWeight       current weight, default=0
        */
        Animal(int _id, string _code, string _name, int _weightToHarvest, int _price, int currWeight=0);

        /**
         * @brief dtor
        */
        ~Animal();

        /**
         * @return Animal id
        */
        int getId() const;

        /**
         * @return Animal code
        */
        string getCode() const;

        /**
         * @return Animal name
        */
        string getName() const;
        
        /**
         * @return Animal price when sold/buy
        */
        int getPrice() const;

        /**
         * @return Animal minimum weight to be harvested
        */
        int getWeightToHarvest() const;

        /**
         * @return Animal current weight
        */
        int getCurrWeight() const;

        /**
         * @brief Set current weight to _weight
         * @param _weight
        */
        void setCurrWeight(int _weight);

        /**
         * @brief Format: <id> <code> <name> <currWeight> <weightToHarvest> <price>
         * 
         * @param os The output stream where the Animal details will be inserted.
         * @param animal The Animal object whose details will be inserted into the output stream.
         * @return Reference to the output stream.
        */
        friend ostream& operator<<(ostream& os, const Animal& animal);
        
        /**
         * @brief Debuging tool, shows all variables.
         * 
        */
        virtual void printInfo();
};



#endif