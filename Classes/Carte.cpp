//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Carte.h"
#include <iostream>
#include <vector>

Carte::Carte(std::string& nom)
        :m_nom{nom},m_active{0}
{}

Carte::Carte(std::string& nom, std::string& description)
        :m_nom{nom}, m_description(description),m_active{0}
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

void Carte::setIp(int ip) {}

void Carte::getChangeHpAttaque(int hp){}

int Carte::getActif() {
    return m_active;
}

void Carte::setActif(int actif) {
    m_active=actif;
}