#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include "product.hpp"

using namespace std;

/**
 * @brief Class Animal used by Peternak
 * 
 * \note - Childrens : Herbivore, Carnivore, Omnivore
 *
*/
class Animal{

    protected:
        const int id;               // Animal id
        const string code;          // Animal code
        const string name;          // Animal name
        const int weightToHarvest;  // Animal minimum weight for animal to be harvested
        const int price;            // Animal price
        const string foodType;      // Animal Food type
        int currWeight;             // Animal current weight 

        
        /* Configuration Variables */
        static vector<string> configName;               // Animal Configuration Names
        static map<string, int> configID;               // Animal Configuration Key: Name, Value: Animal Id, Id starts from 1.
        static map<string, string> configCode;          // Animal Configuration Codes
        static map<string, string> configFoodType;      // Animal Configuration Food Types
        static map<string, int> configWeightToHarvest;  // Animal Configuration Weights To Harvest
        static map<string, int> configPrice;            // Animal Configuration Prices
        
        /* Default Variables */
        static const int DefaultAnimalStartingWeight;
        static const string DefaultAnimalFoodTypeHerbivore;
        static const string DefaultAnimalFoodTypeCarnivore;
        static const string DefaultAnimalFoodTypeOmnivore;

    public:
        /**
         * @brief Animal ctor
         * 
         * \note For actual object dont use this ctor.
         * \note This is for calling initial game function.
         * \note e.g. reading config files.
         * 
         */
        Animal();

        /**
         * @brief ctor user defined.
         * 
         * @param _name              Animal Name
         * @param _foodType          Animal Food Type
         * @param _currWeight       Starting Weight, default = 0
        */
        Animal(string _name, string _foodType, int _currWeight = DefaultAnimalStartingWeight); 

        /**
         * @brief dtor
        */
        ~Animal();

        /**
         * @brief Get animal id
         * 
         * @return int animal id 
        */
        int getId() const;

        /**
         * @brief Get animal code
         * 
         * @return string animal code
        */
        string getCode() const;

        /**
         * @brief Get animal name
         * 
         * @return string animal name
        */
        string getName() const;
        
        /**
         * @brief Get animal price when sold/buy
         * 
         * @return int animal price
        */
        int getPrice() const;

        /**
         * @brief Get animal minimum weight to be harvested
         * 
         * @return int animal weight to harvest
        */
        int getWeightToHarvest() const;

        /**
         * @brief Get animal food type
         * 
         * @return string animal weight to harvest
        */
        string getFoodType() const;

        /**
         * @brief Get animal current weight
         * 
         * @return int animal current weight
        */
        int getCurrWeight() const;

        /**
         * @brief Set current weight to _weight
         * @param _weight new weight
        */
        void setCurrWeight(int _weight);

        /**
         * @brief Add weigth to the current weight
         * 
         * @param weight added weight
        */
        void addWeight(int weight);

        /**
         * @brief Check if Animal is ready to be harvested
         * \note if animal current weight >= minimum weight to be harvested
         * 
         * @return true if ready to be harvest
         * @return false if not ready to be harvest
         */
        bool isReadyToHarvest();

        /**
         * @brief Add new Configuration for Animal
         * 
         * @param _id               Animal id
         * @param _code             Animal code
         * @param _name             Animal name
         * @param _foodType         Food type 
         * @param _weightToHarvest  Minimum weight for animal to be harvested
         * @param _price            Price when sold/buy
         */
        void AddAnimalConfig(int _id, string _code, string _name, string _foodtype, int _weightToHarvest, int _price);

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

        /**
         * @brief Debuging tool, shows all configuration variables
         * 
        */
        void printConfig();
};

/**
 * @brief Class Herbivore used by Peternak
 * 
 * \note - Parent: Animal
 * \note - Childrens: Cow, Sheep, Horse, Rabbit
 * 
*/
class Herbivore : public Animal{  
    public:
        /**
         * @brief ctor user defined.
         * 
         * @param name              Animal Name
         * @param _currWeight       Starting Weight, default = 0
        */
        Herbivore(string name, int _currWeight = DefaultAnimalStartingWeight); 

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

/**
 * @brief Class Carnivore used by Peternak
 * 
 * \note - Parent: Animal
 * \note - Childrens: Snake
 * 
*/
class Carnivore : public Animal{  
    public:
        /**
         * @brief ctor user defined.
         * 
         * @param name              Animal Name
         * @param _currWeight       Starting Weight, default = 0
        */
        Carnivore(string name, int _currWeight = DefaultAnimalStartingWeight); 

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

/**
 * @brief Class Omnivore used by Peternak
 * 
 * \note - Parent: Animal
 * \note - Childrens: Chiken, Duck
 * 
*/
class Omnivore : public Animal{  
    public:
        /**
         * @brief ctor user defined.
         * 
         * @param name              Animal Name
         * @param _currWeight       Starting Weight, default = 0
        */
        Omnivore(string name, int _currWeight = DefaultAnimalStartingWeight); 

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