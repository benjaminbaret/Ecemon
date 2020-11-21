//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_CARTE_H
#define ECEMON_CARTE_H

#include "User.h"
#include <iostream>
#include <vector>


class Carte {
protected :
    User m_user;
    std::string m_rarete;
    std::string m_nom;
    std::string m_description;
    bool m_active;
    int m_cycleVie;

public:
    Carte(std::string nom, bool actif= false);
    virtual ~Carte()=default;
    virtual std::string getNom();
    virtual void afficherCarte();
    void afficher()const;
};


#endif //ECEMON_CARTE_H
