#include "powerup.h"
#include "blokeak.h"
#include "graphics.h"
#include "imagen.h"
#include <windows.h>

int zeinPOWER(JOKO_ELEMENTUA zein, int posx, int posy)
{
	irudiaMugitu(zein.id, posx, posy);
	zein.pos.x = posx;
	return zein.pos.x;
}
int zeinPOWERY(JOKO_ELEMENTUA zein, int posx, int posy)
{
	irudiaMugitu(zein.id, posx, posy);
	zein.pos.y = posy;
	return zein.pos.y;
}
void powerupSortu(POWERUP_ELEMENTUA pow, POWERUP_ELEMENTUA powerupak[])
{
	for (int i = 1; i <= 3; i++)
	{
		if (i == 1)	pow.koloreak = HORIA;

		else if (i == 2) pow.koloreak = MOREA;

		else if (i == 3) pow.koloreak = BERDEA;

		pow.id = JOKOA_SYPowerUPIrudiaSortu(pow, powerupak);
	}
}
int JOKOA_SYPowerUPIrudiaSortu(POWERUP_ELEMENTUA pwup, POWERUP_ELEMENTUA powerupak[])
{
	int balio = 0;
	pwup.id = -1;
	if (pwup.koloreak == HORIA)
	{
		pwup.id = irudiaKargatu(S_YELLOW_POWERUP);
		powerupak[0] = pwup;
	}
	else if (pwup.koloreak == MOREA)
	{
		pwup.id = irudiaKargatu(X_PURPLE_POWERUP);
		powerupak[1] = pwup;
	}
	else if (pwup.koloreak == BERDEA)
	{
		pwup.id = irudiaKargatu(N_GREEN_POWERUP);
		powerupak[2] = pwup;
	}

	irudiaMugitu(pwup.id, 1000, 1000);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pwup.id;
}
int rng(int zenb)
{
	int num;
	num = rand();
	num = num % zenb;
	return num;
}
int tiroaPuxkatu(TIROA_ELEMENTUA tiroa, LAUKIZUZENA_ELEMENTUA Blokeak[], int lehenlauki)
{
	int id = 0, apurtu = 0;
	id = Id_aurkitu(tiroa.pos.x + 3, tiroa.pos.y);

	if (id >= 0 && id <= 130)
	{
		if (Blokeak[id].apurtuta != 1)
		{
			tiroa.pos.x = 4000;
			tiroa.pos.y = 4000;
			Blokeak[id].apurtuta = 1;
			Blokeak[id].pos.x = 4000;
			Blokeak[id].pos.y = 4000;
			irudiaKendu(id + lehenlauki);
			//irudiaKendu(tiroa.id);
			tiroa.pos.x = 4000;
			tiroa.pos.y = 4000;
			irudiaMugitu(tiroa.id, tiroa.pos.x, tiroa.pos.y);
			tiroa.puxkatu = 1;
			apurtu = 1;
		}
	}
	return apurtu;
}