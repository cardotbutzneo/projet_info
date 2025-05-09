#include "en-tete.h"
#include "IA.h"
#include "fonction.h"
#include "affichage.h"
#include "attaque.h"


// Fonction pour choisir une cible valide
int choisir_cible(Equipe *equipe_adverse, char mode) {
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
void ia_noob(Equipe *equipe_ia, Equipe *equipe_adverse) {
    for (int i = 0; i < 3; i++) {
        if (equipe_ia->perso[i].stat.pv_courant > 0) { // Vérifie si le champion est vivant
            attaquesimple(&equipe_ia->perso[i], equipe_adverse->perso);
        }
    }
}

// Fonction pour l'IA facile
void ia_facile(Equipe *equipe_ia, Equipe *equipe_adverse) {
    for (int i = 0; i < 3; i++) {
        if (equipe_ia->perso[i].stat.pv_courant > 0) { // Vérifie si le champion est vivant
            int cible = choisir_cible(equipe_adverse, 'f'); // Mode 'f' pour facile
            attaquesimple(&equipe_ia->perso[i], &equipe_adverse->perso[cible]);
        }
    }
}

// Fonction pour l'IA moyen
void ia_moyen(Equipe *equipe_ia, Equipe *equipe_adverse) {
    for (int i = 0; i < 3; i++) {
        if (equipe_ia->perso[i].stat.pv_courant > 0) { // Vérifie si le champion est vivant
            int cible = choisir_cible(equipe_adverse, 'm'); // Mode 'm' pour moyen
            /*
            if (peut_utiliser_tech_spe(&equipe_ia->perso[i])) {
                utiliser_tech_spe(&equipe_ia->perso[i], &equipe_adverse->perso[cible]);
            } else {
                attaquesimple(equipe_ia->perso[i], &equipe_adverse->perso[cible]);
            }
            */
        }
    }
}

// Fonction principale de l'IA
void ia_principale(Equipe *equipe_ia, Equipe *equipe_adverse, int difficulte) {
    if (!equipe_ia || !equipe_adverse ){
        printf("erreur d'allocation de memoire dans ia_principale\n");
            exit(0);
    }
    if ( difficulte <0 || difficulte > 3){
        printf("difficulte non initialisee ou trop grande\n");
        difficulte = 0; // on met par defaut difficulte a 0
    }
    switch (difficulte) {
        case 0:
            ia_noob(equipe_ia, equipe_adverse);
            break;
        case 1:
            ia_facile(equipe_ia, equipe_adverse);
            break;
        case 2:
            ia_moyen(equipe_ia, equipe_adverse);
            break;
        default:
            printf("Difficulté inconnue. Utilisation de la difficulté facile par défaut.\n");
            ia_noob(equipe_ia, equipe_adverse);
            break;
    }
}


