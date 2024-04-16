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

class InputInvalidException : public exception {
    private:
        string message;
    
    public:
        InputInvalidException() : message("Input yang kamu berikan tidak sesuai"){}
        InputInvalidException(string msg) : message(msg) {}
        string what (){
            return message;
        }
};

class NotEnoughSlotException : public exception {
    private:
        string message;
    
    public:
        NotEnoughSlotException() : message("Banyaknya slot yang dibutuhkan untuk command ini tidak cukup"){}
        NotEnoughSlotException(string msg) : message(msg) {}
        string what (){
            return message;
        }
};

class NotHarvestableException : public exception {
    private:
        string message;
    
    public:
        NotHarvestableException() : message("Petak ini belum bisa dipanen"){}
        NotHarvestableException(string msg) : message(msg) {}
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

class NotEnoughMoney : public exception {
    private: string message;
    public:
        NotEnoughMoney() : message("Uang tidak mencukupi untuk melakukan operasi ini!") {};
        NotEnoughMoney(string msg) : message(msg) {};
        string what() {
            return message;
        }
};
#endif