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
    int m_numero;
public:
    Attaque(std::string nom, int hp, int numero);
    ~Attaque()=default;
    void verificationEnergie();
    int lancerAttaque();
    void choixAttaque();
    int getNumero();
    std::string getNom();

};


#endif //ECEMON_ATTAQUE_H
