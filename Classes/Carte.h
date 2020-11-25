//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_CARTE_H
#define ECEMON_CARTE_H


#include <iostream>
#include <vector>
#include "structures.h"


class Carte {
protected :
    // User m_user;
    std::string m_rarete;
    std::string m_nom;
    std::string m_description;
    int m_active;
    int m_cycleVie;
    int valeur;

public:
    Carte(std::string &nom);

    Carte(std::string &nom, std::string &description);

    virtual ~Carte() = default;

    virtual std::string getNom();

    virtual void afficherCarte();

    virtual std::string getType();

    virtual int compareAvecEnergie1(StructureEnergie comparant);

    virtual int compareAvecEnergie2(StructureEnergie comparant);

    virtual void getNomAttaque(const int &numeroAttaque);

    virtual int getHpAttaquer(int nbAttaque);

    virtual int getIp();

    virtual void enleverIp(int nbHp);

    virtual void setIp(int ip);

    virtual void getChangeHpAttaque(int hp);

    int getActif();

    void setActif(int actif);


};

#endif //ECEMON_CARTE_H
