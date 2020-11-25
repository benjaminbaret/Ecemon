//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Speciale.h"
#include <iostream>
#include <vector>
#include "Carte.h"
#include "User.h"

Speciale::Speciale(std::string nom, std::string description): Carte(nom, description){}

std::string  Speciale::getType() {
    return "Speciale";
}





///
void Speciale::choisir_carte_picohe() const {

}


void Speciale::jouer_deux_fois_de_suite() const{

}

void Speciale:: echange(User adversaire, User me)
{
    int index = 0;

    std::cout << "Quelle carte voulez voulez vous echanger ?" << std::endl;
    std::cin >> index;
    me.getDeck().erase(me.getDeck().begin() + index);
    std::cout << "Par quelle carte voulez vous la remplacer ?" <<std::endl;
    std::cin >>index;
    adversaire.getDeck().push_back(adversaire.getCollection()[index]);

    //  Carte stock=*this;
    //  m_rarete=ct.getRarete();
    //  ct=stock;
}

void Speciale:: voir_les_cartes_adverses(User adversaire){
    std::cout << "Voici le Deck de votre adversaire" << std::endl;
    adversaire.afficherDeck();
}

///