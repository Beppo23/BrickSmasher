#ifndef GAME10_H
#define GAME10_H

#include "ourTypes.h"

void jokoaAurkeztu(void);
EGOERA jokatu(void);
void laukizuzenakEzarri(JOKO_ELEMENTUA Laukizuzenak);
void bihotzakEzarri(JOKO_ELEMENTUA Bihotzak, int bizitza);
void bihotzakKendu(JOKO_ELEMENTUA bihotzak, int bizitza);
int  jokoAmaierakoa(EGOERA egoera);

#endif