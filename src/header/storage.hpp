#ifndef __STORAGE_HPP__
#define __STORAGE_HPP__

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

#include "storageException.hpp"
#include "printColor.hpp"
#include "animal.hpp"
#include "plant.hpp"

using namespace std;

template <class T>
class Storage{
    private:
        /* Attributes */
        const int numRow;
        const int numCol;
        int numElmt;
        vector<vector<T*>> matrix;

        /* Configuration Variable */
        static pair<int, int> defaultStorageSize;

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
         * @brief Get element at position as coded from matrix
         *
         * @param y int row position
         * @param x int column position
         *
         * @return T element matrix[positionCode]
        */
        T getElmt(int y, int x);

        /**
         * @brief Check if the storage is full
         * 
         * @return bool whether the storage is full
        */
        bool isStorageFull();

        /**
         * @brief convert position code into indexes of storage
         * 
         * \note Throw exception if position code is invalid
         * 
         * @return pair of integers signifying <row, col>
        */
        pair<int, int> translatePositionCode(string positionCode);

        /**
         * @brief convert indexes of storage into position code
         * 
         * \note Throw exception if position code is invalid
         * 
         * @return Position code string
        */
        string translatePositionCode(int row, int col);

        /**
         * @brief Insert element elmt at a certain postion coded by positionCode
         * 
         * \note Throw exception if storage is full or code invalid
         * 
         * @param positionCode  string code for position
         * @param elmt  T element to be inserted
        */
        void insertElmtAtPosition(string positionCode, string codeElmt);

        /**
         * @brief Insert element elmt at an empty slot
         * 
         * \note Throw exception if storage is full
         * 
         * @param elmt  T element to be inserted
        */
        void insertElmtAtEmptySlot(string codeElmt);

        /**
         * @brief Delete element elmt at a certain postion coded by positionCode
         * 
         * \note Throw exception if code invalid or no items in that position
         * 
         * @param positionCode  string code for position
        */
        void deleteElmtAtPosition(string positionCode);

        /**
         * @brief Print storage elements as formatted
        */
        void printStorage();

        /**
         * @brief Read config for default storage size
         * 
         * @param size pair<int, int> the size of storage in height X width
        */
        static void readConfigDefaultSize(pair<int,int> size);

        /**
         * @brief cek apakah item pada slot positionCode kosong
         * @return true jika kosong
         */
        bool isEmpty(string idx);

        /**
         * @brief cek apakah item pada slot index x, y kosong
         * @return true jika kosong
         */
        bool isEmpty(int y, int x)
};

template class Storage<string>;
template class Storage<Animal>;
template class Storage<Plant>;

#endif