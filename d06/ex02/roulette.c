#include "header.h"

static double spin(double balance, double dollarsWanted, int nbGame, double probability)
{
	if (!nbGame || balance <= 0 || balance >= dollarsWanted)
		return probability;
	if (!probability)
		probability = (double)18 / (double)37;
	else
		probability *= (double)18 / (double)37;
	return spin(balance * 2, dollarsWanted, nbGame - 1, probability);
}

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
	return(spin(firstDollarsBet, dollarsWanted, nbGame, 0));
}