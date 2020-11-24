//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Attaque.h"
#include <iostream>
#include <vector>
#include "Energie.h"


Attaque::Attaque(std::string nomAttaque1, std::string nomAttaque2, int hpAttaque1, int hpAttaque2)
        : m_nomAttaque1(nomAttaque1), m_nomAttaque2(nomAttaque2), m_hpAttaque1(hpAttaque1), m_hpAttaque2(hpAttaque2),
          m_numeroAttaque(0) {}


int Attaque::getNumeroAttaque() const {
    return m_numeroAttaque;
}

std::string Attaque::getNom(const int &numeroAttaque) const {
    if (numeroAttaque == 1) {
        return m_nomAttaque1;
    } else if(numeroAttaque == 2){
        return m_nomAttaque2;
    }
}

/////////////////////////////////////////////////:

int Attaque::ajouterPV(int nbHp){
    return m_hpAttaque1+=nbHp;
}