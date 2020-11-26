//
// Created by ben on 21/11/2020.
//

#include "jouer.h"
#include "lectureEcritureDonnees.h"
#include "User.h"


void jouer(User &joueur1, User &joueur2) {
    int isEnd = 1;
    if (tirageJoueur(joueur1, joueur2)) { // tirage joueur vaut 1 donc JOUEUR 2 qui commence
        joueur1.tirerCarteEnjeu();
        joueur2.tirerCarteEnjeu();
        do {
            joueur2.affichagePlateau(joueur1);
            joueur2.afficherResume();
            if (joueur2.proposerCarte()) {
                isEnd = joueur2.verificationFinJeu();
                if(isEnd!=0){
                    joueur2.placer(joueur1);
                    joueur2.verificationIpCreature();

                }else
                    joueur1.echangeEnjeu(joueur2);
            }

            if (isEnd != 0) {
                joueur1.affichagePlateau(joueur2);
                joueur1.afficherResume();
                if (joueur1.proposerCarte()) {
                    isEnd = joueur1.verificationFinJeu();
                    if(isEnd!=0){
                        joueur1.placer(joueur2);
                        joueur1.verificationIpCreature();
                    }else
                        joueur2.echangeEnjeu(joueur1);
                }
            }
        } while (isEnd);

    } else {
        joueur1.tirerCarteEnjeu();
        joueur2.tirerCarteEnjeu();
        do {
            joueur1.affichagePlateau(joueur2);
            joueur1.afficherResume();
            if (joueur1.proposerCarte()) {
                isEnd = joueur1.verificationFinJeu();
                if(isEnd!=0){
                    joueur1.placer(joueur2);
                    joueur1.verificationIpCreature();
                }else
                    joueur2.echangeEnjeu(joueur1);
            }

            if (isEnd != 0) {
                joueur2.affichagePlateau(joueur1);
                joueur2.afficherResume();

                if (joueur2.proposerCarte()) {
                    isEnd = joueur2.verificationFinJeu();
                    if(isEnd!=0){
                        joueur2.placer(joueur1);
                        joueur2.verificationIpCreature();
                    }else
                        joueur1.echangeEnjeu(joueur2);

                }
            }

        } while (isEnd);


    }
    // On a 0 renvoyé ici

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
