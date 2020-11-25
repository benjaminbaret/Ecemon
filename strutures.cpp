//
// Created by ben on 24/11/2020.
//

#include "structures.h"
#include <iostream>

void afficherEnergiesNecessaires(StructureEnergie energies){
    std::cout << " / ADV : " <<energies.Adventure << "  FPS : "<< energies.FPS << "  RPG : " << energies.RPG << "  SR : " << energies.SportRace << std::endl;
}

bool operator == (StructureEnergie energieJoueur, StructureEnergie energieCarte){
    if(energieJoueur.FPS==energieCarte.FPS && energieJoueur.RPG==energieCarte.RPG &&
    energieJoueur.Adventure==energieCarte.Adventure && energieJoueur.SportRace==energieCarte.SportRace){
        return true;
    } else{
        return false;
    }
}