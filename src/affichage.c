#include "en-tete.h"
#include "affichage.h"
#include "fonction.h"
#include "IA.h"
#include "attaque.h"

// Fonction pour sauter une ligne dans un fichier
void sauter_ligne(FILE *fichier) {
    if (fichier == NULL) {
        printf("Erreur : fichier non valide dans sauter_ligne\n");
        exit(0);
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fichier)) {
        if (strchr(buffer, '\n') != NULL) {
            break; // Ligne complète lue
        }
    }
}

// Fonction pour afficher les informations d'un champion
void afficher_personnage(Champion *champion) {
    if (champion == NULL || !champion->nom) {
        printf("Erreur : pointeur NULL dans afficher_personnage\n");
        return;
    }

    printf("Nom : %s\n", champion->nom);
    printf("Classe : %s\n", champion->classe);
    printf("PV max : %.1f\n", champion->pv_max);
    printf("PV courant : %.1f\n", champion->stat.pv_courant);
    printf("Attaque : %.1f\n", champion->stat.attaque);
    printf("Défense : %.1f\n", champion->stat.defense);
    printf("Agilité : %.1f\n", champion->stat.agilite);
    printf("Vitesse : %.1f\n", champion->stat.vitesse);
}



// Affichage initial du jeu
void affichage_initial() {
    int buffer = 10;

    printf("Chargement du jeu...\n");
    for (int k=0; k<3; k++){
        printf(".");
        pause_ms(time_sleep);
    }
    printf("\n");
    pause_ms(time_sleep);

    for (int i = 0; i < buffer; i++) {
        // sleep(val_systemeOS); // Décommentez pour activer les temps d'attente
        printf("---");
    }

    printf("\nChargement termine\n");
    printf("Bienvenue dans MultiverSeus\n");
    pause_ms(time_sleep);
}

// Affiche la classe d'un champion
void afficher_classe(Champion *champion) {
    if (champion == NULL) {
        printf("Erreur : pointeur NULL dans afficher_classe\n");
        return;
    }
    if (!champion->nom){
        printf("Erreur : Nom NULL \n");
        exit(0);
    }

    printf("%s est de ", champion->nom);
    switch (trie(champion)) {
        case 1:
            printf("classe : tank\n");
            break;
        case 2:
            printf("classe : dps\n");
            break;
        case 3:
            printf("classe : soutien\n");
            break;
        default:
            printf("Erreur : classe non définie\n");
            break;
    }
    printf("\n");
}

// Séparation visuelle entre les parties
void separation_des_partie() {
    int buffer = 10;
    for (int i = 0; i < buffer; i++) {
        printf("\n");
    }
}

// Affiche les équipes et leurs champions
void afficher_equipe(Equipe equipe1) {
    if (!equipe1.nom || !equipe1.perso){
        printf("erreur lors de l'allocation de la memoire\n");
        exit(0);
    }
    printf("Équipe %d : %s\n",equipe1.perso->equipe, equipe1.nom);
    for (int i = 0; i < Nb_champion_par_equipe; i++) {
        if (equipe1.perso[i].stat.pv_courant > 0) {
            printf("  - %s (PV : %.1f)\n", equipe1.perso[i].nom, equipe1.perso[i].stat.pv_courant);
        } else {
            printf("  - %s (KO)\n", equipe1.perso[i].nom);
        }
    }

    
}

// Affiche les équipes côte à côte
void afficher_equipes_cote_a_cote(Equipe equipe1, Equipe equipe2) {
    if (equipe1.nom == NULL || equipe2.nom == NULL) {
        printf("Erreur : Les noms des équipes ne sont pas initialises.\n");
        exit(0);
    }

    if (equipe1.perso == NULL || equipe2.perso == NULL) {
        printf("Erreur : Les tableaux de champions des equipes ne sont pas initialises.\n");
        exit(0);
    }

    int n = longueur_nom_max(equipe1.perso, Nb_champion_par_equipe);
    int m = longueur_nom_max(equipe2.perso, Nb_champion_par_equipe);
    int largeur_nom = (n > m ? n : m) + 1;
    int espacement = 12;

    printf("%-*s%*s\n", largeur_nom + espacement, equipe1.nom, largeur_nom + espacement, equipe2.nom);
    printf("%-*s%-*s%-*s%*s%-*s%-*s\n", largeur_nom, "Nom", 10, "Classe", 10, "PV", espacement, " ", largeur_nom, "Nom", 10, "Classe", 10, "PV",10);

    for (int i = 0; i < Nb_champion_par_equipe; i++) {
        if (equipe1.perso[i].nom != NULL) {
            printf("%-*s%-*s%-*.1f", largeur_nom, equipe1.perso[i].nom, 10, equipe1.perso[i].classe, 10, (equipe1.perso[i].stat.pv_courant > 0) ? equipe1.perso[i].stat.pv_courant : 0 );
        } else {
            printf("%-*s%-*s%-*s", largeur_nom, " ", 10, " ", 10, " ");
        }

        printf("%*s", espacement, " ");

        if (equipe2.perso[i].nom != NULL) {
            printf("%-*s%-*s%-*.1f\n", largeur_nom, equipe2.perso[i].nom, 10, equipe2.perso[i].classe, 10, (equipe2.perso[i].stat.pv_courant > 0) ? equipe2.perso[i].stat.pv_courant : 0);
        } else {
            printf("%-*s%-*s%-*s\n", largeur_nom, " ", 10, " ", 10, " ");
        }

    }
    /*
    afficher_stats_Equipe(equipe1);
    printf("%*s", espacement, " ");
    afficher_stats_Equipe(equipe2);
    */
}

