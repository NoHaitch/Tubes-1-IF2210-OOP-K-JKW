#include "header/cattleman.hpp"

Cattleman::Cattleman(string _username) : Player(_username){}
Cattleman::Cattleman(string _username, int _wealth, int _currWeight) 
    : Player(_username, _wealth, _currWeight){}

Cattleman::~Cattleman(){}