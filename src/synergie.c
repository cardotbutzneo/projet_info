#include "synergie.h"
#include "couleurs.h"
#include "en-tete.h"
#include "fonction.h"


void buff_troisclassesi_dps(Equipe *equipe) { //applique le buff 
  //synergie de trois classes identiques dps
  if (equipe == NULL) {
      printf(ROUGE_FONCE"Erreur lors de l'allocation de la mémoire\n"RESET);
      exit(0);
  }
  int i = 0;
  for (i = 0; i < Nb_champion_par_equipe; i++) {
      equipe->perso[i].stat.attaque += 2;
      equipe->perso[i].stat.defense -= 2;
      equipe->perso[i].stat.vitesse += 2;
  }
  equipe->synergie += 0.1;
  verifstat(equipe->perso);
}

void buff_troisclassesi_soutien(Equipe *equipe) { //applique le buff 
  //synergie de trois classes identiques soutien 
  int i = 0;
  for (i = 0; i < Nb_champion_par_equipe; i++) {
      equipe->perso[i].stat.attaque -= 2;
      equipe->perso[i].stat.defense += 2;
      equipe->perso[i].stat.pv_courant += 2;
      equipe->perso[i].stat.vitesse -= 2;
  }
  equipe->synergie += 0.1;
  verifstat(equipe->perso);
}

void buff_troisclassesi_tank(Equipe *equipe) { //applique le buff 
  //synergie de trois classes identiques tank + équilibre la méta
  int i = 0;
  for (i = 0; i < Nb_champion_par_equipe; i++) {
      equipe->perso[i].stat.attaque -= 2;
      equipe->perso[i].stat.defense += 2;
      equipe->perso[i].stat.pv_courant += 2;
      equipe->perso[i].stat.vitesse -= 2;
  }
  equipe->synergie += 0.1;
  verifstat(equipe->perso);
}
  
void buff_troisclassesd(Equipe *equipe) { //applique le buff 
  //synergie de trois classes différentes
  for (int i = 0; i < Nb_champion_par_equipe; i++) {
    equipe->perso[i].stat.attaque += 1;
    equipe->perso[i].stat.defense += 1;
    equipe->perso[i].stat.pv_courant += 1;
    equipe->perso[i].stat.vitesse += 1;
  }
  equipe->synergie += 0.1;
    verifstat(equipe->perso);
}

void verifie_classes(Equipe *equipe) { //check les classes de chaque personnage de l'équipe choisie puis lance la fonction dont la condition est validée
 //buff DPS
  if ( strcmp(equipe->perso[0].classe, equipe->perso[1].classe) == 0 && strcmp(equipe->perso[1].classe, equipe->perso[2].classe) == 0 && strcmp(equipe->perso[0].classe, "dps") == 0 ) {
    buff_troisclassesi_dps(equipe);
    printf(VERT"%s : Votre équipe a un buff de classe DPS >:J\n"RESET, equipe->nom);
    return;
  }
  //buff SOUTIEN
  if ( strcmp(equipe->perso[0].classe, equipe->perso[1].classe) == 0 && strcmp(equipe->perso[1].classe, equipe->perso[2].classe) == 0 && strcmp(equipe->perso[0].classe, "soutien") == 0 ) {
    buff_troisclassesi_soutien(equipe);
    printf(VERT"%s : Votre équipe a un buff de classe SOUTIEN >:J\n"RESET, equipe->nom);
    return;
  }
  //equilibrage TANK
  if ( strcmp(equipe->perso[0].classe, equipe->perso[1].classe) == 0 && strcmp(equipe->perso[1].classe, equipe->perso[2].classe) == 0 && strcmp(equipe->perso[0].classe, "tank") == 0 ) {
    buff_troisclassesi_tank(equipe);
    printf(VERT"%s : Votre équipe a un buff de classe TANK >:J\n"RESET, equipe->nom);
    return;
  }
  //buff 3 classes différentes
  if ( strcmp(equipe->perso[0].classe, equipe->perso[1].classe) != 0 && strcmp(equipe->perso[1].classe, equipe->perso[2].classe) != 0 && strcmp(equipe->perso[0].classe, equipe->perso[2].classe) != 0 ) {
    buff_troisclassesd(equipe);
    printf(VERT"%s : Votre équipe a un buff de 3 classes différentes >:J\n"RESET, equipe->nom);
    return;
  }
}
  //pas de buff
