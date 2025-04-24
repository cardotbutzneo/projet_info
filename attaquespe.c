#include "en-tete.h"



void attaqueSpecial (Champion personnage, Champion equipeAdverse){
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
        DonkeySpe(personnage, equipeAdverse);
    default:
        break;
    case 4:
        TenmaSpe(personnage, equipeAdverse);
        break;
    case 5:
        GandalfSpe(personnage, equipeAdverse);
        break;
    case 6:
        GolemSpe(personnage, equipeAdverse);
        break;
    case 7:
        InvaderSpe(personnage, equipeAdverse);
        break;
    case 8:
        ItachiSpe(personnage, equipeAdverse);
        break;
    case 9:
        JackSpe(personnage, equipeAdverse);
        break;
    case 10:
        JaySpe(personnage, equipeAdverse);
        break;
    case 11:
        JohnnySpe(personnage, equipeAdverse);
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
        break;
    }
}

void amongusSpe (Champion personnage, Champion equipeAdverse){

}


