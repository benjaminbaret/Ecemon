//
// Created by ben on 24/11/2020.
//

#ifndef ECEMON_STRUCTURES_H
#define ECEMON_STRUCTURES_H


typedef struct {
    int FPS, Adventure, RPG, SportRace;
} StructureEnergie;

bool operator == (StructureEnergie energieJoueur, StructureEnergie energieCarte);

#endif //ECEMON_STRUCTURES_H
