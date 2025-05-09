#include "en-tete.h"
#include "fonction.h"
#include "affichage.h"
#include "IA.h"
#include "attaque.h"
#include "attaquespe.h"


void initialisation_champion(FILE *fichier, Champion *champion) {
    if (!fichier || !champion){
        printf("erreur lors de l'alocation de la memoire\n");
        exit(0);
    }
    int pv_max = 0, pv = 0, attaque = 0, defense = 0, agilite = 0, vitesse = 0;
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
    if (!champion || !champion->nom){
        printf("erreur lors de l'alocation de la memoire\n");
        exit(0);
    }
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
    if (!classe){
        printf("erreur lors de l'alocation de la memoire\n");
        exit(0);
    }
    if (strcmp(classe, "tank") == 0) return 1;
    if (strcmp(classe, "dps") == 0) return 2;
    if (strcmp(classe, "soutien") == 0) return 3;
    return 4; // Classe inconnue ou autre
}

int comparer_par_classe(const void *a, const void *b) {
    if (!a || !b){
        printf("erreur lors de l'alocation de la memoire\n");
        exit(0);
    }
    Champion *champion1 = (Champion *)a;
    Champion *champion2 = (Champion *)b;

    // Définir un ordre pour les classes
    

    return ordre_classe(champion1->classe) - ordre_classe(champion2->classe);
}

