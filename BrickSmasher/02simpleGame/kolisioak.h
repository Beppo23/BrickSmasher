#ifndef KOLISIOAK_H
#define KOLISIOAK_H
#include "OurTypes.h"

int jokalariaErrebote(POSIZIOA pilota, POSIZIOA jokalaria);
int jokalariaErreboteNoranzkoa(POSIZIOA pilota, POSIZIOA jokalaria, int rebote);
POWERUP_ELEMENTUA powerupJaso(POWERUP_ELEMENTUA powerupak, POSIZIOA jokalaria);
#endif