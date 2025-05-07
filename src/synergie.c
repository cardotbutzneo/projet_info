#include "synergie.h"

void buff_troisclassesi_dps(Equipe *equipe) { //applique le buff 
  //synergie de trois classes identiques dps
  int i = 0;
  for (i = 0; i < Nb_champion_par_equipe; i++) {
      equipe->perso[i].stat.attaque += 5;
      equipe->perso[i].stat.defense += 5;
      equipe->perso[i].stat.vitesse += 5;
  }
  equipe->synergie += 0.1;
}

void buff_troisclassesi_soutien(Equipe *equipe) { //applique le buff 
  //synergie de trois classes identiques soutien 
  int i = 0;
  for (i = 0; i < Nb_champion_par_equipe; i++) {
      equipe->perso[i].stat.attaque -= 5;
      equipe->perso[i].stat.defense += 5;
      equipe->perso[i].stat.pv_courant += 5;
      equipe->perso[i].stat.vitesse -= 5;
  }
  equipe->synergie += 0.1;
}

void buff_troisclassesi_tank(Equipe *equipe) { //applique le buff 
  //synergie de trois classes identiques tank + équilibre la méta
  int i = 0;
  for (i = 0; i < Nb_champion_par_equipe; i++) {
      equipe->perso[i].stat.attaque += 5;
      equipe->perso[i].stat.defense -= 5;
      equipe->perso[i].stat.pv_courant += 5;
      equipe->perso[i].stat.vitesse -= 5;
  }
  equipe->synergie += 0.1;
}
  
void buff_troisclassesd(Equipe *equipe) { //applique le buff 
  //synergie de trois classes différentes
  for (int i = 0; i < Nb_champion_par_equipe; i++) {
    equipe->perso[i].stat.attaque += 5;
    equipe->perso[i].stat.defense -= 5;
    equipe->perso[i].stat.pv_courant -= 5;
    equipe->perso[i].stat.vitesse += 5;
  }
equipe->synergie += 0.1;
}

void verifie_classes(Equipe *equipe) { //check les classes de chaque personnage de l'équipe choisie puis lance la fonction dont la condition est validée
 //buff DPS
  if ( strcmp(equipe->perso[0].classe, equipe->perso[1].classe) == 0 && strcmp(equipe->perso[1].classe, equipe->perso[2].classe) == 0 && strcmp(equipe->perso[0].classe, "dps") == 0 ) {
    buff_troisclassesi_dps(equipe);
    return;
  }
  //buff SOUTIEN
  if ( strcmp(equipe->perso[0].classe, equipe->perso[1].classe) == 0 && strcmp(equipe->perso[1].classe, equipe->perso[2].classe) == 0 && strcmp(equipe->perso[0].classe, "soutien") == 0 ) {
    buff_troisclassesi_soutien(equipe);
    return;
  }
  //equilibrage TANK
  if ( strcmp(equipe->perso[0].classe, equipe->perso[1].classe) == 0 && strcmp(equipe->perso[1].classe, equipe->perso[2].classe) == 0 && strcmp(equipe->perso[0].classe, "soutien") == 0 ) {
    buff_troisclassesi_tank(equipe);
    return;
  }
  //buff 3 classes identiques
  if ( strcmp(equipe->perso[0].classe, equipe->perso[1].classe) != 0 && strcmp(equipe->perso[1].classe, equipe->perso[2].classe) != 0 && strcmp(equipe->perso[0].classe, equipe->perso[2].classe) != 0 ) {
    buff_troisclassesd(equipe);
    return;
  }
}












