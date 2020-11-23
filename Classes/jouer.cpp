//
// Created by ben on 21/11/2020.
//

#include "jouer.h"
#include "lectureEcritureDonnees.h"
#include "User.h"



int tirageJoueur() {
    int commence;
    for (int i = 0; i < 2; i++) {
        commence = rand() %(2);
        if (commence == 0) {
            std::cout << "C'est l'adversaire qui commence a jouer " << std::endl;
        } else {
            std::cout << "C'est moi qui commence le jeu" << std::endl;
        }
    }
    return commence;
}


void comparecarte(Carte& carte1,Carte& carte2)
{
    if(carte1.compare(carte2)==1)//la carte du joueur 1 est superiere que la carte du joueur 2
    {
        me.setScore(1);

    }
    else if(carte1.compare(carte2)==2)//c'est a dire la carte du joueur 1 est inferieur que la carte du joueur 2
    {
        adversaire.setScore(1);

    }

}


void choixJoueurs() {

}

