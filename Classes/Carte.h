//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_CARTE_H
#define ECEMON_CARTE_H


#include <iostream>
#include <vector>


class Carte {
protected :
   // User m_user;
    std::string m_rarete;
    std::string m_nom;
    std::string m_description;
    bool m_active;
    int m_cycleVie;
    int valeur;

public:
    Carte(std::string& nom, bool actif= false);
    Carte(std::string& nom, std::string& description, bool active);
    virtual ~Carte()=default;
    virtual std::string getNom();
    virtual void afficherCarte();
    virtual std::string getType();
    //virtual StructureEnergie
    //void afficher()const;

    ///
    int compare(Carte& ct);
    //  virtual std::string getRarete();
    ///
};


#endif //ECEMON_CARTE_H
