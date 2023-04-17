#include "Partie.h"



void initialiserP(Partie* p, char* joueurs){
    int taille = strlen(joueurs);
    Joueur* newTab = new Joueur[taille];
    p->nbManche = 0;
    p->nbJoueurs = taille;
    for(int i = 0; i < taille; ++i){
        //cout << joueurs[i] << endl;
        if(joueurs[i] == 'R'){
            initialiserJ(&newTab[i], false);
        }
        else{
            initialiserJ(&newTab[i], true);
        }
    }
    p->tab = newTab;
}

void supprmier(Partie* p){
    delete[] p->tab;
}

void vider_chaine(char* chaine){
    for (int i = TAILLE_MAX_MOT-1; i >= 0; --i) {
        chaine[i] = '\0';
    }
    //strcpy(chaine, "\0");
}

void manche(Partie* p, char* chaine, uint* indJcommence){
    bool fin = false;
    char lettre;
    uint indJ = *indJcommence;
    while(fin == false){
        Joueur j = p->tab[indJ];
        cout << indJ+1;
        afficheHouR(&j);
        cout << ", ("<<chaine<< ')' << " > ";
        if(j.humain){
            cin >> lettre;
            if(lettre == '?'){
                saisirMotAvant(p, chaine, &indJ);
                vider_chaine(chaine);
                *indJcommence = indJ;
                fin = true;
            }
            else if (lettre == '!'){
                cout << "le joueur " << indJ + 1;
                afficheHouR(&p->tab[indJ]);
                cout << " abandonne la manche et prend un quart de singe" << endl;
                ajoutQDS(&p->tab[indJ]);
                vider_chaine(chaine);
                *indJcommence = indJ;
                fin = true;
            }
            else{
                ajouter_lettre(chaine, lettre);
                fin = SiMotExiste(p, chaine, indJ, &j, indJcommence);
                }
        }
        else if (!j.humain){ // si c'est un robot qui joue
            char l = coupRobot(chaine);
            cout << l << endl;
                if(l == '?'){
                    saisirMotAvant(p, chaine, &indJ);
                    vider_chaine(chaine);
                    *indJcommence = indJ;
                    fin = true;
                }
                else{
                    ajouter_lettre(chaine, l);
                    fin = SiMotExiste(p, chaine, indJ, &j, indJcommence);
                }
        }
        ++indJ;
        if(indJ >= p->nbJoueurs){
            indJ = 0;
        }
    }
    affichageScore(p);
}

