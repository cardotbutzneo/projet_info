#include "en-tete.h"


void initialisation_champion(FILE *fichier, Champion *champion){

    int pv_max, pv, attaque,defense,agilite, vitesse;
    // lecture des stats dans le fichier du champion
    sauter_ligne(fichier);
    sauter_ligne(fichier);
    fscanf(fichier, "%d", &pv);
    sauter_ligne(fichier);
    fscanf(fichier, "%d", &pv_max);
    sauter_ligne(fichier);
    fscanf(fichier, "%d", &attaque);
    sauter_ligne(fichier);
    fscanf(fichier, "%d", &defense);
    sauter_ligne(fichier);
    fscanf(fichier, "%d", &agilite);
    sauter_ligne(fichier);
    fscanf(fichier, "%d", &vitesse);

    // mise à jour des stats du champion

    champion->pv_max = pv_max;
    champion->stat.pv_courant = pv;
    champion->stat.defense = defense;
    champion->stat.attaque = attaque;
    champion->stat.agilite = agilite;
    champion->stat.vitesse = vitesse;

}

