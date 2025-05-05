#include "en-tete.h"
#include "fonction.h"
#include "attaque.h"
#include "affichage.h"

void amongusSpe (Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque(equipeAdverse);
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    equipeAdverse[cible].stat.defense-=4;
}
void captainSpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    personnage.stat.defense += 4;
}

void donkeySpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void tenmaSpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void gandalfSpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void golemSpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void invaderSpe(Champion personnage, Champion equipeAdverse[]){
    for (int i=0;i<3;i++){
        equipeAdverse[i].stat.vitesse-=3;
    }
}

void itachiSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void jackSpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void jaySpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void johnnySpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void neteroSpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void noxSpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void picsouSpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void pierreSpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void shrekSpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void tuxSpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

void zeldaSpe(Champion personnage, Champion equipeAdverse[]){
    printf("%s utilise %s",personnage.nom,personnage.attaque_spe);
    int cible = cibleAttaque(equipeAdverse);
    equipeAdverse[cible].stat.defense -= 4;
}

int soinCible (Champion equipe[]){
    int cible = 0;
    float min=equipe[0].stat.pv_courant;
    for (int i=0;i<Nb_champion_par_equipe;i++){
        if (equipe[i].stat.pv_courant<min){
            cible=i;
        }
    }
    return cible;
}

void attaqueSpecial (Champion personnage, Champion equipeAdverse[]){
    int numero=0;
    char *tab_nom[Nb_champion] = {"Among_us", "Captain_america","Donkey_Kong", "Dr_Tenma", "Gandalf", "Golem_de_fer", "Invader", "Itachi", "Jack_Frost", "Jay", "Johnny_Hallyday", "Netero", "Nox", "Picsou", "Pierre_Chartier", "Shrek", "Tux","Zelda"};
    for (int i=0; i<Nb_champion;i++){
        if (tab_nom[i]==personnage.nom){
            numero=i+1;
        }
    }
    switch (numero)
    {
    case 1:
        amongusSpe(personnage, equipeAdverse);
        break;
    case 2:
        captainSpe(personnage, equipeAdverse);
        break;
    case 3:
        donkeySpe(personnage, equipeAdverse);
        break;
    case 4:
        tenmaSpe(personnage, equipeAdverse);
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
        itachiSpe(personnage, equipeAdverse);
        break;
    case 9:
        jackSpe(personnage, equipeAdverse);
        break;
    case 10:
        jaySpe(personnage, equipeAdverse);
        break;
    case 11:
        johnnySpe(personnage, equipeAdverse);
        break;
    case 12:
        neteroSpe(personnage, equipeAdverse);
        break;
    case 13:
        noxSpe(personnage, equipeAdverse);
        break;
    case 14:
        picsouSpe(personnage, equipeAdverse);
        break;
    case 15:
        pierreSpe(personnage, equipeAdverse);
        break;
    case 16:
        shrekSpe(personnage, equipeAdverse);
        break;
    case 17:
        tuxSpe(personnage, equipeAdverse);
        break;
    case 18:
        zeldaSpe(personnage, equipeAdverse);
        default:
            break;
    }
}


