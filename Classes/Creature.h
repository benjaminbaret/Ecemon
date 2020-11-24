//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_CREATURE_H
#define ECEMON_CREATURE_H
#include <iostream>
#include <vector>
#include "Classes/Carte.h"
#include "Attaque.h"


class Creature : public Carte{
private:
    std::string descritpion;
    int m_ip;
    Attaque m_attaque;
public:
    Creature(int vie, std::string nom, std::string nomAttaque1, std::string nomAttaque2, int hpAttaque1, int hpAttaque2, StructureEnergie NRJAttaque1, StructureEnergie NRJAttaque2);
    ~Creature()=default;
    void afficherDescription();
    void enleverIp(int nbHp);
    int getIp();
    virtual void afficherCarte();
    std::string getType();
    std::string getNom();
    StructureEnergie getEnergie1();
    StructureEnergie getEnergie2();
    void getNomAttaque(const int& numeroAttaque) ;




};


#endif //ECEMON_CREATURE_H
