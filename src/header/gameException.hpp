#ifndef __GAME_EXECPTION_HPP__
#define __GAME_EXECPTION_HPP__

#include <exception>
#include <string>
using namespace std;

class FileOpenFailedException : public exception {
    private:
        string message;

    public:
        FileOpenFailedException() : message("Failed to open File") {}
        FileOpenFailedException(string msg) : message(msg) {}
        string what () {
            return message;
        }
};

class FilePathException : public exception {
    private:
        string message;

    public:
        FilePathException() : message("File path is not valid") {}
        FilePathException(string msg) : message(msg) {}
        string what () {
            return message;
        }
};

class FileFormatException : public exception {
    private:
        string message;

    public:
        FileFormatException() : message("File format is not valid") {}
        FileFormatException(string msg) : message(msg) {}
        string what () {
            return message;
        }
};

class DirectoryNotFoundException : public exception {
    private:
        string message;

    public:
        DirectoryNotFoundException() : message("Directory not found") {}
        DirectoryNotFoundException(string msg) : message(msg) {}
        string what () {
            return message;
        }
};

class DirectoryCreationFailedException : public exception {
    private:
        string message;

    public:
        DirectoryCreationFailedException() : message("Creating directory failed, make sure path is correct") {}
        DirectoryCreationFailedException(string msg) : message(msg) {}
        string what () {
            return message;
        }
};

#endif