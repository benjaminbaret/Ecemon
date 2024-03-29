//
// Created by ben on 24/11/2020.
//

#include "affichageEnConsole.h"
#include <iostream>
#include "structures.h"
#include "Creature.h"
#include "Speciale.h"
#include "lectureEcritureDonnees.h"
#include "windows.h"


void clearConsole() {
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl; // Nettoyage terminal
}

void Color(int couleurDuTexte, int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}


void afficherBoutique(structureInfoJoueurs &joueur) {
    int choix = 0;
    int carte = 0;
    std::string name;

    // Creation de toutes les cartes afin d'avoir un modèle à montrer pour les proposer dans la boutique

    StructureEnergie zeldaAttaque1{0, 2, 1, 0};
    StructureEnergie zeldaAttaque2{0, 2, 3, 0};
    StructureEnergie sonicAttaque1{0, 1, 0, 1};
    StructureEnergie sonicAttaque2{0, 1, 0, 2};
    StructureEnergie nathanAttaque1{1, 1, 2, 0};
    StructureEnergie nathanAttaque2{1, 2, 2, 0};
    StructureEnergie marioAttaque1{0, 1, 0, 0};
    StructureEnergie marioAttaque2{0, 1, 0, 2};
    StructureEnergie cloudAttaque1{1, 2, 1, 0};
    StructureEnergie cloudAttaque2{2, 1, 3, 0};

    Creature *zelda = new Creature(15, "Zelda", "Breath of wild", "Charge Attaque", 10, 12, zeldaAttaque1,
                                   zeldaAttaque2, 20);
    Creature *nathan = new Creature(16, "Nathan Drake", "Knife throwin", "Gun shot", 10, 12, nathanAttaque1,
                                    nathanAttaque2, 30);
    Creature *sonic = new Creature(10, "Sonic", "Homing attaque", "Spin dash", 10, 12, sonicAttaque1, sonicAttaque2,
                                   15);
    Creature *mario = new Creature(8, "Mario", "Smash Meteor", "Fire Ball", 10, 12, marioAttaque1, marioAttaque2, 12);
    Creature *cloud = new Creature(25, "Cloud Strife", "Ame Brave", "Meteorain", 10, 12, cloudAttaque1, cloudAttaque2,
                                   25);
    Energie *adv = new Energie("Adventure", "Adventure", 5);
    Energie *rpg = new Energie("RPG", "RPG", 5);
    Energie *sport = new Energie("Sport / Race", "Sport / Race", 5);
    Energie *fps = new Energie("FPS", "FPS", 5);
    Speciale *increase = new Speciale{"Increase IP", "Augmente x IP de la carte posée", 10};
    Speciale *destroyer = new Speciale{"Destroyer", "Enleve x IP¨adversaire", 12};
    Speciale *trainer = new Speciale{"Trainer Power", "Augmente x PV de l'attaque en cours", 12};
    Speciale *recover = new Speciale{"Recover", "Récupere la derniere carte du cimetiere", 10};
    Speciale *thief = new Speciale{"Card thief", "Vole une carte a l'adversaire mais enleve 3 IP à la carte posée", 15};
    Speciale *ray = new Speciale{"X-Ray", "Permet de voir intégralement la pioche de l'adversaire", 15};

    // Ajout de ces cartes à un vecteur afin de les manipuler plus facilement

    std::vector<Carte *> boutique;


    boutique.push_back(zelda);
    boutique.push_back(nathan);
    boutique.push_back(sonic);
    boutique.push_back(mario);
    boutique.push_back(cloud);
    boutique.push_back(adv);
    boutique.push_back(rpg);
    boutique.push_back(sport);
    boutique.push_back(fps);
    boutique.push_back(increase);
    boutique.push_back(destroyer);
    boutique.push_back(trainer);
    boutique.push_back(recover);
    boutique.push_back(thief);
    boutique.push_back(ray);


    // Affichage de la boutique

    std::cout << "Voici la boutique" << std::endl;
    std::cout
            << "------------------------------------------------------------------------------------------------------"
            << "\n" << std::endl;
    for (int i = 0; i < boutique.size(); i++) {
        Color(12, 0);
        std::cout << "Carte " << i + 1 << std::endl;
        Color(11, 0);
        boutique[i]->afficherResumeCarteBoutique(); // Affichage des cartes de la boutique
        std::cout << "\n" << std::endl;
    }

    std::cout << joueur.pseudo << ": Tapez 1 pour ajouter une ou des cartes" << std::endl;
    std::cin >> choix; // On demande si le joueur veut acheter des cartes
    if (choix) { // si oui

        do {
            std::cout << "Vous avez " << joueur.donnees[16] << " pieces a disposition" << std::endl;
            std::cout << "Quelle carte voulez vous acheter ?" << std::endl;
            std::cin >> carte;
            if (carte <= 0 || carte > 15) { // verification que la carte souhaitee a un numero qui existe
                std::cout << "La carte n'est pas disonible dans la boutique" << std::endl;
            } else { // Si la carte demandee existe
                carte -= 1;
                if (boutique[carte]->getPrix() > joueur.donnees[16]) { // on verifie si le joueue a les moyens ou non
                    std::cout << "Vous ne pouvez pas acheter cette carte vous n'avez pas assez d'argent" << std::endl;
                } else { // Sinon (il a les moyens)
                    std::cout << "Ajout de la carte " << boutique[carte]->getNom() << " a votre collection"
                              << std::endl;
                    joueur.donnees[16] = (joueur.donnees[16] -
                                          boutique[carte]->getPrix()); // On enleve le prix de la carte à son argent
                    joueur.donnees[carte] += 1; // On ajoute cette carte à sa collection
                }
            }
            std::cout << "Voulez vous achter une autre carte ?" << std::endl;
            std::cin >> choix;
        } while (choix != 0); // On continue tant que le joueur souhaite acheter des cartes
    }
    std::cout << "Vous allez quitter la boutique" << std::endl;


    for (auto it = boutique.begin(); it != boutique.end(); it++) {
        delete *it; // Suppression des cartes pointées par le vecteur boutique (liberation memoire)
    }

}

void acheter(const std::string &path, std::vector<structureInfoJoueurs> &donneesJoueurs) {
    std::string name;
    int verification = 0;

    if (donneesJoueurs.empty()) { // Pas de joueurs existant
        std::cout << "Veuillez creer des joueurs .." << std::endl;
    } else { // Il existe des joueurs

        do {
            std::cout << "Quel joueur veut commencer ces achats ?" << std::endl;
            std::cin >> name; // On demande le nom du joueur qui veut acheter
            for (auto it = donneesJoueurs.begin();
                 it != donneesJoueurs.end(); it++) { // On parcourt la base de BDD (fichier texte..)
                if (it->pseudo == name) { // on trouve le joueur au pseudo correspondant
                    verification = 0;
                    afficherBoutique(*it); // On emmene le joueur "faire ses achats"
                    //Appel de la fonction en passant it en paramètres
                } else {
                    verification += 1;
                }
                if (verification ==
                    donneesJoueurs.size()) { // Aucun nom de la BDD correspond au pseudo entré dans le terminal
                    std::cout << "Veuillez entrer un nom de joueur valide .. " << std::endl;
                }
            }
        } while (verification == donneesJoueurs.size());
        writeFile(path,
                  donneesJoueurs); // On mémorise dans le BDD les achats effectués afin de les utiliser dans le jeu
    }
}
