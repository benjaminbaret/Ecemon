//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_ATTAQUE_H
#define ECEMON_ATTAQUE_H

#include <iostream>
#include <vector>
#include "Energie.h"

class Attaque {
private:
    std::string m_nom;
    int m_hp;
public:
    ~Attaque()=default;
    void verificationEnergie();
    int lancerAttaque();
    void choixAttaque();

};


#endif //ECEMON_ATTAQUE_H
