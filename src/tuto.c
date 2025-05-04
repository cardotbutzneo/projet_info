#include "en-tete.h"
#include "tuto.h"
void afficher_tuto(){
    printf("Bienvenue \n");
    printf("Vous jouerez à MultiverSus\n");
    char rep;
    printf("Connaissez-vous le jeu ? o/n\n");
    scanf("%c",rep);
    if (rep == 'n'){
        printf("Vous jouez à un jeu développé par l'équipe I\n");
        printf("Le jeu se joue au tour par tour\n");
        printf("Dans un premier temps vous choisirez vos champions, puis combattrez !");
        printf("La première equipe qui vainc les champions ennemis gagne !");
    }


}

void note(){
    printf("Avez-vous aimé le jeu ?\n");
    int note;
    do{
        scanf("%d",&note);
    }while(note<0 || note > 10);
    if (note >= 8){
        printf("Merci beaucoup !\n");
    }
}
