//
// Created by ben on 24/11/2020.
//

#include "structures.h"


bool operator == (StructureEnergie energieJoueur, StructureEnergie energieCarte){
    if(energieJoueur.FPS==energieCarte.FPS && energieJoueur.RPG==energieCarte.RPG &&
    energieJoueur.Adventure==energieCarte.Adventure && energieJoueur.SportRace==energieCarte.SportRace){
        return true;
    } else{
        return false;
    }
}