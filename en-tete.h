#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>

// initialisation des structures

typedef struct 
{
    float pv_courant;
    float attaque;
    float defense;
    float agilite;
    float vitesse;
}Propriete;


typedef struct 
{
    char nom;
    float pv_max;
    Propriete stat;
    char attaque_spe;
    char effet_spe[5];
    char classe;
}Champion;




// initialisation des fonctions

void afficher();
void initialisation_champion(FILE *fichier, Champion *champion);
void sauter_ligne(FILE *fichier);
void afficher_personnage(Champion *champion);
