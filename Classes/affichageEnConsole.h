//
// Created by ben on 24/11/2020.
//

#ifndef ECEMON_AFFICHAGEENCONSOLE_H
#define ECEMON_AFFICHAGEENCONSOLE_H

#include <string>
#include "User.h"
#include "lectureEcritureDonnees.h"

void clearConsole();

void Color(int couleurDuTexte,int couleurDeFond);

void afficherBoutique(structureInfoJoueurs& joueur);
void acheter(const std::string &path, std::vector<structureInfoJoueurs> &donneesJoueurs);



#endif //ECEMON_AFFICHAGEENCONSOLE_H
