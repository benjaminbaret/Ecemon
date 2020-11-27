//
// Created by ben on 21/11/2020.
//

#ifndef ECEMON_INITIALISATIONJOUEURS_H
#define ECEMON_INITIALISATIONJOUEURS_H

#include <string>
#include "Classes/User.h"
#include "lectureEcritureDonnees.h"

void reinitialiserJoueurs(User& joueur1, User& joueur2);

void initialisationJoueur(User &joueur, const std::vector<structureInfoJoueurs> &donneesJoueurs,
                          const std::string& nomJoueur);

void initialisationDeckPiocheJoueur(User& joueur);

#endif //ECEMON_INITIALISATIONJOUEURS_H
