#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "en-tete.h"

// Fonctions d'affichage
void afficher_personnage(Champion *champion);
void afficher_champion_init(Champion *champion_soutien, Champion *champion_tank, Champion *champion_dps, int soutien_count, int tank_count, int dps_count);
void afficher_classe(Champion *champion);
void afficher_equipe(Equipe equipe1, Equipe equipe2);
void afficher_equipes_cote_a_cote(Equipe equipe1, Equipe equipe2);
void afficher_degat_recu(Champion cible, Champion attaquant, int type_attaque);
void saisie_utilisateur(Champion *champion, Equipe *equipe2);
void separation_des_partie();
void sauter_ligne(FILE *fichier);
int affichage_saisie_utilisateur(Champion champion);
void affichage_initial();
int type_os(int type_OS);
#endif // AFFICHAGE_H