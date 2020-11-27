//
// Created by ben on 21/11/2020.
//

#include "jouer.h"
#include "lectureEcritureDonnees.h"
#include "User.h"


void jouer(User &joueur1, User &joueur2) {
    if (tirageJoueur(joueur1, joueur2)) {
        boucleJeux(joueur1, joueur2);

    } else {
        boucleJeux(joueur2, joueur1);
    }
}

int tirageJoueur(const User &joueur1, const User &joueur2) {
    int commence;
    commence = rand() % (2);
    if (commence == 0) {
        std::cout << "C'est le joueur : " << joueur1.getNom() << " qui commence" << std::endl;
    } else {
        std::cout << "C'est le joueur : " << joueur2.getNom() << " qui commence" << std::endl;
    }
    return commence;
}


void boucleJeux(User &premierJoueurPioche,User &secondJoueurPioche){
    int isEnd = 1;

    premierJoueurPioche.tirerCarteEnjeu();
    secondJoueurPioche.tirerCarteEnjeu();

    do {
        secondJoueurPioche.verificationIpCreature();
        secondJoueurPioche.affichagePlateau(premierJoueurPioche);
        secondJoueurPioche.afficherResume();
        isEnd = secondJoueurPioche.verificationFinJeu();
        if (isEnd != 0) {
            if (secondJoueurPioche.proposerCarte()) {
                secondJoueurPioche.placer(premierJoueurPioche);
            } else
                secondJoueurPioche.proposerAttaque(premierJoueurPioche);

        } else
            premierJoueurPioche.echangeEnjeu(secondJoueurPioche);


        if (isEnd != 0) {
            premierJoueurPioche.verificationIpCreature();
            premierJoueurPioche.affichagePlateau(secondJoueurPioche);
            premierJoueurPioche.afficherResume();
            isEnd = premierJoueurPioche.verificationFinJeu();
            if (isEnd != 0) {
                if (premierJoueurPioche.proposerCarte()) {

                    premierJoueurPioche.placer(secondJoueurPioche);

                } else
                    premierJoueurPioche.proposerAttaque(secondJoueurPioche);

            } else
                secondJoueurPioche.echangeEnjeu(premierJoueurPioche);

        }
    } while (isEnd);

}
