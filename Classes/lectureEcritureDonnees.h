//
// Created by ben on 19/11/2020.
//

#ifndef ESSAISDIVERS_LECTUREECRITUREDONNEES_H
#define ESSAISDIVERS_LECTUREECRITUREDONNEES_H
#include <string>
#include <vector>
#include <iostream>
#include <vector>


struct structureInfoJoueurs {
    std::string pseudo;
    std::vector<int> donnees;
    int positionFichier;
};

std::vector<structureInfoJoueurs> lectureDonnees(const std::string &path);

std::string joueursCombattants(const std::vector<structureInfoJoueurs>& infoJoueurs, std::string& nomJoueurComparaison);


#endif //ESSAISDIVERS_LECTUREECRITUREDONNEES_H
