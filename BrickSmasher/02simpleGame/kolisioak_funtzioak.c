#include "kolisioak.h"

int jokalariaErrebote(POSIZIOA pilota, POSIZIOA jokalaria)
{
	int goian = 1;

	if ((pilota.x > jokalaria.x - 15) && (pilota.x < (jokalaria.x + 106))) goian = 0;

	return goian;
}
int jokalariaErreboteNoranzkoa(POSIZIOA pilota, POSIZIOA jokalaria, int rebote)
{
	if ((pilota.x > jokalaria.x - 15) && (pilota.x < (jokalaria.x + 106)))
	{
		if (pilota.x + 12 >= jokalaria.x + 53) rebote = 0;
		if (pilota.x + 12 < jokalaria.x + 53) rebote = 1;
	}
	return rebote;
}