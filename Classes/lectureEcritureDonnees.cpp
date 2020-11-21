//
// Created by ben on 19/11/2020.
//

#include "Classes/lectureEcritureDonnees.h"
#include <fstream>
#include <iostream>
#include <vector>

#include "User.h"
#include "menu.h"

/// Pour utiliser readFile :
/// vector = readFile('./pathToFile');
/// vector[i].name --> donne le nom du joueur a la position i (type : string)
/// vector[i].donnees[j] --> donnees j du joueur i avec j correspondant à (ordre non défini pour l'instant)


std::vector<structureInfoJoueurs> lectureDonnees(const std::string &path) {
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
        int j=1;


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
                        std::cout << donneesString << std::endl;
                        donnees.push_back(stoi(donneesString));
                        donneesString.clear();
                    }
                    nbIterations = 1;
                }
            }
            donnees.push_back(stoi(donneesString));
            donneesString.clear();

            tamponInfoJoueurs.pseudo = name;
            tamponInfoJoueurs.donnees = donnees;
            tamponInfoJoueurs.positionFichier = j;

            infoJoueurs.push_back(tamponInfoJoueurs);

            name.clear();
            donnees.clear();
            j+=1;
            nbIterations = 0;
        }
        fichier.close(); // fermeture du flux
    } else // en cas d'erreur...
    {
        std::cout << "Erreur de lecture des données" << std::endl;
    }
    std::cout << infoJoueurs[1].donnees.size() << std::endl;

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




std::string joueursCombattants(const std::vector<structureInfoJoueurs>& donneesJoueurs, std::string &nomJoueurComparaison){
    int isEnd = 1;
    std::string joueur;

    while(isEnd){
        afficherJoueurs(donneesJoueurs);
        std::cout << "Veuillez entrer le nom du Joueur que vous souhaitez séléctionner : " << std::endl;
        std::cin >> joueur;
        std::cout << std::endl;
        if (nomJoueurComparaison == joueur){
            std::cout << "Vous avez déjà sélectionné ce joueur," << std::endl;
        }
        else {
            nomJoueurComparaison = joueur;
            isEnd = 0;
        }


    }
    return joueur;
}


/*void initialisationJoueurs(std::vector<structureInfoJoueurs>& infoJoueurs, User& joueur1, User& joueur2){
   std::string nomJoueur1;
   std::string nomJoueur2;

   nomJoueur1 = joueurCombattants(infoJoueurs);
   nomJoueur2 = joueurCombattants(infoJoueurs);

   for(auto it=infoJoueurs.cbegin(); it!=infoJoueurs.cend(); it++){
       if(nomJoueur1==it->pseudo){
           joueur1.setNom(nomJoueur1);
           joueur1.remplirCollection()
       }
   }



}*/
