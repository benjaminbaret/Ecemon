//
// Created by Lucie Dumont on 2020-11-19.
//

#include "User.h"
#include <iostream>
#include <string>
#include "Carte.h"
#include "lectureEcritureDonnees.h"


User::User() {};

User::~User() {
    for(auto it = m_collection.cbegin(); it!=m_collection.cend(); it++){
        delete *it;
    }
}

User::User(std::string nom) : m_nom(nom) {}


std::string User::getNom() const {
    return m_nom;
}


void User::setNom(std::string nom) {
    m_nom = nom;
}

void User::afficherNom() {
    std::cout << "Name: " << m_nom << std::endl;
}

void User::remplirCollection(Carte *maCarte) {
    m_collection.push_back(maCarte);
}

void User::afficheCollection() {
    for(auto i = 0; i<m_collection.size(); i++){
        std::cout << "Carte " << i + 1 << " ";
        m_collection[i]->afficherCarte();
    }

    std::cout << std::endl;

}