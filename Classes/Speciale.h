//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_SPECIALE_H
#define ECEMON_SPECIALE_H
#include <iostream>
#include <vector>
#include "Classes/Carte.h"
#include <iostream>
#include <vector>
#include "User.h"

class Speciale : public Carte{
private:

public:
    Speciale(std::string nom, std::string description);
    ~Speciale()=default;
    std::string getType();


    ///
    void ressusiter_carte_cimetiere() const ;
    void jouer_deux_fois_de_suite() const;
    void voir_les_cartes_adverses(User adversaire);
    void echange(User adversaire, User me);
    void choisir_carte_picohe() const;
        ///


};



#endif //ECEMON_SPECIALE_H
