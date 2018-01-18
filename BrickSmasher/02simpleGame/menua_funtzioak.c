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
	int ebentu = 0, saguaclick = 0, barruan = 0, bar = 0, irten = 0;
	POSIZIOA pos;
	audioInit();
	loadTheMusic(MENU_AUDIO);
	playMusic();
	sarreraMezuaIdatzi();

	do
	{
		if (ebentu == TECLA_m)
		{
			toggleMusic();
		}
		pos = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		////BOTON DE JOKATU
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 260) && (pos.x <= 375) && (pos.y >= 120) && (pos.y <= 153) && barruan == 0)
		{
			saguaclick = 1;
			barruan = 1;
		}
		////BOTON DE TUTORIALA
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 260) && (pos.x <= 375) && (pos.y >= 210) && (pos.y <= 243) && barruan == 0)
		{
			saguaclick = 2;
			barruan = 1;
		}
		////BOTON DE KREDITUAK
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 260) && (pos.x <= 375) && (pos.y >= 300) && (pos.y <= 333) && barruan == 0)
		{
			saguaclick = 3;
			barruan = 1;
		}
		////BOTON ITXI JOKUA
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 260) && (pos.x <= 375) && (pos.y >= 390) && (pos.y <= 423) && barruan == 0)
		{
			saguaclick = 4;
			barruan = 1;
		}
		////BOTON ITZULI
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 50) && (pos.x <= 175) && (pos.y >= 370) && (pos.y <= 413) && barruan == 1)
		{
			saguaclick = 5;
			barruan = 0;
		}
		////BOTON HURRENGO TUTORIALA POWER UP
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 440) && (pos.x <= 565) && (pos.y >= 370) && (pos.y <= 403) && barruan == 1 && bar == 2) ////BOTON DE HU
		{
			saguaclick = 6;
			barruan = 0;
			bar = 0;
		}
		switch (saguaclick)
		{
		case 1:
			saguaclick = 999;
			barruan = 1;
			toggleMusic();
			audioTerminate();
			/*jokatu;*/
			break;

		case 2:pantailaGarbitu();
			saguaclick = 0;
			barruan = 1;
			bar = 2;
			JOKOA_fondoaSortu();
			JOKOA_teclaEzkerra();
			JOKOA_teclaEskuma();
			JOKOA_barra();
			JOKOA_power();
			JOKOA_itzuli();
			textuaIdatzi(50, 70, NOLA_JOKATU);
			textuaIdatzi(50, 140, NOLA1_JOKATU);
			textuaIdatzi(50, 190, NOLA3_JOKATU);
			textuaIdatzi(50, 250, NOLA2_JOKATU);
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

		case 6:
			pantailaGarbitu();
			saguaclick = 0;
			barruan = 1;
			bar = 2;
			JOKOA_fondoaSortu();
			JOKOA_q();
			JOKOA_itzuli();
			powermorea();
			powerberdea();
			powerhoria();
			textuaIdatzi(50, 67, NOLA4_JOKATU);
			textuaIdatzi(50, 130, NOLA5_JOKATU);
			textuaIdatzi(50, 185, NOLA6_JOKATU);
			textuaIdatzi(50, 219, NOLA7_JOKATU);
			textuaIdatzi(50, 278, NOLA8_JOKATU);
			textuaIdatzi(50, 328, NOLA9_JOKATU);
			pantailaBerriztu();
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
//int JOKOA_itxi2()
//{
//	int itxId = -1;
//	itxId = irudiaKargatu(ITXI);
//	irudiaMugitu(itxId, 440, 370);
//	pantailaGarbitu();
//	irudiakMarraztu();
//	pantailaBerriztu();
//	return itxId;
//
//}
int powermorea()
{
	int powId = -1;
	powId = irudiaKargatu(X_PURPLE_POWERUP);
	irudiaMugitu(powId, 50, 40);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return powId;
}
int powerberdea()
{
	int powId = -1;
	powId = irudiaKargatu(N_GREEN_POWERUP);
	irudiaMugitu(powId, 50, 160);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return powId;
}
int powerhoria()
{
	int powId = -1;
	powId = irudiaKargatu(S_YELLOW_POWERUP);
	irudiaMugitu(powId, 50, 250);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return powId;
}
int JOKOA_power()
{
	int powId = -1;
	powId = irudiaKargatu(HURRENGOA);
	irudiaMugitu(powId, 440, 370);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return powId;
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
	irudiaMugitu(teclaId, 360, 108);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return teclaId;
}
int JOKOA_teclaEskuma()
{
	int teclaId = -1;
	teclaId = irudiaKargatu(TECLA_ESKUMA);
	irudiaMugitu(teclaId, 360, 170);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return teclaId;
}
int JOKOA_q()
{
	int teclaId = -1;
	teclaId = irudiaKargatu(TECLA_Q);
	irudiaMugitu(teclaId, 300, 115);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return teclaId;
}
int JOKOA_barra()
{
	int barraId = -1;
	barraId = irudiaKargatu(TECLA_BARRA);
	irudiaMugitu(barraId, 400, 250);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return barraId;
}
//int JOKOA_menu()
//{
//	int menuraId = -1;
//	menuraId = irudiaKargatu(BOTON_MENU);
//	irudiaMugitu(menuraId, 50, 370);
//	pantailaGarbitu();
//	irudiakMarraztu();
//	pantailaBerriztu();
//	return menuraId;
//}

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