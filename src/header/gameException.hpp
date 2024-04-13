#ifndef __GAME_EXECPTION_HPP__
#define __GAME_EXECPTION_HPP__

#include <exception>
#include <string>
using namespace std;

class FileNotFoundException : public exception {
    private:
        string message;

    public:
        FileNotFoundException() : message("Failed to open File") {}
        FileNotFoundException(string msg) : message(msg) {}
        string what () {
            return message;
        }
};

class FileBadPathException : public exception {
    private:
        string message;

    public:
        FileBadPathException() : message("File path is not valid") {}
        FileBadPathException(string msg) : message(msg) {}
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

class FileReadingFailedException : public exception {
    private:
        string message;

    public:
        FileReadingFailedException() : message("File reading failed") {}
        FileReadingFailedException(string msg) : message(msg) {}
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
        DirectoryCreationFailedException() : message("Creating directory failed, path is not correct") {}
        DirectoryCreationFailedException(string msg) : message(msg) {}
        string what () {
            return message;
        }
};

class PlayerNameIsTakken : public exception{
    private:
        string message;

    public:
        PlayerNameIsTakken() : message("Player Name already exist") {}
        PlayerNameIsTakken(string msg) : message(msg) {}
        string what () {
            return message;
        }
};

class PlayerNotFound : public exception{
    private:
        string message;

    public:
        PlayerNotFound() : message("Player Not Found") {}
        PlayerNotFound(string msg) : message(msg) {}
        string what () {
            return message;
        }
};

class CommandWrongRole : public exception{
    private:
        string message;

    public:
        CommandWrongRole() : message("Perintah tidak dapat dilakukan.") {}
        CommandWrongRole(string msg) : message("Perintah tidak dapat dilakukan." + msg) {}
        string what () {
            return message;
        }
};

#endif