//
// Created by ben on 21/11/2020.
//

#ifndef ECEMON_INITIALISATIONJOUEURS_H
#define ECEMON_INITIALISATIONJOUEURS_H

#include <string>
#include "Classes/User.h"
#include "lectureEcritureDonnees.h"

void initialisationJoueur(User &joueur, const std::vector<structureInfoJoueurs> &donneesJoueurs,
                          const std::string& nomJoueur);

#endif //ECEMON_INITIALISATIONJOUEURS_H
