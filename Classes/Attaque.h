//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_ATTAQUE_H
#define ECEMON_ATTAQUE_H

#include <iostream>
#include <vector>
#include "Energie.h"


// Classe d'Attaque

class Attaque {
private:
    std::string m_nomAttaque1;
    std::string m_nomAttaque2;
    StructureEnergie m_besoinNRJAttaque1;
    StructureEnergie m_besoinNRJAttaque2;
    int m_hpAttaque1;
    int m_hpAttaque2;
    int m_numeroAttaque;
public:
    Attaque(std::string nomAttaque1, std::string nomAttaque2, int hpAttaque1, int hpAttaque2, StructureEnergie NRJAttaque1,StructureEnergie NRJAttaque2);
    ~Attaque()=default;
    int getNumeroAttaque() const; // Connaitre le numero de l'attaque
    std::string getNom(const int& numeroAttaque) const;
    StructureEnergie getNRJAttaque1(); // Renvoi les besoins en énergie de l'attaque
    StructureEnergie getNRJAttaque2(); // Idem que getNRJAttaque1()
    int getHpAttaque(int nbAttaque); // Connaitre HP Attaque utilisée
    void changeHpAttaque(int hp); // Methode utilisée par carte spéciale pour augmenter HP
    void afficherResumeAttaque(); // ..


};


#endif //ECEMON_ATTAQUE_H
