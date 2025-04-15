#include "en-tete.h"

void sauter_ligne(FILE *fichier){
    // permet de sauter une ligne dans le fichier
    char buffer[100];
    fgets(buffer, sizeof(buffer), fichier);
}

void afficher_personnage(Champion champion){
    printf("pv_max : %f\n", champion.pv_max);
    printf("pv_courrant : %f\n", champion.stat.pv_courant);
    printf("attaque : %f\n", champion.stat.attaque);
    printf("attaque_spe : %f\n", champion.attaque_spe);
}

