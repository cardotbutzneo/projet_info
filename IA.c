#include "en-tete.h"
#include "IA.h"
#include "fonction.h"
#include "affichage.h"
#include "attaque.h"


// Fonction pour choisir une cible valide
int choisir_cible(Equipe *equipe_adverse, char mode) {
    int cible = rand() % 3; // Cible aléatoire
    while (equipe_adverse->perso[cible].stat.pv_courant <= 0) { // Vérifie si la cible est vivante
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
            int cible = choisir_cible(equipe_adverse, 'n'); // Mode 'n' pour noob
            attaquesimple(&equipe_ia->perso[i], &equipe_adverse->perso[cible]);
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


