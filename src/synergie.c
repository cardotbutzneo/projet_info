#include "en-tete.h"
#include "synergie.h"


void buff_troisclassesi(Equipe *equipe) { //applique le buff 
  //synergie de trois classes identiques
  int i = 0;
  for (i = 0; i < Nb_champion_par_equipe; i++) {
      equipe->perso[i].stat.attaque += 5;
      equipe->perso[i].stat.defense += 5;
      equipe->perso[i].stat.vitesse += 5;
  }
  equipe->synergie += 0.1;
}
  
void buff_troisclassesd(Equipe *equipe) { //applique le buff 
  //synergie de trois classes différentes
  for (int i = 0; i < Nb_champion_par_equipe; i++) {
    equipe->perso[i].stat.attaque += 5;
    equipe->perso[i].stat.defense -= 5;
    equipe->perso[i].stat.vitesse -= 5;
    equipe->perso[i].stat.vitesse += 5;
  }
equipe->synergie += 0.1;
}

void verifie_classes(Equipe *equipe) { //check les classes de chaque personnage de l'équipe choisie puis lance la fonction dont la condition est validée
  if ( (equipe->perso[1].classe == equipe->perso[2].classe) && (equipe->perso[2].classe == equipe->perso[3].classe) ) {
    buff_troisclassesi(equipe);
    return;
  }
  if ( (equipe.perso[1].classe != equipe.perso[2].classe) && (equipe.perso[2].classe != equipe.perso[3].classe) ) {
    return();
  }







