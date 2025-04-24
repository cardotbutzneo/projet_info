#ifndef EN_TETE_H
#define EN_TETE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

// Constantes
#define Nb_champion 18
#define Nb_champion_cachee 3
#define Nb_champion_par_equipe 3
#define Nb_tour 4

// Structures
typedef struct {
    float pv_courant;
    float attaque;
    float defense;
    float agilite;
    float vitesse;
} Propriete;

typedef struct {
    char *nom;
    float pv_max;
    Propriete stat;
    char *attaque_spe;
    char *effet_spe;
    char *classe;
    int equipe; // 1 ou 2
} Champion;

typedef struct {
    char nom[20];
    char *effet;
    int numero; // numero pour repérer l'objet
} Objet;

typedef struct {
    char *nom;
    Champion perso[Nb_champion_par_equipe];
    float synergie;
    Objet *objet;
} Equipe;

#endif // EN_TETE_H

