//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Creature.h"
#include <iostream>
#include <vector>
#include "Carte.h"
#include "User.h"

Creature::Creature(int vie, std::string nom, std::string nomAttaque1, std::string nomAttaque2, int hpAttaque1, int hpAttaque2, StructureEnergie NRJAttaque1, StructureEnergie NRJAttaque2, int valeur)
        : Carte{nom,valeur}, m_ip{vie}, m_attaque(nomAttaque1,nomAttaque2, hpAttaque1, hpAttaque2, NRJAttaque1, NRJAttaque2){}


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

int Creature::compareAvecEnergie1(StructureEnergie comparant) {
    if(m_attaque.getNRJAttaque1()==comparant){
        return 1;
    } else
        return 0;
}
int Creature::compareAvecEnergie2(StructureEnergie comparant) {

    if(m_attaque.getNRJAttaque2()==comparant){
        return 1;
    } else
        return 0;
}

void Creature::getNomAttaque(const int &numeroAttaque){
    std::cout <<  m_attaque.getNom(numeroAttaque) << std::endl;
}

int Creature::getHpAttaquer(int nbAttaque) {
    return m_attaque.getHpAttaque(nbAttaque);
}

void Creature::setIp(int ip) {
    m_ip+=ip;
}

void Creature::getChangeHpAttaque(int hp) {
    m_attaque.changeHpAttaque(hp);
}

void Creature::afficherResumeCarte() {


    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    std::cout << "Creature : " << m_nom << " Ip =" << m_ip << std::endl;
    m_attaque.afficherResumeAttaque();
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    std::cout<<std::endl;

}

void Creature::afficherResumeCarteBoutique() {
    afficherResumeCarte();
    std::cout<<"                   -------Cout de la carte : "<<m_valeur<<"-------"<<std::endl;

}



