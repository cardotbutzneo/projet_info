
#include "en-tete.h"

int main(){
    srand(time(NULL));
    FILE *fichier = NULL;
    fichier = fopen("personnage/character.txt", "rw");
    Champion Gandalf;
    int pv_max, pv, attaque, attaque_spe;

    sauter_ligne(fichier);
    fscanf(fichier,"%d",&pv_max);
    sauter_ligne(fichier);
    fscanf(fichier,"%d",&pv);
    sauter_ligne(fichier);
    fscanf(fichier,"%d",&attaque);
    sauter_ligne(fichier);
    fscanf(fichier,"%d",&attaque_spe);
    // initialisation des stats
    Gandalf.pv_courrant = pv_max;
    Gandalf.pv_courrant = pv;
    Gandalf.attaque = attaque;
    Gandalf.attaque_spe = attaque_spe;

    afficher_personnage(Gandalf);
    
    fclose(fichier);
    return 0;
}