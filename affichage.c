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

int type_os(int type_OS){
    if (_WIN32 ){
        type_OS = 1000;
    }

    else {
        printf("Nous avons détecter que votre appareil n'est pas sous Windows, de ce fait les temps d'attente pourront etre long.\n");
        type_OS = 1;
    }
    return type_OS;
}

void affichage_initial(){
    int buffer = 10;
    int val_systemeOS;
    val_systemeOS = type_os(val_systemeOS);
    
    printf("Chargement du jeu...\n");
    Sleep(1000);


    for (int i=0;i<buffer;i++){
        Sleep(val_systemeOS); // passer cette ligne en commentaire pour ne pas avoir les temps de chargement
        printf("---");
    }

    printf("\nchargement fini\n");
    printf("Bienvenue dans MultiverSeus\n");
    Sleep(val_systemeOS);
}

void afficher_classe(Champion *champion){
    printf("%s est de ",champion->nom);
    switch (trie(champion))
    {
    case 1:
        printf("classe : tank\n");
        break;
    
    case 2 :
        printf("classe : dps\n");
        break;
    
    case 3 :
        printf("classe : soutien\n");
        break;
    
    default:
        printf("erreur classe non definie\n");
        break;
    }
    printf("\n");
}

void separation_des_partie(){
    int buffer = 10;
    for (int i=0;i<buffer;i++){
        printf("\n");
    }
}

void centrer(){
    
}

void afficher_equipe(Champion *equipe1, Champion *equipe2, char *nom_equipe1, char *nom_equipe2){
    printf("Equipe 1 :\n");
    for (int i=0;i<3;i++){
        if ((equipe1+i)->stat.pv_courant >= 0){
            printf("%s\n",*(equipe1+i)->nom);
        }

    }

    printf("Equipe 2 :\n");
    for (int i=0;i<3;i++){
        if ((equipe1+i)->stat.pv_courant >= 0){
            printf("%s\n",*(equipe1+i)->nom);
        }

    }
}

void afficher_equipes_cote_a_cote(Champion *equipe1, Champion *equipe2, char *nom_equipe1, char *nom_equipe2) {

    // Calculer la largeur maximale des noms pour ajuster l'affichage
    int n = longueur_nom_max(equipe1, Nb_champion_par_equipe);
    int m = longueur_nom_max(equipe2, Nb_champion_par_equipe);
    int largeur_nom = max(n, m)+1;

    // Ajouter un espacement fixe entre les deux équipes
    int espacement = 12;

    // Afficher les noms des équipes alignés
    printf("%-*s%*s\n", largeur_nom + espacement, nom_equipe1, largeur_nom + espacement, nom_equipe2);

    // Afficher les en-têtes des colonnes
    printf("%-*s%-*s%-*s%*s%-*s%-*s\n", largeur_nom, "Nom", 10, "Classe", 10, "PV", espacement, " ", largeur_nom, "Nom", 10, "Classe", 10, "PV");

    // Afficher les champions des deux équipes côte à côte
    for (int i = 0; i < 3; i++) {
        // Équipe 1
        if ((equipe1 + i)->nom != NULL) {
            printf("%-*s%-*s%-*f", largeur_nom, (equipe1 + i)->nom, 10, (equipe1 + i)->classe, 10, (equipe1 + i)->stat.pv_courant);
        } else {
            printf("%-*s%-*s%-*s", largeur_nom, " ", 10, " ", 10, " ");
        }

        // Espacement entre les deux équipes
        printf("%*s", espacement, " ");

        // Équipe 2
        if ((equipe2 + i)->nom != NULL) {
            printf("%-*s%-*s%-*f\n", largeur_nom, (equipe2 + i)->nom, 10, (equipe2 + i)->classe, 10, (equipe2 + i)->stat.pv_courant);
        } else {
            printf("%-*s%-*s%-*s\n", largeur_nom, " ", 10, " ", 10, " ");
        }
    }
}

void afficher_champion_init(Champion *champion_soutien, Champion *champion_tank, Champion *champion_dps, int soutien_count, int tank_count, int dps_count){
    
    int index = 1;
    

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
    printf("\n");
    Sleep(2000);
    printf("Les champions de classe soutien sont : \n");
    for (int i = 0; i < soutien_count; i++) {
        printf("%d : %s\n",index, (champion_soutien + i)->nom);
        index++;
    }
}

void affichage_saisie_utilisateur(Champion *equipe){
    for (int i=0;i<Nb_champion_par_equipe;i++){
        printf("champion selectionner : \n");
        printf("%s\n",(equipe+i)->nom);
        printf("1 : attaquer  |  2 : technique speciale  |  3 : utiliser un objet  |  4 : passer son tour\n");

    }

}