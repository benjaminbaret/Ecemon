//
// Created by Lucie Dumont on 2020-11-19.
//

#include "User.h"
#include <iostream>
#include <string>
#include "Carte.h"
#include "lectureEcritureDonnees.h"
#include <random>
#include <algorithm>
#include <vector>
#include "Creature.h"
#include "Energie.h"
#include "Speciale.h"


User::User() {
    for(int i=0; i<16; i++){
        nombreCartesCategories.push_back(0);
    }
};

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


void User::afficherDeck() {
    for (int i = 0; i < m_deck.size(); i++) {
        std::cout << "Carte " << i << ": " << std::endl;
        m_deck[i]->afficherCarte();
    }
}

void User::creerDeck() {
    bool choix = false;
    bool termine = false;
    int index = 0;

    std::cout << "Creation de votre deck. Pour cela veuillez selectionner 21 cartes" << std::endl;
    std::cout << "Voulez vous revoir votre collection ? 1 pour oui, 0 pour non" << std::endl;
    std::cin >> choix;

    if (choix) {
        afficheCollection();
    } else
        for (int i = 1; i <= 21; i++) {
            std::cout << "Carte n " << i << "?" << std::endl;
            std::cin >> index;
            m_deck.push_back(m_collection[index]);
        }

    do {
        std::cout << "Voci votre Deck voulez vous le modifier ? 1 pour oui, 0 pour non" << std::endl;
        afficherDeck();
        std::cin >> choix;
        if (choix) {
            std::cout << "Quelle carte voulez voulez vous echanger ?" << std::endl;
            std::cin >> index;
            m_deck.erase(m_deck.begin() + index);
            std::cout << "Par quelle carte voulez vous la remplacer ?" << std::endl;
            m_deck.push_back(m_collection[index]);

        } else
            termine = true;
    } while (termine);

}

void User::creerPioche() {
    std::random_device randomDevice;
    std::mt19937 mt19937(randomDevice());                                 //Code permettant de melanger le vector du deck il ne manque plus qu'a copier chaque case puisque le vector est aleatoir maintenant
    std::shuffle(m_deck.begin(),m_deck.end(),mt19937);
    ///https://en.cppreference.com/w/cpp/algorithm/random_shuffle

    for(int i=0;i<m_deck.size();i++){
        m_pioche.push(m_deck[i]);
    }
    /// Ici on a copier le vecteur melangé dans une queue
}

void User::setScore(int score){
    m_score = score;
}


std::vector<int> User::getInfoCartesJoueur(){

    for(auto i=0; i<m_collection.size(); i++){
        if (m_collection[i]->getNom()=="Zelda"){
            nombreCartesCategories[0]+=1;
        }if (m_collection[i]->getNom()=="Nathan Drake"){
            nombreCartesCategories[1]+=1;
        }if (m_collection[i]->getNom()=="Sony"){
            nombreCartesCategories[3]+=1;
        }if (m_collection[i]->getNom()=="Mario"){
            nombreCartesCategories[4]+=1;
        }if (m_collection[i]->getNom()=="Cloud Strife"){
            nombreCartesCategories[5]+=1;
        }if (m_collection[i]->getNom()=="Adventure"){
            nombreCartesCategories[6]+=1;
        }if (m_collection[i]->getNom()=="RPG"){
            nombreCartesCategories[7]+=1;
        }if (m_collection[i]->getNom()=="Sport / Race"){
            nombreCartesCategories[8]+=1;
        }if (m_collection[i]->getNom()=="FPS"){
            nombreCartesCategories[9]+=1;
        }if (m_collection[i]->getNom()=="Increase IP"){
            nombreCartesCategories[10]+=1;
        }if (m_collection[i]->getNom()=="Destroyer"){
            nombreCartesCategories[11]+=1;
        }if (m_collection[i]->getNom()=="Trainer Power"){
            nombreCartesCategories[12]+=1;
        }if (m_collection[i]->getNom()=="Recover"){
            nombreCartesCategories[13]+=1;
        }if (m_collection[i]->getNom()=="Card thief"){
            nombreCartesCategories[14]+=1;
        }if (m_collection[i]->getNom()=="X-Ray"){
            nombreCartesCategories[15]+=1;
        }
    }

    nombreCartesCategories[16] = m_score;
    return nombreCartesCategories;
}
