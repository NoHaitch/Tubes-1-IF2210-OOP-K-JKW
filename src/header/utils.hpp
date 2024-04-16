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
string itemType(string* itemCode);

/**
 * @brief convert item name into the code of the item
 * @param itemName string name of the item
 * @return itemCode string code of the item
 */
string convertItemNameToCode(string itemName);

/**
 * @brief convert item Code into the Name of the item
 * @param itemCode string Code of the item
 * @return itemName string Name of the item
 */
string convertItemCodeToName(string itemCode);


#endif