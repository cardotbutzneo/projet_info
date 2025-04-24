#include "en-tete.h"


void attaqueSpecial (Champion personnage, Champion equipeAdverse){
    switch (affichage_saisie_utilisateur(champion))
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
