// fichier en-tête centralisé

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <string.h>
#include <windows.h>

#define Nb_champion 18
#define Nb_champion_cachee 3
#define Nb_champion_par_equipe 3
#define Nb_tour 4

#include "affichage.h"
#include "attaque.h"
#include "IA.h"


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
    char *nom;
    float pv_max;
    Propriete stat;
    char *attaque_spe;
    char *effet_spe;
    char *classe;
    int equipe; // 1 ou 2
}Champion; 

typedef struct{
    char nom[20];
    char *effet;
    int numero; // numero pour repérer l'objet
}Objet;

typedef struct 
{
    char *nom;
    Champion perso[Nb_champion_par_equipe];
    float synergie;
    Objet *objet;
}Equipe;



// initialisation des fonctions

int comparer_par_classe(const void *a, const void *b);
int ordre_classe(const char *classe);
void attaquesimple (Champion *personnage, Champion equipeAdverse[]);
void vitesse(Champion *ordreAttaque, Champion *tableau_initial);
void ia_principale(Equipe *equipe_ia, Equipe *equipe_adverse, int difficulte);
void trier_par_vitesse(Champion *ordre_passage, Equipe *equipe1, Equipe *equipe2);

