#ifndef __GAME_EXECPTION_HPP__
#define __GAME_EXECPTION_HPP__

#include <exception>
#include <string>
using namespace std;

class FileOpenFailedException : public exception {
    private:
        string message;

    public:
        FileOpenFailedException(string msg) : message(msg) {}
        string what () {
            return message;
        }
};

#endif