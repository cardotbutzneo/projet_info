#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>
#include <string.h>
#include <windows.h>

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
}Champion;

typedef struct 
{
    char *nom;
    Champion perso1;
    Champion perso2;
    Champion perso3;
    float synergie;
}Equipe;


// initialisation des fonctions

void afficher();
void initialisation_champion(FILE *fichier, Champion *champion);
void sauter_ligne(FILE *fichier);
void afficher_personnage(Champion *champion);
void affichage_initial();
int trie (Champion *champion);
void afficher_classe(Champion *champion);
void separation_des_partie();
void classe_champion(Champion *tab, Champion *tab_soutien, Champion *tab_tank, Champion *tab_dps, int *soutien_count, int *tank_count, int *dps_count);
void copie_champion(Champion *source, Champion *destination);