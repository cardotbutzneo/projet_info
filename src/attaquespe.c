#include "en-tete.h"
#include "fonction.h"
#include "attaque.h"
#include "affichage.h"
#include "stat.h"


int soinCible (Champion equipe[]){//choisit la cible du soin
    int cible = 0;
    float min = 0;
    for (int i=0;i<Nb_champion_par_equipe;i++){
        if(vivant(equipe[i])==0){
            min=equipe[i].stat.pv_courant;
        }
    }
    for (int i=0;i<Nb_champion_par_equipe;i++){
        if (equipe[i].stat.pv_courant<min && vivant(equipe[i])==0){
            cible=i;
        }
    }
    return cible;
}


void soin(Champion equipe[],float puissance){//calcul du soin
    if (!equipe) {
        printf("Erreur lors de l'allocation de la mémoire\n");
        exit(28);
    }
    equipe[soinCible(equipe)].stat.pv_courant+=puissance;
}

float attaqueSpeDegat (Champion personnage, Champion equipeAdverse[],float puissance){
    float degats;
    int cible = cibleAttaque(equipeAdverse);
    degats=((personnage.stat.attaque*puissance)*(equipeAdverse[cible].stat.defense/100));
    return degats;
}




void amongusSpe (Champion personnage, Champion equipeAdverse[]){//attaque spéciale de Among Us
    int cible = cibleAttaque(equipeAdverse);
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    equipeAdverse[cible].stat.defense-=4;
}
void captainSpe(Champion *personnage){//attaque spéciale de Captain America
    printf("%s utilise %s\n",personnage->nom,personnage->attaque_spe);
    personnage->stat.defense += 4;
}

void donkeySpe(Champion personnage, Champion equipeAdverse[]){//attaque spéciale de Donkey Kong
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.pv_courant -= attaqueSpeDegat(personnage,equipeAdverse,2);
}

void tenmaSpe(Champion personnage, Champion equipe[]){//attaque spéciale de DR_Tenma
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    soin(equipe,40);
}

void gandalfSpe(Champion personnage, Champion equipeAdverse[]){//attaque spéciale de Gandalf
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.pv_courant -= attaqueSpeDegat(personnage,equipeAdverse,2);
}

void golemSpe(Champion personnage, Champion equipeAdverse[]){//attaque spéciale de Golem de fer
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.pv_courant -= attaqueSpeDegat(personnage,equipeAdverse,2.5);
}

void invaderSpe(Champion personnage, Champion equipeAdverse[]){//attaque spéciale de Invader
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    for (int i=0;i<Nb_champion_par_equipe;i++){
        equipeAdverse[i].stat.vitesse-=3;
    }
}

void itachiSpe(Champion *personnage){//attaque spéciale de Itachi
    printf("%s utilise %s\n",personnage->nom,personnage->attaque_spe);
    personnage->stat.defense += 2;
    personnage->stat.attaque += 2;
}

void jackSpe(Champion personnage, Champion equipeAdverse[]){//attaque spéciale de Jack Frost
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 2;
    equipeAdverse[cible].stat.pv_courant -= attaqueSpeDegat(personnage,equipeAdverse,1.5);
}

void jaySpe(Champion *personnage){//attaque spéciale de Jay
    printf("%s utilise %s\n",personnage->nom,personnage->attaque_spe);
    personnage->stat.attaque += 4;
}

void johnnySpe(Champion personnage, Champion equipeAdverse[]){//attaque spéciale de Johnny Hallyday
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    for (int i=0;i<Nb_champion_par_equipe;i++){
        equipeAdverse[i].stat.pv_courant -= attaqueSpeDegat(personnage,equipeAdverse,0.4);
    }
}

void neteroSpe(Champion personnage, Champion equipe[]){//attaque spéciale de Netero
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    for (int i=0;i<Nb_champion_par_equipe;i++){
        equipe[i].stat.defense+=3;
    }
}

