//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_USER_H
#define ECEMON_USER_H

#include <iostream>
#include<vector>
#include "Carte.h"
#include "Creature.h"
#include "queue"

class User {
private:
    std::string m_nom;
    int m_victoire;
    std::vector<Carte> m_collection;
    std::queue<Carte *> m_pioche;
    std::vector<Creature *> m_cimetiere;
    Carte *m_carteEnJeux;
    Carte *m_creatureActive;
public:
    User();

    User(std::string nom);

    ~User() = default;

    std::string getNom() const;

    void setNom(std::string nom);

    void creerPioche();

    void selectionnerDeck();

    void verifierFile();

    void afficherNom();

    void remplirCollection(Carte maCarte);

    void afficheCollection();


};


#endif //ECEMON_USER_H