// Affiche les champions triés par classe
void afficher_champion_init(Champion *champion_soutien, Champion *champion_tank, Champion *champion_dps, int soutien_count, int tank_count, int dps_count) {
    if (champion_soutien == NULL || champion_tank == NULL || champion_dps == NULL) {
        printf("Erreur : pointeur NULL dans afficher_champion_init\n");
        exit(0);
    }

    int index = 1;

    printf("Les champions de classe BLEU tank RESET sont : \n");
    for (int i = 0; i < tank_count; i++) {
        printf("%d : %s\n", index, (champion_tank + i)->nom);
        index++;
    }
    printf("\n");
    pause_ms(time_sleep);

    printf("Les champions de classe ROUGE dps RESET sont : \n");
    for (int i = 0; i < dps_count; i++) {
        printf("%d : %s\n", index, (champion_dps + i)->nom);
        index++;
    }
    printf("\n");
    pause_ms(time_sleep);

    printf("Les champions de classe VERT soutien RESET sont : \n");
    for (int i = 0; i < soutien_count; i++) {
        printf("%d : %s\n", index, (champion_soutien + i)->nom);
        index++;
    }
}

// Affiche les dégâts reçus par un champion
void afficher_degat_recu(Champion cible, Champion attaquant, int type_attaque) {
    if (type_attaque == 0) { // Attaque classique
        printf("%s reçoit : %.1f degats\n", cible.nom, attaquant.stat.attaque);
        printf("Les PV de %s sont maintenant de : %.1f\n", cible.nom, cible.stat.pv_courant);
    } else if (type_attaque == 1) { // Attaque spéciale
        printf("Attaque speciale\n");
        printf("%s reçoit : %.1f degats\n", cible.nom, attaquant.stat.attaque);
        printf("Les PV de %s sont maintenant de : %.1f\n", cible.nom, cible.stat.pv_courant);
    }
}

// Affiche les options de saisie pour l'utilisateur
int affichage_saisie_utilisateur(Champion champion) {
    if (champion.nom == NULL) {
        printf("Erreur : le nom du champion est NULL\n");
        exit(1); // Retourne une valeur d'erreur
    }
    if (champion.stat.pv_courant <= 0){
        return -1;
    }
    else if (champion.stat.pv_courant > 0){
        printf("\n\n");
        printf("Que voulez-vous faire avec %s ?\n", champion.nom);
            if (champion.stat.jauge_actuelle >= champion.stat.jauge_max){
            printf("l'attaque speciale est rechargee\n");;
    }
        printf("1. Attaque simple\n");
        printf("2. Utiliser une technique speciale\n");
        printf("3. utiliser un objet\n");
        printf("4. passer son tour\n");

        int choix = -1;
        do {
            printf("\nEntrez votre choix (1-4) : ");
            if (scanf("%d", &choix) != 1) {
                printf("Entrée invalide. Veuillez entrer un nombre entre 1 et 4.\n");
                vider_buffer_scanf(); // Vide le buffer d'entrée
                choix = -1; // Réinitialise le choix pour rester dans la boucle
            } 
            if (champion.stat.jauge_actuelle < champion.stat.jauge_max){
                printf("L'attaque spéciale n'est pas encore rechargee\n");
                choix = -1;
            }
            
            else if (choix < 1 || choix > 3) {
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 4.\n");
            }
        } while (choix < 1 || choix > 4);

        return choix;
    }
}
