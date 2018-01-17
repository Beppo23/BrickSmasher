#ifndef POWERUP_H
#define POWERUP_H

#include "OurTypes.h"

#define S_YELLOW_POWERUP ".\\img\\s_Yellow.bmp"
#define X_PURPLE_POWERUP ".\\img\\x_Purple.bmp"
#define N_GREEN_POWERUP ".\\img\\n_Green.bmp"

int zeinPOWER(JOKO_ELEMENTUA zein, int posx, int posy);
int zeinPOWERY(JOKO_ELEMENTUA zein, int posx, int posy);
void powerupSortu(POWERUP_ELEMENTUA pow, POWERUP_ELEMENTUA powerupak[]);
int JOKOA_SYPowerUPIrudiaSortu(POWERUP_ELEMENTUA pwup, POWERUP_ELEMENTUA powerupak[]);
int rng(int zenb);
int tiroaPuxkatu(TIROA_ELEMENTUA tiroa, LAUKIZUZENA_ELEMENTUA Blokeak[], int lehenlauki);
#endif