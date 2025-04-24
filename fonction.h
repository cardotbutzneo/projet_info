#include "en-tete.h"

void initialisation_champion(FILE *fichier, Champion *champion);
int chaine_caractere_egales(char *chaine1, char *chaine2);
int trie (Champion *champion);
void choix_des_champion(Champion *tableau_champion, Equipe *equipe1, Equipe *equipe2, int choix);    void choix_champion_IA(Champion *tableau_champion, Equipe *equipe2);
void classe_champion(Champion *tab, Champion *tab_soutien, Champion *tab_tank, Champion *tab_dps, int *soutien_count, int *tank_count, int *dps_count, Champion *temp);
void copie_champion(Champion *source, Champion *destination);
void saisie_utilisateur(Champion *champion, Equipe equipe2 );
int longueur_nom_max(Champion *champions, int taille);
int comparer_par_vitesse(const void *a, const void *b);
void choix_champion_IA(Champion *tableau_champion, Equipe *equipe2);