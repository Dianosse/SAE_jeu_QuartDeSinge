#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED
#include <cstring>
#include <iostream>
#include "Joueur.h"
#include "Verifications.h"
#include "Robot.h"

#pragma warning (disable:4996)

using namespace std;

typedef unsigned int uint;

enum{TAILLE_MAX_MOT = 26};

/**
*@brief structure partie qui permet de jouer une partie, avec un tableau de type joueur
*un entier non-signé pour le nombre de manche et un pour le nombre de joueurs.
*/
struct Partie{
    Joueur* tab;
    uint nbManche;
    uint nbJoueurs;
};

/**
*@brief initialise la partie avec un tableau de joueur créé dynamiquement
*@param[in-out] la structure de la partie qu'on utilise
*@param[in] le tableau de caractère qui nous permettra de connaitre
*/
void initialiserP(Partie* p, char* joueurs);

/**
*@brief ajoute une lettre à une chaine de caractère
*@param[in-out] chaine qui va être modifier
*@param[in] lettre qui va être ajoutée
*/
void ajouter_lettre(char* chaine, char lettre);

/**
*@brief affiche H ou R en fonction du booléen du joueur
*@param[in] un joueur
*/
void afficheHouR(const Joueur* j);

/**
*@brief affiche le taleau des scores
*@param[in] la partie qui se joue actuellement
*/
void affichageScore(const Partie* p);

/**
*@brief verifie si un joueur a perdu
*@param[in] la partie qui se joue actuellement
*/
bool verifVic(const Partie* p);

/**
*@brief lance une manche composant la partie
*@param[in-out] la partie qui se joue actuellement
*@param[in-out] la chaine de caractère que les joueurs vont construire pendant la partie
*/
void manche(Partie* p, char* chaine, uint* indJcommence);

/**
*@brief désalloue le tableau dynamique de joueur
*@param[in-out] la partie qui s'est joué
*@pre il faut que la partie est été initialisé
*/
void supprmier(Partie* p);

/**
*@brief vide la chaine de caractère quand la manche est finie
*@param[in-out] chaine de caractère utilisé par les joueurs pendant la manche
*/
void vider_chaine(char* chaine);

/**
*@brief cette fonction gère l'interrogation du joueur précédent celui qui interroge
*@param[in-out] la partie qui est en train d'être joué
*@param[in-out] chaine de caractère utilisé par les joueurs pendant la manche
*@param[in-out] pointeur sur l'indice du joueur qui joue actuellement
*/
void saisirMotAvant(Partie* p, char* chaineJoue, uint* indiceJ);

/**
*@brief applique la fonction toupper() à tout les caractères d'une chaine
*@param[in] chaine de caractère utilisé par les joueurs pendant la manche
*/
void mettreMaj(char* chaine);

/**
*@brief assure que la taille d'une chaine est strictement supérieur à 2
*@param[in] chaine de caractère utilisé par les joueurs pendant la manche
*/
bool motValable(char* chaine);

/**
*@brief renvoie un booléen si un mot existe, donc si un joueur en ajoutant une lettre
*à créé un mot
*@param[in] partie qui se joue actuellement
*@param[in] chaine de caractère utilisé par les joueurs pendant la manche
*@param[in] indice du joueur qui joue actuellement
*@param[in-out] joueur qui joue actuellement
*@param[in-out] pointeur sur l'indice du joueur qui commencera la nouvelle manche
*/
bool SiMotExiste(Partie* partie, char* chaine, uint indJoueur, Joueur* joueur, uint* indJoueurCommence);



#endif // PARTIE_H_INCLUDED
