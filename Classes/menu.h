//
// Created by ben on 21/11/2020.
//

#ifndef ECEMON_MENU_H
#define ECEMON_MENU_H

#include "lectureEcritureDonnees.h"

void afficherJoueurs(const std::vector<structureInfoJoueurs>& donneesJoueurs);
int affichageMenu();
int gestionMenu(std::vector<structureInfoJoueurs>& donneesJoueurs);


#endif //ECEMON_MENU_H
