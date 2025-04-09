#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>

// initialisation des structures

typedef struct 
{
    float pv_courrant;
    float pv_max;
    float attaque;
    float attaque_spe;
}Champion;


// initialisation des fonctions

void afficher();
int initialisation_champion(FILE *fichier, Champion champion);
void sauter_ligne(FILE *fichier);
void afficher_personnage(Champion champion);
