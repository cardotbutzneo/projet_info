#include "en-tete.h"


int vivant(Champion personnage){
  if (personnage.stat.pv_courant<=0){
    return 1;
  }
  else{
    return 0;
  }
}

int verifstat(Champion personnage){
  int flag = 0;
  if (personnage.stat.attaque<=1){
    personnage.stat.attaque=1;
    flag = 1;
  }
  if (personnage.stat.defense<1){
    personnage.stat.defense=1;
    flag = 1;
  }
  if (personnage.stat.vitesse<1){
    personnage.stat.vitesse=1;
    flag = 1;
  }
  if (personnage.stat.agilite<1){
    personnage.stat.agilite=1;
    flag = 1;
  }
  if (personnage.stat.jauge_actuelle>personnage.stat.jauge_max){
    personnage.stat.jauge_actuelle=personnage.stat.jauge_max;
    flag = 1;
  }
  if (flag == 1){
    return 1; // le champion n'a pas les bonnes stats
  }
  else{
    return 0; // le champion a les bonnes stats
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
