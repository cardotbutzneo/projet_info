#include "en-tete.h"


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
int nbTank(Champion Equipe[]){
    int nombre;
    for(int i=0;i<3;i++){
        if (Equipe[i].classe==Tank){
            nombre+=1;
        }
    }
    return nombre;
}

int cibleAttaque(Champion Equipe[]){
    int cible=0;
    if (nbTank==0){//si il n'y a pas de tank l'attaque cible l'adversaire le plus lent
        for(int i=0;i<3;i++){
            if (Equipe[i].stat.vitesse<Equipe[cible].stat.vitesse){
                cible=i;
            }
        }
    return cible; 
    }
    if (nbTank==1){//si il n'y qu'un seul tank l'attaque cible le tank
        for(int i=0;i<3;i++){
            if (Equipe[i].classe==Tank){
                return i;
            }
        } 
    }
    if (nbTank>1){//si il y a plusieurs tanks l'attaque cible le tank le plus lent
        if(Equipe[cible].classe!=Tank){//si le premier champion n'est pas un tank on selectionne le suivant
            cible=1;
        }
        for(int i=0;i<3;i++){
            if (Equipe[i].classe==Tank && Equipe[i].stat.vitesse<Equipe[cible].stat.vitesse){
                cible = i;
            }
        }
        return cible;
    }
}

float degat(Champion personnage){//calcule les degats
    return personnage.stat.attaque;
}

void attaquesimple (Champion personnage, Equipe equipeAdverse[]){//actualiser la vie des personnage apres une attaque classique
    int precision;
    int cible=cibleAttaque(equipeAdverse[]);
    if (precision>equipeAdverse[cible].stat.agilite){//si l'attaque touche actualise les pv en prenant en compte la defense
        equipeAdverse[cible].stat.pvactuel-=(degat(personnage)/(equipeAdverse[cible].stat.defense)/100);
    }
    else{
        printf("l attaque a ete esquive");
    }
}



}

