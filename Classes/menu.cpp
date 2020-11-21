//
// Created by ben on 21/11/2020.
//

#include "Classes/menu.h"
#include <iostream>






void affichageMenu(){
    int choix = 0;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "1) Afficher les joueurs existants" << std::endl;
    std::cout << "2) Ajouter un joueur" << std::endl;
    std::cout << "3) Lancer un combat" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    std::cin >> choix;
}
