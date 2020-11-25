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

