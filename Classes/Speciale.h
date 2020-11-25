//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_SPECIALE_H
#define ECEMON_SPECIALE_H
#include <iostream>
#include <vector>
#include "Classes/Carte.h"
#include <iostream>
#include <vector>
#include "User.h"

class Speciale : public Carte{
private:

public:
    Speciale(std::string nom, std::string description);
    ~Speciale()=default;
    std::string getType();



};



#endif //ECEMON_SPECIALE_H
