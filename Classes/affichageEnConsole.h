//
// Created by ben on 24/11/2020.
//

#ifndef ECEMON_AFFICHAGEENCONSOLE_H
#define ECEMON_AFFICHAGEENCONSOLE_H

#include <string>
#include "User.h"
#include "lectureEcritureDonnees.h"

void clearConsole(); // "nettoyer" le terminal

void Color(int couleurDuTexte, int couleurDeFond); // Affichage couleur sous windows

void afficherBoutique(structureInfoJoueurs &joueur); // Affichage boutique (achat cartes avec argent)

void acheter(const std::string &path, std::vector<structureInfoJoueurs> &donneesJoueurs);  // Fonction appelee pour acheter de nouvelles cartes


#endif //ECEMON_AFFICHAGEENCONSOLE_H
