#include "en-tete.h"




int main(){

    srand(time(NULL));
    FILE *fichier = NULL;
    char *base_chemin = "personnage/";
    char chemin_acces[100];

    // création d'un tableau de tous les champions
    Champion *tableau_champion = malloc(sizeof(Champion) * 19);
    char *tableau_nom_personnage[19] = {"adchayan.txt","amongus.txt","captainamerica.txt","drtenma.txt","gandalf.txt","garrigusprimus.txt","golemdefer.txt","grossinge.txt","invader.txt","itachi.txt","jackfrost.txt","jay.txt","johnnyhallyday.txt","netero.txt","nox.txt","picsou.txt","pierrechartier.txt","shrek.txt","tux.txt"};


    for (int i = 0; i < 19; i++) {
        snprintf(chemin_acces, sizeof(chemin_acces), "%s%s", base_chemin,tableau_nom_personnage[i]) ; // actuellement je sais pas ce que fait cette ligne (IA à 100%)

        fichier = fopen(chemin_acces, "r+");

        if (fichier == NULL) {
            printf("Erreur d'ouverture du fichier\n");
            //return 1;
            continue;
        }

        initialisation_champion(fichier, tableau_champion + i);

        fclose(fichier);
    }

    printf("fin de l'initialisation des personnages\n");



    // affichage de l'initialisation
    affichage_initial(); // passer cette ligne en commentaire pour ne pas afficher le chargement du jeu

    for (int i = 0; i < 19; i++) {
        printf("\n");
    }

    // affichage des stats

    for (int i=0;i<19;i++){
        afficher_personnage(tableau_champion+i);
        printf("\n");
    }

    printf("code fini");
    return 0;
}