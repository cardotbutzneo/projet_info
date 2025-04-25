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
*/
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

int nbTank(Champion Equipe[]){
    int nombre;
    for(int i=0;i<3;i++){
        if (Equipe[i].classe=="tank"){
            nombre+=1;
        }
    }
    return nombre;
}

int cibleAttaque(Champion Equipe[]){
    int cible=0;
    if (nbTank(Equipe)==0){//si il n'y a pas de tank l'attaque cible l'adversaire le plus lent
        for(int i=0;i<3;i++){
            if (Equipe[i].stat.vitesse<Equipe[cible].stat.vitesse){
                cible=i;
            }
        }
    return cible; 
    }
    if (nbTank(Equipe)==1){//si il n'y qu'un seul tank l'attaque cible le tank
        for(int i=0;i<3;i++){
            if (Equipe[i].classe=="tank"){
                return i;
            }
        } 
    }
    if (nbTank(Equipe)>1){//si il y a plusieurs tanks l'attaque cible le tank le plus lent
        if(Equipe[cible].classe!="tank"){//si le premier champion n'est pas un tank on selectionne le suivant
            cible=1;
        }
        for(int i=0;i<3;i++){
            if (Equipe[i].classe=="tank" && Equipe[i].stat.vitesse<Equipe[cible].stat.vitesse){
                cible = i;
            }
        }
        return cible;
    }
}

float degat(Champion personnage){//calcule les degats
    return personnage.stat.attaque;
}

void attaquesimple (Champion *personnage, Champion equipeAdverse[]){//actualiser la vie des personnage apres une attaque classique
    int precision=0;
    precision=rand()%101;
    int cible=cibleAttaque(equipeAdverse);
    if (precision>equipeAdverse[cible].stat.agilite){//si l'attaque touche actualise les pv en prenant en compte la defense
        if (equipeAdverse[cible].stat.defense == 0){
            exit(2);
        }
        equipeAdverse[cible].stat.pv_courant-=(degat(*personnage)/(equipeAdverse[cible].stat.defense)/100);
        printf("%s attaque : \n",personnage->nom);
        afficher_degat_recu(equipeAdverse[cible],*personnage,0);
    }
    else{
        printf("%s esquive\n",personnage->nom);
        printf("Attaque ratée\n");
    }
}


