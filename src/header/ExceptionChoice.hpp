#ifndef EXCEPTION_CHOICE
#define EXCEPTION_CHOICE

#include <exception>
using namespace std;

struct ChoiceOutOfBound : public exception {
    const char* what() throw() {
        return "Pilihan tidak ditemukan!";
    }
};

#endif