void classe_champion(Champion *tab, Champion *tab_soutien, Champion *tab_tank, Champion *tab_dps, int *soutien_count, int *tank_count, int *dps_count, Champion *temp) {
    if(!tab ||!tab_soutien || !tab_tank || !tab_dps || !soutien_count ||!tank_count || !dps_count  || !temp){
        printf("erreur lors de l'alocation de la memoire\n");
        exit(0);
    } 
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
    if (!source || !destination){
        printf("erreur lors de l'alocation de la memoire\n");
        exit(0);
    }
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

int verif_number(int number[],int n){
    for (int i=0;i<n;i++){
        if (number[i] == n){
            return 1;
        }
    }
    return 0;
}

void choix_des_champion(Champion *tableau_champion, Equipe *equipe1, Equipe *equipe2, int choix, Champion *tableau_champion_cachee) {
    if (!tableau_champion || !tableau_champion_cachee|| !equipe1 || !equipe2 || !equipe1->nom || !equipe2->nom){
        printf("erreur lors de l'alocation de la memoire\n");
        exit(0);
    }
    int tempp;
    int rep[6] = {0};
    if (choix == 2) {
        printf("Equipe 1 choisissez vos champions\n");
        for (int i = 0; i < Nb_champion_par_equipe; i++) {
            tempp = -1; // Initialisation à une valeur invalide pour entrer dans la boucle
            do {
                printf("Champion %d : ", i + 1);
                if (scanf("%d", &tempp) != 1) {
                    printf("Entrée invalide. Veuillez entrer un nombre entre 1 et 18 \n");
                    vider_buffer_scanf(); // Vide le buffer d'entrée
                    tempp = -1; // Réinitialise tempp pour rester dans la boucle
                } else if ((tempp < 1 || tempp > 18) && (tempp < 100 || tempp > 102)) {
                    printf("Numéro invalide. Veuillez entrer un nombre entre 1 et 18 \n");
                    tempp = -1;
                }
                if (strcmp(equipe1->perso[i].nom, tableau_champion[tempp - 1].nom) == 0 && verif_number(rep, tempp) == 0) {
                    printf("Ce champion est déjà choisi. Veuillez en choisir un autre.\n");
                    tempp = -1;
                }
            } while ((tempp < 1 || tempp > 18) && (tempp < 100 || tempp > 102));
            
            if (tempp >= 1 && tempp <= 18) {
                copie_champion((tableau_champion + (tempp - 1)), &equipe1->perso[i]);
                equipe1->perso[i].equipe = 1;
                equipe1->perso[i].index = i;
            } else if (tempp >= 100 && tempp <= 102) {
                copie_champion((tableau_champion_cachee + (tempp - 100)), &equipe1->perso[i]);
                equipe1->perso[i].equipe = 1;
                printf("Bravo ! Vous avez trouvé un champion caché\n");
                equipe1->perso[i].index = i;
            }
            rep[i] = tempp; // Enregistre le numéro choisi

            
        }
        printf("Equipe 2 choisissez vos champions\n");
        for (int i = 0; i < Nb_champion_par_equipe; i++) {
            tempp = -1; // Initialisation à une valeur invalide pour entrer dans la boucle
            do {
                printf("Champion %d : ", i + 1);
                if (scanf("%d", &tempp) != 1) {
                    printf("Entrée invalide. Veuillez entrer un nombre entre 1 et 18 \n");
                    vider_buffer_scanf(); // Vide le buffer d'entrée
                    tempp = -1; // Réinitialise tempp pour rester dans la boucle
                } else if ((tempp < 1 || tempp > 18) && (tempp < 100 || tempp > 102)) {
                    printf("Numéro invalide. Veuillez entrer un nombre entre 1 et 18 \n");
                    tempp = -1;
                }
                if (strcmp(equipe1->perso[i].nom, tableau_champion[tempp - 1].nom) == 0 && verif_number(rep, tempp) == 0) {
                    printf("Ce champion est déjà choisi. Veuillez en choisir un autre.\n");
                    tempp = -1;
                }
            } while ((tempp < 1 || tempp > 18) && (tempp < 100 || tempp > 102));
            
            if (tempp >= 1 && tempp <= 18) {
                copie_champion((tableau_champion + (tempp - 1)), &equipe2->perso[i]);
                equipe2->perso[i].equipe = 2;
                equipe2->perso[i].index = i;
            } else if (tempp >= 100 && tempp <= 102) {
                copie_champion((tableau_champion_cachee + (tempp - 100)), &equipe2->perso[i]);
                equipe2->perso[i].equipe = 2;
                equipe2->perso[i].index = i;
                printf("Bravo ! Vous avez trouvé un champion caché\n");
            }
            if (strcmp(equipe1->perso[i].nom, tableau_champion[tempp - 1].nom) == 0 && verif_number(rep, tempp) == 0) {
                    printf("Ce champion est déjà choisi. Veuillez en choisir un autre.\n");
                    tempp = -1;
                }
                rep[i] = tempp; // Enregistre le numéro choisi
        }
    } else if (choix == 1) {
        printf("Equipe 1 choisissez vos champions\n");
        for (int i = 0; i < Nb_champion_par_equipe; i++) {
             // Initialisation à une valeur invalide pour entrer dans la boucle
             do {
                printf("Champion %d : ", i + 1);
                if (scanf("%d", &tempp) != 1) {
                    printf("Entrée invalide. Veuillez entrer un nombre entre 1 et 18 ou entre 100 et 102.\n");
                    vider_buffer_scanf(); // Vide le buffer d'entrée
                    tempp = -1; // Réinitialise tempp pour rester dans la boucle
                } else if ((tempp < 1 || tempp > 18) && (tempp < 100 || tempp > 102)) {
                    printf("Numéro invalide. Veuillez entrer un nombre entre 1 et 18 ou entre 100 et 102.\n");
                    tempp = -1;
                }
                if (strcmp(equipe1->perso[i].nom, tableau_champion[tempp - 1].nom) == 0 && verif_number(rep, tempp) == 0) {
                    printf("Ce champion est déjà choisi. Veuillez en choisir un autre.\n");
                    tempp = -1;
                }
            } while ((tempp < 1 || tempp > 18) && (tempp < 100 || tempp > 102));
            
            if (tempp >= 1 && tempp <= 18) {
                copie_champion((tableau_champion + (tempp - 1)), &equipe1->perso[i]);
                equipe1->perso[i].equipe = 1;
                equipe1->perso[i].index = i;
            } else if (tempp >= 100 && tempp <= 102) {
                copie_champion((tableau_champion_cachee + (tempp - 100)), &equipe1->perso[i]);
                equipe1->perso[i].equipe = 1;
                equipe1->perso[i].index = i;
                printf("Bravo ! Vous avez trouve un champion cache\n");
            }
            rep[i] = tempp; // Enregistre le numéro choisi
        }
        
        choix_champion_IA(tableau_champion, equipe2, rep);
    }
}

void choix_champion_IA(Champion *tableau_champion, Equipe *equipe2, int rep[]){
    if (!tableau_champion || !equipe2 ||! equipe2->nom){
        printf("erreur lors de l'alocation de la memoire\n");
        exit(0);
    } 
    for (int i=0;i<Nb_champion_par_equipe;i++){
        int x = rand()%18;
        while (verif_number(rep,x) == 1){
            x = rand()%18;
        }
        copie_champion((tableau_champion+x), &equipe2->perso[i]);  // choix des champions aléatoirement
        equipe2->perso[i].equipe = 2; // Assigner l'équipe 2 au champion
        equipe2->perso[i].index = i+2;
    }
}

int longueur_nom_max(Champion *champions, int taille) {
    if (!champions || !champions->nom){
        printf("erreur lors de l'alocation de la memoire\n");
        exit(0);
    }
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

void afficher_inventaire(Equipe equipe) {
    printf("-----------------------\n");
    printf("Affichage de l'inventaire\n\n");
    for (int i = 0; i < Nb_objet_par_equipe; i++) {
        if (equipe.objet[i].nom != NULL) {
            printf("%s :\n", equipe.objet[i].nom);
        } else {
            printf("Nom de l'objet non défini, exit\n");
            exit(0);
        }
        if (equipe.objet[i].effet != NULL) {
            printf("%s :\n", equipe.objet[i].effet);
        } else {
            printf("Effet de l'objet non défini,exit\n");
            exit(0);
        }
    }
}

void afficher_stats_Equipe(Equipe equipe){
    afficher_equipe(equipe);
    if (equipe.objet == NULL){
        return;
    }
    else{
        afficher_inventaire(equipe);
    }
}

void saisie_utilisateur(Champion *champion, Equipe *equieAdverse, Equipe *equipe) { // demande à l'utilisateur les actions à faire
    if (!champion || !equieAdverse || !equieAdverse->nom || !champion->nom) {
        printf("Erreur lors de l'allocation de la mémoire\n");
        exit(0);
    }

    // Vérification des PV du champion
    if (champion->stat.pv_courant <= 0) {
        printf("Le champion %s est KO et ne peut pas agir.\n", champion->nom);
        return; // Sort de la fonction sans effectuer d'action
    }

    switch (affichage_saisie_utilisateur(*champion)) {
        case 1:
            attaquesimple(champion, equieAdverse->perso); // attaque simple
            break;
        case 2:
            attaqueSpecial(*champion, equieAdverse->perso, equipe->perso); // attaque spéciale
            break;
        case 3:
            printf("Fonction pas encore definie\n"); // utiliser un objet
            break;
        default: // passer son tour
            printf("%s passe son tour.\n", champion->nom);
            break;
    }
}

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

void vider_buffer_scanf(){
    while(getchar() != '\n');
}

int est_en_vie(Champion champion){
    if (champion.stat.pv_courant <= 0){
        return 0; // faux
    }
    if (champion.stat.pv_courant > 0 && champion.stat.pv_courant <= champion.pv_max){
        return 1; // vraix
    }
    else{
        printf("erreur de PV dans est_en_vie\n");
        exit(-1);
    }
}

#ifdef _WIN32
     #include <windows.h>
     void pause_ms(int milliseconds){
        Sleep(milliseconds);
     }
#else
        #include <unistd.h>
        void pause_ms(int milliseconds){
            usleep(milliseconds / 1000); // Convertit les millisecondes en secondes
        }   
#endif