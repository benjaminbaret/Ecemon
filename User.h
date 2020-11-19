//
// Created by Lucie Dumont on 2020-11-19.
//

#ifndef ECEMON_USER_H
#define ECEMON_USER_H

#include <iostream>
#include<vector>

class User {
private:
    std::string m_name;
    int m_victoire;
public:
    User();
    User (std::string name);
    ~User()=default;
    std::string getName() const;
    void setName(std::string name);
    void creerPioche();
    void selectionnerDeck();
    void verifierFile();



};


#endif //ECEMON_USER_H
