#include "en-tete.h"




int initialisation_champion(FILE *fichier, Champion champion){

    // lecture des statistiques du champion

    int valeur;

    fscanf(fichier,"%d",&valeur);
    champion.stat.pv_courant = valeur;
    
    printf("pv : %f\n",champion.stat.pv_courant); // on affiche les stats pour le degub
}

