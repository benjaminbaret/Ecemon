//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_USER_H
#define ECEMON_USER_H


#include <iostream>
#include<vector>
#include "Creature.h"
#include "queue"
#include "Carte.h"


class User {
private:
    std::string m_nom;
    int m_pointsVie;
    int m_score;
    std::vector<Carte*> m_collection;
    std::queue<Carte *> m_pioche;
    std::vector<Carte *> m_cimetiere;
    std::vector<Carte *>m_energies;
    Carte* m_carteEnjeu;
    std::vector<Carte*>m_deck;
    std::vector<int> nombreCartesCategories;
    Carte* m_creatureActive;
    StructureEnergie m_energieDisponible;
public:
    User();
    ~User();
    User(std::string nom);

    std::string getNom() const;
    void afficherDeck();
    void afficheCollection();
    std::vector<int> getInfoCartesJoueur();
    void tirerCarteEnjeu();
    int proposerCarte();
    void placer(User &joueur1, User &joueur2);
    void enleverPvAdversaire(int hp);
    int getIp();
    void attaquer(User &joueurAdverse,int nbAttaque);
    void creerDeck();
    int getIpJoueur();


    void creerPioche();

    void setNom(std::string nom);

    void verifierFile();

    void afficherNom();

    void setScore(int score);

    void remplirCollection(Carte* maCarte);

    void enleverPointsVie(int nbHp);

    int getCreatureActive();

    void volerCarte(User &joueurAdverse);

    void enleverIpCarteOuJoueur(int hp);

    //Verifications

    void verificationIpCreature();

    int verificationFinJeu();

    void afficherResume();


    //Verification finJeu (on regarde que créature dans pioche ==> dans deck)




    ///
    std::vector<Carte*> getDeck();
    std::vector<Carte*> getCollection();
    ///

};


#endif //ECEMON_USER_H
