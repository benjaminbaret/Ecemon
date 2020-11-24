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
    void afficherDeck();
    void afficheCollection();
    std::vector<int> getInfoCartesJoueur();
    Carte *getCarteEnJeu() const;
    void setCarteEnJeu();

    void creerDeck();

    void creerPioche();

    void setNom(std::string nom);

    void verifierFile();

    void afficherNom();

    void setScore(int score);

    void remplirCollection(Carte* maCarte);

    std::vector<Carte*> getDeck();
    std::vector<Carte*> getCollection();

    Carte *piocherCarte();

    };


#endif //ECEMON_USER_H
