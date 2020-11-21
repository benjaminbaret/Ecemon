//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Attaque.h"
#include <iostream>
#include <vector>
#include "Energie.h"


Attaque::Attaque(std::string nom,int hp, int numero)
        :m_nom{nom},m_hp{hp},m_numero{numero}

{}

Attaque::~Attaque(){
    std::cout<<"Destruction d'un attaque"<<std::endl;
}

int Attaque::getNumero() {
    return m_numero;
}

std::string Attaque::getNom() {
    return m_nom;
}