// File: animal.hpp
#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>
#include <string>
using namespace std;

/* Global Variables for Default Values */
const string DefaultAnimalFoodType = "ANY";
const string DefaultAnimalFoodTypeHerbivore = "HERBIVORE";
const string DefaultAnimalFoodTypeCarnivore = "CARNIVORE";
const string DefaultAnimalFoodTypeOmnivore = "OMNIVORE";
const string DefaultAnimalNameCow = "COW";
const string DefaultAnimalNameSheep = "SHEEP";
const string DefaultAnimalNameHorse = "HORSE";
const string DefaultAnimalNameRabbit = "RABBIT";
const string DefaultAnimalNameSnake = "SNAKE";
const string DefaultAnimalNameChicken = "CHICKEN";
const string DefaultAnimalNameDuck = "DUCK";
const int DefaultAnimalStartingWeight = 0;

/**
 * @brief Class Animal used by Peternak
 * 
 * \note  - Childrens : Herbivore, Carnivore, Omnivore
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
        const string foodType;      // Animal Food type
        
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
        Animal(int _id, string _code, string _name, int _weightToHarvest, int _price, string _foodType = DefaultAnimalFoodType, int _currWeight = DefaultAnimalStartingWeight);

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
         * @param _id               Herbivore id
         * @param _code             Herbivore code
         * @param _name             Herbivore name
         * @param _weightToHarvest  Minimum weight to be harvested
         * @param _price            Price when sold/buy
         * @param _currWeight       Starting Weight, default = 0
        */
        Herbivore(int _id, string _code, string _name, int _weightToHarvest, int _price, int _currWeight = DefaultAnimalStartingWeight); 

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
         * @param _id               Carnivore id
         * @param _code             Carnivore code
         * @param _name             Carnivore name
         * @param _weightToHarvest  Minimum weight to be harvested
         * @param _price            Price when sold/buy
         * @param _currWeight       Starting Weight, default = 0
        */
        Carnivore(int _id, string _code, string _name, int _weightToHarvest, int _price, int _currWeight = DefaultAnimalStartingWeight); 

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
         * @param _id               Omnivore id
         * @param _code             Omnivore code
         * @param _name             Omnivore name
         * @param _weightToHarvest  Minimum weight to be harvested
         * @param _price            Price when sold/buy
         * @param _currWeight       Starting Weight, default = 0
        */
        Omnivore(int _id, string _code, string _name, int _weightToHarvest, int _price, int _currWeight = DefaultAnimalStartingWeight); 

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

/**
 * @brief Class Cow used by Peternak
 * 
 * \note - Parent: Herbivore
 * 
*/
class Cow : public Herbivore{
    public:
    /**
         * @brief ctor user defined.
         * 
         * @param _id               Cow id
         * @param _code             Cow code
         * @param _weightToHarvest  Minimum weight to be harvested
         * @param _price            Price when sold/buy
         * @param _currWeight       Starting Weight, default = 0
        */
        Cow(int _id, string _code, int _weightToHarvest, int _price, int _currWeight = DefaultAnimalStartingWeight); 

        /**
         * @brief dtor
        */
        ~Cow();   

        /**
         * @brief Output Format: <id> <code> <name> <foodType> <currWeight> <weightToHarvest> <price>
         * 
         * @param os    output stream
         * @param cow   cow reference
         * 
         * @return Reference to the output stream.
        */
        friend ostream& operator<<(ostream& os, const Cow& cow);

        /**
         * @brief Debuging tool, shows all variables.
         * 
        */
        void printInfo() override;
};

/**
 * @brief Class Sheep used by Peternak
 * 
 * \note - Parent: Herbivore
 * 
*/
class Sheep : public Herbivore{
    public:
    /**
         * @brief ctor user defined.
         * 
         * @param _id               Sheep id
         * @param _code             Sheep code
         * @param _weightToHarvest  Minimum weight to be harvested
         * @param _price            Price when sold/buy
         * @param _currWeight       Starting Weight, default = 0
        */
        Sheep(int _id, string _code, int _weightToHarvest, int _price, int _currWeight = DefaultAnimalStartingWeight); 

        /**
         * @brief dtor
        */
        ~Sheep();   

        /**
         * @brief Output Format: <id> <code> <name> <foodType> <currWeight> <weightToHarvest> <price>
         * 
         * @param os    output stream
         * @param sheep   sheep reference
         * 
         * @return Reference to the output stream.
        */
        friend ostream& operator<<(ostream& os, const Sheep& sheep);

        /**
         * @brief Debuging tool, shows all variables.
         * 
        */
        void printInfo() override;
};

/**
 * @brief Class Horse used by Peternak
 * 
 * \note - Parent: Herbivore
 * 
*/
class Horse : public Herbivore{
    public:
    /**
         * @brief ctor user defined.
         * 
         * @param _id               Horse id
         * @param _code             Horse code
         * @param _weightToHarvest  Minimum weight to be harvested
         * @param _price            Price when sold/buy
         * @param _currWeight       Starting Weight, default = 0
        */
        Horse(int _id, string _code, int _weightToHarvest, int _price, int _currWeight = DefaultAnimalStartingWeight); 

