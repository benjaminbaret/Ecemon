//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Carte.h"
#include <iostream>
#include <vector>

Carte::Carte(std::string nom, bool active)
        :m_nom{nom}
{}
std::string Carte::getNom() {
    return m_nom;
}

void Carte::afficherCarte() {

    std::cout<<m_nom<<std::endl;
}



