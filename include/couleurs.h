// couleurs.h

#ifndef COULEURS_H
#define COULEURS_H

// Codes de couleur ANSI
#define RESET   "\033[0m"
#define ROUGE   "\033[1;31m" //tout ce qui est dégâts et effets d'attaque, personnages DPS, effets négatif etc
#define BLEU    "\033[1;34m" //titres, affichages
#define VERT    "\033[1;32m" //soins, effets positifs etc
#define JAUNE   "\033[1;33m" //pour les avertissements, les messages d'erreur
#define MAGENTA "\033[1;35m" 
#define CYAN    "\033[1;36m" //esquives
#define BLANC   "\033[1;37m"      // Blanc
#define NOIR    "\033[1;30m"      // Noir
#define ROUGE_CLAIR   "\033[1;91m" // Rouge clair   classe DPS
#define BLEU_CLAIR    "\033[1;94m" // Bleu clair    classe tank
#define VERT_CLAIR    "\033[1;92m" // Vert clair  classe soutiens
#define JAUNE_CLAIR   "\033[1;93m" // Jaune clair
#define MAGENTA_CLAIR "\033[1;95m" // Magenta clair
#define CYAN_CLAIR    "\033[1;96m" // Cyan clair
#define BLANC_CLAIR   "\033[1;97m" // Blanc clair
#define GRIS    "\033[1;90m"      // Gris   
#define ROUGE_FONCE   "\033[0;31m" // Rouge foncé
#define BLEU_FONCE    "\033[0;34m" // Bleu foncé
#define VERT_FONCE    "\033[0;32m" // Vert foncé
#define JAUNE_FONCE   "\033[0;33m" // Jaune foncé
#define MAGENTA_FONCE "\033[0;35m" // Magenta foncé
#define CYAN_FONCE    "\033[0;36m" // Cyan foncé
#define BLANC_FONCE   "\033[0;37m" // Blanc foncé
#define GRIS_FONCE    "\033[0;90m" // Gris foncé
#endif // COULEURS_H

// exemple d'utilisation : 

/*
#include "couleurs.h"

int main() {
    printf(ROUGE "Ce texte est en rouge\n" RESET);
    printf(BLEU "Ce texte est en bleu\n" RESET);
    printf(VERT "Ce texte est en vert\n" RESET);
    printf(JAUNE "Ce texte est en jaune\n" RESET);
    printf(MAGENTA "Ce texte est en magenta\n" RESET);
    printf(CYAN "Ce texte est en cyan\n" RESET);

    return 0;
}
*/
