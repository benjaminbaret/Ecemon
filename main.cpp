//
// Created by Lucie Dumont on 2020-11-19.
//

#include <iostream>
#include <vector>


#include "Classes/Energie.h"
#include "Classes/Attaque.h"
#include "Classes/Carte.h"
#include "Classes/Creature.h"
#include "Classes/Speciale.h"
#include "Classes/User.h"
#include "Classes/menu.h"
#include "Classes/lectureEcritureDonnees.h"
#include "Classes/initialisationJoueurs.h"
#include "Classes/jouer.h"
#include <time.h>


int main() {

    int isEnd = 1;
    int nbCartes = 0;
    std::string nomJoueurComparaison;
    std::vector<structureInfoJoueurs> donneesJoueurs;
    structureInfoJoueurs nouveauJoueur;
    srand(time(NULL));


    while (isEnd) {

        donneesJoueurs = lectureDonnees("../Classes/fichier.csv"); // Gestion d'erreur en cas d'echec de lecture ?
        isEnd = gestionMenu(donneesJoueurs);

        if (isEnd == 2) {
            ajoutJoueurEnMemoire("../Classes/fichier.csv", donneesJoueurs);

        } else if (isEnd == 3) {
            User joueur1;
            User joueur2;

            if (donneesJoueurs.size() >= 2) {
                std::cout << joueur1.getIpJoueur() << std::endl;
                std::cout << joueur2.getIpJoueur() << std::endl;

                initialisationJoueur(joueur1, donneesJoueurs, joueursCombattants(donneesJoueurs, nomJoueurComparaison));
                initialisationJoueur(joueur2, donneesJoueurs, joueursCombattants(donneesJoueurs, nomJoueurComparaison));

                std::cout << joueur1.getIpJoueur() << std::endl;
                std::cout << joueur2.getIpJoueur() << std::endl;

                initialisationDeckPiocheJoueur(joueur1);
                initialisationDeckPiocheJoueur(joueur2);


                //On lance la partie ici
                jouer(joueur1, joueur2);


                enregistrementDonneesJoueurs("../Classes/fichier.csv", donneesJoueurs, joueur1, joueur2);
                donneesJoueurs.clear();

            } else {
                std::cout << "Veuillez enregistrer au miniumum deux joueurs" << std::endl;
            }

        }

        nomJoueurComparaison.clear();

    }


    return 0;
}