void saisirMotAvant(Partie* p, char* chaineJoue, uint* indiceJ){
    char motJoueur[TAILLE_MAX_MOT];
    if(*indiceJ == 0){
        uint indJinter = p->nbJoueurs;
        cout << p->nbJoueurs;
        afficheHouR(&p->tab[indJinter-1]);
        cout << ", saisir le mot > ";
        if(p->tab[indJinter-1].humain){
            cin >> motJoueur;
            mettreMaj(motJoueur);
            if(triche(chaineJoue, motJoueur)){
                cout << "le mot "<<motJoueur<<" ne commence pas par les lettres attendues, le joueur "<< indJinter;
                afficheHouR(&p->tab[indJinter-1]);
                cout << " prend un quart de singe" << endl;
                ajoutQDS(&p->tab[indJinter-1]);
                *indiceJ = indJinter - 1;   
                return;
            }
            if (ouvertureDico(motJoueur)){
                cout << "le mot "<<motJoueur<<" existe, le joueur " << *indiceJ+1;
                afficheHouR(&p->tab[*indiceJ]);
                cout << " prend un quart de singe" << endl;
                ajoutQDS(&p->tab[*indiceJ]);
            }
            else{
                cout << "le mot "<<motJoueur<<" n'existe pas, le joueur " <<indJinter;
                afficheHouR(&p->tab[indJinter-1]);
                cout << " prend un quart de singe" << endl;
                ajoutQDS(&p->tab[indJinter-1]);
                *indiceJ = indJinter-1;
            }
        }
        else{
            bool motTrouve = false;
            saisieMotAvantRob(chaineJoue, &motTrouve);
            if(motTrouve){
                cout << "le mot "<<chaineJoue<< " existe, le joueur " << *indiceJ+1;
                afficheHouR(&p->tab[*indiceJ]);
                cout << " prend un quart de singe" << endl;
                ajoutQDS(&p->tab[*indiceJ]);
            }
            else{
                cout << "le mot "<<chaineJoue<< " n'existe pas, le joueur " <<indJinter;
                afficheHouR(&p->tab[indJinter-1]);
                cout << " prend un quart de singe" << endl;
                ajoutQDS(&p->tab[indJinter-1]);
                *indiceJ = indJinter-1;
            }
        }
    }
    else{
        cout << *indiceJ;
        afficheHouR(&p->tab[*indiceJ-1]);
        cout << ", saisir le mot > ";
        if(p->tab[*indiceJ-1].humain){
            cin >> motJoueur;
            mettreMaj(motJoueur);
            if(triche(chaineJoue, motJoueur)){
                cout << "le mot "<<motJoueur<<" ne commence pas par les lettres attendues, le joueur "<< *indiceJ;
                afficheHouR(&p->tab[*indiceJ-1]);
                cout << " prend un quart de singe" << endl;
                ajoutQDS(&p->tab[*indiceJ-1]);
                *indiceJ = *indiceJ - 1;
                return;
            }
            if (ouvertureDico(motJoueur) == true){
                cout << "le mot "<<motJoueur<< " existe, le joueur " << *indiceJ+1;
                afficheHouR(&p->tab[*indiceJ]);
                cout << " prend un quart de singe" << endl;
                ajoutQDS(&p->tab[*indiceJ]);
            }
            else{
                cout << "le mot "<<motJoueur << " n'existe pas, le joueur " <<*indiceJ;
                afficheHouR(&p->tab[*indiceJ-1]);
                cout << " prend un quart de singe" << endl;
                ajoutQDS(&p->tab[*indiceJ-1]);
                *indiceJ = *indiceJ-1;
            }
        }
        else{
            bool motTrouve = false;
            saisieMotAvantRob(chaineJoue, &motTrouve);
            if(motTrouve){
                cout << "le mot "<<chaineJoue<< " existe, le joueur " << *indiceJ+1;
                afficheHouR(&p->tab[*indiceJ]);
                cout << " prend un quart de singe" << endl;
                ajoutQDS(&p->tab[*indiceJ]);
            }
            else{
                cout << "le mot " << chaineJoue << " n'existe pas, le joueur " << *indiceJ;
                afficheHouR(&p->tab[*indiceJ-1]);
                cout << " prend un quart de singe" << endl;
                ajoutQDS(&p->tab[*indiceJ-1]);
                *indiceJ = *indiceJ-1;
            }
        }
    }
}

bool motValable(char* chaine){
    return strlen(chaine) > 2;
}

bool SiMotExiste(Partie* partie, char* ch, uint indJoueur, Joueur* joueur, uint* indJoueurCommence){
    if(motValable(ch) && ouvertureDico(ch)){
        cout << "le mot " << ch <<" existe, le joueur " << indJoueur+1;
        afficheHouR(joueur);
        cout << " prend un quart de singe" << endl;
        ajoutQDS(&partie->tab[indJoueur]);
        vider_chaine(ch);
        *indJoueurCommence = indJoueur;
        return true;
    }
    return false;
}


void ajouter_lettre(char* chaine, char lettre){
    int indice = strlen(chaine);
	chaine[indice] = toupper(lettre);
    chaine[indice + 1] = '\0';
}

void afficheHouR(const Joueur* j){
    if(j->humain == true){
        cout << 'H';
    }
    else{
        cout << 'R';
    }
}

void mettreMaj(char* chaine){
    int taille = strlen(chaine);
    for(int i = 0; i < taille; ++i){
        chaine[i] = toupper(chaine[i]);
    }
}

void affichageScore(const Partie* p){
    //cout << "Nb joueurs : " << p->nbJoueurs << endl;
    for(uint i = 0; i < p->nbJoueurs; ++i){
        Joueur j = p->tab[i];
        cout << i+1;
        afficheHouR(&j);
        cout << " : " << j.singe;
        if (!(i == p->nbJoueurs - 1)) {
            cout << "; ";
        }
    }
    cout << endl;
}

bool verifVic(const Partie* p){
    for(uint i = 0; i < p->nbJoueurs; ++i){
        if(p->tab[i].singe == 1.){
            return true;
        }
    }
    return false;
}

