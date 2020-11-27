//
// Created by ben on 21/11/2020.
//

#include "Classes/menu.h"
#include <iostream>
#include <sstream>
#include "affichageEnConsole.h"


#include "lectureEcritureDonnees.h"

int affichageMenu() {
    int choix = 0;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "0) Quitter le jeu" << std::endl;
    std::cout << "1) Afficher les joueurs existants" << std::endl;
    std::cout << "2) Ajouter un joueur" << std::endl;
    std::cout << "3) Lancer un combat" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    choix = getint();
    return choix;
}

void lancerCombat() {

}

void afficherJoueurs(const std::vector<structureInfoJoueurs> &donneesJoueurs) {
    for (auto it = donneesJoueurs.cbegin(); it != donneesJoueurs.cend(); it++) {
        std::cout << "Joueur : " << it->pseudo << std::endl;
    }
    std::cout << std::endl;
}


int gestionMenu(std::vector<structureInfoJoueurs> &donneesJoueurs) {
    int sortieBoucle = 0;
    int choix = 0;


    while (sortieBoucle == 0) {
        choix = affichageMenu();
        clearConsole();
        switch (choix) {
            case 0: {
                sortieBoucle = 1;
            }
            case 1: {
                afficherJoueurs(donneesJoueurs);
                sortieBoucle = 1;
                break;
            }
            case 2:
            case 3: {
                sortieBoucle = 1;
                break;
            }
            default: {
                std::cout << "Veuillez entrer un paramètre valide" << std::endl;
            }
        }
    }
    return choix;
}

void afficherCartes(std::string joueur, std::vector<Carte *> &vec_deck) {
    std::cout << " Voici les Cartes du deck " << joueur << " : " << std::endl;
    std::cout << std::endl;
    for (const auto &pz :vec_deck) {
        std::cout << "_______________________________________________" << std::endl;
        std::cout << " - Nom : " << pz->getNom() << std::endl;
        std::cout << " - Type : " << pz->getType() << std::endl;
        std::cout << "_______________________________________________" << std::endl;
        std::cout << std::endl;
    }
}

void afficherMenu(int &choice, bool &end) {
    int a;
    std::string str;

    str = "Tapez < 0 > pour accéder au menu.";
    std::cout << str << std::endl;
    a = getint();

    while (a) {
        std::cout << str << std::endl;
        a = getint();
        std::cout << std::endl;
    }

    std::cout << "1)\tJouer" << std::endl;
    std::cout << "2)\tAfficher les joueurs" << std::endl;
    std::cout << "3)\tAjouter un joueur" << std::endl;
    std::cout << "Veuillez taper le numéro de la rubrique souhaitée OU bien taper 0 pour quitter le jeu" << std::endl;
    choice = getint();
    std::cout << std::endl;

    if (choice != 0) {
        while (choice != 1 && choice != 2 && choice != 3) {
            std::cout << "Veuillez choisir un chiffre entre 1 et 3" << std::endl;
            choice = getint();
            std::cout << std::endl;
        }
        end = false;
    } else {
        end = true;
        choice = 0;
    }
}