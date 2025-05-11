#include "en-tete.h"
#include "fonction.h"
#include "affichage.h"
#include "couleurs.h"



int nbTank(Champion Equipe[]) {//compte le nombre de tank dans l'equipe
    if (!Equipe) {
        printf(ROUGE_FONCE"Erreur lors de l'allocation de la mémoire\n"RESET);
        exit(0);
    }
    int nombre = 0;
    for (int i = 0; i < Nb_champion_par_equipe; i++) {
        if (Equipe[i].classe != NULL && strcmp(Equipe[i].classe, "tank") == 0 && Equipe[i].stat.pv_courant > 0) {
            nombre++;
        }
    }
    return nombre;
}

int cibleAttaque(Champion Equipe[]) {//choisit la cible de l'attaque
    if (!Equipe) {
        printf(ROUGE_FONCE"Erreur lors de l'allocation de la mémoire\n"RESET);
        exit(0);
    }

    int cible = -1; // Initialise cible à -1 pour indiquer qu'aucune cible n'a été trouvée
    float vitesse_min = 20; // Initialise à une valeur maximale pour trouver le plus lent

    // Si aucun tank n'est présent, cible le personnage le plus lent
    if (nbTank(Equipe) == 0) {
        for (int i = 0; i < Nb_champion_par_equipe; i++) {
            if (est_en_vie(Equipe[i]) && Equipe[i].stat.vitesse < vitesse_min) {
                vitesse_min = Equipe[i].stat.vitesse;
                cible = i;
            }
        }
        return cible; // Retourne le plus lent
    }

    // Si un seul tank est présent, cible ce tank
    if (nbTank(Equipe) == 1) {
        for (int i = 0; i < Nb_champion_par_equipe; i++) {
            if (strcmp(Equipe[i].classe, "tank") == 0 && est_en_vie(Equipe[i])) {
                return i;
            }
        }
    }

    // Si plusieurs tanks sont présents, cible le tank le plus lent
    if (nbTank(Equipe) > 1) {
        for (int i = 0; i < Nb_champion_par_equipe; i++) {
            if (strcmp(Equipe[i].classe, "tank") == 0 && est_en_vie(Equipe[i]) && 
                (cible == -1 || Equipe[i].stat.vitesse < Equipe[cible].stat.vitesse)) {
                cible = i;
            }
        }
        return cible;
    }

    return -1; // Retourne -1 si aucune cible valide n'est trouvée
}

float degat(Champion personnage){//calcule les degats
    return personnage.stat.attaque;
}

void attaquesimple (Champion *personnage, Champion equipeAdverse[]){//actualiser la vie des personnage apres une attaque classique
    if (!personnage || !equipeAdverse){
        printf("erreur d'allocation de memoire");
        exit(0);
    }
    int precision=0;
    precision=rand()%101;
    int cible=cibleAttaque(equipeAdverse);
    if (equipeAdverse[cible].stat.pv_courant <= 0 || personnage->stat.pv_courant <= 0){
        return;
    }
    if (precision>equipeAdverse[cible].stat.agilite){//si l'attaque touche
        if (equipeAdverse[cible].stat.defense == 0){//verifie que la defense n'est pas nulle pour eviter la division par 0
            printf(GRIS"division par 0 dans attaquesimple\n"RESET);
            exit(2);
        }
        equipeAdverse[cible].stat.pv_courant-=(degat(*personnage)-(equipeAdverse[cible].stat.defense)/100);//actualise les pv de l'adversaire
        if (equipeAdverse[cible].stat.pv_courant <=1){
            equipeAdverse[cible].stat.pv_courant = 0;
        }
        printf(ROUGE"%s attaque >:)\n" RESET,personnage->nom);
        afficher_degat_recu(equipeAdverse[cible],*personnage,0);
    }
    else{
        printf(CYAN "%s esquive\n" RESET,equipeAdverse[cible].nom);
        printf("Attaque ratée :p\n");
    }
}
