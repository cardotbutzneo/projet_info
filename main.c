
#include "en-tete.h"

int main(){
    srand(time(NULL));
    FILE *fichier = NULL;
    fichier = fopen("character.txt", "rw");
    Champion Gandalf;
    Champion champ;
    int valeur;
    char buffer[100];
    fgets(buffer, sizeof(buffer), fichier);
    // initialisation des stats
    Gandalf.pv_courrant = pv_max;
    Gandalf.pv_courrant = pv;
    Gandalf.attaque = attaque;
    Gandalf.attaque_spe = attaque_spe;

    afficher_personnage(Gandalf);
    
    fclose(fichier);
    return 0;
}