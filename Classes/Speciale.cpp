//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Speciale.h"
#include "User.h"
#include <iostream>
#include <vector>
#include "Carte.h"

Speciale::Speciale(std::string nom, std::string description): Carte(nom, description, false){}


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


void Speciale:: x_ray(User adversaire){
    std::cout << "Voici le Deck de votre adversaire" << std::endl;
    adversaire.afficherDeck();
}
///////////////////////////////////////////:

int Speciale::increaseIP(Creature C1){
    int nouveau_point=0;
    nouveau_point=C1.ajouterIp(2);
    return nouveau_point;
}
int Speciale::destroyerIP(Creature C1){
    int nouveau_point=0;
    nouveau_point=C1.enleverIp(2);
    return nouveau_point;
}
int Speciale::trainerPower(Attaque A1) {
    int nouvelle_attaque=0;
    nouvelle_attaque=A1.ajouterPV(1);
    return nouvelle_attaque;
}
void Speciale::card_thief(User adversaire, Creature C){
    int nouveau_point=0;
    nouveau_point=C.enleverIp(3); //eneleve 3 IP a la carte
    // Commment voler une carte a l'adversaire ????
}
