//
// Created by ben on 21/11/2020.
//

#include "jouer.h"
#include "lectureEcritureDonnees.h"
#include "User.h"









/*void jouer(User &joueur1, User &joueur2){

    if(tirageJoueur()){

        // c'est le joueur 2 qui joue ici, à l'appel d'une fonction avec "User& joueur2 dedans du coup
    }
    else{

    }



}*/












///
///
int tirageJoueur(const User& joueur1, const User& joueur2) {
    int commence;
    for (int i = 0; i < 2; i++) {
        commence = rand() %(2);
        if (commence == 0) {
            std::cout << "C'est le joueur : "<< joueur1.getNom() << " qui commence" << std::endl;
        } else {
            std::cout << "C'est le joueur : "<< joueur2.getNom() << " qui commence"<< std::endl;
        }
    }
    return commence;
}


void comparecarte(Carte& carte1,Carte& carte2)
{
    if(carte1.compare(carte2)==1)//la carte du joueur 1 est superiere que la carte du joueur 2
    {
        //me.setScore(1);


    }
    else if(carte1.compare(carte2)==2)//c'est a dire la carte du joueur 1 est inferieur que la carte du joueur 2
    {
        //adversaire.setScore(1);

    }

}
///

void choixJoueurs(){

};
