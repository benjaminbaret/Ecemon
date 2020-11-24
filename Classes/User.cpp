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
#include "affichageEnConsole.h"


User::User() {
    for (int i = 0; i < 16; i++) {
        nombreCartesCategories.push_back(0);
    }
};

User::~User() {
    for (auto it = m_collection.cbegin(); it != m_collection.cend(); it++) {
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
    for (auto i = 0; i < m_collection.size(); i++) {
        std::cout << "Carte " << i + 1 << " ";
        m_collection[i]->afficherCarte();
    }
    std::cout << std::endl;
}


void User::afficherDeck() {
    for (int i = 0; i < m_deck.size(); i++) {
        std::cout << "Carte " << i + 1 << ": " << std::endl;
        m_deck[i]->afficherCarte();
    }
}

void User::creerDeck() {
    bool choix = false;
    bool termine = true;
    int index = 0;
    int index2 = 0;
    std::vector<int> indexMemoire;
    bool efface = true;
    Carte *tampon;


    std::cout << getNom() << " nous allons créer vôtre deck" << std::endl;
    std::cout << "Votre collection :" << std::endl;
    afficheCollection();
    std::cout << "Voulez vous générer un deck aléatoire ? 1 pour oui, 0 pou non" << std::endl;
    std::cin >> choix;

    if (choix) {
        for (int i = 0; i < 21; i++) {
            index = rand() % (m_collection.size());
            m_deck.push_back(m_collection[index]);
            indexMemoire.push_back(index);
        }
    } else {
        std::cout << "Veuillez entrer les index des cartes que vous souhaitez sélectionner" << std::endl;
        for (int i = 0; i < 21; i++) {
            std::cout << "Carte " << i << ") " << std::endl;
            std::cin >> index;
            m_deck.push_back(m_collection[index - 1]);
            indexMemoire.push_back(index);

        }
    }
    do {
        std::cout << "Voici votre Deck, voulez vous le modifier ? 1 pour oui, 0 pour non" << std::endl;
        afficherDeck();
        std::cin >> choix;
        if (choix) {

            do {
                std::cout << "Quelle carte voulez voulez vous echanger ?" << std::endl;
                std::cin >> index;
                index -= 1;

                if (index > m_deck.size() || index < 0) {
                    std::cout << "Veuillez recommencer la carte n'est pas dans votre deck"
                              << std::endl;  // Vérification que la carte  est bien dans le deck
                }

            } while (index > m_deck.size() || index < 0);
            //m_deck.erase(m_deck.begin() + index);
            tampon = m_deck[index];

            do {
                efface = true;
                std::cout << "Par quelle carte voulez vous la remplacer ? (voir collection pour l'index)"
                          << std::endl;
                std::cin >> index2;
                index2 -= 1;

                if (index2 > m_collection.size() || index2 < 0) {
                    std::cout << "La carte n'est pas dans votre collection" << std::endl;
                }

                for (int i = 0; i < indexMemoire.size(); i++) {
                    if (index2 == indexMemoire[i])
                        efface = false;
                }

                if (!efface) {
                    std::cout << "La carte est deja dans votre deck" << std::endl;
                }
            } while (index2 < 0 || index2 > m_collection.size() || !efface);
            m_deck[index] = m_collection[index2];
            m_collection[index2] = tampon;

        } else
            termine = false;
    } while (termine);

}

void User::creerPioche() {
    std::random_device randomDevice;
    std::mt19937 mt19937(
            randomDevice());                                 //Code permettant de melanger le vector du deck il ne manque plus qu'a copier chaque case puisque le vector est aleatoir maintenant
    std::shuffle(m_deck.begin(), m_deck.end(), mt19937);
    ///https://en.cppreference.com/w/cpp/algorithm/random_shuffle

    for (int i = 0; i < m_deck.size(); i++) {
        m_pioche.push(m_deck[i]);
    }
    /// Ici on a copié le vecteur melangé dans une queue
}

void User::setScore(int score) {
    m_score = score;
}


std::vector<int> User::getInfoCartesJoueur() {

    for (auto i = 0; i < m_collection.size(); i++) {
        if (m_collection[i]->getNom() == "Zelda") {
            nombreCartesCategories[0] += 1;
        }
        if (m_collection[i]->getNom() == "Nathan Drake") {
            nombreCartesCategories[1] += 1;
        }
        if (m_collection[i]->getNom() == "Sony") {
            nombreCartesCategories[2] += 1;
        }
        if (m_collection[i]->getNom() == "Mario") {
            nombreCartesCategories[3] += 1;
        }
        if (m_collection[i]->getNom() == "Cloud Strife") {
            nombreCartesCategories[4] += 1;
        }
        if (m_collection[i]->getNom() == "Adventure") {
            nombreCartesCategories[5] += 1;
        }
        if (m_collection[i]->getNom() == "RPG") {
            nombreCartesCategories[6] += 1;
        }
        if (m_collection[i]->getNom() == "Sport / Race") {
            nombreCartesCategories[7] += 1;
        }
        if (m_collection[i]->getNom() == "FPS") {
            nombreCartesCategories[8] += 1;
        }
        if (m_collection[i]->getNom() == "Increase IP") {
            nombreCartesCategories[9] += 1;
        }
        if (m_collection[i]->getNom() == "Destroyer") {
            nombreCartesCategories[10] += 1;
        }
        if (m_collection[i]->getNom() == "Trainer Power") {
            nombreCartesCategories[11] += 1;
        }
        if (m_collection[i]->getNom() == "Recover") {
            nombreCartesCategories[12] += 1;
        }
        if (m_collection[i]->getNom() == "Card thief") {
            nombreCartesCategories[13] += 1;
        }
        if (m_collection[i]->getNom() == "X-Ray") {
            nombreCartesCategories[14] += 1;
        }
    }

    nombreCartesCategories[16] = m_score;
    return nombreCartesCategories;
}

void User::enleverPointsVie(int nbHp) {
    m_pointsVie -= nbHp;
}


///
std::vector<Carte*> User:: getDeck(){
    return m_deck;
}

std::vector<Carte*> User:: getCollection(){
    return m_collection;
}
///