//bon encodage pour vscode windows
#ifdef _WIN32
#include <windows.h>
#endif

void configurer_encodage() {
    #ifdef _WIN32
    // Configuration pour Windows
    SetConsoleOutputCP(CP_UTF8);
    #else
    ///pas besoin sur linux
    #endif
}


//include 
#include "en-tete.h"
#include "fonction.h"
#include "affichage.h"
#include "attaque.h"
#include "IA.h"
#include "tuto.h"
#include "couleurs.h"
#include "synergie.h"

//fonction principale


int main() {
    configurer_encodage();


    srand(time(NULL));

    // Initialisation des variables pour les fichiers
    FILE *fichier = NULL;
    char *base_chemin = "personnage/";
    char chemin_acces[100];

    // Initialisation des tableaux
    Champion *tableau_champion = malloc(sizeof(Champion) * Nb_champion);
    Champion *tableau_champion_cachee = malloc(sizeof(Champion)*Nb_champion_cachee);
    Champion *champion_soutien = malloc(sizeof(Champion) * 6);
    Champion *champion_tank = malloc(sizeof(Champion) * 6);
    Champion *champion_dps = malloc(sizeof(Champion) * 6);
    Champion *ordre_attaque = malloc(sizeof(Champion) * Nb_champion_par_equipe * 2);
    Champion *ordre_attaque_ind = malloc(sizeof(Champion) * Nb_champion_par_equipe * 2);

    if (!tableau_champion || !champion_soutien || !champion_tank || !champion_dps || !ordre_attaque || !ordre_attaque_ind || !tableau_champion_cachee) {
        printf(ROUGE_FONCE "Erreur d'allocation mémoire\n" RESET);
        exit(0);
    }

    char *tableau_nom_personnage[Nb_champion] = {"amongus.txt", "captainamerica.txt", "donkeykong.txt", "drtenma.txt", "gandalf.txt", "golemdefer.txt", "invader.txt", "itachi.txt", "jackfrost.txt", "jay.txt", "johnnyhallyday.txt", "netero.txt", "nox.txt", "picsou.txt", "pierrechartier.txt", "shrek.txt", "tux.txt", "zelda.txt"};

    char *personnage_cachee[Nb_champion_cachee] = {"adchayan.txt", "garrigusprimus.txt", "grossinge.txt"};
    int difficulte;

    // Chargement des fichiers
    for (int i = 0; i < Nb_champion; i++) {
        snprintf(chemin_acces, sizeof(chemin_acces), "%s%s", base_chemin, tableau_nom_personnage[i]);
        fichier = fopen(chemin_acces, "r+");
        if (fichier == NULL) {
            printf(ROUGE_FONCE "Erreur d'ouverture du fichier : %s\n" RESET, chemin_acces);
            exit(0);
        }
        initialisation_champion(fichier, tableau_champion + i);
        fclose(fichier);
        
    }

    for (int i=0;i<Nb_champion_cachee;i++){
        snprintf(chemin_acces, sizeof(chemin_acces), "%s%s",base_chemin, personnage_cachee[i]);
        fichier = fopen(chemin_acces, "r+");
        if (fichier == NULL){
            printf(ROUGE_FONCE "Erreur d'ouverture du fichier : %s\n" RESET, chemin_acces);
            exit(0);
        }
        initialisation_champion(fichier,tableau_champion_cachee+i);
        fclose(fichier);
    }

    // Initialisation des compteurs de champions par classe
    int soutien_count = 0, tank_count = 0, dps_count = 0;
    int choix_nb_joueur;

    char choix_tuto;  
    int verif_tuto = -1; 
    afficher_tuto();

    // choix du nombre de joueur
    affichage_initial(); // affichage de l'écran d'accueil
    int v = -1;
    do {
        printf(BLEU"=========================================================\n"RESET);
        printf(BLEU"                     Mode de jeu\n"RESET);
        printf(BLEU"=========================================================\n"RESET);
        printf("    1 pour PvE, 2 pour PvP\n"RESET);
        v= scanf("%d", &choix_nb_joueur);
        if (v != 1){
            vider_buffer_scanf();
            v = -1;
        }
        if (choix_nb_joueur <= 0 || choix_nb_joueur > 2){
            printf(ROUGE"entrée invalide !\n"RESET);
            vider_buffer_scanf();
            v = -1;
        }
    } while ((choix_nb_joueur <= 0 || choix_nb_joueur > 2) && v!= 1);

    char *nom_IA[8] = {"Wall-E", "Atlas", "Sentinelle", "Fonctionnaire", "Paperclip", "Pnj", "Nano", "Arcade"};
    
    // Initialisation des équipes
    // Allocation de mémoire pour les noms des équipes
    Equipe equipe1;
    Equipe equipe2;

    equipe1.difficulte = -1;
    equipe2.difficulte = -1;

    int verif;
    equipe1.nom = malloc(sizeof(char) * 20);
    if (equipe1.nom == NULL) {
        printf(ROUGE_FONCE"erreur allocation de mémoire\n"RESET);
    }
    equipe2.nom = malloc(sizeof(char) * 20);
    if (equipe2.nom == NULL) {
        printf(ROUGE_FONCE"erreur allocation de mémoire\n"RESET);
    }

    if (choix_nb_joueur == 2) {
        do {
            printf(BLEU"Saisir un nom du joueur 1 (20 caracteres maximum , sinon votre nom sera tronqué) :\n"RESET);
            verif = scanf("%20s", equipe1.nom);
        
            if (verif != 1) {
                printf(ROUGE"Entrée invalide, réessayez.\n"RESET);
                verif = -1;
            }
        
            // Dans tous les cas, on vide le buffer
            vider_buffer_scanf();
        
        } while (verif != 1);
        
        verif = -1;
        do{
            printf(BLEU"Saisir un nom du joueur 2 : (20 caracteres maximum , sinon votre nom sera tronqué)\n"RESET);
            
            verif = scanf("%20s", equipe2.nom);
        
            if (verif != 1) {
                printf(ROUGE"Entrée invalide, réessayez.\n"RESET);
                verif = -1;
            }
        
            vider_buffer_scanf();
        
        } while (verif != 1);
    }

    if (choix_nb_joueur == 1) {
        difficulte = 0; // noob par défault
        printf("Vous jouez contre une IA :\n");
        verif = -1;
        do {
            printf("Saisir un nom du joueur 1 (20 caracteres maximum, sinon votre nom sera tronqué) :\n");
            verif = scanf("%20s", equipe1.nom);
        
            if (verif != 1) {
                printf(ROUGE"Entrée invalide, réessayez.\n"RESET);
                verif = -1;
            }
            vider_buffer_scanf();
        
        } while (verif != 1);

        do{
            printf("Choisir la difficulté de l'IA (0 = noob, 1 = facile, 2 = difficile) :\n");
            verif = scanf("%d", &difficulte);
        
            if (verif != 1) {
                printf(ROUGE"Entrée invalide, réessayez.\n"RESET);
                verif = -1;
            }
        
            vider_buffer_scanf();
        }while (verif != 1 || difficulte < 0 || difficulte > 2);
        if (difficulte == 0){
            printf("Vous avez choisi la difficulté noob, l'IA fera uniquement des attaques simples !\n");
            pause_ms(time_sleep);
        }
        else if (difficulte == 1){
            printf("Vous avez choisi la difficulté facile, l'IA fera des attaques simples...!\n");
            pause_ms(time_sleep);
            printf("...et des attaques spéciales une fois sur 10 !!\n");
            pause_ms(time_sleep);
        }
        else if (difficulte == 2){
            printf("Vous avez choisi la difficulté difficile <:O !!!!\n");
            pause_ms(time_sleep);
            printf("L'IA fera des attaques spéciales chaque fois qu'elle le peut !!!\n");
            pause_ms(time_sleep);
        }
        equipe2.difficulte = difficulte;
        equipe2.nom = *(nom_IA + rand() % 8);
        if (equipe2.nom == NULL){
            printf(ROUGE_FONCE"erreur lors de l'allocation de la mémoire    pour le nom de l'IA\n"RESET);
            exit(0);
        }
    }

    separation_des_partie();
    // Classement des champions par classe
    //qsort(tableau_champion, Nb_champion, sizeof(Champion), comparer_par_classe);

    Champion temp[Nb_champion];
    classe_champion(tableau_champion, champion_soutien, champion_tank, champion_dps, &soutien_count, &tank_count, &dps_count, temp);
    // Affichage des champions par classe
    afficher_champion_init(champion_soutien, champion_tank, champion_dps, soutien_count, tank_count, dps_count);

    printf("\nFin de l'initialisation des personnages\n");
    
    //choix des champions
    choix_des_champion(temp, &equipe1, &equipe2, choix_nb_joueur, tableau_champion_cachee);

    //synergies
    pause_ms(time_sleep);
    verifie_classes(&equipe1);
    pause_ms(time_sleep);
    verifie_classes(&equipe2);

    int index = 0;

    
    // Trier par vitesse
    trier_par_vitesse(ordre_attaque_ind,&equipe1,&equipe2);
    

    // boucle de jeu
    int finJeu = 0;
    separation_des_partie();
    for (int i = 0; i < Nb_tour && finJeu != 1; i++) {
        printf(BLEU"=========================================================\n");
        printf("                        Tour %d\n", i + 1);
        printf("=========================================================\n\n"RESET);

        for (int k = 0; k < Nb_champion_par_equipe * 2; k++) {
            afficher_equipes_cote_a_cote(equipe1,equipe2);
            Champion *champion_intermediaire = ordre_attaque_ind+k; 
            if (!champion_intermediaire) {
                printf(ROUGE_FONCE"Erreur lors de l'allocation de la mémoire\n"RESET);
                exit(0);
            }

            // Vérifier si le champion est KO (PV <= 0)
            if (champion_intermediaire->stat.pv_courant <= 0) {
                printf(GRIS"Le champion %s est KO et ne peut pas jouer ce tour.\n"RESET, champion_intermediaire->nom);
                continue; // Passer au prochain personnage
            }

            // Identifier l'équipe du personnage
            int equipe = champion_intermediaire->equipe;
            if (equipe != 1 && equipe != 2) {
                printf(ROUGE"Erreur : le champion n'appartient à aucune équipe\n"RESET);
                exit(1);
            }

            // Gestion des actions en fonction du nombre de joueurs
            if (choix_nb_joueur == 2) { // Mode PvP
                if (equipe == 1) {
                    printf("\n\nJoueur 1 joue\n");
                    saisie_utilisateur(champion_intermediaire, &equipe2, &equipe1);
                }
                if (equipe == 2) {
                    printf("\n\nJoueur 2 joue\n");
                    saisie_utilisateur(champion_intermediaire, &equipe1, &equipe2);
                }
            }

            if (choix_nb_joueur == 1) { // Mode PvE
                if (equipe == 1) {
                    printf(BLEU_CLAIR"\n\nJoueur 1 joue\n"RESET);
                    saisie_utilisateur(champion_intermediaire, &equipe2, &equipe1);
                }
                if (equipe == 2) {
                    printf(BLEU_CLAIR);
                    printf("\n\nIA joue\n");
                    printf(RESET);
                    ia_principale(champion_intermediaire,&equipe2, &equipe1, difficulte);
                }
            }
            
            //copie du champion pour la sauvegarde des statistiques
            for (int i = 0;i<Nb_champion_par_equipe*2;i++){
                if ((ordre_attaque_ind+i)->equipe == 1){
                    copie_champion(&equipe1.perso[(ordre_attaque_ind+i)->index],ordre_attaque_ind+i);
                }
                if ((ordre_attaque_ind+i)->equipe == 2){
                    copie_champion(&equipe2.perso[(ordre_attaque_ind+i)->index],ordre_attaque_ind+i);
                }      
            }
            //verification de la fin du jeu
            // Vérifier si tous les champions d'une équipe sont KO
            int flag = 0;
            for (int i=0;i<Nb_champion_par_equipe;i++){
                if (equipe1.perso[i].stat.pv_courant <= 0){
                    flag++;
                }
            }
            if (flag >=3){
                pause_ms(time_sleep*2);
                printf("Tous les champions de l'équipe 1 sont morts ! L'équipe 2 gagne !\n");
                finJeu = 1;
                break;
            }
            flag = 0;
            for (int i=0;i<Nb_champion_par_equipe;i++){
                if (equipe2.perso[i].stat.pv_courant <= 0){
                    flag++;
                }
            }
            if (flag >=3){
                pause_ms(time_sleep*2);
                printf("Tous les champions de l'équipe 2 sont morts ! L'équipe 1 gagne !\n");
                finJeu = 1;
                break;
            }
            pause_ms(time_sleep);
            trier_par_vitesse(ordre_attaque_ind,&equipe1,&equipe2);
        }
        
        // Augmenter la jauge de chaque champion
        /*
        for (int i = 0; i < Nb_champion_par_equipe; i++) {
            // Équipe 1
            if (equipe1.perso[i].stat.pv_courant > 0) { // Vérifie que le champion n'est pas KO
                if (equipe1.perso[i].stat.jauge_actuelle <= equipe1.perso[i].stat.jauge_max) {
                    equipe1.perso[i].stat.jauge_actuelle += 1;
                }
            }

            // Équipe 2
            if (equipe2.perso[i].stat.pv_courant > 0) { // Vérifie que le champion n'est pas KO
                if (equipe2.perso[i].stat.jauge_actuelle <= equipe2.perso[i].stat.jauge_max) {
                    equipe2.perso[i].stat.jauge_actuelle += 1;
                }
            }
            
        }
        */
        printf(GRIS"Réparation des décors\n"RESET);
        for (int i = 0; i < 5; i++) {
            pause_ms(time_sleep);
            printf(".");
        }
        separation_des_partie();
        
        
    }

    //note();
    printf(GRIS"libération de la mémoire\n"RESET);

    // Libération des champs dynamiques dans les tableaux de Champion
    for (int i = 0; i < Nb_champion; i++) {
        free_champion(&tableau_champion[i]); // Utilise free_champion pour libérer chaque Champion
    }

    for (int i = 0; i < Nb_champion_cachee; i++) {
        free_champion(&tableau_champion_cachee[i]); // Libère les champions cachés
    }

    for (int i = 0; i < 6; i++) {
        free_champion(&champion_soutien[i]); // Libère les champions de soutien
        free_champion(&champion_tank[i]);    // Libère les champions tank
        free_champion(&champion_dps[i]);     // Libère les champions DPS
    }

    printf(GRIS"\nLibération des tableaux de champions\n"RESET);
    // Libération des tableaux de Champion
    free(champion_soutien);
    free(champion_tank);
    free(champion_dps);
    free(tableau_champion);
    free(tableau_champion_cachee);
    free(ordre_attaque);
    free(ordre_attaque_ind);

    // Libération des noms des équipes
    
    free(equipe1.nom);
    if (choix_nb_joueur == 2){ // pas incroyable je sais sinon seg fault
        free(equipe2.nom);
    }

    printf(GRIS"\nMémoire libérée avec succès\n"RESET);

    printf(GRIS"\nCode fini\n"RESET);

    note();
    
    return 0;
}
