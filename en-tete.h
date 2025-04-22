#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <string.h>
#include <windows.h>

#define Nb_champion 18
#define Nb_champion_cachee 3
#define Nb_champion_par_equipe 3
#define Nb_tour 4


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

void initialisation_champion(FILE *fichier, Champion *champion);
void sauter_ligne(FILE *fichier);
void afficher_personnage(Champion *champion);
void affichage_initial();
int trie (Champion *champion);
void afficher_classe(Champion *champion);
void separation_des_partie();
void classe_champion(Champion *tab, Champion *tab_soutien, Champion *tab_tank, Champion *tab_dps, int *soutien_count, int *tank_count, int *dps_count, Champion *temp);
void copie_champion(Champion *source, Champion *destination);
void afficher_equipes_cote_a_cote(Champion *equipe1, Champion *equipe2, char *nom_equipe1, char *nom_equipe2);
void afficher_champion_init(Champion *champion_soutien, Champion *champion_tank, Champion *champion_dps, int soutien_count, int tank_count, int dps_count);
void choix_des_champion(Champion *tableau_champion, Champion *equipe1);
void choix_champion_IA(Champion *tableau_champion, Champion *equipe2);
int longueur_nom_max(Champion *champions, int taille);
int comparer_par_classe(const void *a, const void *b);
int ordre_classe(const char *classe);
void affichage_saisie_utilisateur(Champion *equipe);
void afficher_degat_recu(Champion cible,Champion attaquant, int type_attaque);