#include "en-tete.h"
#include "fonction.h"
#include "affichage.h"
#include "attaque.h"
#include "IA.h"
#include "tuto.h"
#include "couleurs.h"


int main() {
    srand(time(NULL));
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
    int soutien_count = 0, tank_count = 0, dps_count = 0;
    int choix_nb_joueur;

    char choix_tuto;  
int verif_tuto = -1; 
afficher_tuto();
/*

do {
    printf("Voulez-vous un tuto ? (o/n)\n");
    verif_tuto = scanf(" %c", &choix_tuto);  // Ajoute un espace avant %c pour ignorer les blancs
    if (verif_tuto != 1 || (choix_tuto != 'o' && choix_tuto != 'n')) {
        printf("Entree invalide !\n");
        vider_buffer_scanf(); // à définir si ce n'est pas déjà fait
        verif_tuto = -1;
    }
} while (verif_tuto != 1 || (choix_tuto != 'o' && choix_tuto != 'n'));


    if (choix_tuto == 'o'){
        afficher_tuto();
    }
    else if (choix_tuto == 'n'){
        printf("Bonne game !\n");
    }
*/

    // choix du nombre de joueur
    affichage_initial();
    int v = -1;
    do {
        printf(BLEU"=============================\n");
        printf("          Mode de jeu\n");
        printf("=============================\n\n");
        printf("1 pour PvE, 2 pour PvP\n"RESET);
        v= scanf("%d", &choix_nb_joueur);
        if (v != 1){
            vider_buffer_scanf();
            v = -1;
        }
        if (choix_nb_joueur <= 0 || choix_nb_joueur > 2){
            printf("entree invalide !\n");
            vider_buffer_scanf();
            v = -1;
        }
    } while ((choix_nb_joueur <= 0 || choix_nb_joueur > 2) && v!= 1);

    char *nom_IA[8] = {"Wall-E", "Atlas", "Sentinelle", "Fonctionnaire", "Paperclip", "Pnj", "Nano", "Arcade"};
    
    Equipe equipe1;
    Equipe equipe2;

    int verif;
    equipe1.nom = malloc(sizeof(char) * 20);
    if (equipe1.nom == NULL) {
        printf(ROUGE_FONCE"erreur allocation de memoire\n"RESET);
    }
    equipe2.nom = malloc(sizeof(char) * 20);
    if (equipe2.nom == NULL) {
        printf(ROUGE_FONCE"erreur allocation de memoire\n"RESET);
    }

    if (choix_nb_joueur == 2) {
        do {
            printf("Saisir un nom du joueur 1 (20 caracteres maximum , sinon votre nom sera tronqué) :\n");
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
            printf("Saisir un nom du joueur 2 : (20 caracteres maximum , sinon votre nom sera tronqué)\n");
            
            verif = scanf("%20s", equipe2.nom);
        
            if (verif != 1) {
                printf("Entrée invalide, réessayez.\n");
                verif = -1;
            }
        
            // Dans tous les cas, on vide le buffer
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
        
            // Dans tous les cas, on vide le buffer
            vider_buffer_scanf();
        
        } while (verif != 1);
        
        equipe2.nom = *(nom_IA + rand() % 8);
        if (equipe2.nom == NULL){
            printf(ROUGE_FONCE"erreur lors de l'allocation de la memoire pour le nom de l'IA\n"RESET);
            exit(0);
        }
    }

    // Classement des champions par classe
    qsort(tableau_champion, Nb_champion, sizeof(Champion), comparer_par_classe);

    Champion temp[Nb_champion];
    classe_champion(tableau_champion, champion_soutien, champion_tank, champion_dps, &soutien_count, &tank_count, &dps_count, temp);
    // Affichage des champions par classe
    afficher_champion_init(champion_soutien, champion_tank, champion_dps, soutien_count, tank_count, dps_count);

    printf("Fin de l'initialisation des personnages\n");

    choix_des_champion(temp, &equipe1, &equipe2, choix_nb_joueur, tableau_champion_cachee);

    int index = 0;

    
    // Trier par vitesse
    trier_par_vitesse(ordre_attaque_ind,&equipe1,&equipe2);
    

    // Main game loop
    int finJeu = 0;
    separation_des_partie();
    for (int i = 0; i < Nb_tour && finJeu != 1; i++) {
        printf("tour %d : \n", i + 1);

        for (int k = 0; k < Nb_champion_par_equipe * 2; k++) {
            afficher_equipes_cote_a_cote(equipe1,equipe2);
            Champion *champion_intermediaire = ordre_attaque_ind+k; // Récupérer directement le pointeur
            if (!champion_intermediaire) {
                printf(ROUGE_FONCE"Erreur lors de l'allocation de la mémoire\n"RESET);
                exit(0);
            }

            // Vérifier si le champion est KO (PV <= 0)
            if (champion_intermediaire->stat.pv_courant <= 0) {
                printf("Le champion %s est KO et ne peut pas jouer ce tour.\n", champion_intermediaire->nom);
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
                    printf("Joueur 1 joue\n");
                    saisie_utilisateur(champion_intermediaire, &equipe2, &equipe1);
                }
                if (equipe == 2) {
                    printf("Joueur 2 joue\n");
                    saisie_utilisateur(champion_intermediaire, &equipe1, &equipe2);
                }
            }

            if (choix_nb_joueur == 1) { // Mode PvE
                if (equipe == 1) {
                    printf("Joueur 1 joue\n");
                    saisie_utilisateur(champion_intermediaire, &equipe2, &equipe1);
                }
                if (equipe == 2) {
                    printf("IA joue\n");
                    ia_principale(&equipe2, &equipe1, difficulte);
                }
            }
            for (int i = 0;i<Nb_champion_par_equipe*2;i++){
                if ((ordre_attaque_ind+i)->equipe == 1){
                    copie_champion(&equipe1.perso[(ordre_attaque_ind+i)->index],ordre_attaque_ind+i);
                }
                if ((ordre_attaque_ind+i)->equipe == 2){
                    copie_champion(&equipe2.perso[(ordre_attaque_ind+i)->index],ordre_attaque_ind+i);
                }      
            }
            trier_par_vitesse(ordre_attaque_ind,&equipe1,&equipe2);
            int flag = 0;
            for (int i=0;i<Nb_champion_par_equipe;i++){
                if (equipe1.perso[i].stat.pv_courant <= 0){
                    flag++;
                }
            }
            if (flag >=3){
                printf("tous les champions de l'equipe 1 sont mort ! L'equipe 2 gagne !\n");
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
                printf("tous les champions de l'equipe 2 sont mort ! L'equipe 1 gagne !\n");
                finJeu = 1;
                break;
            }
            pause_ms(time_sleep);
        }

        printf(GRIS"Réparation des décors\n"RESET);
        for (int i = 0; i < 5; i++) {
            pause_ms(time_sleep);
            printf(".");
        }
        separation_des_partie();
        
        
    }

    //note();
    printf(GRIS"libération de la mémoire\n"RESET);

    // Libération des champs alloués dynamiquement dans les tableaux de Champion
    for (int i = 0; i < Nb_champion; i++) {
        free(tableau_champion[i].nom);
        free(tableau_champion[i].classe);
        free(tableau_champion[i].attaque_spe);
        free(tableau_champion[i].effet_spe);
    }

    // Libération des tableaux de Champion
    free(champion_soutien);
    free(champion_tank);
    free(champion_dps);
    free(tableau_champion);
    free(ordre_attaque);
    free(ordre_attaque_ind);

    // Libération des noms des équipes
    free(equipe1.nom);
    free(equipe2.nom);


    printf(GRIS"\nCode fini\n"RESET);
    return 0;
}
