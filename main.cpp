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
#include <time.h>



int main() {

    int isEnd = 1;
    int nbCartes = 0;
    User joueur1;
    User joueur2;
    std::string nomJoueurComparaison;
    std::vector<structureInfoJoueurs> donneesJoueurs;
    structureInfoJoueurs nouveauJoueur;
    srand(time(NULL));


    while (isEnd) {

        donneesJoueurs = lectureDonnees("../Classes/fichier.csv"); // Gestion d'erreur en cas d'echec de lecture ?
        isEnd = gestionMenu(donneesJoueurs);

        if (isEnd == 2){
            ajoutJoueurEnMemoire("../Classes/fichier.csv", donneesJoueurs);
        }
        else if (isEnd == 3) {

            if (donneesJoueurs.size()>=2){
                initialisationJoueur(joueur1, donneesJoueurs, joueursCombattants(donneesJoueurs, nomJoueurComparaison));
                initialisationJoueur(joueur2, donneesJoueurs, joueursCombattants(donneesJoueurs, nomJoueurComparaison));

                initialisationDeckPiocheJoueur(joueur1);
                initialisationDeckPiocheJoueur(joueur2);

                // On lance la partie ici


                enregistrementDonneesJoueurs("../Classes/fichier.csv", donneesJoueurs, joueur1, joueur2);
            }
            else {
                std::cout << "Veuillez enregistrer au miniumum deux joueurs" << std::endl;
            }

        }

        nomJoueurComparaison.clear();

    }




    joueur1.afficheCollection();
    joueur2.afficheCollection();

    return 0;
}