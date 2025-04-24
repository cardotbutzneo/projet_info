#ifndef IA_H
#define IA_H

#include "en-tete.h"

// Fonctions liées à l'IA
void ia_noob(Equipe *equipe_ia, Equipe *equipe_adverse);
void ia_facile(Equipe *equipe_ia, Equipe *equipe_adverse);
void ia_moyen(Equipe *equipe_ia, Equipe *equipe_adverse);
void ia_principale(Equipe *equipe_ia, Equipe *equipe_adverse, int difficulte);
int choisir_cible(Equipe *equipe_adverse, char mode);

#endif // IA_H