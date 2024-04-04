#include "header/utils.hpp"

using namespace std;

bool isNumber(const std::string& s) {
    string::const_iterator it = s.begin();

    while (it != s.end() && isdigit(*it)){
        ++it;
    } 
    
    return !s.empty() && it == s.end();
}