#include "en-tete.h"


int vivant(Champion personnage){
  if (personnage.stat.pv_courant<=0){
    return 1;
  }
  else{
    return 0;
  }
}

void verifstat(Champion personnage){
  if (personnage.stat.attaque<=0){
    personnage.stat.attaque=1;
  }
  if (personnage.stat.defense<0){
    personnage.stat.defense=0;
  }
  if (personnage.stat.vitesse<0){
    personnage.stat.vitesse=0;
  }
  if (personnage.stat.agilite<0){
    personnage.stat.agilite=0;
  }
  if (personnage.stat.jauge_actuelle>personnage.stat.jauge_max){
    personnage.stat.jauge_actuelle=personnage.stat.jauge_max;
  }
}

void verifstatComplet(Champion equipe[],Champion equipeAdverse[]){
  for (int i=0;i<Nb_champion_par_equipe;i++){
    verifstat(equipe[i]);
  }
  for (int i=0;i<Nb_champion_par_equipe;i++){
    verifstat(equipeAdverse[i]);
  }
}