        /**
         * @brief dtor
        */
        ~Horse();   

        /**
         * @brief Output Format: <id> <code> <name> <foodType> <currWeight> <weightToHarvest> <price>
         * 
         * @param os    output stream
         * @param horse   horse reference
         * 
         * @return Reference to the output stream.
        */
        friend ostream& operator<<(ostream& os, const Horse& horse);

        /**
         * @brief Debuging tool, shows all variables.
         * 
        */
        void printInfo() override;
};

/**
 * @brief Class Rabbit used by Peternak
 * 
 * \note - Parent: Herbivore
 * 
*/
class Rabbit : public Herbivore{
    public:
    /**
         * @brief ctor user defined.
         * 
         * @param _id               Rabbit id
         * @param _code             Rabbit code
         * @param _weightToHarvest  Minimum weight to be harvested
         * @param _price            Price when sold/buy
         * @param _currWeight       Starting Weight, default = 0
        */
        Rabbit(int _id, string _code, int _weightToHarvest, int _price, int _currWeight = DefaultAnimalStartingWeight); 

        /**
         * @brief dtor
        */
        ~Rabbit();   

        /**
         * @brief Output Format: <id> <code> <name> <foodType> <currWeight> <weightToHarvest> <price>
         * 
         * @param os    output stream
         * @param rabbit   rabbit reference
         * 
         * @return Reference to the output stream.
        */
        friend ostream& operator<<(ostream& os, const Rabbit& rabbit);

        /**
         * @brief Debuging tool, shows all variables.
         * 
        */
        void printInfo() override;
};

/**
 * @brief Class Snake used by Peternak
 * 
 * \note - Parent: Carnivore
 * 
*/
class Snake : public Carnivore{
    public:
    /**
         * @brief ctor user defined.
         * 
         * @param _id               Snake id
         * @param _code             Snake code
         * @param _weightToHarvest  Minimum weight to be harvested
         * @param _price            Price when sold/buy
         * @param _currWeight       Starting Weight, default = 0
        */
        Snake(int _id, string _code, int _weightToHarvest, int _price, int _currWeight = DefaultAnimalStartingWeight); 

        /**
         * @brief dtor
        */
        ~Snake();   

        /**
         * @brief Output Format: <id> <code> <name> <foodType> <currWeight> <weightToHarvest> <price>
         * 
         * @param os    output stream
         * @param snake   snake reference
         * 
         * @return Reference to the output stream.
        */
        friend ostream& operator<<(ostream& os, const Snake& snake);

        /**
         * @brief Debuging tool, shows all variables.
         * 
        */
        void printInfo() override;
};

/**
 * @brief Class Chicken used by Peternak
 * 
 * \note - Parent: Carnivore
 * 
*/
class Chicken : public Omnivore{
    public:
    /**
         * @brief ctor user defined.
         * 
         * @param _id               Chicken id
         * @param _code             Chicken code
         * @param _weightToHarvest  Minimum weight to be harvested
         * @param _price            Price when sold/buy
         * @param _currWeight       Starting Weight, default = 0
        */
        Chicken(int _id, string _code, int _weightToHarvest, int _price, int _currWeight = DefaultAnimalStartingWeight); 

        /**
         * @brief dtor
        */
        ~Chicken();   

        /**
         * @brief Output Format: <id> <code> <name> <foodType> <currWeight> <weightToHarvest> <price>
         * 
         * @param os    output stream
         * @param chicken   chicken reference
         * 
         * @return Reference to the output stream.
        */
        friend ostream& operator<<(ostream& os, const Chicken& chicken);

        /**
         * @brief Debuging tool, shows all variables.
         * 
        */
        void printInfo() override;
};

/**
 * @brief Class Duck used by Peternak
 * 
 * \note - Parent: Carnivore
 * 
*/
class Duck : public Omnivore{
    public:
    /**
         * @brief ctor user defined.
         * 
         * @param _id               Duck id
         * @param _code             Duck code
         * @param _weightToHarvest  Minimum weight to be harvested
         * @param _price            Price when sold/buy
         * @param _currWeight       Starting Weight, default = 0
        */
        Duck(int _id, string _code, int _weightToHarvest, int _price, int _currWeight = DefaultAnimalStartingWeight); 

        /**
         * @brief dtor
        */
        ~Duck();   

        /**
         * @brief Output Format: <id> <code> <name> <foodType> <currWeight> <weightToHarvest> <price>
         * 
         * @param os    output stream
         * @param duck   duck reference
         * 
         * @return Reference to the output stream.
        */
        friend ostream& operator<<(ostream& os, const Duck& duck);

        /**
         * @brief Debuging tool, shows all variables.
         * 
        */
        void printInfo() override;
};

#endif