void noxSpe(Champion personnage, Champion equipe[]){//attaque spéciale de Nox
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    for (int i=0;i<Nb_champion_par_equipe;i++){
        equipe[i].stat.attaque+=1;
        equipe[i].stat.agilite+=2;
    }
}

void picsouSpe(Champion personnage, Champion equipe[]){//attaque spéciale de Picsou
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    for (int i=0;i<Nb_champion_par_equipe;i++){
        equipe[i].stat.defense+=1;
    }
    soin(equipe,25);
}

void pierreSpe(Champion personnage, Champion equipeAdverse[]){//attaque spéciale de Pierre Chartier
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.pv_courant -= attaqueSpeDegat(personnage,equipeAdverse,3);
}

void shrekSpe(Champion personnage, Champion equipeAdverse[]){//attaque spéciale de Shrek
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    for (int i=0;i<Nb_champion_par_equipe;i++){
        equipeAdverse[i].stat.pv_courant -= attaqueSpeDegat(personnage,equipeAdverse,0.5);
    }
}

void tuxSpe(Champion personnage, Champion equipe[]){//attaque spéciale de Tux
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    for (int i=0;i<Nb_champion_par_equipe;i++){
        equipe[i].stat.vitesse+=0.5;
        equipe[i].stat.attaque+=1;
    }
}

void zeldaSpe(Champion personnage, Champion equipe[]){//attaque spéciale de Zelda
    printf("%s utilise %s\n",personnage.nom,personnage.attaque_spe);
    soin(equipe,25);
    for (int i=0;i<Nb_champion_par_equipe;i++){
        equipe[i].stat.vitesse+=0.5;
        equipe[i].stat.defense+=0.5;
    }    
}




void attaqueSpecial (Champion personnage, Champion equipeAdverse[],Champion equipe[]){//gere l'attaque spéciale
    int numero=0;
    char *tab_nom[Nb_champion] = {"Among_us", "Captain_America","Donkey_kong", "DR_Tenma", "Gandalf", "Golem_de_fer", "Invader", "Itachi", "Jack_Frost", "Jay", "Johnny_Hallyday", "Netero", "Nox", "Picsou", "Pierre_Chartier", "Shrek", "Tux","Zelda"};
    verifstat(personnage);
    for (int i=0; i<Nb_champion;i++){
        if (strcmp(personnage.nom,tab_nom[i])==0){
            numero=i+1;
        }
    }
    switch (numero)//on verifie le nom du personnage pour savoir quelle attaque spéciale il a
    {
    case 1:
        amongusSpe(personnage, equipeAdverse);
        break;
    case 2:
        captainSpe(&personnage);
        break;
    case 3:
        donkeySpe(personnage, equipeAdverse);
        break;
    case 4:
        tenmaSpe(personnage, equipe);
        break;
    case 5:
        gandalfSpe(personnage, equipeAdverse);
        break;
    case 6:
        golemSpe(personnage, equipeAdverse);
        break;
    case 7:
        invaderSpe(personnage, equipeAdverse);
        break;
    case 8:
        itachiSpe(&personnage);
        break;
    case 9:
        jackSpe(personnage, equipeAdverse);
        break;
    case 10:
        jaySpe(&personnage);
        break;
    case 11:
        johnnySpe(personnage, equipeAdverse);
        break;
    case 12:
        neteroSpe(personnage, equipe);
        break;
    case 13:
        noxSpe(personnage, equipe);
        break;
    case 14:
        picsouSpe(personnage, equipe);
        break;
    case 15:
        pierreSpe(personnage, equipeAdverse);
        break;
    case 16:
        shrekSpe(personnage, equipeAdverse);
        break;
    case 17:
        tuxSpe(personnage, equipe);
        break;
    case 18:
        zeldaSpe(personnage, equipe);
        break;
    default:
        printf("Attaque spé inconnue pour %s\n", personnage.nom); //si erreur
        break;
    }
}
