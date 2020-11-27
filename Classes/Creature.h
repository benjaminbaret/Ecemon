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
    int m_ip;
    Attaque m_attaque;
public:
    Creature(int vie, std::string nom, std::string nomAttaque1, std::string nomAttaque2, int hpAttaque1, int hpAttaque2, StructureEnergie NRJAttaque1, StructureEnergie NRJAttaque2,int valeur);
    ~Creature()=default;
    void afficherDescription();
    void enleverIp(int nbHp);
    int getIp();
    virtual void afficherCarte();
    std::string getType();
    std::string getNom();
    int compareAvecEnergie1(StructureEnergie comparant);
    int compareAvecEnergie2(StructureEnergie comparant);
    void getNomAttaque(const int& numeroAttaque) ;
    int getHpAttaquer(int nbAttaque);
    void setIp(int ip);
    void getChangeHpAttaque(int hp);
    void afficherResumeCarte();
    void afficherResumeCarteBoutique();
    StructureEnergie getEnergieAttaque(int nbAttaque);










};


#endif //ECEMON_CREATURE_H
