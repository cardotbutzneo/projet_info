#include "en-tete.h"


void degat(Champion *champion1, Champion *champion2){ 

    // calcul les degats des champion et modifie les pv apres attaque du champion attaqué

    float degat = champion2->attaque;
    float vie = champion1->pv_courrant - degat;
    champion1->pv_courrant = vie;
}

int initialisation_champion(FILE *fichier, Champion champion){

    // lecture des statistiques du champion

    int valeur;

    fscanf(fichier,"%d",&valeur);
    champion.pv_courrant = valeur;
    
    printf("pv : %f\n",champion.pv_courrant); // on affiche les stats pour le degub
}

void sauter_ligne(FILE *fichier){
    // permet de sauter une ligne dans le fichier
    char buffer[100];
    fgets(buffer, sizeof(buffer), fichier);
}

void afficher_personnage(Champion champion){
    printf("pv_courrant : %f\n", champion.pv_courrant);
    printf("pv_max : %f\n", champion.pv_max);
    printf("attaque : %f\n", champion.attaque);
    printf("attaque_spe : %f\n", champion.attaque_spe);
    
}