#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>

// initialisation des structures

typedef struct 
{
    float pv_courant;
    float attaque;
    float attaque_spe;
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
int initialisation_champion(FILE *fichier, Champion champion);




