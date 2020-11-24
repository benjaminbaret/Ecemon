//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Carte.h"
#include <iostream>
#include <vector>

Carte::Carte(std::string& nom, bool active)
        :m_nom{nom}
{}

Carte::Carte(std::string& nom, std::string& description, bool active)
        :m_nom{nom}, m_description(description)
{}

std::string Carte::getNom() {
    return m_nom;
}

void Carte::afficherCarte() {
    std::cout<<m_nom<<std::endl;
}
std::string Carte::getType(){
    return "Carte";
}

int Carte::compareAvecEnergie1(StructureEnergie comparant){
    return 0;
}

int Carte::compareAvecEnergie2(StructureEnergie comparant){
    return 0;
}

void Carte::getNomAttaque(const int& numeroAttaque){}

int Carte::getHpAttaquer(int nbAttaque){
    return 0;
}

int Carte::getIp() {
    return 0;
}

void Carte::enleverIp(int nbHp){}



