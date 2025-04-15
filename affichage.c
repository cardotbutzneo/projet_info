#include "en-tete.h"

void sauter_ligne(FILE *fichier){
    // permet de sauter une ligne dans le fichier
    char buffer[100];
    fgets(buffer, sizeof(buffer), fichier);
}

void afficher_personnage(Champion *champion){
    printf("%s",champion->nom);
    printf("Classe : %s\n", champion->classe);
    printf("pv_max : %f\n", champion->pv_max);
    printf("pv_courrant : %f\n", champion->stat.pv_courant);
    printf("attaque : %f\n", champion->stat.attaque);
    printf("defense : %f\n", champion->stat.defense);
    printf("agilite : %f\n", champion->stat.agilite);
    printf("vitesse : %f\n", champion->stat.vitesse);
}

