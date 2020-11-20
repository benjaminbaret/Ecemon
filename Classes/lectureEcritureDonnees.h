//
// Created by ben on 19/11/2020.
//

#ifndef ESSAISDIVERS_LECTUREECRITUREDONNEES_H
#define ESSAISDIVERS_LECTUREECRITUREDONNEES_H
#include <string>
#include <vector>

struct structureInfoJoueurs {
    std::string pseudo;
    std::vector<int> donnees;
};

std::vector<structureInfoJoueurs> readFile(const std::string &path);

#endif //ESSAISDIVERS_LECTUREECRITUREDONNEES_H
