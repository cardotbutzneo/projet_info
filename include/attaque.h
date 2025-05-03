#ifndef ATTAQUE_H
#define ATTAQUE_H

#include "en-tete.h"

// Fonctions liées aux attaques
void attaquesimple(Champion *personnage, Champion equipeAdverse[]);
float degat(Champion personnage);
int cibleAttaque(Champion equipe[]);

#endif // ATTAQUE_H