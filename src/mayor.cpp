#include "header/mayor.hpp"

Mayor::Mayor(string _username) : Player(_username){}
Mayor::Mayor(string _username, int _wealth, int _currWeight) 
    : Player(_username, _wealth, _currWeight){}

Mayor::~Mayor(){}