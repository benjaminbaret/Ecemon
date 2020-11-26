//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Speciale.h"
#include <iostream>
#include <vector>
#include "Carte.h"
#include "User.h"

Speciale::Speciale(std::string nom, std::string description, int valeur): Carte(nom, description,valeur){}

std::string  Speciale::getType() {
    return "Speciale";
}

void Speciale::afficherResumeCarte(){
    std::cout<<std::endl;
    std::cout << "Carte Spécial :" << m_nom << std::endl;
    std::cout << "Description: " << m_description << std::endl;

}


void Speciale::afficherResumeCarteBoutique() {
    afficherResumeCarte();
    std::cout<<"          -------Cout de la carte : "<<m_valeur<<"-------"<<std::endl;
}





