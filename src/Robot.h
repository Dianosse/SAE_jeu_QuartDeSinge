#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED
#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream> // pour ifstream
#include <iomanip> // pour setw
#include <cstring>
#include "Partie.h"

using namespace std;

//constante utilisé pour la chaine de caractère représentant l'alphabet
enum{T = 26};


/**
*@brief renvoie une lettre, le coup du robot mais en fonction de si
*il commence à jouer ou si il continue un mot
*@param[in] chaine de caractère utilisé par les joueurs pendant la manche
*/
char coupRobot(char* chaineQuiJoue);

/**
*@brief renvoie une lettre tiré aléatoirement
*/
char lettreAleatoire();

/**
*@brief vérifie que le début de la première chaine est la deuxième chaine
*@param[in] première chaine
*@param[in] deuxième chaine
*/
bool verifmotDeb(char* s, char* x);

/**
*@brief vérifie que chaine1 à une taille strictement inférieur à chaine2
*@param[in] chaine de caractère utilisé par les joueurs pendant la manche
*@param[in] chaine de caractère sorti du dictionnaire
*/
bool tailleSup(char* chaine1, char* chaine2);

/**
*@brief renvoie une lettre complétant la chaine en jeu
*@param[in] chaine de caractère utilisé par les joueurs pendant la manche
*/
char derLettreMot(char* chaineQuiJoue);

/**
*@brief gère quand un robot est interrogé par un joueur
*@param[in] chaine de caractère utilisé par les joueurs pendant la manche
*@param[in-out] pointeur sur un booleen pour savoir si un mot a été trouvé
*/
void saisieMotAvantRob(char* chaineQuiJoue, bool* trouve);

/**
*@brief génère un nombre en 0 et borneMax qui est passé en paramètre
*@param[in] entier qui est utilisé comme borne à ne pas dépasser
*/
int nombreAlea(int borneMax);

/**
*@brief renvoie une lettre complétant un mot qui a été choisi aléatoirement
*@param[in] chaine de caractère sortie du dictionnaire
*@param[in] chaine de caractère utilisé par les joueurs pendant la manche
*@param[in] entier qui a compté le nombre de mot possiblement jouable lors d'un
*premier passage.
*/
char deuxiemePassage(char* chaineDico, char* chaineQuiJoue, int PremierCompteur);



#endif // ROBOT_H_INCLUDED
