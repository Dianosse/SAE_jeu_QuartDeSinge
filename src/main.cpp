#include <iostream>
#include "Joueur.h"
#include "Partie.h"
#include "Verifications.h"

using namespace std;


int main(int argc, char* argv[]){
    if (verification(argv[1]) == false) {
        cout << "Desole les parametres rentre sont incorrects" << endl;
        return 0;
    }

    ifstream in("ods4.txt"); // on ouvre le fichier
    if (!in) {
        cout << "le dictionnaire n'a pu etre ouvert" << endl;
        return false;
    }

    //déclarations et initialisation des variables de type et tableau minuimum
    Partie PA;
    initialiserP(&PA, argv[1]);
    char mot[TAILLE_MAX_MOT] = "";
    uint Jcom = 0;

    //boucle qui fait avancer la partie
    while(verifVic(&PA) == false){
        manche(&PA, mot, &Jcom);
    }
    cout << "La partie est finie" << endl;

    supprmier(&PA);

    return 0;
}
