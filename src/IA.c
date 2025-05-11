#include "en-tete.h"
#include "IA.h"
#include "fonction.h"
#include "affichage.h"
#include "attaque.h"
#include "attaquespe.h"
#include "couleurs.h"


// Fonction pour choisir une cible valide
int choisir_cible(Equipe *equipe_adverse, char mode) {
    if (!equipe_adverse ){
        printf(ROUGE"erreur lors de l'allocation de la mémoire\n"RESET);
        exit(0);
    }
    int vivant = 0;
    for (int i = 0; i < 3; i++) {
        if (equipe_adverse->perso[i].stat.pv_courant > 0) {
            vivant = 1;
            break;
        }
    }
    if (!vivant) {
        printf("Aucune cible valide trouvée\n");
        return -1;
    }

    int cible = rand() % 3;
    while (equipe_adverse->perso[cible].stat.pv_courant <= 0) {
        cible = rand() % 3;
    }
    return cible;
}

// Fonction pour vérifier si une technique spéciale peut être utilisée
/*
int peut_utiliser_tech_spe(Champion *champion) {
    // Exemple : Vérifiez si le champion a suffisamment d'énergie
    return champion->stat. >= 10; // Remplacez par votre logique
}

// Fonction pour utiliser une technique spéciale
void utiliser_tech_spe(Champion *attaquant, Champion *cible) {
    printf("%s utilise une technique spéciale sur %s !\n", attaquant->nom, cible->nom);
    // Exemple de logique : inflige des dégâts fixes et consomme de l'énergie
    cible->stat.pv_courant -= 50; // Inflige 50 points de dégâts
    attaquant->stat.energie -= 10; // Consomme 10 points d'énergie
}
*/
// Fonction pour l'IA noob
void ia_noob(Champion *champion,Equipe *equipe_ia, Equipe *equipe_adverse) {
    if (!champion || !equipe_adverse || !equipe_adverse){
        printf(ROUGE"erreur lors de l'allocation de la mémoire\n"RESET);
        exit(0);
    }
        attaquesimple(champion, equipe_adverse->perso);
        printf(ROUGE"IA attaque >:) \n\n"RESET);
}

// Fonction pour l'IA facile
void ia_facile( Champion *champion,Equipe *equipe_ia, Equipe *equipe_adverse) {
    if (!champion || !equipe_adverse || !equipe_adverse){
        printf(ROUGE"erreur lors de l'allocation de la mémoire\n"RESET);
        exit(0);
    }
    int x = rand() % 11; // 10% de chance d'utiliser une technique spéciale
    if (x == 0 && champion->stat.jauge_actuelle >= champion->stat.jauge_max) {
        attaqueSpecial(*champion, equipe_adverse->perso, equipe_adverse->perso); // Utilise une technique spéciale
        printf(JAUNE"IA utilise une attaque spéciale\n\n"RESET);
    } else {
        attaquesimple(champion, equipe_adverse->perso);
        printf(ROUGE"IA attaque >:) \n\n"RESET);
    }
}

// Fonction pour l'IA moyen
void ia_moyen(Champion *champion, Equipe *equipe_adverse, Equipe *equipe) {
    if (!champion || !equipe_adverse || !equipe){
        printf("erreur lors de l'allocation de la mémoire\n");
        exit(0);
    }
    int x = rand() % 5; // 60% de chance d'utiliser une technique spéciale
    if (x == 0 && champion->stat.jauge_actuelle >= champion->stat.jauge_max) {
        attaqueSpecial(*champion, equipe_adverse->perso, equipe->perso); // Utilise une technique spéciale
        printf(JAUNE"IA utilise une attaque spéciale\n\n"RESET);
    } 
    else  {
        attaquesimple(champion, equipe_adverse->perso);
        printf(ROUGE"IA attaque\n");
    }
}

// Fonction principale de l'IA
void ia_principale(Champion *champion, Equipe *equipe_ia, Equipe *equipe_adverse, int difficulte) {
    if (!equipe_ia || !equipe_adverse ){
        printf("erreur d'allocation de mémoire dans ia_principale\n");
            exit(0);
    }
    if ( difficulte <0 || difficulte > 3){
        printf("difficulté non initialisée ou trop grande\n");
        difficulte = 0; // on met par défaut difficulté à 0
    }
    switch (difficulte) {
        case 0:
            ia_noob(champion,equipe_ia, equipe_adverse);
            break;
        case 1:
            ia_facile(champion, equipe_ia, equipe_adverse);
            break;
        case 2:
            ia_moyen(champion, equipe_adverse, equipe_ia);
            break;
        default:
            printf("Difficulté inconnue. Utilisation de la difficulté facile par défaut.\n");
            ia_noob(champion,equipe_ia, equipe_adverse);
            break;
    }
}



