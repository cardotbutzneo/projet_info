#include "en-tete.h"
#define Nb_champion 16
#define Nb_champion_cachee 3
int main() {
    srand(time(NULL));
    FILE *fichier = NULL;
    char *base_chemin = "personnage/";
    char chemin_acces[100];

    // Initialisation des tableaux
    Champion *tableau_champion = malloc(sizeof(Champion) * Nb_champion);
    Champion *champion_soutien = malloc(sizeof(Champion) * 6);
    Champion *champion_tank = malloc(sizeof(Champion) * 6);
    Champion *champion_dps = malloc(sizeof(Champion) * 6);

    if (!tableau_champion || !champion_soutien || !champion_tank || !champion_dps) {
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }

    char *tableau_nom_personnage[Nb_champion] = {"amongus.txt", "captainamerica.txt", "drtenma.txt", "gandalf.txt", "golemdefer.txt", "invader.txt", "itachi.txt", "jackfrost.txt", "jay.txt", "johnnyhallyday.txt", "netero.txt", "nox.txt", "picsou.txt", "pierrechartier.txt", "shrek.txt", "tux.txt","zelda.txt"};

    char *personnage_cachee[Nb_champion_cachee] = {"adchayan.txt","garrigusprimus.txt","grossinge.txt"};

    // Chargement des fichiers
    for (int i = 0; i < Nb_champion; i++) {
        snprintf(chemin_acces, sizeof(chemin_acces), "%s%s", base_chemin, tableau_nom_personnage[i]);
        fichier = fopen(chemin_acces, "r+");
        if (fichier == NULL) {
            printf("Erreur d'ouverture du fichier : %s\n", chemin_acces);
            continue;
        }
        initialisation_champion(fichier, tableau_champion + i);
        fclose(fichier);
    }

    printf("Fin de l'initialisation des personnages\n");
    affichage_initial();

    // Classement des champions
    int soutien_count = 0, tank_count = 0, dps_count = 0;
    classe_champion(tableau_champion,champion_soutien,champion_tank,champion_dps, &soutien_count, &tank_count, &dps_count);

    // Affichage des champions par classe
    printf("Les champions de classe soutien sont : \n");
    for (int i = 0; i < soutien_count; i++) {
        printf("%s\n", (champion_soutien + i)->nom);
    }
    printf("\n");
    printf("Les champions de classe tank sont : \n");
    for (int i = 0; i < tank_count; i++) {
        printf("%s\n", (champion_tank + i)->nom);
    }
    printf("\n");
    printf("Les champions de classe dps sont : \n");
    for (int i = 0; i < dps_count; i++) {
        printf("%s\n", (champion_dps + i)->nom);
    }

    // Libération de la mémoire
    free(champion_soutien);
    free(champion_tank);
    free(champion_dps);
    free(tableau_champion);

    printf("Code fini\n");
    return 0;
}