//
// Created by ben on 19/11/2020.
//

#include "Classes/lectureEcritureDonnees.h"
#include <fstream>
#include <iostream>
#include <vector>

/// Pour utiliser readFile :
/// vector = readFile('./pathToFile');
/// vector[i].name --> donne le nom du joueur a la position i (type : string)
/// vector[i].donnees[j] --> donnees j du joueur i avec j correspondant à (ordre non défini pour l'instant)


std::vector<structureInfoJoueurs> readFile(const std::string &path) {
    std::ifstream fichier(path.c_str());
    std::vector<structureInfoJoueurs> infoJoueurs;

    structureInfoJoueurs tamponInfoJoueurs;

    if (fichier) // test si le fichier est bien ouvert
    {
        std::string line;
        std::string name;
        std::string donneesString;
        std::vector<int> donnees;
        int nbIterations = 0;

        while (std::getline(fichier, line)) // lecture ligne par ligne
        {
            for (auto i = 0; i < line.size(); i++) {
                if (char(line[i]) != ',') {
                    if (nbIterations == 0) {
                        name.push_back(line[i]);
                    } else {
                        donneesString.push_back(line[i]);
                    }
                } else {
                    if (nbIterations == 1) {
                        donnees.push_back(stoi(donneesString));
                        donneesString.clear();
                    }
                    nbIterations = 1;
                }

            }
            tamponInfoJoueurs.pseudo = name;
            tamponInfoJoueurs.donnees = donnees;

            infoJoueurs.push_back(tamponInfoJoueurs);

            name.clear();
            donnees.clear();
            nbIterations = 0;
        }
        fichier.close(); // fermeture du flux
    } else // en cas d'erreur...
    {
        std::cout << "Erreur 504 ;)" << path << std::endl;
    }

    return infoJoueurs;
}


/// Fonction qui sera utilisés dans une méthode de User pour écrire les données car accès en private aux données du User

void writeFile(const std::string &path,const std::string& name, const int m_victoire, const std::vector<int> ) {

    // pour le mode append, utiliser std::ios::app
    std::ofstream ofs(path.c_str(), std::ios::out);
    if (ofs) {
        // Ecriture dans le fichier
        float flottant = 123.456;
        ofs << "Coucou je suis une phrase" << std::endl;
        ofs << 50 << std::endl;
        ofs << flottant << std::endl;
        ofs.close(); // fermeture du flux
    }
}
