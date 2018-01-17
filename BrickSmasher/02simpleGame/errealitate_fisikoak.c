#include "Errealitateak.h"

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