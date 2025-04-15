
#include "en-tete.h"

int main()
{
    srand(time(NULL));
    FILE *fichier = NULL;
    char *base_chemin = "personnage/";
    char chemin_acces[100];

    snprintf(chemin_acces, sizeof(chemin_acces), "%s%s", base_chemin, "Gandalf.txt"); // actuellement je sais pas ce que fait cette ligne (IA à 100%)

    fichier = fopen(chemin_acces, "r+");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    Champion *Gandalf = malloc(sizeof(Champion));

    if (Gandalf == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        fclose(fichier);
        return 1;
    }
    

    // initialisation des stats
    initialisation_champion(fichier, Gandalf);

   

    // affichage de l'initialisation

    
    affichage_initial(); // passer cette ligne en commentaire pour ne pas afficher le chargement du jeu

    for(int i = 0; i < 10; i++) {
        printf("\n");
    }

    // affichage des stats
     afficher_personnage(Gandalf);

    fclose(fichier);

    printf("code fini");
    return 0;
}