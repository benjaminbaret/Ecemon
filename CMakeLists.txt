cmake_minimum_required(VERSION 3.17)
project(Ecemon)

set(CMAKE_CXX_STANDARD 14)


include_directories(.)

add_executable(Ecemon main.cpp Classes/Creature.cpp Classes/Creature.h Classes/Attaque.cpp Classes/Attaque.h Classes/Carte.cpp Classes/Carte.h Classes/Energie.cpp Classes/Energie.h Classes/Speciale.h Classes/Speciale.cpp Classes/User.cpp Classes/User.h Classes/lectureEcritureDonnees.cpp Classes/lectureEcritureDonnees.h Classes/menu.cpp Classes/menu.h Classes/jouer.cpp Classes/jouer.h Classes/initialisationJoueurs.cpp Classes/initialisationJoueurs.h Classes/affichageEnConsole.cpp Classes/affichageEnConsole.h)


