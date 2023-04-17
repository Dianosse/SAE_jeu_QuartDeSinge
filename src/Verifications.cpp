#include "Verifications.h"


bool verification(const char* chaine){
    int taille = strlen(chaine);
    if(taille < 2){
        return false;
    }
    for(int i = 0; i < taille; ++i){
        if(chaine[i]!= 'H' && chaine[i]!= 'R'){
            return false;
        }
    }
    return true;
}



bool ouvertureDico(char* chaineCherche){
	// lecture du dictionnaire mot à mot
	ifstream in("ods4.txt"); // on ouvre le fichier
	if (!in) {
		cout << "le dictionnaire n'a pu etre ouvert" << endl;
		return false;
	}
	int taille = strlen(chaineCherche);
	for (int i = 0; i < taille; ++i) {
		chaineCherche[i] = toupper(chaineCherche[i]);
	}
	const int MAX = 26;
	bool existe = false;
	char s[MAX];
	in >> setw(MAX) >> s; // on essaye de lire le premier mot
	while (in) {
		if (strcmp(s, chaineCherche) == 0) {
			existe = true;
		}
		in >> setw(MAX) >> s; // on essaye de lire le mot suivant
	}

	in.close(); // on ferme le fichier
	return existe;
}

bool triche(char* chaineQuiJoue, char* chaineJoueur){
    int taille = strlen(chaineQuiJoue);
    for(int i = 0; i < taille; ++i){
        if(chaineQuiJoue[i] != chaineJoueur[i]){
            return true;
        }
    }
    return false;
}
