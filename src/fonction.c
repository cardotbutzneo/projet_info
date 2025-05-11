#include "en-tete.h"
#include "fonction.h"
#include "affichage.h"
#include "IA.h"
#include "attaque.h"
#include "attaquespe.h"
#include "couleurs.h"

void free_champion(Champion *champion) { // fonction pour liberer la memoire
    if (champion == NULL) {
        return; // Si le pointeur est NULL, ne rien faire
    }

    // Libérer les champs dynamiquement alloués et réinitialiser les pointeurs à NULL
    if (champion->nom) {
        free(champion->nom);
        champion->nom = NULL;
    }

    if (champion->classe) {
        free(champion->classe);
        champion->classe = NULL;
    }

    if (champion->attaque_spe) {
        free(champion->attaque_spe);
        champion->attaque_spe = NULL;
    }

    if (champion->effet_spe) {
        free(champion->effet_spe);
        champion->effet_spe = NULL;
    }

    if (champion->description) {
        free(champion->description);
        champion->description = NULL;
    }

    if (champion->description_attaque_spe) {
        free(champion->description_attaque_spe);
        champion->description_attaque_spe = NULL;
    }
}

void initialisation_champion(FILE *fichier, Champion *champion) { //fonction pour initialiser un champion
    printf(ROUGE_FONCE);
    if (!fichier || !champion){
        printf("erreur lors de l'allocation de la memoire\n");
        free_champion(champion);
        exit(0);
    }
    int pv_max = 0, pv = 0, attaque = 0, defense = 0, agilite = 0, vitesse = 0, jauge_actuelle = 0, jauge_max = 0;
    char nom[50], classe[50], attaque_spe[50], effet_spe[50],  description_attaquespe[100],description[100];

    // Lecture des stats dans le fichier du champion
    sauter_ligne(fichier);
    if (fscanf(fichier, "%s", nom) != 1) {
        printf("Erreur lors de la lecture du nom\n");
        free_champion(champion);
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &pv) != 1) {
        printf("Erreur lors de la lecture des PV\n");
        free_champion(champion);
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &pv_max) != 1) {
        printf("Erreur lors de la lecture des PV max\n");
        free_champion(champion);
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &attaque) != 1) {
        printf("Erreur lors de la lecture de l'attaque\n");
        free_champion(champion);
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &defense) != 1) {
        printf("Erreur lors de la lecture de la défense\n");
        free_champion(champion);
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &agilite) != 1) {
        printf("Erreur lors de la lecture de l'agilité\n");
        free_champion(champion);
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &vitesse) != 1) {
        printf("Erreur lors de la lecture de la vitesse\n");
        free_champion(champion);
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &jauge_actuelle) != 1) {
        printf("Erreur lors de la lecture de la jauge\n");
        free_champion(champion);
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%d", &jauge_max) != 1) {
        printf("Erreur lors de la lecture de la jauge max\n");
        free_champion(champion);
        exit(1);
    }
   
    sauter_ligne(fichier);
    if (fscanf(fichier, "%s", attaque_spe) != 1) {
        printf("Erreur lors de la lecture de l'attaque speciale\n");
        free_champion(champion);
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%s", classe) != 1) {
        printf("Erreur lors de la lecture de la classe\n");
        free_champion(champion);
        exit(1);
    }
    sauter_ligne(fichier);
    if (fscanf(fichier, "%s", effet_spe) != 1) {
        printf("Erreur lors de la lecture de l'effet spécial\n");
        free_champion(champion);
        exit(1);
    }
   

    // Mise à jour des stats du champion
    champion->pv_max = pv_max;
    champion->stat.pv_courant = pv;
    champion->stat.defense = defense;
    champion->stat.attaque = attaque;
    champion->stat.agilite = agilite;
    champion->stat.vitesse = vitesse;
    champion->stat.jauge_max = jauge_max;
    champion->stat.jauge_actuelle = jauge_actuelle;


    // Allocation dynamique et copie des chaînes de caractères
    champion->nom = malloc(strlen(nom) + 1);
    if (champion->nom == NULL) {
        printf("Erreur d'allocation de memoire pour le nom\n");
        free_champion(champion);
        exit(1);
    }
    strcpy(champion->nom, nom);

    champion->classe = malloc(strlen(classe) + 1);
    if (champion->classe == NULL) {
        printf("Erreur d'allocation de memoire pour la classe\n");
        free_champion(champion);
        exit(1);
    }
    strcpy(champion->classe, classe);

    champion->attaque_spe = malloc(strlen(attaque_spe) + 1);
    if (champion->attaque_spe == NULL) {
        printf("Erreur d'allocation de mémoire pour l'attaque spéciale\n");
        free_champion(champion);
        exit(1);
    }
    strcpy(champion->attaque_spe, attaque_spe);

    champion->effet_spe = malloc(strlen(effet_spe) + 1);
    if (champion->effet_spe == NULL) {
        printf("Erreur d'allocation de mémoire pour l'effet spécial\n");
        free_champion(champion);
        exit(1);
    }
    strcpy(champion->effet_spe, effet_spe);
    
    champion->description = malloc(strlen(description) + 1);
    if (champion->description == NULL) {
        printf("Erreur d'allocation de mémoire pour la description\n");
        free_champion(champion);
        exit(1);
    }
    strcpy(champion->description, description);
    printf(RESET);
    champion->description_attaque_spe = malloc(strlen(description_attaquespe) + 1);
    if (champion->description_attaque_spe == NULL) {
        printf("Erreur d'allocation de mémoire pour la description de l'attaque spéciale\n");
        free_champion(champion);
        exit(1);
    }
}

