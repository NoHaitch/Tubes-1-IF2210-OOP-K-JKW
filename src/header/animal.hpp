// File: animal.hpp
#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>
#include <string>
using namespace std;

const string DEFAULTFOODTYPE = "any";
const int DEFAULTWEIGHT = 0;

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
        const string foodType;      // Food type
        
    public:
        /**
         * @brief ctor user defined.
         * 
         * @param _id               Animal id
         * @param _code             Animal code
         * @param _name             Animal name
         * @param _weightToHarvest  Minimum weight for animal to be harvested
         * @param _price            Price when sold/buy
         * @param _foodType         Food type
        */
        Animal(int _id, string _code, string _name, int _weightToHarvest, int _price, string _foodType = DEFAULTFOODTYPE, int _currWeight = DEFAULTWEIGHT);

        /**
         * @brief dtor
        */
        ~Animal();

        /**
         * @brief Get animal id
        */
        int getId() const;

        /**
         * @brief Get animal code
        */
        string getCode() const;

        /**
         * @brief Get animal name
        */
        string getName() const;
        
        /**
         * @brief Get animal price when sold/buy
        */
        int getPrice() const;

        /**
         * @brief Get animal minimum weight to be harvested
        */
        int getWeightToHarvest() const;

        /**
         * @brief Get animal current weight
        */
        int getCurrWeight() const;

        /**
         * @brief Set current weight to _weight
         * @param _weight new weight
        */
        void setCurrWeight(int _weight);

        /**
         * @brief Output Format: <id> <code> <name> <foodType> <currWeight> <weightToHarvest> <price>
         * 
         * @param os        output stream
         * @param animal    animal reference
         * 
         * @return Reference to the output stream.
        */
        friend ostream& operator<<(ostream& stream, const Animal& animal);
        
        /**
         * @brief Debuging tool, shows all variables.
         * 
        */
        virtual void printInfo();
};

class Herbivore : public Animal{  
    public:
        /**
         * @brief ctor user defined.
         * 
         * @param _id               Herbivore id
         * @param _code             Herbivore code
         * @param _name             Herbivore name
         * @param _weightToHarvest  Minimum weight to be harvested
         * @param _price            Price when sold/buy
         * @param _currWeight       Current Weight
        */
        Herbivore(int _id, string _code, string _name, int _weightToHarvest, int _price, int _currWeight = DEFAULTWEIGHT); 

        /**
         * @brief dtor
        */
        ~Herbivore();   

        /**
         * @brief Output Format: <id> <code> <name> <foodType> <currWeight> <weightToHarvest> <price>
         * 
         * @param os        output stream
         * @param herbivore herbivore reference
         * 
         * @return Reference to the output stream.
        */
        friend ostream& operator<<(ostream& os, const Herbivore& herbivore);

        /**
         * @brief Debuging tool, shows all variables.
         * 
        */
        virtual void printInfo() override;
};

class Carnivore : public Animal{  
    public:
        /**
         * @brief ctor user defined.
         * 
         * @param _id               Carnivore id
         * @param _code             Carnivore code
         * @param _name             Carnivore name
         * @param _weightToHarvest  Minimum weight to be harvested
         * @param _price            Price when sold/buy
         * @param _currWeight       Current Weight
        */
        Carnivore(int _id, string _code, string _name, int _weightToHarvest, int _price, int _currWeight = DEFAULTWEIGHT); 

        /**
         * @brief dtor
        */
        ~Carnivore();   

        /**
         * @brief Output Format: <id> <code> <name> <foodType> <currWeight> <weightToHarvest> <price>
         * 
         * @param os        Output stream
         * @param carnivore Carnivore reference
         * 
         * @return Reference to the output stream.
        */
        friend ostream& operator<<(ostream& os, const Carnivore& carnivore);

        /**
         * @brief Debuging tool, shows all variables.
         * 
        */
        virtual void printInfo() override;
};

class Omnivore : public Animal{  
    public:
        /**
         * @brief ctor user defined.
         * 
         * @param _id               Omnivore id
         * @param _code             Omnivore code
         * @param _name             Omnivore name
         * @param _weightToHarvest  Minimum weight to be harvested
         * @param _price            Price when sold/buy
         * @param _currWeight       Current Weight
        */
        Omnivore(int _id, string _code, string _name, int _weightToHarvest, int _price, int _currWeight = DEFAULTWEIGHT); 

        /**
         * @brief dtor
        */
        ~Omnivore();   

        /**
         * @brief Output Format: <id> <code> <name> <foodType> <currWeight> <weightToHarvest> <price>
         * 
         * @param os        Output stream
         * @param carnivore Carnivore reference
         * 
         * @return Reference to the output stream.
        */
        friend ostream& operator<<(ostream& os, const Omnivore& omnivore);

        /**
         * @brief Debuging tool, shows all variables.
         * 
        */
        virtual void printInfo() override;
};

#endif