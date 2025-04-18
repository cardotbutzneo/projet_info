#include "en-tete.h"

/*
//à faire : créer fonction peut_utiliser_tech_spe(Equipe.combattant[]), fonction utiliser_tech_spe(), fonction pour choisir une cible 


// Fonction pour l'IA noob
//void ia_noob(Equipe *equipe_ia, Equipe *equipe_adverse) {
    for (int i = 0; i < 3; i++) {
        if (equipe_ia->combattants[i].points_vie_courants > 0) {
            int cible = rand() % 3; // Cible aléatoire
            while (equipe_adverse->combattants[cible].points_vie_courants <= 0) {
                cible = rand() % 3; // Trouver une cible vivante
            }
            attaque(&equipe_ia->combattants[i], &equipe_adverse->combattants[cible]);
        }
    }
}

// Fonction pour l'IA facile
//void ia_facile(Equipe *equipe_ia, Equipe *equipe_adverse) {
    for (int i = 0; i < 3; i++) {
        if (equipe_ia->combattants[i].points_vie_courants > 0) {
            int cible = choisir_cible(equipe_adverse, 'f');
            attaque(&equipe_ia->combattants[i], &equipe_adverse->combattants[cible]);
        }
    }
}

// Fonction pour l'IA moyen
//void ia_moyen(Equipe *equipe_ia, Equipe *equipe_adverse) {
    for (int i = 0; i < 3; i++) {
        if (equipe_ia->combattants[i].points_vie_courants > 0) {
            int cible = choisir_cible(equipe_adverse, 'm');
            if (peut_utiliser_tech_spe(&equipe_ia->combattants[i])) { 
                utiliser_tech_spe(&equipe_ia->combattants[i], &equipe_adverse->combattants[cible]);
            } else {
                attaque(&equipe_ia->combattants[i], &equipe_adverse->combattants[cible]);
            }
        }
    }
}

// Fonction principale de l'IA
//void ia_principale(Equipe *equipe_ia, Equipe *equipe_adverse, char difficulte) {
    switch (difficulte) {
        case 'n':
            ia_noob(equipe_ia, equipe_adverse);
            break;
        case 'f':
            ia_facile(equipe_ia, equipe_adverse);
            break;
        case 'm':
            ia_moyen(equipe_ia, equipe_adverse);
            break;
        default:
            printf("Difficulté inconnue. Utilisation de la difficulté noob par défaut.\n");
            ia_noob(equipe_ia, equipe_adverse);
            break;
    }
}

// Fonction pour choisir une cible (celle avec le moins de PV)
//int choisir_cible(Equipe *equipe_adverse, char difficulte) {
*/