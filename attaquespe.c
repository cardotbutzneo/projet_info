#include "en-tete.h"

int soinCible (Champion equipe[]){
    int cible 0;
    float min=equipe[0].stat.pv_actuel;
    for (int i=0;i<Nb_champion_par_equipe;i++){
        if (equipe[i].stat.pv_actuel<min){
            cible=i;
        }
    }
}

void attaqueSpecial (Champion personnage, Champion equipeAdverse[]){
    int numero=0;
    char tab_nom[Nb_champion] = {"Among us", "Captain america","Donkey Kong", "Dr Tenma", "Gandalf", "Golem de fer", "Invader", "Itachi", "Jack Frost", "Jay", "Johnny Hallyday", "Netero", "Nox", "Picsou", "Pierre Chartier", "Shrek", "Tux","Zelda"};
    for (int i=0; i<Nb_champion;i++){
        if (tab[i]==personnage.nom){
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

void amongusSpe (Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense-=4;
}
void captainSpe(Champion personnage, Champion equipeAdverse[]){
    personnage.stat.defense += 4;
}

void donkeySpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void tenmaSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void gandalfSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void golemSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void invaderSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void itachiSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void jackSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void jaySpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void johnnySpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void neteroSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void noxSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void picsouSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void pierreSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void shrekSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void tuxSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

void zeldaSpe(Champion personnage, Champion equipeAdverse[]){
    int cible = cibleAttaque[equipeAdverse];
    equipeAdverse[cible].stat.defense -= 4;
}

