#include "en-tete.h"
#include "fonction.h"
#include "affichage.h"

/*
Champion ordreAttaque[6];
ordreAttaque[0]=equipe1[0];
ordreAttaque[1]=equipe1[1];
ordreAttaque[2]=equipe1[2];
ordreAttaque[3]=equipe2[0];
ordreAttaque[4]=equipe2[1];
ordreAttaque[5]=equipe2[2];

void vitesse(Champion *ordreAttaque, Champion *tableau_initial) { // Tri les champions par leur vitesse
    // Remplir ordreAttaque avec les champions de tableau_initial
    for (int i = 0; i < 6; i++) {
        copie_champion(&tableau_initial[i], &ordreAttaque[i]);
    }

    // Trier ordreAttaque par vitesse croissante
    Champion temp;
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) { // Commence à i + 1 pour éviter de comparer un élément avec lui-même
            if (ordreAttaque[i].stat.vitesse > ordreAttaque[j].stat.vitesse) {
                // Effectuer une deep copy pour échanger les éléments
                copie_champion(&ordreAttaque[i], &temp);
                copie_champion(&ordreAttaque[j], &ordreAttaque[i]);
                copie_champion(&temp, &ordreAttaque[j]);
            }
        }
    }
}
*/

int nbTank(Champion Equipe[]) {
    if (!Equipe) {
        printf("Erreur lors de l'allocation de la mémoire\n");
        exit(0);
    }
    int nombre = 0;
    
    for (int i = 0; i < Nb_champion_par_equipe; i++) {
        if (Equipe[i].classe != NULL && strcmp(Equipe[i].classe, "tank") == 0) {
            nombre++;
        }
    }
    return nombre;
}

int cibleAttaque(Champion Equipe[]) {
    if (!Equipe) {
        printf("Erreur lors de l'allocation de la mémoire\n");
        exit(0);
    }
    int cible = 0;

    if (nbTank(Equipe) == 0) { // Si il n'y a pas de tank, l'attaque cible l'adversaire le plus lent
        int flag = 0;
        int index = 0;
        for (int i=0;i<Nb_champion_par_equipe;i++){ // compte les champions en vie
            if (est_en_vie(Equipe[i]) == 1){
                flag++;
                index++;
            }
        }
        if (flag == 1){ // 1 seul champion en vie
            cible = index;
            return cible;
        }
        for (int i = 0; i < 3; i++) {
            if (Equipe[i].stat.vitesse < Equipe[cible].stat.vitesse && Equipe[i].stat.pv_courant > 0) {
                cible = i;
            }
        }
        return cible;
    }

    if (nbTank(Equipe) == 1) { // Si il n'y a qu'un seul tank, l'attaque cible le tank
        for (int i = 0; i < 3; i++) {
            if (strcmp(Equipe[i].classe, "tank") == 0 && Equipe[i].stat.pv_courant > 0) {
                return i;
            }
        }
    }

    if (nbTank(Equipe) > 1) { // Si il y a plusieurs tanks, l'attaque cible le tank le plus lent
        for (int i = 0; i < 3; i++) {
            if (strcmp(Equipe[i].classe, "tank") == 0 && Equipe[i].stat.pv_courant > 0) {
                if (Equipe[cible].stat.pv_courant <= 0 || // Si le tank actuel est mort
                    Equipe[i].stat.vitesse < Equipe[cible].stat.vitesse) { // Ou si ce tank est plus lent
                    cible = i;
                }
            }
        }
        return cible;
    }

    return -1; // Retourne -1 si aucune cible valide n'est trouvée (ne devrait pas arriver)
}

float degat(Champion personnage){//calcule les degats
    return personnage.stat.attaque;
}

void attaquesimple (Champion *personnage, Champion equipeAdverse[]){//actualiser la vie des personnage apres une attaque classique
    if (!personnage || !equipeAdverse){
        printf("erreur d'alocation de memoire");
        exit(0);
    }
    int precision=0;
    precision=rand()%101;
    int cible=cibleAttaque(equipeAdverse);
    if (equipeAdverse[cible].stat.pv_courant <= 0 || personnage->stat.pv_courant <= 0){
        return;
    }
    if (precision>equipeAdverse[cible].stat.agilite){//si l'attaque touche actualise les pv en prenant en compte la defense
        if (equipeAdverse[cible].stat.defense == 0){
            printf("division par 0 dans attaquesimple\n");
            exit(2);
        }
        equipeAdverse[cible].stat.pv_courant-=(degat(*personnage)-(equipeAdverse[cible].stat.defense)/100);
        if (equipeAdverse[cible].stat.pv_courant <=1){
            equipeAdverse[cible].stat.pv_courant = 0;
        }
        printf("%s attaque : \n",personnage->nom);
        afficher_degat_recu(equipeAdverse[cible],*personnage,0);
    }
    else{
        printf("%s esquive\n",equipeAdverse[cible].nom);
        printf("Attaque ratée\n");
    }
}


