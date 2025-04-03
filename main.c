
#include "en-tete.h"

int main(){
    srand(time(NULL));
    FILE *fichier = NULL;
    fichier = fopen("character.txt", "rw");
    Champion matheo;
    Champion champ;
    int valeur;
    char buffer[100];
    fgets(buffer, sizeof(buffer), fichier);
    // initialisation des stats
    
    printf("programme fini\n");
    fclose(fichier);
    return 0;
}