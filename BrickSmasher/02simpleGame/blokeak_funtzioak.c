#include "blokeak.h"
#include "graphics.h"
#include "imagen.h"

int posx = 0;
int posy = 0;

int JOKOA_LaukizuzenaIrudiaSortu(int posizioax, int posizioay, int zein)
{
	int Laukizuzena = -1;
	switch (zein)
	{
	case 1:
		Laukizuzena = irudiaKargatu(LAUKIZUZENA1_1BMP);
		break;
	case 2:
		Laukizuzena = irudiaKargatu(LAUKIZUZENA1_2BMP);
		break;
	case 3:
		Laukizuzena = irudiaKargatu(LAUKIZUZENA1_3BMP);
		break;
	default:
		break;
	}
	irudiaMugitu(Laukizuzena, posizioax, posizioay);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return Laukizuzena;
}
int laukizuzenakEzarri(LAUKIZUZENA_ELEMENTUA Laukizuzena, LAUKIZUZENA_ELEMENTUA blokeak[]) {
	int r = 1, maximoa = 0, j = 0;

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)	posy = 50;

		for (int t = 0; t < 13; t++)
		{
			if (t == 0)	posx = 60;
			Laukizuzena.id = JOKOA_LaukizuzenaIrudiaSortu(posx, posy, r);
			Laukizuzena.apurtuta = 0;
			Laukizuzena.pos.x = posx;
			Laukizuzena.pos.y = posy;
			Laukizuzena.apurtuta = 0;
			Laukizuzena.mota = IRUDIA;
			blokeak[j] = Laukizuzena;
			posx += 40;
			j++;
		}
		posy += 20;
		if (r == 3)	maximoa = 1;

		else if (r == 1) maximoa = 0;

		if (maximoa == 1) r--;

		else r++;
	}
	return blokeak[0].id;
}
int Id_aurkitu(int x, int y)
{
	int id = 0, xtxiki = 60, ytxikia = 50;

	if (x < 60 || x > 580 || y < 50 || y > 250) id = 1000;

	while ((x<xtxiki || x > xtxiki + 40) && (xtxiki < 600))
	{
		xtxiki += 40;
		id++;
	}
	while ((y < ytxikia || y > ytxikia + 20) && (ytxikia < 260))
	{
		ytxikia += 20;
		id += 13;
	}
	return id;
}