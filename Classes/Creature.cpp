//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Creature.h"
#include <iostream>
#include <vector>
#include "Carte.h"

Creature::Creature(int vie, std::string nom)
        : Carte{nom}, m_ip{vie} {


}


int Creature::getIp() {
    return m_ip;
}

void Creature::afficherCarte() {
    std::cout << "Nom: " << m_nom << " Ip: " << m_ip << std::endl;
}

std::string Creature::getNom() {
    return m_nom;
}
