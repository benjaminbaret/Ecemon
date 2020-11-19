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
    bool m_active;
    std::string m_rarete;
    User m_user;
    std::string m_description;
    int m_cycleVie;
    std::string m_nom;
public:
    //Carte();
    ~Carte()= default;
    void afficher()const;
};


#endif //ECEMON_CARTE_H
