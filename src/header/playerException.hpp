#ifndef __PLAYER_EXCEPTION_HPP__
#define __PLAYER_EXCEPTION_HPP__

#include <exception>
#include <string>
using namespace std;

class InedibleProductException : public exception {
    private:
        string message;
    
    public:
        InedibleProductException() : message("Produk yang dipilih tidak bisa dimakan"){}
        InedibleProductException(string msg) : message(msg) {}
        string what (){
            return message;
        }
};

class NotProductException : public exception {
    private:
        string message;
    
    public:
        NotProductException() : message("Barang yand dipilih bukan sebuah produk"){}
        NotProductException(string msg) : message(msg) {}
        string what (){
            return message;
        }
};

class NotAnimalException : public exception {
    private:
        string message;
    
    public:
        NotAnimalException() : message("Barang yang dipilih bukanlah binatang"){}
        NotAnimalException(string msg) : message(msg) {}
        string what (){
            return message;
        }
};

class CommandCannotBeDoneException : public exception {
    private:
        string message;
    
    public:
        CommandCannotBeDoneException() : message("Command ini tidak dapat dijalankan sekarang karena suatu kondisi"){}
        CommandCannotBeDoneException(string msg) : message(msg) {}
        string what (){
            return message;
        }
};
#endif