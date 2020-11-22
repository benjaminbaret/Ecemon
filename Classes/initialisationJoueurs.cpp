//
// Created by ben on 21/11/2020.
//

#include "initialisationJoueurs.h"
#include <string>
#include "Classes/User.h"
#include "Classes/lectureEcritureDonnees.h"
#include "Classes/Energie.h"
#include "Classes/Speciale.h"
#include "Classes/Creature.h"

void initialisationJoueur(User &joueur, const std::vector<structureInfoJoueurs> &donneesJoueurs,
                          const std::string &nomJoueur) {

    for (auto it = donneesJoueurs.cbegin(); it != donneesJoueurs.cend(); it++) {
        if (it->pseudo == nomJoueur) {
            for (auto i = 0; i < it->donnees.size(); i++) {
                for (int j = 0; j < it->donnees[i]; j++) {
                    switch (i) {
                        case 0:
                            joueur.remplirCollection(new Creature(15, "Zelda"));
                            break;
                        case 1:
                            joueur.remplirCollection(new Creature(16, "Nathan Drake"));
                            break;
                        case 2:
                            joueur.remplirCollection(new Creature(10, "Sony"));
                            break;
                        case 3:
                            joueur.remplirCollection(new Creature(8, "Mario"));
                            break;
                        case 4:
                            joueur.remplirCollection(new Creature(8, "Cloud Strife"));
                            break;
                        case 5:
                            joueur.remplirCollection(new Energie("Adventure", "Adventure"));
                            break;
                        case 6:
                            joueur.remplirCollection(new Energie("RPG", "RPG"));
                            break;
                        case 7:
                            joueur.remplirCollection(new Energie("Sport / Race", "Sport / Race"));
                            break;
                        case 8:
                            joueur.remplirCollection(new Energie("FPS", "FPS"));
                            break;
                        case 9:
                            joueur.remplirCollection(new Speciale{"Increase IP", "Augmente x IP de la carte posée"});
                            break;
                        case 10:
                            joueur.remplirCollection(new Speciale{"Destroyer", "Enleve x IP¨adversaire"});
                            break;
                        case 11:
                            joueur.remplirCollection(new Speciale{"Trainer Power", "Augmente x PV de l'attaque en cours"});
                            break;
                        case 12:
                            joueur.remplirCollection(new Speciale{"Recover", "Récupere la derniere carte du cimetiere"});
                            break;
                        case 13:
                            joueur.remplirCollection(new Speciale{"Card thief", "Vole une carte a l'adversaire mais enleve 3 IP à la carte posée"});
                            break;
                        case 14:
                            joueur.remplirCollection(new Speciale{"X-Ray", "Permet de voir intégralement la pioche de l'adversaire"});
                            break;
                        case 15:
                            joueur.setScore(j);
                            break;
                        default:
                            std::cout << "Erreur d'initialisation des joueurs" << std::endl;
                    }
                }
            }
        }
    }
}