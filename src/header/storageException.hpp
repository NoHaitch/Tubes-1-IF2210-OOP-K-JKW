#ifndef __STORAGE_EXCEPTION_HPP__
#define __STORAGE_EXCEPTION_HPP__

#include <exception>
#include <string>
using namespace std;

class PositionCodeInvalidException : public exception {
    private:
        string message;
    
    public:
        PositionCodeInvalidException() : message("Position Code is not valid for this storage"){}
        PositionCodeInvalidException(string msg) : message(msg) {}
        string what (){
            return message;
        }
};

class StorageFullException : public exception {
    private:
        string message;
    
    public:
        StorageFullException() : message("Storage is already full"){}
        StorageFullException(string msg) : message(msg) {}
        string what (){
            return message;
        }
};

#endif