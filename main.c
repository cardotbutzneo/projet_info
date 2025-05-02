#include "en-tete.h"
#include "fonction.h"
#include "affichage.h"
#include "attaque.h"
#include "IA.h"

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
    Champion *ordre_attaque = malloc(sizeof(Champion) * Nb_champion_par_equipe * 2);
    Champion *ordre_attaque_ind = malloc(sizeof(Champion) * Nb_champion_par_equipe * 2);

    if (!tableau_champion || !champion_soutien || !champion_tank || !champion_dps || !ordre_attaque || !ordre_attaque_ind) {
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }

    char *tableau_nom_personnage[Nb_champion] = {"amongus.txt", "captainamerica.txt", "donkeykong.txt", "drtenma.txt", "gandalf.txt", "golemdefer.txt", "invader.txt", "itachi.txt", "jackfrost.txt", "jay.txt", "johnnyhallyday.txt", "netero.txt", "nox.txt", "picsou.txt", "pierrechartier.txt", "shrek.txt", "tux.txt", "zelda.txt"};

    char *personnage_cachee[Nb_champion_cachee] = {"adchayan.txt", "garrigusprimus.txt", "grossinge.txt"};
    int difficulte;

    // Chargement des fichiers
    for (int i = 0; i < Nb_champion; i++) {
        snprintf(chemin_acces, sizeof(chemin_acces), "%s%s", base_chemin, tableau_nom_personnage[i]);
        fichier = fopen(chemin_acces, "r+");
        if (fichier == NULL) {
            printf("Erreur d'ouverture du fichier : %s\n", chemin_acces);
            exit(0);
        }
        initialisation_champion(fichier, tableau_champion + i);
        fclose(fichier);
    }

    int soutien_count = 0, tank_count = 0, dps_count = 0;
    int choix_nb_joueur;

    // choix du nombre de joueur
    affichage_initial();

    do {
        printf("Combien de joueur : \n");
        printf("1 pour PvE, 2 pour PvP\n");
        scanf("%d", &choix_nb_joueur);
    } while (choix_nb_joueur <= 0 || choix_nb_joueur > 2);

    char *nom_IA[8] = {"Wall-E", "Atlas", "Sentinelle", "Fonctionnaire", "Paperclip", "Pnj", "Nano", "Arcade"};
    Equipe equipe1;
    Equipe equipe2;

    int verif;
    equipe1.nom = malloc(sizeof(char) * 20);
    if (equipe1.nom == NULL) {
        printf("erreur allocation de memoire\n");
    }
    equipe2.nom = malloc(sizeof(char) * 20);
    if (equipe2.nom == NULL) {
        printf("erreur allocation de memoire\n");
    }

    if (choix_nb_joueur == 2) {
        do{
            printf("saisir un nom du joueur 1 : \n");
            verif = scanf("%s", equipe1.nom);
        }while(verif != 1);
        printf("saisir un nom du joueur 2 : \n");
        scanf("%s", equipe2.nom);
    }

    if (choix_nb_joueur == 1) {
        difficulte = 0; // noob par défault
        printf("Vous jouez contre une IA :\n");
        printf("saisir le nom du joueur 1 :\n");
        scanf("%s", equipe1.nom);
        equipe2.nom = *(nom_IA + rand() % 8);
    }

    // Classement des champions par classe
    qsort(tableau_champion, Nb_champion, sizeof(Champion), comparer_par_classe);

    Champion temp[Nb_champion];
    classe_champion(tableau_champion, champion_soutien, champion_tank, champion_dps, &soutien_count, &tank_count, &dps_count, temp);
    // Affichage des champions par classe
    afficher_champion_init(champion_soutien, champion_tank, champion_dps, soutien_count, tank_count, dps_count);

    printf("Fin de l'initialisation des personnages\n");

    choix_des_champion(temp, &equipe1, &equipe2, choix_nb_joueur);

    trier_par_vitesse(ordre_attaque_ind, &equipe1, &equipe2);

    // Initialize ordre_attaque_ind
    afficher_equipe(equipe1, equipe2);

    // Main game loop
    int finJeu = 0;
    for (int i = 0; i < Nb_tour || finJeu == 1; i++) {
        printf("tour %d : \n", i + 1);
        printf("afficher les champions\n");

        for (int k = 0; k < Nb_champion_par_equipe * 2; k++) {
            afficher_equipes_cote_a_cote(equipe1, equipe2);
            Champion *champion_intermediaire = (ordre_attaque_ind + k); // Récupérer directement le pointeur

            // Utiliser la fonction recuperer_equipe avec le pointeur
            int equipe = champion_intermediaire->equipe;
            if (equipe != 1 && equipe != 2) {
                printf("Error: le champion n appartient a aucune equipe\n");
                exit(1);
            }

            if (choix_nb_joueur == 2) {
                if (equipe == 1) {
                    printf("joueur 1 joue\n");
                    saisie_utilisateur(champion_intermediaire, &equipe2);
                }
                if (equipe == 2) {
                    printf("joueur 2 joue\n");
                    saisie_utilisateur(champion_intermediaire, &equipe1);
                }
            }

            if (choix_nb_joueur == 1) {
                if (equipe == 1) {
                    printf("joueur 1 joue\n");
                    saisie_utilisateur(champion_intermediaire, &equipe2);
                }
                if (equipe == 2) {
                    printf("IA joue\n");
                    ia_principale(&equipe2, &equipe1, difficulte);
                }
            }
            afficher_equipe(equipe1,equipe2);
        }
        printf("reparation des decord...\n");
        for (int i=0;i<5;i++){
            Sleep(1000);
        }
        separation_des_partie();
    }

    // Libération de la mémoire
    free(champion_soutien);
    free(champion_tank);
    free(champion_dps);
    free(tableau_champion);
    free(ordre_attaque);
    free(ordre_attaque_ind);
    free(equipe1.nom);
    free(equipe2.nom);
    free(equipe1.objet);
    free(equipe2.objet);
    printf("\nCode fini\n");
    return 0;
}

