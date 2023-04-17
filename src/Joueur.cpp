#include "Joueur.h"

void ajoutQDS(Joueur* j){
	j->singe += 0.25;
}

void initialiserJ(Joueur* j, bool h){
    j->singe = 0.;
    j->humain = h;
}
