//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Energie.h"
#include <iostream>
#include <vector>
#include "Carte.h"


Energie::Energie(std::string element,std::string nom,int valeur)
        :m_element{std::move(element)},Carte(nom,valeur)
{}

void Energie::afficherCarte() {
    std::cout<<m_nom<<std::endl<<"appartient a : "<<m_element<<std::endl;
}

std::string Energie::getNom() {
    return m_nom;
}

std::string Energie::getType() {
    return "Energie";
}

void Energie::afficherResumeCarte(){
    std::cout<<std::endl;
    afficherCarte();
}

void Energie::afficherResumeCarteBoutique() {
    afficherResumeCarte();
    std::cout << "-------Cout de la carte : " << m_valeur << "-------" << std::endl;
}


