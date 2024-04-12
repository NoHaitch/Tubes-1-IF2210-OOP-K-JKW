#ifndef __PLAYER_EXCEPTION_HPP__
#define __PLAYER_EXCEPTION_HPP__

#include <exception>
#include <string>
using namespace std;

class InedibleProductException : public exception {
    private:
        string message;
    
    public:
        InedibleProductException() : message("Selected product is Inedible"){}
        InedibleProductException(string msg) : message(msg) {}
        string what (){
            return message;
        }
};

class NotProductException : public exception {
    private:
        string message;
    
    public:
        NotProductException() : message("Selected item is Inedible"){}
        NotProductException(string msg) : message(msg) {}
        string what (){
            return message;
        }
};

#endif