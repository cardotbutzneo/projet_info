#include "en-tete.h"


void initialisation_champion(FILE *fichier, Champion *champion) {
    int pv_max, pv, attaque, defense, agilite, vitesse;
    char nom[50], classe[50], attaque_spe[50], effet_spe[50];

    // Lecture des stats dans le fichier du champion
    sauter_ligne(fichier);
    if (fscanf(fichier, "%s", nom) != 1) {
        printf("Erreur lors de la lecture du nom\n");
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &pv) != 1) {
        printf("Erreur lors de la lecture des PV\n");
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &pv_max) != 1) {
        printf("Erreur lors de la lecture des PV max\n");
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &attaque) != 1) {
        printf("Erreur lors de la lecture de l'attaque\n");
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &defense) != 1) {
        printf("Erreur lors de la lecture de la défense\n");
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &agilite) != 1) {
        printf("Erreur lors de la lecture de l'agilité\n");
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &vitesse) != 1) {
        printf("Erreur lors de la lecture de la vitesse\n");
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%s", attaque_spe) != 1) {
        printf("Erreur lors de la lecture de l'attaque spéciale\n");
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%s", classe) != 1) {
        printf("Erreur lors de la lecture de la classe\n");
        exit(1);
    }
    
    sauter_ligne(fichier);
    if (fscanf(fichier, "%s", effet_spe) != 1) {
        printf("Erreur lors de la lecture de l'effet spécial\n");
        exit(1);
    }

    // Mise à jour des stats du champion
    champion->pv_max = pv_max;
    champion->stat.pv_courant = pv;
    champion->stat.defense = defense;
    champion->stat.attaque = attaque;
    champion->stat.agilite = agilite;
    champion->stat.vitesse = vitesse;

    // Allocation dynamique et copie des chaînes de caractères
    champion->nom = malloc(strlen(nom) + 1);
    if (champion->nom == NULL) {
        printf("Erreur d'allocation de mémoire pour le nom\n");
        exit(1);
    }
    strcpy(champion->nom, nom);

    champion->classe = malloc(strlen(classe) + 1);
    if (champion->classe == NULL) {
        printf("Erreur d'allocation de mémoire pour la classe\n");
        free(champion->nom); // Libère la mémoire déjà allouée
        exit(1);
    }
    strcpy(champion->classe, classe);

    champion->attaque_spe = malloc(strlen(attaque_spe) + 1);
    if (champion->attaque_spe == NULL) {
        printf("Erreur d'allocation de mémoire pour l'attaque spéciale\n");
        free(champion->nom);
        free(champion->classe);
        exit(1);
    }
    strcpy(champion->attaque_spe, attaque_spe);

    champion->effet_spe = malloc(strlen(effet_spe) + 1);
    if (champion->effet_spe == NULL) {
        printf("Erreur d'allocation de mémoire pour l'effet spécial\n");
        free(champion->nom);
        free(champion->classe);
        free(champion->attaque_spe);
        exit(1);
    }
    strcpy(champion->effet_spe, effet_spe);
}

int chaine_caractere_egales(char *chaine1, char *chaine2){

    if (chaine1 == NULL || chaine2 == NULL){
        printf("une des chaines pointe vers NULL");
        return -1;
    }
    for (int i=0;i<strlen(chaine1);i++){
        if (chaine1[i] != chaine2[i]  ){
            return 1;
        }
    }
    return 0;
}


int trie (Champion *champion){
    if (chaine_caractere_egales(champion->classe,"enattente") == 0){
        printf("erreur lors de l'attribution des classes\n");
        return -1;
    }
    else if (chaine_caractere_egales(champion->classe,"tank") == 0){
        return 1;
    }
    else if (chaine_caractere_egales(champion->classe,"dps") == 0){
        return 2;
    }
    else if (chaine_caractere_egales(champion->classe,"soutien") == 0){
        return 3;
    }
    else{
        printf("erreur inconnue\n");
        return -1;
    }
}

void classe_champion(Champion *tab, Champion *tab_soutien, Champion *tab_tank, Champion *tab_dps, int *soutien_count, int *tank_count, int *dps_count) {
    *soutien_count = 0;
    *tank_count = 0;
    *dps_count = 0;

    for (int i = 0; i < 19; i++) {
        switch (trie(tab + i)) {
        case 1: // Tank
            if (*tank_count < 6) {
                copie_champion(tab + i, tab_tank + *tank_count);
                (*tank_count)++;
            } else {
                printf("Erreur : trop de tanks détectés\n");
            }
            break;

        case 2: // DPS
            if (*dps_count < 6) {
                copie_champion(tab + i, tab_dps + *dps_count);
                (*dps_count)++;
            } else {
                printf("Erreur : trop de DPS détectés\n");
            }
            break;

        case 3: // Soutien
            if (*soutien_count < 6) {
                copie_champion(tab + i, tab_soutien + *soutien_count);
                (*soutien_count)++;
            } else {
                printf("Erreur : trop de soutiens détectés\n");
            }
            break;

        default:
            printf("Classe inconnue pour le champion %s\n", (tab + i)->nom);
            break;
        }
    }
}

void copie_champion(Champion *source, Champion *destination) {
    // Copier les champs simples
    destination->pv_max = source->pv_max;
    destination->stat.pv_courant = source->stat.pv_courant;
    destination->stat.defense = source->stat.defense;
    destination->stat.attaque = source->stat.attaque;
    destination->stat.agilite = source->stat.agilite;
    destination->stat.vitesse = source->stat.vitesse;

    // Copier les chaînes de caractères avec allocation dynamique
    destination->nom = malloc(strlen(source->nom) + 1);
    if (destination->nom == NULL) {
        printf("Erreur d'allocation mémoire pour le nom\n");
        exit(1);
    }
    strcpy(destination->nom, source->nom);

    destination->classe = malloc(strlen(source->classe) + 1);
    if (destination->classe == NULL) {
        printf("Erreur d'allocation mémoire pour la classe\n");
        free(destination->nom);
        exit(1);
    }
    strcpy(destination->classe, source->classe);

    destination->attaque_spe = malloc(strlen(source->attaque_spe) + 1);
    if (destination->attaque_spe == NULL) {
        printf("Erreur d'allocation mémoire pour l'attaque spéciale\n");
        free(destination->nom);
        free(destination->classe);
        exit(1);
    }
    strcpy(destination->attaque_spe, source->attaque_spe);

    destination->effet_spe = malloc(strlen(source->effet_spe) + 1);
    if (destination->effet_spe == NULL) {
        printf("Erreur d'allocation mémoire pour l'effet spécial\n");
        free(destination->nom);
        free(destination->classe);
        free(destination->attaque_spe);
        exit(1);
    }
    strcpy(destination->effet_spe, source->effet_spe);
}
