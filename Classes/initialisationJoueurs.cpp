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
                          const std::string& nomJoueur) {

    for (auto it = donneesJoueurs.cbegin(); it != donneesJoueurs.cend(); it++) {
        if (it->pseudo == nomJoueur) {
            for (auto i = 0; i < it->donnees.size(); i++) {
                for (int j = 0; j < it->donnees[i]; j++) {
                    switch (i) {
                        case 0:
                            joueur.remplirCollection(new Creature(15, "Mario"));
                            break;
                        case 1:
                            joueur.remplirCollection(new Creature(16, "Luigi"));
                            break;
                        case 2:
                            joueur.remplirCollection(new Creature(10, "Boo"));
                            break;
                        case 3:
                            joueur.remplirCollection(new Creature(8, "Squelette"));
                            break;
                        case 4:
                            joueur.remplirCollection(new Energie("Hiver", "Tempete de neige"));
                            break;
                        case 5:
                            joueur.remplirCollection(new Energie("Ete", "Canicule"));
                            break;
                        case 6:
                            joueur.remplirCollection(new Energie("Automonne", "Tornade"));
                            break;
                        case 7:
                            joueur.remplirCollection(new Energie("Printemps", "Giboules"));
                            break;
                        default:
                            std::cout << "Erreur d'initialisation des joueurs" << std::endl;
                    }
                }
            }
        }
    }
}