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
        Sleep(1000); // passer cette ligne en commentaire pour ne pas avoir les temps de chargement
        printf("---");
    }

    printf("\nchargement fini\n");
    printf("Bienvenue dans MultiverSeus\n");

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
    // Obtenir la largeur du terminal
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int largeur_terminal = 80; // Valeur par défaut
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        largeur_terminal = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }

    // Calculer l'espacement pour centrer les équipes
    int largeur_colonne = largeur_terminal / 2 - 5; // Diviser l'écran en deux colonnes
    int espace_entre_equipes = 5; // Espacement entre les deux colonnes

    // Calculer les positions centrées pour les noms des équipes
    int espace_gauche_equipe1 = (largeur_colonne - strlen(nom_equipe1)) / 2;
    int espace_gauche_equipe2 = (largeur_colonne - strlen(nom_equipe2)) / 2;

    separation_des_partie();

    // Afficher les noms des équipes alignés avec les colonnes des personnages
    printf("%*s%*s\n", strlen(nom_equipe1), nom_equipe1, espace_gauche_equipe1 +
           largeur_colonne + espace_gauche_equipe2 + espace_entre_equipes, nom_equipe2);

    // Afficher les champions des deux équipes côte à côte avec leurs points de vie
    for (int i = 0; i < 3; i++) {
        char *nom_champion1 = (equipe1 + i)->stat.pv_courant >= 0 ? (equipe1 + i)->nom : " ";
        char *nom_champion2 = (equipe2 + i)->stat.pv_courant >= 0 ? (equipe2 + i)->nom : " ";
        float pv_champion1 = (equipe1 + i)->stat.pv_courant >= 0 ? (equipe1 + i)->stat.pv_courant : 0;
        float pv_champion2 = (equipe2 + i)->stat.pv_courant >= 0 ? (equipe2 + i)->stat.pv_courant : 0;

        printf("%-*s (%.1f PV)%*s (%.1f PV)\n", largeur_colonne - 10, nom_champion1, pv_champion1,
               espace_entre_equipes + largeur_colonne - 10, nom_champion2, pv_champion2);
    }
}