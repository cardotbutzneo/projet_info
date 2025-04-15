#include "en-tete.h"

// affichges des champions

void sauter_ligne(FILE *fichier) {
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fichier)) {
        if (strchr(buffer, '\n') != NULL) {
            break; // Ligne complète lue
        }
    }
}

void afficher_personnage(Champion *champion){
    printf("nom : %s\n",champion->nom);
    printf("Classe : %s\n", champion->classe);
    printf("pv_max : %f\n", champion->pv_max);
    printf("pv_courrant : %f\n", champion->stat.pv_courant);
    printf("attaque : %f\n", champion->stat.attaque);
    printf("defense : %f\n", champion->stat.defense);
    printf("agilite : %f\n", champion->stat.agilite);
    printf("vitesse : %f\n", champion->stat.vitesse);
}

// affichage global

void affichage_initial(){
    int buffer = 10;

    int chargement = 0;
    printf("Chargement du jeu...\n");

    int val_systemeOS;

    if (_WIN32 ){
        val_systemeOS = 1000;
    }

    else {
        printf("Nous avons détecter que votre appareil n'est pas sous Windows, de ce fait les temps d'attente pourront etre long.\n");
        val_systemeOS = 1;
    }


    for (int i=0;i<buffer;i++){
        chargement = rand()%10 * val_systemeOS;
        Sleep(chargement);
        printf("---");
    }

    printf("\nchargement fini\n");
    printf("Bienvenue dans MultiverSeus\n");

}