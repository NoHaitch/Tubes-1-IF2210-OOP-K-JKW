#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <string>

#include "printColor.hpp"

using namespace std;

bool isNumber(const string& s);

void printTitle();

/**
        * @brief check item type from code
        *
        * \note returns one of ["Animal", "Plant", "Product", "Building"]
        * \note returns "" if item is empty (nullptr) or unidentified
        * 
        * @param itemCode string signifies the code of item
        * @return string item type
        */
        string itemType(char* itemCode);
#endif