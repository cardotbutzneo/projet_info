#include "en-tete.h"
#include "tuto.h"
#include "affichage.h"
#include "fonction.h"
#include "couleurs.h"

void afficher_tuto(){
    //printf("Bienvenue \n");
    printf(BLEU); // Changer la couleur du texte en bleu
    printf("=========================================================\n");
    printf("                 Vous jouez a MultiverSeus\n");
    printf("=========================================================\n\n");
    printf(RESET); // Réinitialiser la couleur
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
        printf("Vous jouez a un jeu developpe par l'equipe I\n\n");
        printf(BLEU); // Changer la couleur du texte en bleu
        printf("=========================================================\n");
        printf("                   Instructions du jeu\n");
        printf("=========================================================\n\n");
        printf(RESET); // Réinitialiser la couleur
        Sleep(time_sleep);
        printf("Le jeu se joue en 2 equipes de 3 champions !\n\n");
        Sleep(time_sleep);
        printf("Le but du jeu est de choisir une equipe de champions et de les faire combattre contre une autre equipe de champions !\n\n");
        Sleep(time_sleep);
        printf("Chaque champion a des statistiques et des attaques speciaux qui lui sont propres !\n\n");
        Sleep(time_sleep);
        printf("Il existe trois classes de champions :\n");
        Sleep(time_sleep);
        printf("1. Tank : ils ont beaucoup de PV et de defense, mais peu d'attaque\n");
        Sleep(time_sleep);
        printf("2. DPS : ils ont beaucoup d'attaque, mais peu de PV et de defense\n");
        Sleep(time_sleep);
        printf("3. Soutien : ils ont peu de PV et d'attaque, mais beaucoup de defense\n\n");
        Sleep(time_sleep);
        printf("Il existe aussi des synergies entre les champions... Et beaucoup d'autres surprises a decouvrir !\n\n");
        Sleep(time_sleep);
        printf("La premiere equipe qui vainc les champions ennemis gagne !\n\n");
        Sleep(time_sleep);
        printf("======================================================\n\n");
        Sleep(time_sleep);
        printf("Choisissez vos champions, puis... ");
        Sleep(time_sleep);
        printf(ROUGE "COMBATTEEEZZZZ !" RESET);
        Sleep(time_sleep);
        printf("\n\n");
    }

}

void note() {
    printf("\n======================================================\n");
    printf("            Avez-vous aimé le jeu ? (/10)\n");
    printf("=======================================================\n");

    int note;
    do {
        scanf("%d", &note);
        vider_buffer_scanf();
    } while (note < 0 || note > 10);

    if (note >= 8) {
        printf("Merci beaucoup !\n");
    }
}


