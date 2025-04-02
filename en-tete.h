#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>

// initialisation des fonctions

void afficher();
int initialisation_champion(FILE *fichier, champion champion);

// initialisation des structures

typedef struct 
{
    float pv_courrant;
    float pv_max;
    float attaque;
    float attaque_spe;
}champion;
