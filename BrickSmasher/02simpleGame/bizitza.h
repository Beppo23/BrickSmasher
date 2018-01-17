#ifndef BIZITZA_H
#define BIZITZA_H
#include "OurTypes.h"

#define JOKOA_BIHOTZAK_IMAGE ".\\img\\bihotza.bmp"

void bihotzakEzarri(JOKO_ELEMENTUA bihotzak, int bizitza, int bihotzArray[]);
int BihotzakMarraztu(int posizioax, int posizioay);
void bihotzaKendu(int bizitza, int bihotzArray[]);
#endif