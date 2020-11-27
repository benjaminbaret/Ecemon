//
// Created by ben on 19/11/2020.
//

#ifndef ESSAISDIVERS_LECTUREECRITUREDONNEES_H
#define ESSAISDIVERS_LECTUREECRITUREDONNEES_H
#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include "Classes/User.h"


struct structureInfoJoueurs {
    std::string pseudo;
    std::vector<int> donnees;
    int positionFichier;
};

void writeFile(const std::string &path, std::vector<structureInfoJoueurs>& donneesJoueurs);

void enregistrementDonneesJoueurs(const std::string &path, std::vector<structureInfoJoueurs> &donneesJoueurs, User &joueur1,User &joueur2);

std::vector<structureInfoJoueurs> lectureDonnees(const std::string &path);

std::string joueursCombattants(const std::vector<structureInfoJoueurs>& infoJoueurs, std::string& nomJoueurComparaison);

void ajoutJoueurEnMemoire(const std::string &path, std::vector<structureInfoJoueurs>& donneesJoueurs);



#endif //ESSAISDIVERS_LECTUREECRITUREDONNEES_H
