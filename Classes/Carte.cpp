//
// Created by Lucie Dumont on 2020-11-19.
//

#include "Carte.h"
#include <iostream>
#include <vector>

Carte::Carte(std::string& nom, bool active)
        :m_nom{nom}
{}

Carte::Carte(std::string& nom, std::string& description, bool active)
        :m_nom{nom}, m_description(description)
{}

std::string Carte::getNom() {
    return m_nom;
}

void Carte::afficherCarte() {
    std::cout<<m_nom<<std::endl;
}
/*std::string Carte::getRarete(){
    return m_rarete;
}
 */

int Carte:: compare(Carte& ct)
{
    if(this->valeur > ct.valeur)
        return 1;//si la premiere carte superieure a la 2 eme
    else if(this->valeur < ct.valeur)
        return 2;//si la premiere carte inferieure a la 2 eme
    else
        return 0;//ils sont egaux
}

