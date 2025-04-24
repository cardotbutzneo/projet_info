#include "en-tete.h"

void afficher_tuto(){
    printf("Bienvenu \n");
    printf("Vous jourez à MultiverSus\n");
    char rep;
    printf("connaissez-vous le jeu ? o/n\n");
    scanf("%c",rep);
    if (rep == 'n'){
        printf("Vous jouez à un jeu developper par l'equipe I\n");
        printf("Le jeu se joue au tour par tour\n");
        printf("Dans un premier temps vous choisiez vos champions, puis combatez !");
        printf("La premiere equipe qui vaint les champions enemies gagne !");
    }


}

void note(){
    printf("Avez vous aimez le jeu ?\n");
    int note;
    do{
        scanf("%d",&note);
    }while(note<0 || note > 10);
    if (note >= 8){
        printf("Merci beaucoup !\n");
    }
}