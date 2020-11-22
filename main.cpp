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


// Penser à empecher la création d'un joueur avec le même pseudo




int main() {

    int isEnd = 1;
    User joueur1;
    User joueur2;
    std::string nomJoueurComparaison;
    std::vector<structureInfoJoueurs> donneesJoueurs;

    std::cout << "Chargement des données" << std::endl;
    donneesJoueurs = lectureDonnees("../Classes/fichier.csv"); // Gestion d'erreur en cas d'echec de lecture ?

    while (isEnd) {
        isEnd = gestionMenu(donneesJoueurs);
        if (isEnd == 2){
            // Création d'un nouveau joueur càd enregistrement en mémoire + recharger la variable "donneesJoueurs" afin qu'elles soient utilisables
        }
        else if (isEnd == 3) {
            initialisationJoueur(joueur1, donneesJoueurs, joueursCombattants(donneesJoueurs, nomJoueurComparaison));
            initialisationJoueur(joueur2, donneesJoueurs, joueursCombattants(donneesJoueurs, nomJoueurComparaison));

            // On séléctionne le deck
            // On lance la partie
        }
       enregistrementDonneesJoueurs("../Classes/fichier.csv", donneesJoueurs, joueur1, joueur2);
        nomJoueurComparaison.clear();
    }




    joueur1.afficheCollection();
    joueur2.afficheCollection();

    return 0;
}