#ifndef __STORAGE_HPP__
#define __STORAGE_HPP__

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

using namespace std;

template <class T>
class Storage{
    private:
        /* Attributes */
        const int numRow;
        const int numCol;
        int numElmt;
        T* matrix;

    public:
        /**
         * @brief Default Storage ctor
        */
        Storage();

        /**
         * @brief User Defined Storage ctor
         * 
         * @param _numRow   number of rows
         * @param _numCol   number of columns
         * 
        */
        Storage(int _numRow, int _numCol);

        /**
         * @brief Storage dtor
        */
        ~Storage();

        /**
         * @brief Get number of rows
         * 
         * @return int numRow
        */
        int getNumRow();

        /**
         * @brief Get number of columns
         * 
         * @return int numCol
        */
        int getNumCol();

        /**
         * @brief Get number of elements
         * 
         * @return int numElmt
        */
        int getNumElmt();

        /**
         * @brief Get element at position as coded from matrix
         * 
         * @param positionCode  string code for position
         * 
         * @return T element matrix[positionCode]
        */
        T getElmt(string positionCode);

        /**
         * @brief Check if the storage is full
         * 
         * @return bool whether the storage is full
        */
        bool isStorageFull();

        /**
         * @brief Insert element elmt at a certain postion coded by positionCode
         * 
         * \note Throw exception if storage is full or code invalid
         * 
         * @param positionCode  string code for position
         * @param elmt  T element to be inserted
        */
        void insertElmtAtPosition(string postionCode, T elmt);

        /**
         * @brief Insert element elmt at an empty slot
         * 
         * \note Throw exception if storage is full
         * 
         * @param elmt  T element to be inserted
        */
        void insertElmtAtEmptySlot(T elmt);

        /**
         * @brief Delete element elmt at a certain postion coded by positionCode
         * 
         * \note Throw exception if code invalid or no items in that position
         * 
         * @param positionCode  string code for position
        */
        void deleteElmtAtPosition(string postionCode);

        /**
         * @brief Print storage elements as formatted
        */
        void printStorage();

};

#endif __STORAGE_HPP__