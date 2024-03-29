//
// Created by ben on 24/11/2020.
//

#ifndef ECEMON_STRUCTURES_H
#define ECEMON_STRUCTURES_H


typedef struct {
    int FPS, Adventure, RPG, SportRace;
} StructureEnergie;

void afficherEnergiesNecessaires(StructureEnergie energies);

bool operator <= (StructureEnergie energieCarte, StructureEnergie energieJoueur);
StructureEnergie operator -(StructureEnergie &energieJoueur,StructureEnergie& energieCarte);
StructureEnergie differenceStructureEnergie(StructureEnergie energieJoueur, StructureEnergie energieCarte);

#endif //ECEMON_STRUCTURES_H
