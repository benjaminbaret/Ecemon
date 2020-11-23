//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Creature.h"
#include <iostream>
#include <vector>
#include "Carte.h"

Creature::Creature(int vie, std::string nom, std::string nomAttaque1, std::string nomAttaque2, int hpAttaque1, int hpAttaque2)
        : Carte{nom}, m_ip{vie}, m_attaque(nomAttaque1,nomAttaque2, hpAttaque1, hpAttaque2) {}


int Creature::getIp() {
    return m_ip;
}

void Creature::afficherCarte() {
    std::cout << "Nom: " << m_nom << " Ip: " << m_ip << std::endl;
}

std::string Creature::getNom() {
    return m_nom;
}

void Creature::enleverIp(int nbHp){
    m_ip-=nbHp;
}


std::string Creature::getType() {
    return "Creature";
}
