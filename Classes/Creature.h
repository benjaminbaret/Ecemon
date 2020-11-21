//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_CREATURE_H
#define ECEMON_CREATURE_H
#include <iostream>
#include <vector>
#include "Carte.h"

class Creature : public Carte{
private:
    std::string descritpion;
    int m_ip;
public:
    Creature(int vie, std::string nom);
    ~Creature()=default;
    void afficherDescription();
    int enleverPv();
    int getIp();
    virtual void afficherCarte();
    std::string getNom();

};


#endif //ECEMON_CREATURE_H
