#ifndef VERIFICATIONS_H_INCLUDED
#define VERIFICATIONS_H_INCLUDED
#include <iostream>
#include <cstring>
#include <fstream> // pour ifstream
#include <iomanip> // pour setw
#include <cctype>

using namespace std;

/**
*@brief vérifie que la chaine de caractère suivant le nom de l'éxéctable
*correspond bien aux attentes du jeu
*@param[in] chaine qui définie le nombre et le type des joueurs
*/
bool verification(const char* chaine);

/**
*@brief ouvre le dictionnaire et recherche dedans une chaine de caractère
*@param[in] chaine de caractère utilisé par les joueurs pendant la manche
*/
bool ouvertureDico(char* chaineCherche);

/**
*@brief anti-triche lors de la saisie d'un mot quand un joueur est interrogé
*@param[in] chaine de caractère utilisé par les joueurs pendant la manche
*@param[in] chaine de caractère que le joueur à rentré
*/
bool triche(char* chaineQuiJoue, char* chaineJoueur);



#endif // VERIFICATIONS_H_INCLUDED
