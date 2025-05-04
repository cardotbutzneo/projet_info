#include "en-tete.h"
#include "tuto.h"
#include "affichage.h"
#include "fonction.h"
void afficher_tuto(){
    printf("Bienvenue \n");
    printf("Vous jouez a MultiverSus\n");
    char rep;
    printf("Connaissez-vous le jeu ? o/n\n");
    int verif = -1;
    do{
        verif = scanf("%c",&rep);
        if (verif != 1 ){
            printf("entree invalide !\n");
            verif = -1;   
            vider_buffer_scanf();
        }
    }while(verif != 1 || (rep != 'o' && rep != 'n'));

    if (rep == 'n'){
        printf("Vous jouez a un jeu developpe par l'équipe I\n");
        printf("Le jeu se joue au tour par tour\n");
        printf("Choisisez vos champions, puis... ");
        Sleep(type_os(0)*3);
        printf("combattrez !");
        printf("La première equipe qui vainc les champions ennemis gagne !\n");
    }


}

void note(){
    printf("Avez-vous aimé le jeu ? (/10)\n");
    int note;
    do{
        scanf("%d",&note);
        vider_buffer_scanf();
    }while(note<0 || note > 10);
    if (note >= 8){
        printf("Merci beaucoup !\n");
    }
}
