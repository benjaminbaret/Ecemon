//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Attaque.h"
#include <iostream>
#include <vector>
#include "Energie.h"
#include "structures.h"


Attaque::Attaque(std::string nomAttaque1, std::string nomAttaque2, int hpAttaque1, int hpAttaque2, StructureEnergie NRJAttaque1, StructureEnergie NRJAttaque2)
        : m_nomAttaque1(nomAttaque1), m_nomAttaque2(nomAttaque2), m_hpAttaque1(hpAttaque1), m_hpAttaque2(hpAttaque2),
          m_numeroAttaque(0), m_besoinNRJAttaque1(NRJAttaque1), m_besoinNRJAttaque2(NRJAttaque2){}



std::string Attaque::getNom(const int &numeroAttaque) const {
    if (numeroAttaque == 1) {
        return m_nomAttaque1;
    } else {
        return m_nomAttaque2;
    }
}

StructureEnergie Attaque::getNRJAttaque1(){
    return m_besoinNRJAttaque1;
}
StructureEnergie Attaque::getNRJAttaque2(){
    return m_besoinNRJAttaque2;
}

int Attaque::getNumeroAttaque() const {
    return m_numeroAttaque;
}


int Attaque::getHpAttaque(int nbAttaque) {
    if(nbAttaque==1){
        return m_hpAttaque1;
    } else
        return m_hpAttaque2;
}

void Attaque::changeHpAttaque(int hp){
    m_hpAttaque1+=hp;
    m_hpAttaque2+=hp;
}



void Attaque::afficherResumeAttaque() {
    std::cout << "Attaques : -" << m_nomAttaque1 << ", HP = "<< m_hpAttaque1, afficherEnergiesNecessaires(m_besoinNRJAttaque1);
    std::cout << "           -" << m_nomAttaque2 << ", HP = "<< m_hpAttaque2, afficherEnergiesNecessaires(m_besoinNRJAttaque2);

}







