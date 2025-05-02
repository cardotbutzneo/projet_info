#include "en-tete.h"
#include "fonction.h"
#include "affichage.h"
#include "IA.h"
#include "attaque.h"


Champion *persoenjeu; // attention variable globale



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
    sauter_ligne(fichier);
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


int ordre_classe(const char *classe) {
    if (strcmp(classe, "tank") == 0) return 1;
    if (strcmp(classe, "dps") == 0) return 2;
    if (strcmp(classe, "soutien") == 0) return 3;
    return 4; // Classe inconnue ou autre
}

int comparer_par_classe(const void *a, const void *b) {
    Champion *champion1 = (Champion *)a;
    Champion *champion2 = (Champion *)b;

    // Définir un ordre pour les classes
    

    return ordre_classe(champion1->classe) - ordre_classe(champion2->classe);
}

void classe_champion(Champion *tab, Champion *tab_soutien, Champion *tab_tank, Champion *tab_dps, int *soutien_count, int *tank_count, int *dps_count, Champion *temp) {
    memcpy(temp, tab, sizeof(Champion) * Nb_champion); // Copier les données dans un tableau temporaire

    // Trier le tableau temporaire par classe
    qsort(temp, Nb_champion, sizeof(Champion), comparer_par_classe);

    // Réinitialiser les compteurs
    *soutien_count = 0;
    *tank_count = 0;
    *dps_count = 0;

    // Parcourir le tableau trié et remplir les tableaux par classe
    for (int i = 0; i < Nb_champion; i++) {
        if (strcmp(temp[i].classe, "tank") == 0) {
            copie_champion(&temp[i], &tab_tank[*tank_count]);
            (*tank_count)++;
        } else if (strcmp(temp[i].classe, "dps") == 0) {
            copie_champion(&temp[i], &tab_dps[*dps_count]);
            (*dps_count)++;
        } else if (strcmp(temp[i].classe, "soutien") == 0) {
            copie_champion(&temp[i], &tab_soutien[*soutien_count]);
            (*soutien_count)++;
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
/*
    destination->effet_spe = malloc(strlen(source->effet_spe) + 1);
    if (destination->effet_spe == NULL) {
        printf("Erreur d'allocation mémoire pour l'effet spécial\n");
        free(destination->nom);
        free(destination->classe);
        free(destination->attaque_spe);
        exit(1);
    }
    strcpy(destination->effet_spe, effet_spe);
*/
}

void choix_des_champion(Champion *tableau_champion, Equipe *equipe1, Equipe *equipe2, int choix) {
    int tempp;
    if (choix == 2) {
        printf("Equipe 1 choisissez vos champions\n");
        for (int i = 0; i < Nb_champion_par_equipe; i++) {
            tempp = -1; // Initialisation à une valeur invalide pour entrer dans la boucle
            do {
                printf("Champion %d : \n", i + 1);
                if (scanf("%d", &tempp) != 1) {
                    printf("Entrée invalide. Veuillez entrer un nombre entre 1 et 18.\n");
                    while (getchar() != '\n'); // Vide le buffer d'entrée
                    tempp = -1; // Réinitialise tempp pour rester dans la boucle
                } else if (tempp > 18 || tempp <= 0) {
                    printf("Numéro invalide. Veuillez entrer un nombre entre 1 et 18.\n");
                }
            } while (tempp > 18 || tempp <= 0);
            copie_champion((tableau_champion + (tempp - 1)), &equipe1->perso[i]);
            equipe1->perso[i].equipe = 1; // Assigner l'équipe 1 au champion
            
        }
        printf("Equipe 2 choisissez vos champions\n");
        for (int i = 0; i < Nb_champion_par_equipe; i++) {
            tempp = -1; // Initialisation à une valeur invalide pour entrer dans la boucle
            do {
                printf("Champion %d : \n", i + 1);
                if (scanf("%d", &tempp) != 1) {
                    printf("Entrée invalide. Veuillez entrer un nombre entre 1 et 18.\n");
                    while (getchar() != '\n'); // Vide le buffer d'entrée
                    tempp = -1; // Réinitialise tempp pour rester dans la boucle
                } else if (tempp > 18 || tempp <= 0) {
                    printf("Numéro invalide. Veuillez entrer un nombre entre 1 et 18.\n");
                }
            } while (tempp > 18 || tempp <= 0);
            copie_champion((tableau_champion + (tempp - 1)), &equipe2->perso[i]);
            equipe2->perso[i].equipe = 2; // Assigner l'équipe 2 au champion
        }
    } else if (choix == 1) {
        printf("Equipe 1 choisissez vos champions\n");
        for (int i = 0; i < Nb_champion_par_equipe; i++) {
             // Initialisation à une valeur invalide pour entrer dans la boucle
            do {
                printf("Champion %d : ", i + 1);
                if (scanf("%d", &tempp) != 1) {
                    printf("Entrée invalide. Veuillez entrer un nombre entre 1 et 18.\n");
                    while (getchar() != '\n'); // Vide le buffer d'entrée
                    tempp = -1; // Réinitialise tempp pour rester dans la boucle
                } else if (tempp > 18 || tempp <= 0) {
                    printf("Numéro invalide. Veuillez entrer un nombre entre 1 et 18.\n");
                }
            } while (tempp > 18 || tempp <= 0);
            copie_champion((tableau_champion + (tempp - 1)), &equipe1->perso[i]);
            equipe1->perso[i].equipe = 1; // Assigner l'équipe 1 au champion
        }
        
        choix_champion_IA(tableau_champion, equipe2);
    }
}

void choix_champion_IA(Champion *tableau_champion, Equipe *equipe2){
    for (int i=0;i<Nb_champion_par_equipe;i++){
        copie_champion(((tableau_champion+(rand()%18))),&equipe2->perso[i]);  // choix des champions aléatoirement
        equipe2->perso[i].equipe = 2; // Assigner l'équipe 2 au champion
    }
}

int longueur_nom_max(Champion *champions, int taille) {
    int max_longueur = 0;
    for (int i = 0; i < taille; i++) {
        if (champions[i].nom != NULL) {
            int longueur = strlen(champions[i].nom);
            if (longueur > max_longueur) {
                max_longueur = longueur;
            }
        }
    }
    return max_longueur;
}

void saisie_utilisateur(Champion *champion, Equipe *equipe2 ){ // demande à l'utilisateur les actions à faire

    switch (affichage_saisie_utilisateur(*champion))
    {
    case 1:
        attaquesimple(champion, equipe2->perso);
        break;
    case 2:
        
        printf("fonction pas encore definie\n");
        break;
    case 3:
        printf("fonction pas encore definie\n");
    default:
        break;
    }
}
/*
Equipe *recuperer_equipe(Champion *champion, Equipe *equipe1, Equipe *equipe2) {
    // Vérifier si le champion appartient à equipe1
    for (int i = 0; i < Nb_champion_par_equipe; i++) {
        if (champion->equipe == 1) {
            return equipe1;
        }
    }

    // Vérifier si le champion appartient à equipe2
    for (int i = 0; i < Nb_champion_par_equipe; i++) {
        if (champion->equipe == 2) {
            return equipe2;
        }
    }

    // Si le champion n'appartient à aucune équipe
    return NULL;
}
    */
// Fonction de comparaison pour qsort (tri par vitesse décroissante)
int comparer_par_vitesse(const void *a, const void *b) {
    Champion *champion1 = (Champion *)a;
    Champion *champion2 = (Champion *)b;
    if (champion1->stat.vitesse > champion2->stat.vitesse) return -1;
    if (champion1->stat.vitesse < champion2->stat.vitesse) return 1;
    return 0;
}

void trier_par_vitesse(Champion *liste_champion, Equipe *equipe1, Equipe *equipe2) {
    int index = 0;

    // Copier les champions de l'équipe 1
    for (int i = 0; i < Nb_champion_par_equipe; i++) {
        copie_champion(&equipe1->perso[i], &liste_champion[index++]);
        liste_champion[index-1].equipe = 1; // Assigner l'équipe 1 au champion
    }

    // Copier les champions de l'équipe 2
    for (int i = 0; i < Nb_champion_par_equipe; i++) {
        copie_champion(&equipe2->perso[i], &liste_champion[index++]);
        liste_champion[index-1].equipe = 2; // Assigner l'équipe 2 au champion
    }

    // Trier les champions par vitesse décroissante
    qsort(liste_champion, Nb_champion_par_equipe * 2, sizeof(Champion), comparer_par_vitesse);

}
