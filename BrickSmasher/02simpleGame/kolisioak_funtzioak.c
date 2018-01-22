#include "kolisioak.h"
#include "imagen.h"

int jokalariaErrebote(POSIZIOA pilota, POSIZIOA jokalaria)
{
	int goian = 1;

	if ((pilota.x > jokalaria.x - 15) && (pilota.x < (jokalaria.x + 106))) goian = 0;

	return goian;
}
int jokalariaErreboteNoranzkoa(POSIZIOA pilota, POSIZIOA jokalaria, int rebote)
{
	if ((pilota.x > jokalaria.x - 20) && (pilota.x < (jokalaria.x + 106)))
	{
		if (pilota.x + 12 >= jokalaria.x + 53) rebote = 0;
		if (pilota.x + 12 < jokalaria.x + 53) rebote = 1;
	}
	return rebote;
}
POWERUP_ELEMENTUA powerupJaso(POWERUP_ELEMENTUA powerupak, POSIZIOA jokalaria)
{
	if ((powerupak.pos.x > jokalaria.x) && (powerupak.pos.x < (jokalaria.x + 106)))
	{

		irudiaMugitu(powerupak.id, 4000, -4000);
		powerupak.pos.x = 4000;
		powerupak.pos.y = -4000;
	}
	return powerupak;
}
NORA erreboteaKalkulatu(JOKO_ELEMENTUA pilota, POSIZIOA blokea)
{
	if ((pilota.pos.x + 21 <= blokea.x) && (pilota.pos.x + 27 >= blokea.x)) pilota.nora.ezkerrera = 1;
	else if (pilota.pos.x == blokea.x + 40) pilota.nora.ezkerrera = 0;
	else if ((pilota.pos.y + 21 <= blokea.y) && (pilota.pos.y + 27 >= blokea.y)) pilota.nora.behera = 0;
	else if (pilota.pos.y == blokea.y + 20) pilota.nora.behera = 1;

	return pilota.nora;
}