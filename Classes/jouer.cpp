//
// Created by ben on 21/11/2020.
//

#include "jouer.h"
#include "lectureEcritureDonnees.h"
#include "User.h"


void jouer(User &joueur1, User &joueur2) {
    if (tirageJoueur(joueur1, joueur2)) { // On détermine ici qui commence
        boucleJeux(joueur1, joueur2); // On appelle en conséquence les joueurs dans la boucle de jeu dans l'ordre tiré

    } else {
        boucleJeux(joueur2, joueur1);
    }
}

int tirageJoueur(const User &joueur1, const User &joueur2) { // Determination de quel joueur commence
    int commence;
    commence = rand() % (2);
    if (commence == 0) {
        std::cout << "C'est le joueur : " << joueur1.getNom() << " qui commence" << std::endl;
    } else {
        std::cout << "C'est le joueur : " << joueur2.getNom() << " qui commence" << std::endl;
    }
    return commence; // on renvoi qui commence
}


void boucleJeux(User &premierJoueurPioche,User &secondJoueurPioche){ // on tourne dans cette boucle pour le déroulement du jeu
    int isEnd = 1;

    // on appelle méthodes permettant de tirer les cartes enjeu

    premierJoueurPioche.tirerCarteEnjeu();
    secondJoueurPioche.tirerCarteEnjeu();

    do {
        secondJoueurPioche.verificationIpCreature();                           // On regarde si les créatures du joueur on lieu de rester sur le plateau (ip>0)
        secondJoueurPioche.affichagePlateau(premierJoueurPioche);
        secondJoueurPioche.afficherResume();
        isEnd = secondJoueurPioche.verificationFinJeu();                        // On regarde si le joueur a encore des IP ou s'il a encore des créatures
        if (isEnd != 0) {                                                       // Si ce n'est pas la fin du jeu
            if (secondJoueurPioche.proposerCarte()) {                           // On propose de placer carte
                secondJoueurPioche.placer(premierJoueurPioche);     // Si oui pour la placer, on la place (on proposera d'attaquer dans la méthode placer)
            } else
                secondJoueurPioche.proposerAttaque(premierJoueurPioche); // On propose sinon d'attaquer

        } else
            premierJoueurPioche.echangeEnjeu(secondJoueurPioche); // Sinon, c'est la fin de jeu, on prend la carte "Enjeu" de l'adversaire


        if (isEnd != 0) { //
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
    } while (isEnd); // on repete tant que tous les joueurs on une créature (au moins) ou on assez de pv

}
