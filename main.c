#include "en-tete.h"

int main() {
    srand(time(NULL));
    FILE *fichier = NULL;
    char *base_chemin = "personnage/";
    char chemin_acces[100];

    // Initialisation des tableaux

    Champion *tableau_champion= malloc(sizeof(Champion) * Nb_champion);
    Champion *champion_soutien = malloc(sizeof(Champion) * 6);
    Champion *champion_tank = malloc(sizeof(Champion) * 6);
    Champion *champion_dps = malloc(sizeof(Champion) * 6);

    if (!tableau_champion || !champion_soutien || !champion_tank || !champion_dps) {
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }

    char *tableau_nom_personnage[Nb_champion] = {"amongus.txt", "captainamerica.txt","donkeykong.txt", "drtenma.txt", "gandalf.txt", "golemdefer.txt", "invader.txt", "itachi.txt", "jackfrost.txt", "jay.txt", "johnnyhallyday.txt", "netero.txt", "nox.txt", "picsou.txt", "pierrechartier.txt", "shrek.txt", "tux.txt","zelda.txt"};

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
    int soutien_count = 0, tank_count = 0, dps_count = 0;
    int choix_nb_joueur;
    
    // choix du nombre de joueur

    affichage_initial();

    do {
        printf("Combien de joueur : \n");
        printf("1 pour PvE, 2 pour PvP\n");
        scanf("%d",&choix_nb_joueur);
    }while(choix_nb_joueur <=0 ||choix_nb_joueur > 2);
    
    char *nom_equipe1 = malloc(sizeof(char)*50);
    char *nom_equipe2 = malloc(sizeof(char)*50);
    char *nom_IA[8] = {"Wall-E","Atlas","Sentinelle","Factionnaire","Paperclip","Pnj","Nano","Arcade"};
    Champion equipe1[Nb_champion_par_equipe];
    Champion equipe2[Nb_champion_par_equipe];
    
    if (choix_nb_joueur == 2){
        printf("saisir un nom du joueur 1 : \n");
        scanf("%s",nom_equipe1);
        printf("saisir un nom du joueur 2 : \n");
        scanf("%s",nom_equipe2);
    }
    
    else if (choix_nb_joueur == 1){
        printf("Vous jouez contre une IA :\n");
        printf("saisir le nom du joueur 1 :\n");
        scanf("%s",nom_equipe1);
    }



    // Classement des champions par classe
    qsort(tableau_champion, Nb_champion, sizeof(Champion), comparer_par_classe);

    Champion temp[Nb_champion];
    classe_champion(tableau_champion, champion_soutien, champion_tank, champion_dps, &soutien_count, &tank_count, &dps_count,temp);


    // Affichage des champions par classe
    afficher_champion_init(champion_soutien, champion_tank, champion_dps, soutien_count, tank_count, dps_count);

    printf("Fin de l'initialisation des personnages\n");

        
        printf("Equipe 1 choisissez vos champions : \n");
        choix_des_champion(temp,equipe1,equipe2,choix_nb_joueur);
        nom_equipe2 = *(nom_IA+rand()%8);
        choix_champion_IA(temp,equipe2);

    

    // affichage des équipe tour par tour

    // corps du jeu
    int finJeu=0;
    for (int i=0;i<Nb_tour|| finJeu==1;i++){
        printf("tour %d : \n",i+1);
        afficher_equipes_cote_a_cote(equipe1,equipe2,nom_equipe1,nom_equipe2);
        // faudrait faire une boucle avec les champions trié par vitesse
        affichage_saisie_utilisateur(equipe1);

        // code de combat


        // fin du code de combat
        Sleep(5000);
        separation_des_partie();
    }
    

    // Libération de la mémoire
    free(champion_soutien);
    free(champion_tank);
    free(champion_dps);
    free(tableau_champion);
    free(nom_equipe1);
    free(nom_equipe2);
    printf("\nCode fini\n");
    return 0;
}
