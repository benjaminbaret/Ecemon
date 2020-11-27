//
// Created by ben on 19/11/2020.
//

#include "Classes/lectureEcritureDonnees.h"
#include <fstream>
#include <iostream>
#include <vector>

#include "User.h"
#include "menu.h"
#include "affichageEnConsole.h"

/// Pour utiliser readFile :
/// vector = readFile('./pathToFile');
/// vector[i].name --> donne le nom du joueur a la position i (type : string)
/// vector[i].donnees[j] --> donnees j du joueur i avec j correspondant à (ordre non défini pour l'instant)


std::vector<structureInfoJoueurs> lectureDonnees(const std::string &path) { // On lit dans le fichier texte
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
        int j = 1;


        while (std::getline(fichier, line)) // lecture ligne par ligne
        {
            for (auto i = 0; i < line.size(); i++) { // On parcout chaque caractère de la ligne
                if (char(line[i]) != ',') {
                    if (nbIterations == 0) {
                        name.push_back(
                                line[i]); // recuperation des caractères du pseudo (lors de la première lecture car on a pas encore rencontré le marsqueur ","
                    } else {
                        donneesString.push_back(
                                line[i]); // Sinon, c'est une donnee, on la retient dans une chaine de caractère
                    }
                } else {
                    if (nbIterations == 1) {
                        donnees.push_back(
                                stoi(donneesString)); // on convertie la chaine de caractère de chiffres en nombre que l'on retient dans un vecteur
                        donneesString.clear();
                    }
                    nbIterations = 1;
                }
            }
            donnees.push_back(stoi(donneesString));
            donneesString.clear();

            tamponInfoJoueurs.pseudo = name;
            tamponInfoJoueurs.donnees = donnees;

            tamponInfoJoueurs.positionFichier = 0;

            infoJoueurs.push_back(tamponInfoJoueurs); // on retient tou ça dans une vecteur de structure

            name.clear();
            donnees.clear();
            j += 1;
            nbIterations = 0;
        }
        fichier.close(); // fermeture du flux
    } else // gestion d'erreur
    {
        std::cout << "Erreur de lecture des données" << std::endl;
    }

    return infoJoueurs;
}

/// Fonction qui sera utilisés dans une méthode de User pour écrire les données car accès en private aux données du User

void writeFile(const std::string &path, std::vector<structureInfoJoueurs> &donneesJoueurs) {


    // pour le mode append, utiliser std::ios::app
    std::ofstream ofs(path.c_str(), std::ios::out);

    if (ofs) {
        // Ecriture dans le fichier
        ofs.clear();
        for (auto it = donneesJoueurs.cbegin(); it != donneesJoueurs.cend(); it++) {
            ofs << it->pseudo; // on commence par écrire le pseudo
            for (int i = 0; i < it->donnees.size(); i++) {
                ofs << ","
                    << it->donnees[i];  // on écrit ensuite les données les une après les autres dans la forme décidée pour pouvoir être relue
            }
            ofs << std::endl;
        }
    }
    ofs.close();
}

void
enregistrementDonneesJoueurs(const std::string &path, std::vector<structureInfoJoueurs> &donneesJoueurs, User &joueur1,
                             User &joueur2) {

    std::vector<int> vecteurTransition;

    for (auto it = donneesJoueurs.begin(); it != donneesJoueurs.end(); it++) {
        if (it->pseudo == joueur1.getNom()) { // on retrouve les donnees correspondant au joueur
            vecteurTransition = joueur1.getInfoCartesJoueur(); // on récupère les informations du joueur (donnees)
            for (int i = 0; i < vecteurTransition.size(); i++) {
                it->donnees[i] = vecteurTransition[i]; // On retient les informations dans le vecteur de structure retenant toutes les donnees de chaque joueur

            }


        } else if (it->pseudo == joueur2.getNom()) { // de même pour le joueur 2
            vecteurTransition = joueur2.getInfoCartesJoueur();
            for (int i = 0; i < vecteurTransition.size(); i++) {
                it->donnees[i] = vecteurTransition[i];
            }
        }
    }


    writeFile(path, donneesJoueurs); // On réécrit toutes les données mises à jour dans le fichier texte

}

void ajoutJoueurEnMemoire(const std::string &path, std::vector<structureInfoJoueurs> &donneesJoueurs) {

    int verification = 1;
    int nonUtilise = 0;

    structureInfoJoueurs nouveauJoueur;
    nouveauJoueur.positionFichier = 0;

    std::cout << "Création d'un nouveau joueur" << std::endl;


    while (verification) {
        std::cout << "Veuillez entrer le pseudo du joueur" << std::endl;
        std::cin >> nouveauJoueur.pseudo;
        for (int i = 0; i < donneesJoueurs.size(); i++) {
            if (donneesJoueurs[i].pseudo !=
                nouveauJoueur.pseudo) { // on verifie que pseudo n'est pas utilisé en parcourant la BDD
                nonUtilise += 1;
            } else {
                std::cout << "Pseudo déjà utilisé" << std::endl;
            }
        }
        if (nonUtilise == donneesJoueurs.size()) { // Ok pour utiliser le pseudo
            verification = 0;
        }
        nonUtilise = 0;
    }

    std::cout << "Piochage aléatoire de 30 cartes pour vous constituer une collection" << std::endl;

    for (int i = 0; i < 15; i++) {
        nouveauJoueur.donnees.push_back(2); // 2 cartes de chaque à la création
    }

    nouveauJoueur.donnees.push_back(0); // score de 0 à la création
    nouveauJoueur.donnees.push_back(20); // Ajout de 20 argent à la création
    donneesJoueurs.push_back(nouveauJoueur);
    writeFile(path, donneesJoueurs);
    donneesJoueurs = lectureDonnees("../Classes/fichier.csv");
}


std::string joueursCombattants(const std::vector<structureInfoJoueurs> &donneesJoueurs, std::string &nomJoueurComparaison) {
    int isEnd = 1;
    std::string joueur;

    while (isEnd) {
        afficherJoueurs(donneesJoueurs);
        std::cout << "Veuillez entrer le nom du Joueur que vous souhaitez séléctionner : " << std::endl;
        std::cin >> joueur; // on recupere le nom du joueur qui veut jouer
        std::cout << std::endl;
        if (nomJoueurComparaison == joueur) { // on verifie que on appelle pas deux fois le même joueur
            std::cout << "Vous avez déjà sélectionné ce joueur," << std::endl;
        } else {
            nomJoueurComparaison = joueur;
            isEnd = 0;
        }
        clearConsole();
    }
    return joueur;
}
