#include "menua.h"
#include "arkanoid.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

int jokoaAurkeztu()
{
	int ebentu = 0, saguaclick = 0, barruan = 0, irten = 0;
	POSIZIOA pos;
	audioInit();
	loadTheMusic(MENU_AUDIO);
	playMusic();
	sarreraMezuaIdatzi();

	do
	{
		pos = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 260) && (pos.x <= 375) && (pos.y >= 120) && (pos.y <= 153) && barruan == 0)
		{
			saguaclick = 1;
			barruan = 1;
		}
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 260) && (pos.x <= 375) && (pos.y >= 210) && (pos.y <= 243) && barruan == 0)
		{
			saguaclick = 2;
			barruan = 1;
		}
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 260) && (pos.x <= 375) && (pos.y >= 300) && (pos.y <= 333) && barruan == 0)
		{
			saguaclick = 3;
			barruan = 1;
		}
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 260) && (pos.x <= 375) && (pos.y >= 390) && (pos.y <= 423) && barruan == 0)
		{
			saguaclick = 4;
			barruan = 1;
		}
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 50) && (pos.x <= 175) && (pos.y >= 370) && (pos.y <= 423) && barruan == 1)
		{
			saguaclick = 5;
			barruan = 0;
		}
		switch (saguaclick)
		{
		case 1:
			saguaclick = 999;
			toggleMusic();
			audioTerminate();
			break;

		case 2:pantailaGarbitu();
			saguaclick = 0;
			JOKOA_fondoaSortu();
			JOKOA_itzuli();
			JOKOA_teclaEzkerra();
			JOKOA_teclaEskuma();
			JOKOA_barra();
			JOKOA_q();
			textuaIdatzi(50, 50, NOLA_JOKATU);
			textuaIdatzi(50, 120, NOLA1_JOKATU);
			textuaIdatzi(50, 170, NOLA3_JOKATU);
			textuaIdatzi(50, 230, NOLA2_JOKATU);
			textuaIdatzi(50, 280, NOLA4_JOKATU);
			textuaIdatzi(50, 320, NOLA5_JOKATU);
			pantailaBerriztu();
			break;
		case 3:pantailaGarbitu();
			saguaclick = 0;
			JOKOA_KreditoakSortu();
			JOKOA_itzuli();
			pantailaBerriztu();
			break;
		case 4:
			audioTerminate();
			saguaclick = 999;
			irten = 1;
			break;
		case 5:
			saguaclick = 0;
			barruan = 0;
			sarreraMezuaIdatzi();
			break;
		}
	} while (saguaclick != 999);
	return (irten != 1) ? 1 : 0;
}
void sarreraMezuaIdatzi()
{
	pantailaGarbitu();
	JOKOA_backSortu();
	JOKOA_jokatu();
	JOKOA_tutoriala();
	JOKOA_kreditoak();
	JOKOA_itxi();

	pantailaBerriztu();
}
int JOKOA_jokatu()
{
	int jokatuId = -1;
	jokatuId = irudiaKargatu(JOKATU);
	irudiaMugitu(jokatuId, 260, 120);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return jokatuId;
}
int JOKOA_tutoriala()
{
	int tutoId = -1;
	tutoId = irudiaKargatu(TUTORIALA);
	irudiaMugitu(tutoId, 260, 210);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return tutoId;
}
int JOKOA_kreditoak()
{
	int kreId = -1;
	kreId = irudiaKargatu(KREDITUAK);
	irudiaMugitu(kreId, 260, 300);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kreId;
}
int JOKOA_itxi()
{
	int itxId = -1;
	itxId = irudiaKargatu(ITXI);
	irudiaMugitu(itxId, 260, 390);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return itxId;
}
int JOKOA_itzuli()
{
	int itzulId = -1;
	itzulId = irudiaKargatu(BOTON_ITZULI);
	irudiaMugitu(itzulId, 50, 370);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return itzulId;
}
int JOKOA_teclaEzkerra()
{
	int teclaId = -1;
	teclaId = irudiaKargatu(TECLA_EZKERRA);
	irudiaMugitu(teclaId, 360, 88);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return teclaId;
}
int JOKOA_teclaEskuma()
{
	int teclaId = -1;
	teclaId = irudiaKargatu(TECLA_ESKUMA);
	irudiaMugitu(teclaId, 360, 150);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return teclaId;
}
int JOKOA_q()
{
	int teclaId = -1;
	teclaId = irudiaKargatu(TECLA_Q);
	irudiaMugitu(teclaId, 300, 320);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return teclaId;
}
int JOKOA_barra()
{
	int barraId = -1;
	barraId = irudiaKargatu(TECLA_BARRA);
	irudiaMugitu(barraId, 400, 230);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return barraId;
}
int JOKOA_backSortu()
{
	int backId = -1;
	backId = irudiaKargatu(MENU_BACKGROUD_IMAGE);
	irudiaMugitu(backId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return backId;
}
int JOKOA_KreditoakSortu()
{
	int kredId = -1;
	kredId = irudiaKargatu(KREDITOAK_IMAGE);
	irudiaMugitu(kredId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kredId;
}
int JOKOA_fondoaSortu()
{
	int fondoaId = -1;
	fondoaId = irudiaKargatu(JOKOA_BACKGROUND_IMAGE);
	irudiaMugitu(fondoaId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return fondoaId;
}