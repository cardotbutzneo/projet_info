#include "en-tete.h"


int vivant(Champion personnage){// fonction pour verifier si le champion est vivant
  if (personnage.stat.pv_courant<=0.1){
    return 1;// le champion est mort
  }
  else{
    return 0;// le champion est vivant
  }
}

int verifstat(Champion *personnage){// fonction pour verifier les stats du champion
  if (!personnage) {
    printf("Erreur lors de l'allocation de la mémoire\n");
    exit(16);
  }
  int flag = 0;
  if (personnage->stat.attaque<=1){
    personnage->stat.attaque=1;
    flag = 1;
  }
  if (personnage->stat.defense<1){
    personnage->stat.defense=1;
    flag = 1;
  }
  if (personnage->stat.vitesse<1){
    personnage->stat.vitesse=1;
    flag = 1;
  }
  if (personnage->stat.agilite<1){
    personnage->stat.agilite=1;
    flag = 1;
  }
  if (personnage->stat.jauge_actuelle>personnage->stat.jauge_max){
    personnage->stat.jauge_actuelle=personnage->stat.jauge_max;
    flag = 1;
  }
  if (flag == 1){
    return 1; // le champion n'a pas les bonnes stats
  }
  else{
    return 0; // le champion a les bonnes stats
  }
}

