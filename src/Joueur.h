#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <iostream>

using namespace std;

/**
*@brief structure joueur comprenant un réel pour le score et un
*booléen pour savoir si le joueur est un humain ou non.
*/
struct Joueur{
	float singe;
	bool humain;
};

/**
 * @brief ajoute un quart de singe à un joueur
 * @param[in-out] une struture joueur
 */
void ajoutQDS(Joueur* j);

/**
*@brief initialise un joueur avec singe à 0
*@param[in-out] une structure joueur
*@param[in] un booleen true: humain et false: robot
*/
void initialiserJ(Joueur* j, bool h);

#endif // JOUEUR_H_INCLUDED
