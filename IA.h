#include "en-tete.h"

int choisir_cible(Equipe *equipe_adverse, char mode);
void ia_noob(Equipe *equipe_ia, Equipe *equipe_adverse);
void ia_facile(Equipe *equipe_ia, Equipe *equipe_adverse);
void ia_moyen(Equipe *equipe_ia, Equipe *equipe_adverse);
void ia_principale(Equipe *equipe_ia, Equipe *equipe_adverse, int difficulte);