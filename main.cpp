#include <fstream>
#include <iostream>
#include <vector>
#include <fstream>


struct structureInfoJoueurs {
    std::string pseudo;
    std::vector<int> donnees;
};

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


int main() {
    
    readFile("../fichier.csv");


    return 0;
}



/*for(auto i=0; i<infoJoueurs.size(); i++){
std::cout << infoJoueurs[i].pseudo << "ICI" << std::endl;
for(auto j=0; j<infoJoueurs[i].donnees.size(); j++){
std::cout << infoJoueurs[i].donnees[j] << "LA" << std::endl;
}
}*/ //peut éventuellement servir pour afficher les donnes



void writeFile(const std::string &path) {
    // Ouverture fichier en mode "w"
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