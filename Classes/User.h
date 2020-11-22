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
    int m_score;
    std::vector<Carte*> m_collection;
    std::queue<Carte *> m_pioche;
    std::vector<Creature *> m_cimetiere;
    Carte* m_carteEnJeux;
    std::vector<Carte*>m_deck;
    std::vector<int> nombreCartesCategories;

    Carte* m_creatureActive;
public:
    User();
    ~User();
    User(std::string nom);

    std::string getNom() const;

    void setNom(std::string nom);

    void creerPioche();

    void creerDeck();

    void afficherDeck();

    void selectionnerDeck();

    void verifierFile();

    void afficherNom();

    void setScore(int score);

    void remplirCollection(Carte* maCarte);

    void afficheCollection();

    std::vector<int> getInfoCartesJoueur();


};


#endif //ECEMON_USER_H
