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
#include "Classes/Attaque.h"

void initialisationJoueur(User &joueur, const std::vector<structureInfoJoueurs> &donneesJoueurs,
                          const std::string &nomJoueur) {

    StructureEnergie zeldaAttaque1{0, 2, 1, 0};
    StructureEnergie zeldaAttaque2{0, 2, 3, 0};
    StructureEnergie sonicAttaque1{0, 1, 0, 1};
    StructureEnergie sonicAttaque2{0, 1, 0, 2};
    StructureEnergie nathanAttaque1{1, 1, 2, 0};
    StructureEnergie nathanAttaque2{1, 2, 2, 0};
    StructureEnergie marioAttaque1{0, 1, 0, 0};
    StructureEnergie marioAttaque2{0, 1, 0, 2};
    StructureEnergie cloudAttaque1{1, 2, 1, 0};
    StructureEnergie cloudAttaque2{2, 1, 3, 0};


    for (auto it = donneesJoueurs.cbegin(); it != donneesJoueurs.cend(); it++) {
        if (it->pseudo == nomJoueur) {
            joueur.setNom(it->pseudo);
            for (int i = 0; i < it->donnees.size(); i++) {
                for (int j = 0; j < it->donnees[i]; j++) {
                    switch (i) {
                        case 0:
                            joueur.remplirCollection(new Creature(15, "Zelda", "Breath of wild", "Charge Attaque", 10, 12, zeldaAttaque1, zeldaAttaque2));
                            break;
                        case 1:
                            joueur.remplirCollection(new Creature(16, "Nathan Drake", "Knife throwin", "Gun shot", 10, 12, nathanAttaque1, nathanAttaque2));
                            break;
                        case 2:
                            joueur.remplirCollection(new Creature(10, "Sonic", "Homing attaque", "Spin dash", 10, 12, sonicAttaque1, sonicAttaque2));
                            break;
                        case 3:
                            joueur.remplirCollection(new Creature(8, "Mario", "Smash Meteor", "Fire Ball", 10, 12, marioAttaque1, marioAttaque2));
                            break;
                        case 4:
                            joueur.remplirCollection(new Creature(8, "Cloud Strife", "Ame Brave", "Meteorain", 10, 12, cloudAttaque1, cloudAttaque2));
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

void initialisationDeckPiocheJoueur(User& joueur){
    std::cout << joueur.getNom() << " veuillez prendre l'ordinateur" << std::endl;
    joueur.creerDeck();
    joueur.creerPioche();
}