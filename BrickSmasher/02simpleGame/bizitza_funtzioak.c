#include "imagen.h"
#include "graphics.h"
#include "bizitzak.h"

void bihotzakEzarri(JOKO_ELEMENTUA bihotzak, int bizitza, int bihotzArray[])
{
	int i, posy = 430, posx = 30;
	for (i = 0; i < bizitza; i++)
	{
		bihotzak.id = BihotzakMarraztu(posx, posy);
		bihotzArray[i] = bihotzak.id;
		posx += 30;
	}
}

int BihotzakMarraztu(int posizioax, int posizioay)
{
	int bihotzId = -1;
	bihotzId = irudiaKargatu(JOKOA_BIHOTZAK_IMAGE);
	irudiaMugitu(bihotzId, posizioax, posizioay);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return bihotzId;
}

void bihotzaKendu(int bizitza, int bihotzArray[])
{
	if (bizitza == 2) irudiaKendu(bihotzArray[2]);
	else irudiaKendu(bihotzArray[1]);
}