#ifndef IA_H
#define IA_H

#include "en-tete.h"

// Fonctions liées à l'IA
void ia_noob(Champion *champion,Equipe *equipe_ia, Equipe *equipe_adverse);
void ia_facile( Champion *champion,Equipe *equipe_ia, Equipe *equipe_adverse);
void ia_moyen(Champion *champion, Equipe *equipe_adverse, Equipe *equipe);
void ia_principale(Champion *champion, Equipe *equipe_ia, Equipe *equipe_adverse, int difficulte);
int choisir_cible(Equipe *equipe_adverse, char mode);

#endif // IA_H