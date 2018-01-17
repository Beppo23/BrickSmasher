#ifndef BLOKEAK_H
#define BLOKEAK_H

#include "OurTypes.h"

#define LAUKIZUZENA1_1BMP ".\\img\\blokeGorria.bmp"
#define LAUKIZUZENA1_2BMP ".\\img\\blokeUrdina.bmp"
#define LAUKIZUZENA1_3BMP ".\\img\\blokeHoria.bmp"

int JOKOA_LaukizuzenaIrudiaSortu(int posx, int posy, int zein);
int laukizuzenakEzarri(LAUKIZUZENA_ELEMENTUA Laukizuzena, LAUKIZUZENA_ELEMENTUA blokeak[]);
int Id_aurkitu(int x, int y);
#endif