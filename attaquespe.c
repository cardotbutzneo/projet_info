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
        attaquesimple(champion, equipe2.perso);
        break;
    case 2:
        printf("fonction pas encore definie\n");
        break;
    case 3:
        printf("fonction pas encore definie\n");
    default:
        break;
    }

}


