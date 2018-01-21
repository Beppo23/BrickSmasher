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