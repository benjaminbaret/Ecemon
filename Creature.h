//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_CREATURE_H
#define ECEMON_CREATURE_H
#include <iostream>
#include <vector>
#include "Carte.h"

class Creature public Carte {
private:
    int m_ip;
public:
    ~Creature()=default;
    void afficherDescription();
    int enleverPv();

};


#endif //ECEMON_CREATURE_H
