//
// Created by ben on 21/11/2020.
//

#include "jouer.h"
#include "lectureEcritureDonnees.h"
#include "User.h"


void jouer(User &joueur1, User &joueur2) {
    int isEnd=1;
    if (tirageJoueur(joueur1, joueur2)) { // tirage joueur vaut 1 donc JOUEUR 2 qui commence
        joueur1.tirerCarteEnjeu();
        joueur2.tirerCarteEnjeu();
        do {


            std::cout << "Au tour de " << joueur2.getNom() << " de jouer" << std::endl;
            if (joueur2.proposerCarte()) {
                joueur2.placer(joueur1, joueur2);
            }

            std::cout << "Au tour de " << joueur1.getNom() << " de jouer" << std::endl;
            if (joueur1.proposerCarte()) {
                joueur1.placer(joueur1, joueur2);
            }
        }while (isEnd);

    } else {
        joueur1.tirerCarteEnjeu();
        joueur2.tirerCarteEnjeu();
        do {

            std::cout << "Au tour de " << joueur1.getNom() << " de jouer" << std::endl;
            if (joueur1.proposerCarte()) {
                joueur1.placer(joueur1, joueur2);
            }
            std::cout << "Au tour de " << joueur2.getNom() << " de jouer" << std::endl;
            if (joueur2.proposerCarte()) {
                joueur2.placer(joueur1, joueur2);
            }
        }while (isEnd);

    }
    // On a 0 renvoyé ici

}
int tirageJoueur(const User& joueur1, const User& joueur2) {
    int commence;
    commence = rand() %(2);
    if (commence == 0) {
        std::cout << "C'est le joueur : "<< joueur1.getNom() << " qui commence" << std::endl;
    } else {
        std::cout << "C'est le joueur : "<< joueur2.getNom() << " qui commence"<< std::endl;
    }
    return commence;
}
