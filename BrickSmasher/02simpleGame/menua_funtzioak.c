#include "menua.h"
#include "arkanoid.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include "irudiaksortu.h"

#define WIN_SOUND ".\\sound\\WIN.wav"
#define LOSE_SOUND ".\\sound\\LOSE.wav"

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
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 50) && (pos.x <= 175) && (pos.y >= 430) && (pos.y <= 463) && barruan == 1)
		{
			saguaclick = 5;
			barruan = 0;
		}
		////BOTON HURRENGO TUTORIALA POWER UP
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 440) && (pos.x <= 565) && (pos.y >= 430) && (pos.y <= 463) && barruan == 1 && bar == 2) ////BOTON DE HU
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
		powergorria();
		textuaIdatzi(50, 70, NOLA_JOKATU);
		textuaIdatzi(50, 140, NOLA1_JOKATU);
		textuaIdatzi(50, 190, NOLA3_JOKATU);
		textuaIdatzi(50, 250, NOLA2_JOKATU);
		textuaIdatzi(50, 330, NOLA10_JOKATU);

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
			textuaIdatzi(50, 320, NOLA9_JOKATU);
			pantailaBerriztu();
			break;
		}
	} while (saguaclick != 999);
	return (irten != 1) ? 1 : 0;
}
int  jokoAmaierakoa(EGOERA egoera, int scoreArray[])
{
	int ebentu = 0, id;
	int idAudioGame;
	int idSoundGame;
	int saguaclick = 0;
	POSIZIOA pos;
	if (egoera == ITXITA) {
		saguaclick = 1;
	}
	if (egoera == IRABAZI) {
		idAudioGame = loadSound(JOKOA_SOUND_WIN);
		playSound(idAudioGame);
		loadTheMusic(WIN_SOUND);
		playMusic();
		id = IRABAZI_irudiaBistaratu(scoreArray);
	}
	else {
		idAudioGame = loadSound(JOKOA_SOUND_LOSE);
		playSound(idAudioGame);
		loadTheMusic(LOSE_SOUND);
		playMusic();
		id = BUKAERA_irudiaBistaratu(scoreArray);
	}
	do
	{
		pos = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == SAGU_BOTOIA_EZKERRA && (pos.x >= 243) && (pos.x <= 368) && (pos.y >= 408) && (pos.y <= 441))
		{
			saguaclick = 1;
		}
	} while (saguaclick != 1);
	/*audioTerminate();*/
	irudiaKendu(id);
	return (saguaclick != 1) ? 1 : 0;
}
EGOERA JOKOA_egoera(JOKALARIA_ELEMENTUA jokalaria, JOKO_ELEMENTUA pilota, int bizitza, int hutsik)
{
	EGOERA  ret = JOLASTEN;
	if (hutsik == 129)
	{
		ret = IRABAZI;
		pilota.pos.x = 20;
		pilota.pos.y = 20;
		irudiaKendu(jokalaria.id);
		irudiaKendu(pilota.id);
	}
	else if (bizitza == 0)
	{
		ret = GALDU;
		irudiaKendu(jokalaria.id);
		irudiaKendu(pilota.id);
	}
	return ret;
}