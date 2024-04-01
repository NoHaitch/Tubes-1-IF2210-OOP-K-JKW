#ifndef TANAMAN
#define TANAMAN

#include <string>

class Plant {
protected:
    int id;
    string code;
    string plantType;
    string plantName;
};

class MaterialPlant : public Plant {
protected:
    string plantType = "Material Plant";
    string plantName;
};

class

#endif