// couleurs.h

#ifndef COULEURS_H
#define COULEURS_H

// Codes de couleur ANSI
#define RESET   "\033[0m"
#define ROUGE   "\033[1;31m" //tout ce qui est dégâts et effets d'attaque, personnages DPS, négatif etc
#define BLEU    "\033[1;34m" //titres, tanks
#define VERT    "\033[1;32m" //soutien, soins, effets positifs etc
#define JAUNE   "\033[1;33m" //pour les avertissements, les messages d'erreur
#define MAGENTA "\033[1;35m" 
#define CYAN    "\033[1;36m" 

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
