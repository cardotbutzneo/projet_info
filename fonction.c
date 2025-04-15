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
    if (fscanf(fichier, "%s", classe) != 1) {
        printf("Erreur lors de la lecture de la classe\n");
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%s", attaque_spe) != 1) {
        printf("Erreur lors de la lecture de l'attaque spéciale\n");
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
/*
void vitesse(Equipe *equipe1, Equipe *equipe2){ //tri les champion par leur vitesse
    Champion *ordreAttaque[6];
    Champion min;
    ordreAttaque[0]=equipe1->perso1;
    ordreAttaque[1]=equipe1->perso2;
    ordreAttaque[2]=equipe1->perso3;
    ordreAttaque[3]=equipe2->perso1;
    ordreAttaque[4]=equipe2->perso2;
    ordreAttaque[5]=equipe2->perso3;
    for(int i=0;i<6;i++){
        for(int j=i;j<6;j++){
            if (ordreAttaque[i]->stat->vitesse > ordreAttaque[j]->stat->vitesse){
                min=ordreAttaque[i];
                ordreAttaque[i]=ordreAttaque[j];
                ordreAttaque[j]=min;
            }
        }
    } 
}
float degat(Equipe equipe1, Equipe equipe2){//calcule les degat



}
void attaque (Equipe *equipe1, Equipe *equipe2){//actualiser la vie des personnage apres une attaque classique





}
*/

int chaine_caractere_egales(char *chaine1, char *chaine2){

    if (chaine1 == NULL || chaine2 == NULL){
        printf("une des chaines pointe vers NULL");
        return -1;
    }
    for (int i=0;i<strlen(chaine1);i++){
        if (chaine1[i] != chaine2[i] ){
            return 1;
        }
    }
    return 0;
}


int trie (Champion *champion, Champion tableau_champion){
    if (chaine_caractere_egales(champion->classe,"enattente")){
        printf("erreur lors de l'attribution des classes");
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
        return -1;
    }
}

