//
// Created by Lucie Dumont on 2020-11-19.
//

#include "User.h"
#include <iostream>
#include <vector>

User::User() {};

User::User(std::string name) :
        m_name(name){}


User User::getName() const {
    return m_name;
}


void User::setName(std::string name) {
    m_name = name;
}
