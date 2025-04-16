#include "en-tete.h"


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

    char *tableau_nom_personnage[Nb_champion] = {"amongus.txt", "captainamerica.txt", "drtenma.txt", "gandalf.txt", "golemdefer.txt","inconnu.txt", "invader.txt", "itachi.txt", "jackfrost.txt", "jay.txt", "johnnyhallyday.txt", "netero.txt", "nox.txt", "picsou.txt", "pierrechartier.txt", "shrek.txt", "tux.txt","zelda.txt"};

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

    int choix_nb_joueur;
    
    do {
        printf("Combien de joueur : \n");
        printf("1 pour PvE, 2 pour PvP");
        scanf("%d",&choix_nb_joueur);
    }while(choix_nb_joueur <=0 ||choix_nb_joueur > 2);
    
    char *nom_equipe1 = malloc(sizeof(char)*50);
    char *nom_equipe2 = malloc(sizeof(char)*50);
    Champion equipe1[3];
    Champion equipe2[3];
    

    
    


    printf("Fin de l'initialisation des personnages\n");
    affichage_initial();

    // Classement des champions
    int soutien_count = 0, tank_count = 0, dps_count = 0;
    classe_champion(tableau_champion,champion_soutien,champion_tank,champion_dps, &soutien_count, &tank_count, &dps_count);

    // Affichage des champions par classe
    int index = 1;
    printf("Les champions de classe soutien sont : \n");
    for (int i = 0; i < soutien_count; i++) {
        printf("%d : %s\n",index, (champion_soutien + i)->nom);
        index++;
    }
    printf("\n");
    Sleep(2000);
    printf("Les champions de classe tank sont : \n");
    for (int i = 0; i < tank_count; i++) {
        printf("%d : %s\n",index, (champion_tank + i)->nom);
        index++;
    }
    printf("\n");
    Sleep(2000);
    printf("Les champions de classe dps sont : \n");
    for (int i = 0; i < dps_count; i++) {
        printf("%d : %s\n",index, (champion_dps + i)->nom);
        index++;
    }

    

    if (choix_nb_joueur == 2){
        int index = 1;
        printf("saisir un nom du joueur 1: \n");
        scanf("%s",nom_equipe1);
        printf("saisir un nom du joueur 2: \n");
        scanf("%s",nom_equipe2);

        printf("Equipe 1 choisissez vos champion : \n");
        int temp;
        for (int i=0;i<3;i++){
            temp = -1;
            do {
                printf("champion %d : ",index);
                scanf("%d",&temp);
            }while(temp > 18 || temp <=0);
            *(equipe1 + i) = *(tableau_champion + (temp - 1));
        }
        printf("Equipe 2 choisissez vos champion : \n");
        for (int i=0;i<3;i++){
            temp = -1;
            do {
                printf("champion %d : ",index);
                scanf("%d",&temp);
            }while(temp > 18 || temp <=0);
            *(equipe2 + i) = *(tableau_champion + (temp - 1));
        }
            
    }

    afficher_equipes_cote_a_cote(equipe1,equipe2,nom_equipe1,nom_equipe2);

    // Libération de la mémoire
    free(champion_soutien);
    free(champion_tank);
    free(champion_dps);
    free(tableau_champion);

    printf("\nCode fini\n");
    return 0;
}