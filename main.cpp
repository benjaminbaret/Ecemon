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
#include "Classes/affichageGraphique.h"
#include "Classes/jouer.h"
#include "Classes/affichageEnConsole.h"
#include <time.h>


int main(int argc, char **argv) {

    int isEnd = 1, verification = 0, debutJeu = 0;
    std::string nomJoueurComparaison;
    std::vector<structureInfoJoueurs> donneesJoueurs;
    structureInfoJoueurs nouveauJoueur;
    srand(time(NULL));
    std::string path = "../Classes/fichier.csv";


    while (isEnd) {


        if(debutJeu==0){
            //Color(1,0);
            std::cout<<"______  _                                                     _                     \n"
                       "| ___ \\(_)                                                   | |                    \n"
                       "| |_/ / _   ___  _ __ __   __ ___  _ __   _   _   ___      __| |  __ _  _ __   ___  \n"
                       "| ___ \\| | / _ \\| '_ \\\\ \\ / // _ \\| '_ \\ | | | | / _ \\    / _` | / _` || '_ \\ / __| \n"
                       "| |_/ /| ||  __/| | | |\\ V /|  __/| | | || |_| ||  __/   | (_| || (_| || | | |\\__ \\ \n"
                       "\\____/ |_| \\___||_| |_| \\_/  \\___||_| |_| \\__,_| \\___|    \\__,_| \\__,_||_| |_||___/ \n"
                       "                                                                                    \n"
                       "                                                                                    "<<"\n"<<std::endl;
            //Color(14,0);
            std::cout<<" (     (    (     (           (          (     (                )          \n"
                       " )\\ )  )\\ ) )\\ )  )\\ )        )\\ )       )\\ )  )\\ )  (       ( /(   *   )  \n"
                       "(()/( (()/((()/( (()/(    (  (()/( (    (()/( (()/(  )\\ )    )\\())` )  /(  \n"
                       " /(_)) /(_))/(_)) /(_))   )\\  /(_)))\\    /(_)) /(_))(()/(   ((_)\\  ( )(_)) \n"
                       "(_))_ (_)) (_))_|(_))_|_ ((_)(_)) ((_)  (_))_|(_))   /(_))_  _((_)(_(_())  \n"
                       " |   \\|_ _|| |_  | |_ | | | |/ __|| __| | |_  |_ _| (_)) __|| || ||_   _|  \n"
                       " | |) || | | __| | __|| |_| |\\__ \\| _|  | __|  | |    | (_ || __ |  | |    \n"
                       " |___/|___||_|   |_|   \\___/ |___/|___| |_|   |___|    \\___||_||_|  |_|    \n"
                       "                                                                           "<<std::endl;
            //Color(11,0);
            debutJeu=1;
        }

        donneesJoueurs = lectureDonnees(path); // Gestion d'erreur en cas d'echec de lecture ?
        isEnd = gestionMenu(donneesJoueurs);

        if (isEnd == 2) {
            ajoutJoueurEnMemoire(path, donneesJoueurs);

        } else if (isEnd == 3) {

            if (donneesJoueurs.size() >= 2) {
                User joueur1;
                User joueur2;


                initialisationJoueur(joueur1, donneesJoueurs, joueursCombattants(donneesJoueurs, nomJoueurComparaison));
                initialisationJoueur(joueur2, donneesJoueurs, joueursCombattants(donneesJoueurs, nomJoueurComparaison));

                initialisationDeckPiocheJoueur(joueur1);
                initialisationDeckPiocheJoueur(joueur2);

                //On lance la partie ici
                jouer(joueur1, joueur2);


                enregistrementDonneesJoueurs(path, donneesJoueurs, joueur1, joueur2);
                donneesJoueurs.clear();
                isEnd=0;

            } else {
                std::cout << "Veuillez enregistrer au miniumum deux joueurs" << std::endl;
            }

        } else if(isEnd==4){
            acheter(path, donneesJoueurs);
        }
        else if(isEnd==5){
           affichageGraphique();
        }

        nomJoueurComparaison.clear();

    }


    return 0;
}