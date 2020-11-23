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
    void voir_les_cartes_adverses(User adversaire);
    void echange(User adversaire, User me);


};



#endif //ECEMON_SPECIALE_H
