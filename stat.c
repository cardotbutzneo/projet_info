include "en-tete.h"


int vivant(Champion personnage){
  if (personnage.stat.pv_courrant<=0){
    return 1;
  }
  else{
    return 0;
  }
}

int verifstat(Champion personnage){
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
  if (personnage.stat.jauge_actuel>personnage.jauge_max){
    personnage.stat.jauge_actuel=personnage.jauge_max;
  }
}
