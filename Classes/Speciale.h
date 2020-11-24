//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_SPECIALE_H
#define ECEMON_SPECIALE_H
#include <iostream>
#include <vector>
#include "Classes/Carte.h"
#include "User.h"
#include <iostream>
#include <vector>

class Speciale : public Carte{
private:

public:
    Speciale(std::string nom, std::string description);
    ~Speciale()=default;
   // void choisir_carte_picohe() const ;
    void ressusiter_carte_cimetiere() const ;
    void jouer_deux_fois_de_suite() const;

    void echange(User adversaire, User me);


    int increaseIP(Creature C1);
    int destroyerIP(Creature C1);
    int trainerPower(Attaque A1);
    void x_ray(User adversaire); // voir_les_cartes_adverses
    void card_thief(User adversaire, Creature C);


};



#endif //ECEMON_SPECIALE_H
