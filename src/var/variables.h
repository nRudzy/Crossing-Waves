#ifndef VARIABLES_H
#define VARIABLES_H

//! DEBUG
#define DEBUG true
//! FRAMERATE
#define FRAMERATE 60

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

//! Variables globales
extern const int window_width, window_height;
extern int compteur_tick;
extern bool en_jeu;
//extern bool pause;
extern bool start;

extern const float vitessePlayer;
extern const float vitesseMonster;

extern const int playerDamage;
extern const float vitesseBalle;


#endif //! variables.h
