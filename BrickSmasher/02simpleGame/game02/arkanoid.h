#ifndef GAME10_H
#define GAME10_H

#include "ourTypes.h"

void jokoaAurkeztu(void);
EGOERA jokatu(void);
void laukizuzenakEzarri(LAUKIZUZENA_ELEMENTUA Laukizuzenak, LAUKIZUZENA_ELEMENTUA blokeak[]);
void tiroakSortu(TIROA_ELEMENTUA  tiroa, TIROA_ELEMENTUA  Tiroak[]);
void laukizuzenakEzarri(LAUKIZUZENA_ELEMENTUA Laukizuzenak, LAUKIZUZENA_ELEMENTUA blokeak[]);
void bihotzakEzarri(JOKO_ELEMENTUA Bihotzak, int bizitza);
int  jokoAmaierakoa(EGOERA egoera);

#endif