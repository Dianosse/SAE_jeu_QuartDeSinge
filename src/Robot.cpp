#include "Robot.h"

char lettreAleatoire(){
	srand((unsigned int)time(0));
	int alea = rand()%25;
	char tabAlpha[T+1] = "ABCDEFGHIJKLMONPQRSTUVWXYZ";
   	return tabAlpha[alea];
}

int nombreAlea(int borneMax){
    srand((unsigned int)time(0));
    int nombre = rand()%borneMax;
    return nombre;
}

char coupRobot(char* chaineQuiJoue){
    char lettre;
    //cout << "\nTaille de chaine : " << strlen(chaineQuiJoue) << endl;
	if(strlen(chaineQuiJoue) == 0){
        lettre = lettreAleatoire();
 	}
	else{
        lettre = derLettreMot(chaineQuiJoue);
    }
	return lettre;
}



char derLettreMot(char* chaineQuiJoue){
	int cmpPremierPassage = 1;
	//PREMIER PASSAGE on compte le nombre de mots jouables
	// lecture du dictionnaire mot à mot
	ifstream in("ods4.txt"); // on ouvre le fichier
	if (!in) {
		cout << "le dictionnaire n'a pu etre ouvert" << endl;
	}
	char chaineDico[T];
	in >> setw(T) >> chaineDico; // on essaye de lire le premier mot
	while(in){
		if(verifmotDeb(chaineDico, chaineQuiJoue) && tailleSup(chaineQuiJoue, chaineDico)){
            ++cmpPremierPassage;
		}
		in >> setw(T) >> chaineDico; // on essaye de lire le mot suivant
	}
	in.close(); // on ferme le fichier
	return deuxiemePassage(chaineDico, chaineQuiJoue, cmpPremierPassage);
}

char deuxiemePassage(char* chaineDico, char* chaineQuiJoue, int PremierCompteur){
    //DEUXIEME PASSGE on choisit un mot de facon aleatoire
    int cmpDeuxiemePassage = 1;
    int nbAlea = nombreAlea(PremierCompteur);
    char lettre = '?';
    ifstream in("ods4.txt"); // on ouvre le fichier
	if (!in) {
		cout << "le dictionnaire n'a pu etre ouvert" << endl;
	}
	in >> setw(T) >> chaineDico; // on essaye de lire le premier mot
	while(in){
		if(verifmotDeb(chaineDico, chaineQuiJoue) && tailleSup(chaineQuiJoue, chaineDico)){
            if(cmpDeuxiemePassage == nbAlea){
                lettre = chaineDico[strlen(chaineQuiJoue)];
                in.close();
                return lettre;
            }
            ++cmpDeuxiemePassage;
		}
		in >> setw(T) >> chaineDico; // on essaye de lire le mot suivant
	}
	in.close();
	return lettre;
}


bool verifmotDeb(char* s, char* x){
	int taille = strlen(x);
	for (int i = 0; i < taille; ++i){
		if (x[i] != s[i]) {
			return false;
		}
	}
	return true;
}

bool tailleSup(char* chaine1, char* chaine2){
	return strlen(chaine1)+2 < strlen(chaine2);
}

void saisieMotAvantRob(char* chaineQuiJoue, bool* trouve){
    ifstream in("ods4.txt"); // on ouvre le fichier
	if (!in) {
		cout << "le dictionnaire n'a pu etre ouvert" << endl;
	}
	char chaineDico[T];
	in >> setw(T) >> chaineDico; // on essaye de lire le premier mot
	while(in){
		if(verifmotDeb(chaineDico, chaineQuiJoue) && tailleSup(chaineQuiJoue, chaineDico)){
            strcpy(chaineQuiJoue, chaineDico);
            *trouve = true;
            in.close();
            return;
		}
		in >> setw(T) >> chaineDico; // on essaye de lire le mot suivant
	}
	//si le robot ne trouve pas de mot il rajoute une lettre aléatoirement
	ajouter_lettre(chaineQuiJoue, lettreAleatoire());
	in.close(); // on ferme le fichier
}
