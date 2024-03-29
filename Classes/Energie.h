//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_ENERGIE_H
#define ECEMON_ENERGIE_H
#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include "Carte.h"
#include "structures.h"

class Energie : public Carte{
private :
    std::string m_element;
public :
    Energie(std::string element, std::string nom, int valeur);
    virtual void afficherCarte();
    std::string getNom();
    std::string getType();
    ~Energie()=default;
    void afficherResumeCarte();
    void afficherResumeCarteBoutique();




};


#endif //ECEMON_ENERGIE_H