int chaine_caractere_egales(char *chaine1, char *chaine2){ // compzre les chaines de caracteres on utilise strcmp apres

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


int trie (Champion *champion){ // fonction pour trier les champions par classe
    if (!champion || !champion->nom){
        printf(ROUGE_FONCE"erreur lors de l'alocation de la memoire\n");
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
    printf("RESET");
}


int ordre_classe(const char *classe) { // identique a trie mais renvoie plus robuste
    if (!classe){
        printf(ROUGE_FONCE"erreur lors de l'alocation de la memoire\n"RESET);
        exit(0);
    }
    if (strcmp(classe, "tank") == 0) return 1;
    if (strcmp(classe, "dps") == 0) return 2;
    if (strcmp(classe, "soutien") == 0) return 3;
    return 4; // Classe inconnue ou autre
}

int comparer_par_classe(const void *a, const void *b) { // Fonction de comparaison pour qsort (fait avec l'IA), trie de facon arbitraire en fonction de la classe
    if (!a || !b){
        printf(ROUGE_FONCE"erreur lors de l'allocation de la memoire\n"RESET);
        exit(0);
    }
    Champion *champion1 = (Champion *)a;
    Champion *champion2 = (Champion *)b;

    // Définir un ordre pour les classes
    

    return ordre_classe(champion1->classe) - ordre_classe(champion2->classe);
}

void classe_champion(Champion *tab, Champion *tab_soutien, Champion *tab_tank, Champion *tab_dps, int *soutien_count, int *tank_count, int *dps_count, Champion *temp) { // Fonction pour trier les champions par classe
    if(!tab ||!tab_soutien || !tab_tank || !tab_dps || !soutien_count ||!tank_count || !dps_count  || !temp){
        printf(ROUGE_FONCE"erreur lors de l'allocation de la memoire\n"RESET);
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

void copie_champion(Champion *source, Champion *destination) { // Fonction pour copier un champion
    printf(ROUGE_FONCE);
    if (!source || !destination) {
        printf("Erreur : pointeur NULL passé à copie_champion\n");
        exit(0);
    }

    // Initialiser les pointeurs de destination à NULL
    destination->nom = NULL;
    destination->classe = NULL;
    destination->attaque_spe = NULL;
    destination->effet_spe = NULL;
    destination->description = NULL;
    destination->description_attaque_spe = NULL;

    // Copier les champs simples
    destination->pv_max = source->pv_max;
    destination->stat.pv_courant = source->stat.pv_courant;
    destination->stat.defense = source->stat.defense;
    destination->stat.attaque = source->stat.attaque;
    destination->stat.agilite = source->stat.agilite;
    destination->stat.vitesse = source->stat.vitesse;
    destination->stat.jauge_max = source->stat.jauge_max;
    destination->stat.jauge_actuelle = source->stat.jauge_actuelle;

    // Copier les chaînes de caractères avec allocation dynamique
    if (source->nom != NULL) {
        destination->nom = malloc(strlen(source->nom) + 1);
        if (destination->nom == NULL) {
            printf("Erreur d'allocation mémoire pour le nom\n");
            exit(1);
        }
        strcpy(destination->nom, source->nom);
    }

    if (source->classe != NULL) {
        destination->classe = malloc(strlen(source->classe) + 1);
        if (destination->classe == NULL) {
            printf("Erreur d'allocation mémoire pour la classe\n");
            exit(1);
        }
        strcpy(destination->classe, source->classe);
    }

    if (source->attaque_spe != NULL) {
        destination->attaque_spe = malloc(strlen(source->attaque_spe) + 1);
        if (destination->attaque_spe == NULL) {
            printf("Erreur d'allocation mémoire pour l'attaque spéciale\n");
            exit(1);
        }
        strcpy(destination->attaque_spe, source->attaque_spe);
    }

    if (source->effet_spe != NULL) {
        destination->effet_spe = malloc(strlen(source->effet_spe) + 1);
        if (destination->effet_spe == NULL) {
            printf("Erreur d'allocation mémoire pour l'effet spécial\n");
            exit(1);
        }
        strcpy(destination->effet_spe, source->effet_spe);
    }

    if (source->description != NULL) {
        destination->description = malloc(strlen(source->description) + 1);
        if (destination->description == NULL) {
            printf("Erreur d'allocation mémoire pour la description\n");
            exit(1);
        }
        strcpy(destination->description, source->description);
    }

    if (source->description_attaque_spe != NULL) {
        destination->description_attaque_spe = malloc(strlen(source->description_attaque_spe) + 1);
        if (destination->description_attaque_spe == NULL) {
            printf("Erreur d'allocation mémoire pour la description de l'attaque spéciale\n");
            exit(1);
        }
        strcpy(destination->description_attaque_spe, source->description_attaque_spe);
    }

    printf(RESET);
}

int verif_number(int number[],int n){ // verifie si un nombre est deja dans le tableau
        if (number[n-1] == 1){
            return 1;
        }
    return 0;
}

void choix_des_champion(Champion *tableau_champion, Equipe *equipe1, Equipe *equipe2, int choix, Champion *tableau_champion_cachee) { // choix des champions
    if (!tableau_champion || !tableau_champion_cachee || !equipe1 || !equipe2 || !equipe1->nom || !equipe2->nom) {
        printf(ROUGE_FONCE"Erreur lors de l'allocation de la mémoire\n"RESET);
        exit(0);
    }

    int tempp;
    int rep[18 + 3] = {0}; // Tableau pour suivre les numéros choisis (18 champions normaux + 3 cachés)
    printf(ROUGE);
    printf("Lors de la selection, si vous saisissez un nombre avec un caractere non valide, le programme recupera le nombre\n");
    printf(RESET);
    if (choix == 2) {
        // Sélection pour l'équipe 1
        printf(BLANC_FONCE"\nEquipe 1, choisissez vos champions\n"RESET);
        for (int i = 0; i < Nb_champion_par_equipe; i++) {
            tempp = -1; // Initialisation à une valeur invalide
            do {
                printf(BLANC_FONCE"Champion %d : "RESET, i + 1);
                if (scanf("%d", &tempp) != 1) {
                    printf(GRIS"Entrée invalide. Veuillez entrer un nombre entre 1 et 18 \n"RESET);
                    vider_buffer_scanf(); // Vide le buffer d'entrée
                    tempp = -1; // Réinitialise tempp pour rester dans la boucle
                } else if ((tempp < 1 || tempp > 18) && (tempp < 100 || tempp > 102)) {
                    printf(ROUGE_FONCE"Numéro invalide. Veuillez entrer un nombre entre 1 et 18\n"RESET);
                    tempp = -1;
                } else if (verif_number(rep, tempp)) { // Vérifie si le numéro est déjà choisi
                    printf(ROUGE_FONCE"Ce champion est déjà choisi. Veuillez en choisir un autre.\n"RESET);
                    tempp = -1;
                }
            } while (tempp == -1);

            // Ajouter le numéro choisi au tableau de suivi
            rep[tempp-1] = 1;

            // Copier le champion sélectionné dans l'équipe
            if (tempp >= 1 && tempp <= 18) {
                copie_champion(&tableau_champion[tempp - 1], &equipe1->perso[i]);
                equipe1->perso[i].equipe = 1;
                equipe1->perso[i].index = i;
            } else if (tempp >= 100 && tempp <= 102) {
                copie_champion(&tableau_champion_cachee[tempp - 100], &equipe1->perso[i]);
                equipe1->perso[i].equipe = 1;
                equipe1->perso[i].index = i;
                printf(VERT"Bravo ! Vous avez trouvé un champion caché :D\n");
            }
        }

        // Sélection pour l'équipe 2
        printf(BLANC_FONCE"\nEquipe 2, choisissez vos champions\n"RESET);
        for (int i = 0; i < Nb_champion_par_equipe; i++) {
            tempp = -1; // Initialisation à une valeur invalide
            do {
                printf(BLANC_FONCE"Champion %d : "RESET, i + 1);
                if (scanf("%d", &tempp) != 1) {
                    printf(GRIS"Entrée invalide. Veuillez entrer un nombre entre 1 et 18 \n"RESET);
                    vider_buffer_scanf(); // Vide le buffer d'entrée
                    tempp = -1; // Réinitialise tempp pour rester dans la boucle
                } else if ((tempp < 1 || tempp > 18) && (tempp < 100 || tempp > 102)) {
                    printf(GRIS"Numéro invalide. Veuillez entrer un nombre entre 1 et 18 \n"RESET);
                    tempp = -1;
                } else if (verif_number(rep, tempp)) { // Vérifie si le numéro est déjà choisi
                    printf(GRIS"Ce champion est déjà choisi. Veuillez en choisir un autre.\n"RESET);
                    tempp = -1;
                }
            } while (tempp == -1);

            // Ajouter le numéro choisi au tableau de suivi
            rep[tempp-1] = 1;

            // Copier le champion sélectionné dans l'équipe
            if (tempp >= 1 && tempp <= 18) {
                copie_champion(&tableau_champion[tempp - 1], &equipe2->perso[i]);
                equipe2->perso[i].equipe = 2;
                equipe2->perso[i].index = i;
            } else if (tempp >= 100 && tempp <= 102) {
                copie_champion(&tableau_champion_cachee[tempp - 100], &equipe2->perso[i]);
                equipe2->perso[i].equipe = 2;
                equipe2->perso[i].index = i;
                printf(VERT"Bravo ! Vous avez trouvé un champion caché :D\n"RESET);
            }
        }
    } else if (choix == 1) {
        // Sélection pour l'équipe 1
        printf(BLANC_FONCE"\nEquipe 1, choisissez vos champions\n"RESET);
        for (int i = 0; i < Nb_champion_par_equipe; i++) {
            tempp = -1; // Initialisation à une valeur invalide
            do {
                printf(BLANC_FONCE"Champion %d : "RESET, i + 1);
                if (scanf("%d", &tempp) != 1) {
                    printf(GRIS"Entrée invalide. Veuillez entrer un nombre entre 1 et 18\n"RESET);
                    vider_buffer_scanf(); // Vide le buffer d'entrée
                    tempp = -1; // Réinitialise tempp pour rester dans la boucle
                } else if ((tempp < 1 || tempp > 18) && (tempp < 100 || tempp > 102)) {
                    printf(GRIS"Numéro invalide. Veuillez entrer un nombre entre 1 et 18 \n"RESET);
                    tempp = -1;
                } else if (verif_number(rep, tempp)) { // Vérifie si le numéro est déjà choisi
                    printf(GRIS"Ce champion est déjà choisi. Veuillez en choisir un autre.\n"RESET);
                    tempp = -1;
                }
            } while (tempp == -1);

            // Ajouter le numéro choisi au tableau de suivi
            rep[tempp-1] = 1;

            // Copier le champion sélectionné dans l'équipe
            if (tempp >= 1 && tempp <= 18) {
                copie_champion(&tableau_champion[tempp - 1], &equipe1->perso[i]);
                equipe1->perso[i].equipe = 1;
                equipe1->perso[i].index = i;
            } else if (tempp >= 100 && tempp <= 102) {
                copie_champion(&tableau_champion_cachee[tempp - 100], &equipe1->perso[i]);
                equipe1->perso[i].equipe = 1;
                equipe1->perso[i].index = i;
                printf(VERT"Bravo ! Vous avez trouvé un champion caché\n"RESET);
            }
        }

        // Sélection automatique pour l'équipe 2 (IA)
        choix_champion_IA(tableau_champion, equipe2, rep);
    }
}

void choix_champion_IA(Champion *tableau_champion, Equipe *equipe2, int rep[]){
    if (!tableau_champion || !equipe2 ||! equipe2->nom || !rep){
        printf(ROUGE_FONCE"erreur lors de l'allocation de la memoire\n"RESET);
        exit(0);
    } 
    if (equipe2->difficulte == 0){
        for (int i=0;i<Nb_champion_par_equipe;i++){
            int x = rand()%17+1;
            do{
                x = rand()%17+1;
            }while(verif_number(rep, x) != 0);
            copie_champion((tableau_champion+x), &equipe2->perso[i]);  // choix des champions aléatoirement
            equipe2->perso[i].equipe = 2; // Assigner l'équipe 2 au champion
            equipe2->perso[i].index = i+2;
            rep[x-1] = 1;
        }
    }
    else if (equipe2->difficulte == 1 || equipe2->difficulte == 2){
            int tank_choisi = 0, dps_choisi = 0, soutien_choisi = 0;

        for (int i = 0; i < Nb_champion_par_equipe; i++) {
            int index = -1;

            // Choisir un champion en fonction des classes manquantes
            do {
                index = rand() % 18; // Supposons qu'il y a 18 champions dans le tableau
            } while (verif_number(rep, index + 1) != 0 || 
                    (tank_choisi && strcmp(tableau_champion[index].classe, "tank") == 0) ||
                    (dps_choisi && strcmp(tableau_champion[index].classe, "dps") == 0) ||
                    (soutien_choisi && strcmp(tableau_champion[index].classe, "soutien") == 0));

            // Copier le champion sélectionné dans l'équipe
            copie_champion(&tableau_champion[index], &equipe2->perso[i]);
            equipe2->perso[i].equipe = 2; // Assigner l'équipe 2 au champion
            equipe2->perso[i].index = i + 2;
            rep[index] = 1; // Marquer le champion comme choisi

            // Mettre à jour les classes choisies
            if (strcmp(tableau_champion[index].classe, "tank") == 0) {
                tank_choisi = 1;
            } else if (strcmp(tableau_champion[index].classe, "dps") == 0) {
                dps_choisi = 1;
            } else if (strcmp(tableau_champion[index].classe, "soutien") == 0) {
                soutien_choisi = 1;
            }
        }
    }
}

int longueur_nom_max(Champion *champions, int taille) {
    if (!champions || !champions->nom){
        printf(ROUGE_FONCE"erreur lors de l'allocation de la memoire\n"RESET);
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


void saisie_utilisateur(Champion *champion, Equipe *equieAdverse, Equipe *equipe) { // demande à l'utilisateur les actions à faire
    if (!champion || !equieAdverse || !equieAdverse->nom || !champion->nom) {
        printf(ROUGE_FONCE"Erreur lors de l'allocation de la mémoire\n"RESET);
        exit(0);
    }

    // Vérification des PV du champion
    if (champion->stat.pv_courant <= 0) {
        printf(ROUGE_FONCE"Le champion %s est KO et ne peut pas agir.\n"RESET, champion->nom);
        return; // Sort de la fonction sans effectuer d'action
    }
 switch (affichage_saisie_utilisateur(*champion)) {
        case 1:
            attaquesimple(champion, equieAdverse->perso); // attaque simple
            champion->stat.jauge_actuelle += 1; // augmente la jauge de l'attaque speciale
            if (champion->stat.jauge_actuelle > champion->stat.jauge_max) {
                champion->stat.jauge_actuelle = champion->stat.jauge_max; // limite la jauge a la jauge max
            }
            break;
        case 2:
            attaqueSpecial(*champion, equieAdverse->perso, equipe->perso); // attaque spéciale
            champion->stat.jauge_actuelle = 0; // remet la jauge a 0
            break;
        default: // passer son tour
            printf(GRIS"%s passe son tour.\n"RESET, champion->nom);
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
        return 1; // vrai
    }
    else{
        printf(ROUGE_FONCE"erreur de PV dans est_en_vie\n"RESET);
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
            sleep(milliseconds / 1000); // Convertit les millisecondes en secondes
        }   
#endif
