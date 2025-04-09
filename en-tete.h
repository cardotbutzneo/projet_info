#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>

// initialisation des structures

typedef struct 
{
    char nom;
    float pv_max;
    Propriete stat;
    char attaque_spe;
    char effet_spe[5];
    char classe;
}Champion;


typedef struct 
{
    float pv_courant;
    float attaque;
    float defense;
    float esquive;
    float agilite;
    float vitesse;
}Propriete;


// initialisation des fonctions

void afficher();
int initialisation_champion(FILE *fichier, Champion champion);
void sauter_ligne(FILE *fichier);
void afficher_personnage(Champion champion);
