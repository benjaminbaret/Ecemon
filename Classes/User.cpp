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
#include "structures.h"


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

User::User(std::string nom) : m_nom(nom), m_creatureActive(nullptr), m_pointsVie(20) {}


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
        std::cout << m_collection[i]->getActif() << std::endl;
    }
    std::cout << std::endl;
}


void User::afficherDeck() {
    for (int i = 0; i < m_deck.size(); i++) {
        if (m_deck[i]->getActif() == 0) {
            std::cout << "Carte " << i + 1 << ": " << std::endl;
            m_deck[i]->afficherCarte();
        }
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
            std::cout << "Carte " << i + 1 << ") " << std::endl;
            std::cin >> index;
            index -= 1;
            m_deck.push_back(m_collection[index]);
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
        if (m_deck[i]->getActif() == 0)
            m_pioche.push(m_deck[i]);
    }
    /// Ici on a copié le vecteur melangé dans une queue
}

void User::setScore(int score) {
    m_score = score;
}


std::vector<int> User::getInfoCartesJoueur() {

    nombreCartesCategories.clear();

    for (auto i = 0; i < m_collection.size(); i++) {
        if (m_collection[i]->getNom() == "Zelda") {
            nombreCartesCategories[0] += 1;
        }
        if (m_collection[i]->getNom() == "Nathan Drake") {
            nombreCartesCategories[1] += 1;
        }
        if (m_collection[i]->getNom() == "Sonic") {
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

    nombreCartesCategories[15] = m_score;
    return nombreCartesCategories;
}

void User::enleverPointsVie(int nbHp) {
    m_pointsVie -= nbHp;
}

void User::tirerCarteEnjeu() {
    m_carteEnjeu = m_pioche.front();
    m_pioche.pop();
}

int User::proposerCarte() {
    int choix = 0;
    Carte *tampon;

    m_pioche.front()->afficherCarte();
    std::cout << "Voulez vous jouer cette carte ? " << std::endl;
    std::cin >> choix;
    if (choix == 1) {
        m_pioche.front()->setActif(1);
        for(auto i=0; i < m_deck.size(); i++){
            if(m_deck[i]==m_pioche.front()){
                m_deck.erase(m_deck.begin()+i);
            }
        }
    } else {
        tampon = m_pioche.front();
        m_pioche.push(tampon);
        m_pioche.pop();
    }


    return choix;
}

void User::attaquer(User &joueurAdverse, int nbAttaque) {
    int a = 0;
    if (joueurAdverse.m_creatureActive->getIp() <= m_creatureActive->getHpAttaquer(
            nbAttaque)) { // si le nombre de points de vie de la carte est inférieur que le HP qde celle qui attaque
        a = m_creatureActive->getHpAttaquer(nbAttaque) -
            joueurAdverse.m_creatureActive->getIp(); // Différence de points de vie
        joueurAdverse.m_creatureActive->enleverIp(joueurAdverse.m_creatureActive->getIp());
        joueurAdverse.enleverPointsVie(a);
    } else if (joueurAdverse.m_creatureActive->getIp() > m_creatureActive->getHpAttaquer(nbAttaque)) {
        joueurAdverse.m_creatureActive->enleverIp(m_creatureActive->getHpAttaquer(nbAttaque));
    }
}


void User::placer(User &joueur1, User &joueur2) {
    int a = 0, b = 0;

    std::string name;
    int choix = 0;
    int numeroAttaque = 0;
    if (m_pioche.front()->getType() == "Creature") {

        m_creatureActive = m_pioche.front();

        std::cout << "Voulez vous attaquer ? " << std::endl;

        std::cin >> choix;
        if (choix) {
            if (m_creatureActive->compareAvecEnergie1(m_energieDisponible)) {
                a = 1;
            }
            if (m_creatureActive->compareAvecEnergie2(m_energieDisponible)) {
                b = 1;
            }
            if (a == 1 && b == 1) {
                std::cout << "2 attaques possibles " << std::endl;
                m_creatureActive->getNomAttaque(1);
                m_creatureActive->getNomAttaque(2);
                std::cout << "Quelle attaque voulez vous utiliser ?" << std::endl;
                std::cin >> numeroAttaque;
                attaquer(joueur1, numeroAttaque);

            } else if (a == 1) {
                std::cout << "1 attaque possible (attaque 1) " << std::endl;
                m_creatureActive->getNomAttaque(1);
                attaquer(joueur1, 1);
                // : On montre les attaques
            } else if (b == 1) {
                std::cout << "1 attaque possible (attaque 2) " << std::endl;
                m_creatureActive->getNomAttaque(2);
                attaquer(joueur1, 2);
                // : On montre les attaques

            } else {
                std::cout << "Vous n'avez pas assez d'énergie pour attaquer" << std::endl;
            }
        }
        m_pioche.pop();

    } else if (m_pioche.front()->getType() == "Energie") {
        m_energies.push_back(m_pioche.front());
        name = m_pioche.front()->getNom();
        if (name == "FPS") {
            m_energieDisponible.FPS += 1;
        } else if (name == "RPG") {
            m_energieDisponible.RPG += 1;
        } else if (name == "Adventure") {
            m_energieDisponible.Adventure += 1;
        } else {
            m_energieDisponible.SportRace += 1;
        }
        m_pioche.pop();

    } else if (m_pioche.front()->getType() == "Speciale") {
        name = m_pioche.front()->getNom();

        if (name == "Increase IP") {
            if (m_creatureActive == nullptr) {             // On verifie qu'il y a une creacture sur la table
                m_pointsVie += 3;

            } else
                m_creatureActive->setIp(3);

        } else if (name == "Destroyer") {

            joueur1.enleverIpCarteOuJoueur(2);

        } else if (name == "Trainer Power") {
            if (m_creatureActive == nullptr) {
                std::cout << "Votre carte ne peut pas être utilisé car vous n'avez pas de créature sur le plateau"
                          << std::endl;
            } else
                m_creatureActive->getChangeHpAttaque(1);

        } else if (name == "Recover") {
            std::cout << "Decide ce qu'on fait si on récupère une carte créature" << std::endl;

        } else if (name == "Carde thief") {

            enleverIpCarteOuJoueur(3);
            volerCarte(joueur1);

        } else if (name == "X-Ray")
            joueur1.afficherDeck();

        m_pioche.front()->setActif(2); // On dit que carte est dans cimetiere (cimetiere = 2)
        m_cimetiere.push_back(m_pioche.front()); // On ajoute la carte dans le cimetiere
        m_pioche.pop(); // On enleve la carte de la pioche
    }
}

void User::enleverPvAdversaire(int hp) {
    m_pointsVie -= hp;
}

int User::getIp() {
    return m_creatureActive->getIp();
}

int User::getCreatureActive() {
    if (m_creatureActive == nullptr) {
        return 0;
    } else
        return 0;
}

void User::volerCarte(User &joueurAdverse) {
    Carte *tampon;
    int aleatoire = 0;
    aleatoire = rand() % joueurAdverse.m_deck.size(); // On prend la position d'une des cartes du joueur adverse
    tampon = joueurAdverse.m_deck[aleatoire]; // On retient l'adresse dans une variable tampon
    m_deck.push_back(tampon); // Ajout au deck
    joueurAdverse.m_deck.erase(joueurAdverse.m_deck.begin() + aleatoire);
    joueurAdverse.creerPioche(); // On enlever la carte de la pioche en la regénérant
    creerPioche(); // On ajoute à la pioche la nouvelle carte en regénérant la pioche
}

void User::enleverIpCarteOuJoueur(int hp) {

    int diff = 0;

    if (m_creatureActive == nullptr || m_creatureActive->getIp() <= hp) {
        if (m_creatureActive == nullptr) {
            m_pointsVie -= hp;

        } else {
            diff = hp - m_creatureActive->getIp();
            if (diff == 0) {
                m_creatureActive->enleverIp(hp);
            } else {
                m_creatureActive->enleverIp(m_creatureActive->getIp());
                enleverPvAdversaire(diff);
            }
        }
    } else
        m_creatureActive->enleverIp(hp);


}


void User::verificationIpCreature(){
    if(m_creatureActive->getActif()==1){
        if(m_creatureActive->getIp()<=0){ // Si n'a plus de points de vie
            m_creatureActive->setActif(2); // Mise au cimetiere (cimetiere =2)
            m_cimetiere.push_back(m_creatureActive); // Mise au cimetiere
            m_creatureActive= nullptr; // plus de carte créature active pour le joueur
            std::cout << "Votre creature a ete mise au cimetiere" << std::endl;
        }
    }
}

int User ::verificationFinJeu() {
    int nb=0;

    for(int i=0; i<m_deck.size(); i++){
        if(m_deck[i]->getType()=="Creature")
            nb+=1;
    }
    if(nb==0){
        std::cout << "Fin du jeu, plus de cartes créature" << std::endl;
        return 0;
    }else
        return 1;

}

