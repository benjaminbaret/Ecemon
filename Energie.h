//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_ENERGIE_H
#define ECEMON_ENERGIE_H
#include <iostream>
#include <vector>
#include "Carte.h"

class Energie public : Carte{
private :
    std::string m_element;
public :
    ~Energie()=default;
};


#endif //ECEMON_ENERGIE_H