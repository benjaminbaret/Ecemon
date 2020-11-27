//
// Created by ben on 24/11/2020.
//

#include "structures.h"
#include <iostream>

void afficherEnergiesNecessaires(StructureEnergie energies){
    std::cout << " / ADV : " <<energies.Adventure << "  FPS : "<< energies.FPS << "  RPG : " << energies.RPG << "  SR : " << energies.SportRace << std::endl;
}


bool operator<=(StructureEnergie energieCarte, StructureEnergie energieJoueur){
    if(energieCarte.FPS<=energieJoueur.FPS && energieCarte.RPG<=energieJoueur.RPG && energieCarte.Adventure<=energieJoueur.Adventure && energieCarte.SportRace<=energieJoueur.SportRace){
        return true;
    } else
        return 0;
}


StructureEnergie operator-(StructureEnergie& energieJoueur,StructureEnergie &energieCarte){
    StructureEnergie resultat;
    resultat.FPS=energieJoueur.FPS-energieCarte.FPS;
    resultat.RPG=energieJoueur.RPG-energieCarte.RPG;
    resultat.SportRace=energieJoueur.SportRace-energieCarte.SportRace;
    resultat.Adventure=energieJoueur.Adventure-energieCarte.Adventure ;

    return resultat;

}


StructureEnergie differenceStructureEnergie(StructureEnergie energieJoueur, StructureEnergie energieCarte){

    StructureEnergie  resultat;
    resultat = energieJoueur-energieCarte;
    return resultat;
}