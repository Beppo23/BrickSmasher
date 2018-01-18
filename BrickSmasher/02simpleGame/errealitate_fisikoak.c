#include "Errealitateak.h"

POSIZIOA pilotaMugitu(int goian, int rebote, POSIZIOA pilota, POSIZIOA aux)
{
	if (goian == 1)
	{
		aux = ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEGOI(pilota);
		pilota.y = aux.y;

		if (rebote == 0)
		{
			aux = ERREALITATE_FISIKOA_mugimenduaPILOTA(pilota);
			pilota.x = aux.x;
		}
		else if (rebote == 1)
		{
			aux = ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEESK(pilota);
			pilota.x = aux.x;
		}
	}
	else
	{
		if (rebote == 0)
		{
			aux = ERREALITATE_FISIKOA_mugimenduaPILOTA(pilota);
			pilota.y = aux.y;
			pilota.x = aux.x;
		}
		else if (rebote == 1)
		{
			aux = ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEESK(pilota);
			pilota.y = aux.y;
			pilota.x = aux.x;
		}
	}
	return pilota;
}
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa)
{
	posizioa.x = posizioa.x + 15;
	return posizioa;
}
POSIZIOA ERREALITATE_FISIKOA_mugimenduaEZK(POSIZIOA posizioa)
{
	posizioa.x = posizioa.x - 15;
	return posizioa;
}
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPILOTA(POSIZIOA posizioa)
{
	posizioa.y = posizioa.y - 1;
	posizioa.x = posizioa.x + 1;
	return posizioa;
}
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEESK(POSIZIOA posizioa)
{
	posizioa.y = posizioa.y - 1;
	posizioa.x = posizioa.x - 1;
	return posizioa;
}
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEGOI(POSIZIOA posizioa)
{
	posizioa.y = posizioa.y + 1;
	posizioa.x = posizioa.x + 1;
	return posizioa;
}
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPOWERUP(POSIZIOA posizioa)
{
	posizioa.y = posizioa.y + 2;
	return posizioa;
}
POSIZIOA ERREALITATE_FISIKOA_mugimenduaTIROA(POSIZIOA posizioa)
{
	posizioa.y = posizioa.y - 2;
	return posizioa;
}