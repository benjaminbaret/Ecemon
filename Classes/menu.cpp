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
    std::cout << "4) Boutique" << std::endl;
    std::cout << "5) Description des cartes (graphique)"<<std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    std::cin >> choix;
    return choix;
}



void afficherJoueurs(const std::vector<structureInfoJoueurs>& donneesJoueurs){
    std::cout << "Joueurs : " << std::endl;

    for(auto it = donneesJoueurs.cbegin(); it!=donneesJoueurs.cend(); it++){
        std::cout<< "- " << it->pseudo << ", argent : " << it->donnees[16]<<std::endl;
    }
    std::cout << std::endl;
}


int gestionMenu(std::vector<structureInfoJoueurs>& donneesJoueurs) {
    int sortieBoucle = 0;
    int choix = 0;


    while (sortieBoucle==0) {
        choix = affichageMenu();
        clearConsole();
        switch (choix) {
            case 0:{
                sortieBoucle=1;
            }
            case 1: {
                afficherJoueurs(donneesJoueurs);
                sortieBoucle=1;
                break;
            }
            case 2: {
                sortieBoucle=1;
                break;
            }
            case 3: {
                sortieBoucle=1;
                break;
            }
            case 4:{
                sortieBoucle=1;
                break;
            }
            case 5:{
                sortieBoucle=1;
                break;
            }
            default: {
                std::cout << "Veuillez entrer un paramètre valide" << std::endl;
            }
        }
    }
    return choix;
}

