#ifndef FONCTION_H
#define FONCTION_H

#include "en-tete.h"

// Fonctions liées aux champions et équipes
void initialisation_champion(FILE *fichier, Champion *champion);
void choix_des_champion(Champion *tableau_champion, Equipe *equipe1, Equipe *equipe2, int choix);
void choix_champion_IA(Champion *tableau_champion, Equipe *equipe2);
void copie_champion(Champion *source, Champion *destination);
void classe_champion(Champion *tab, Champion *tab_soutien, Champion *tab_tank, Champion *tab_dps, int *soutien_count, int *tank_count, int *dps_count, Champion *temp);
int trie(Champion *champion);
int chaine_caractere_egales(char *chaine1, char *chaine2);
int comparer_par_classe(const void *a, const void *b);
void trier_par_vitesse(Champion *ordre_attaque_ind, Equipe *equipe1, Equipe *equipe2);
void vitesse(Champion *ordre_attaque, Champion *ordre_attaque_ind);

#endif // FONCTION_H