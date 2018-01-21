#include "arkanoid.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include "score.h"
#include "errealitateak.h"
#include "bizitza.h"
#include "menua.h"
#include "blokeak.h"
#include "powerup.h"
#include "kolisioak.h"
#include "irudiaksortu.h"

#define JOKOA_SOUND ".\\sound\\arkanoid_audio.wav"
#define JOKOA_PLAYER_IMAGE ".\\img\\barra1.bmp"
#define JOKOA_PELOTA_IMAGE ".\\img\\pelota.bmp"
#define JOKOA_ENERGIA_IMAGE ".\\img\\barra_energia.bmp"
#define JOKOA_TIROA_IMAGE ".\\img\\tiroa.bmp"
#define BUKAERA_SOUND_1 ".\\sound\\arkanoid_audio.wav"
#define BUKAERA_IMAGE ".\\img\\gameOver_3.bmp"
#define IRABAZI_IMAGE ".\\img\\IRABAZI.bmp"
#define TIROA_SOUND ".\\sound\\Tiro.wav"

int zein = 1;
int pwUP = 0;
int apurtu = 0;
int irten = 0;

int jokoa_pause();

//int  BUKAERA_menua(EGOERA egoera);

EGOERA jokatu(int scoreArray[])
{
	int posx = 0;
	int posy = 0;
	int hasi = 0;
	int multiballhasi = 0;
	int bizitza = 3, bihotzArray[3];
	int kontScore = 0, zenbakiArray[3];
	int zeinTiro = 0;
	int biak = 0;
	int id = 0;
	int lehenLaukizuzen = 0;
	int hutsik = 0;
	int tiroaid;
	int multiballon = 0;
	int pause = 0;
	int pauseid;

	EGOERA  egoera = JOLASTEN;
	int ebentu = 0;
	JOKO_ELEMENTUA pilota,  fondoa, barra, bihotzak, zenbakiak, multiBall;
	JOKALARIA_ELEMENTUA jokalaria;
	POWERUP_ELEMENTUA powerup;
	POWERUP_ELEMENTUA powerupak[4];
	LAUKIZUZENA_ELEMENTUA Laukizuzena;
	TIROA_ELEMENTUA  tiroa;
	POSIZIOA aux;
	LAUKIZUZENA_ELEMENTUA Blokeak[130];
	TIROA_ELEMENTUA Tiroak[8];

	jokalaria.pos.x = 280;
	jokalaria.pos.y = 400;
	jokalaria.egoera = NORMAL;

	multiBall.pos.x = 4000;
	multiBall.pos.y = 4000;

	
	Laukizuzena.pos.x = 280;
	Laukizuzena.pos.y = 400;

	bihotzak.pos.x = 280;
	bihotzak.pos.y = 400;

	zenbakiak.pos.x = 0;
	zenbakiak.pos.y = 0;

	pilota.pos.x = jokalaria.pos.x + 38;
	pilota.pos.y = jokalaria.pos.y - 23;
	barra.pos.x = jokalaria.pos.x;
	barra.pos.y = jokalaria.pos.y + 23;

	tiroa.pos.y = 1000;
	tiroa.pos.x = 1000;

	fondoa.pos.x = 0;
	fondoa.pos.y = 0;

	powerup.pos.x = 700;
	powerup.pos.y = -550;

	audioInit();
	loadTheMusic(JOKOA_SOUND);
	tiroaid = loadSound(TIROA_SOUND);
	//playMusic();    /////////////////////////Comentado para que no de la brasa durante el testeo, quitar para la publicación final
	fondoa.id = JOKOA_fondoaSortu();
	lehenLaukizuzen = laukizuzenakEzarri(Laukizuzena, Blokeak);
	bihotzakEzarri(bihotzak, bizitza, bihotzArray);
	jokalaria.id = JOKOA_jokalariaIrudiaSortu();
	pilota.id = JOKOA_pilotaIrudiaSortu();
	multiBall.id = JOKOA_pilotaIrudiaSortu(4000, 4000);
	barra.id = JOKOA_barraIrudiaSortu();
	puntuazioaMarraztu();
	powerupSortu(powerup, powerupak);
	tiroakSortu(tiroa, Tiroak);

	do
	{
		Sleep(6);
		pantailaGarbitu();
		arkatzKoloreaEzarri(0, 0, 0xFF);
		hutsik = 0;
		if (ebentu == TECLA_m)
		{
			toggleMusic();
		}
		if (hasi) {
			irudiaMugitu(pilota.id, pilota.pos.x, pilota.pos.y);
			irudiaMugitu(multiBall.id, multiBall.pos.x, multiBall.pos.y);
		}

		else
		{
			irudiaMugitu(pilota.id, jokalaria.pos.x + 38, jokalaria.pos.y - 23);
			if (multiballon == 1)
			{
				irudiaMugitu(multiBall.id, multiBall.pos.x, multiBall.pos.y);
			}
			
			irudiaAldatu(barra.id, 2);
		}
		irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		irudiaMugitu(barra.id, jokalaria.pos.x - 5, jokalaria.pos.y + 20);
		for (int i = 0; i < 4; i++)
		{
			irudiaMugitu(powerupak[i].id, powerupak[i].pos.x, powerupak[i].pos.y);
		}
		if (Tiroak[zeinTiro].puxkatu != 1)
		{
			irudiaMugitu(Tiroak[zeinTiro].id, Tiroak[zeinTiro].pos.x, Tiroak[zeinTiro].pos.y);
		}
		irudiakMarraztu();
		pantailaBerriztu();
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == TECLA_ESCAPE)
		{
			pauseid = jokoa_pause();
			do
			{

				ebentu = 0;
				ebentu = ebentuaJasoGertatuBada();
				if (ebentu == TECLA_m)
				{
					toggleMusic();
				}
				if (ebentu == TECLA_ESCAPE)
				{
					pause = 1;
				}

			} while (pause != 1);
			irudiaKendu(pauseid);
			pause = 0;
		}
		/////////////////////////////////////////////////////////////////////PILOTA JAURTI DA
		if (ebentu == TECLA_SPACE)
		{
			if (pilota.pos.x < 320 && hasi == 0)///////////////// Si esta a la izquierda de la mitad lo lanza hacia la izquierda
			{
				pilota.nora.ezkerrera = 1;
			}
			hasi = 1;
		}
		/////////////////////////////////////////////////////////////////////PILOTA JAURTI DA
		/////////////////////////////////////////////////////////////////////////////TIROAK
		if (Tiroak[zeinTiro].jaurti == 1) 
		{
			aux = ERREALITATE_FISIKOA_mugimenduaTIROA(Tiroak[zeinTiro].pos);
			Tiroak[zeinTiro].pos.y = aux.y;
		}
		if (zeinTiro == 7) {
			pwUP = 0;
			tiroakSortu(tiroa, Tiroak);
			zeinTiro = 0;
			pwUP = 0;
			powerupak[1].zein = 0;
		}
		if ((Tiroak[zeinTiro].pos.y >= 50) && (Tiroak[zeinTiro].pos.y <= 250) && (Tiroak[zeinTiro].pos.x >= 60) && (Tiroak[zeinTiro].pos.x <= 580) && Tiroak[zeinTiro].puxkatu != 1)
		{
			apurtu = tiroaPuxkatu(Tiroak[zeinTiro], Blokeak, lehenLaukizuzen);
			if (apurtu == 1)
			{
				zeinTiro++;
			}

		}
		else if (Tiroak[zeinTiro].pos.y == 0)
		{
			irudiaKendu(Tiroak[zeinTiro].id);
			zeinTiro++;
			apurtu = 1;
		}
		/////////////////////////////////////////////////////////////////////////////TIROAK
		////////////////////////////////////////////////////////////////////MUGIMENDUA LIMITATUA

		const Uint8 * state = SDL_GetKeyboardState(NULL);
		if ((state[SDL_SCANCODE_LEFT]) && (jokalaria.pos.x > 20)) jokalaria.pos.x -= 2;
		if ((state[SDL_SCANCODE_RIGHT]) && (jokalaria.pos.x < 520)) jokalaria.pos.x += 2;
		if ((state[SDL_SCANCODE_Q]) && (Tiroak[zeinTiro].jaurti == 0))
		{
			playSound(tiroaid);
			Tiroak[zeinTiro].pos.x = jokalaria.pos.x + 45;
			Tiroak[zeinTiro].pos.y = jokalaria.pos.y - 12;
			Tiroak[zeinTiro].jaurti = 1;
			irudiaAldatu(barra.id, 1);
		}

		if (hasi == 0)
		{
			pilota.pos.x = jokalaria.pos.x + 38;
			pilota.pos.y = jokalaria.pos.y - 23;
		}
		else
		{
			pilota.pos = pilotaMugitu(pilota.nora.behera, pilota.nora.ezkerrera, pilota.pos, aux);

			if ((pilota.pos.y + 24 >= 50) && (pilota.pos.y <= 250) && (pilota.pos.x + 24 >= 60) && (pilota.pos.x <= 580))
			{		
				id = Id_aurkitu(pilota.pos.x, pilota.pos.y, pilota.nora.behera, pilota.nora.ezkerrera);

				if (id >= 0 && id <= 129) 
				{
					if (Blokeak[id].apurtuta != 1)
					{
						if (jokalaria.egoera != GOD)
						{
							if ((pilota.pos.x + 21 <= Blokeak[id].pos.x) && (pilota.pos.x + 27 >= Blokeak[id].pos.x)) pilota.nora.ezkerrera = 1;
							else if (pilota.pos.x == Blokeak[id].pos.x + 40) pilota.nora.ezkerrera = 0;
							else if ((pilota.pos.y + 21 <= Blokeak[id].pos.y) && (pilota.pos.y + 27 >= Blokeak[id].pos.y)) pilota.nora.behera = 0;
							else if (pilota.pos.y == Blokeak[id].pos.y + 20) pilota.nora.behera = 1;
						}
						Blokeak[id].apurtuta = 1;
						irudiaKendu(id + lehenLaukizuzen);
						kontScore += 10;
						scoreArray[0] = kontScore;
						markagailua(scoreArray, zenbakiak, zenbakiArray);

						if (pwUP == 0) pwUP = powerupaErabaki(pwUP, powerupak, Blokeak, id);
						if (powerupak[1].zein == 1) zeinTiro = 1;
					}
				}
			}
			if (powerupak[0].pos.y > 500)
			{
				pwUP = 0;
				powerupak[0].zein = 0;
			}
			else if (powerupak[1].pos.y > 500)
			{
				pwUP = 0;
				powerupak[1].zein = 0;
			}
			else if (powerupak[2].pos.y > 500)
			{
				pwUP = 0;
				powerupak[2].zein = 0;
			}
			else if (powerupak[3].pos.y > 500)
			{
				pwUP = 0;
				powerupak[3].zein = 0;
			}
			if (pwUP == 1)
			{
				if (powerupak[0].zein == 1)
				{
					aux = ERREALITATE_FISIKOA_mugimenduaPOWERUP(powerupak[0].pos);
					powerupak[0].pos.y = aux.y;
					if (powerupak[0].pos.y == 390)
					{
						powerupak[0] = powerupJaso(powerupak[0], jokalaria.pos);
						if (powerupak[0].pos.x == 4000) jokalaria.egoera = MULTIBALL;
					}
				}
				if (powerupak[1].zein == 1)
				{
					aux = ERREALITATE_FISIKOA_mugimenduaPOWERUP(powerupak[1].pos);
					powerupak[1].pos.y = aux.y;
					if (powerupak[1].pos.y == 390)
					{
						powerupak[1] = powerupJaso(powerupak[1], jokalaria.pos);/*|| ((powerupak[1].pos.x+29 > jokalaria.pos.x) && (powerupak[1].pos.x+29 < (jokalaria.pos.x + 106)))*/
						if (powerupak[1].pos.x == 4000)
						{
							jokalaria.egoera = TIROAK;
							for (int i = 1; i <= 6; i++) Tiroak[i].jaurti = 0;
						}
					}
				}
				if (powerupak[2].zein == 1)
				{
					aux = ERREALITATE_FISIKOA_mugimenduaPOWERUP(powerupak[2].pos);
					powerupak[2].pos.y = aux.y;
					if (powerupak[2].pos.y == 390)
					{
						powerupak[2] = powerupJaso(powerupak[2], jokalaria.pos);
						if (powerupak[2].pos.x == 4000) jokalaria.egoera = ITSATSITA;
					}
				}
				if (powerupak[3].zein == 1)
				{
					aux = ERREALITATE_FISIKOA_mugimenduaPOWERUP(powerupak[3].pos);
					powerupak[3].pos.y = aux.y;
					if (powerupak[3].pos.y == 390)
					{
						powerupak[3] = powerupJaso(powerupak[3], jokalaria.pos);
						if (powerupak[3].pos.x == 4000)
						{
							if (pilota.pos.y >= 250 && pilota.nora.behera == 1) jokalaria.egoera = GODON;

							else jokalaria.egoera = GOD;
						}
					}
				}
				//amarillo 0 morado 1 berde 2 rojo 3 COJER EL PWUP
					if (jokalaria.egoera == TIROAK) 
					{
						irudiaAldatu(barra.id, 0);
						powerupak[1].zein = 0;

						for (int i = 1; i <= 6; i++) Tiroak[i].jaurti = 0;
						
						biak = 0;
						jokalaria.egoera = NORMAL;
					}
					if (jokalaria.egoera == ITSATSITA)
					{
						irudiaAldatu(barra.id, 0);
						powerupak[2].zein = 0;
						if ((pilota.pos.y == 377) && (pilota.pos.x > jokalaria.pos.x - 15) && (pilota.pos.x < (jokalaria.pos.x + 106)))
						{
							hasi = 0;
							pilota.nora.ezkerrera = 0;
							pilota.nora.behera = 0;
							pwUP = 0;
							jokalaria.egoera = NORMAL;
						}
						if (pilota.pos.y == 480) {
							jokalaria.egoera = NORMAL;
							pwUP = 0;
						}
					}
					if (jokalaria.egoera == MULTIBALL) {
						multiballon = 1;
						multiballhasi = 0;
						powerupak[0].zein = 0;
						irudiaMugitu(multiBall.id, pilota.pos.x + 24, pilota.pos.y);
						jokalaria.egoera = NORMAL;
					}
					//MULTIBALL ACTIVADO
					if (multiballon == 1)
					{
						if (multiballhasi == 0)
						{
							multiBall.pos = pilota.pos;
							multiballhasi = 1;

							if (pilota.nora.behera) multiBall.nora.behera = 0;
							else multiBall.nora.behera = 1;

							if (pilota.nora.ezkerrera) multiBall.nora.ezkerrera = 0;
							else multiBall.nora.ezkerrera = 1;
							////ARRIBA IZQUIERDA
							//if (!pilota.nora.behera && pilota.nora.ezkerrera) {
							//	multiBall.nora.behera = 1;
							//	multiBall.nora.ezkerrera = 0;
							//}
							////ARRIBA DERECHAa
							//else if (!pilota.nora.behera && !pilota.nora.ezkerrera) {
							//	multiBall.nora.behera = 1;
							//	multiBall.nora.ezkerrera = 1;
							//}
							////ABAJO DERECHA
							//else if (pilota.nora.behera && !pilota.nora.ezkerrera) {
							//	multiBall.nora.behera = 0;
							//	multiBall.nora.ezkerrera = 1;
							//}
							////ABAJO IZQUIERDA
							//else if (pilota.nora.behera && pilota.nora.ezkerrera) {
							//	multiBall.nora.behera = 0;
							//	multiBall.nora.ezkerrera = 0;
							//}
						}
						
						multiBall.pos = pilotaMugitu(multiBall.nora.behera, multiBall.nora.ezkerrera, multiBall.pos, aux);

						if ((multiBall.pos.y + 24 >= 50) && (multiBall.pos.y <= 250) && (multiBall.pos.x + 24 >= 60) && (multiBall.pos.x <= 580))
						{
							id = Id_aurkitu(multiBall.pos.x, multiBall.pos.y, multiBall.nora.behera, multiBall.nora.ezkerrera);

							if (id >= 0 && id <= 129)
							{
								if (Blokeak[id].apurtuta != 1)
								{
									if ((multiBall.pos.x + 21 <= Blokeak[id].pos.x) && (multiBall.pos.x + 27 >= Blokeak[id].pos.x)) multiBall.nora.ezkerrera = 1;
									else if (multiBall.pos.x == Blokeak[id].pos.x + 40) multiBall.nora.ezkerrera = 0;
									else if ((multiBall.pos.y + 21 <= Blokeak[id].pos.y) && (multiBall.pos.y + 27 >= Blokeak[id].pos.y)) multiBall.nora.behera = 0;
									else if (multiBall.pos.y == Blokeak[id].pos.y + 20) multiBall.nora.behera = 1;

									Blokeak[id].apurtuta = 1;
									irudiaKendu(id + lehenLaukizuzen);
									kontScore += 10;
									scoreArray[0] = kontScore;
									markagailua(scoreArray, zenbakiak, zenbakiArray);
								}
							}
						}
						//REBOTE ENTRE PELOTAS
						
						if ((pilota.pos.x >= multiBall.pos.x + 21) && (pilota.pos.x <= multiBall.pos.x + 27) && (((pilota.pos.y <= multiBall.pos.y + 24) && (pilota.pos.y >= multiBall.pos.y)) || ((pilota.pos.y + 24 >= multiBall.pos.y) && (pilota.pos.y + 24 <= multiBall.pos.y + 24))))
						{
							multiBall.nora.ezkerrera = 1;
							pilota.nora.ezkerrera = 0;
						}
						else if ((multiBall.pos.x >= pilota.pos.x + 21) && (multiBall.pos.x <= pilota.pos.x + 27) && (((multiBall.pos.y <= pilota.pos.y + 24) && (multiBall.pos.y >= pilota.pos.y)) || ((multiBall.pos.y + 24 >= pilota.pos.y) && (multiBall.pos.y + 24 <= pilota.pos.y + 24)))) {
							multiBall.nora.ezkerrera = 0;
							pilota.nora.ezkerrera = 1;
						}
						else if ((pilota.pos.y >= multiBall.pos.y + 21) && (pilota.pos.y <= multiBall.pos.y + 27) && (((pilota.pos.x <= multiBall.pos.x + 24) && (pilota.pos.x >= multiBall.pos.x)) || ((pilota.pos.x + 24 >= multiBall.pos.x) && (pilota.pos.x + 24 <= multiBall.pos.x + 24))))
						{
							pilota.nora.behera = 1;
							multiBall.nora.behera = 0;
						}
						else if ((multiBall.pos.y >= pilota.pos.y + 21) && (multiBall.pos.y <= pilota.pos.y + 27) && (((multiBall.pos.x <= pilota.pos.x + 24) && (multiBall.pos.x >= pilota.pos.x)) || ((multiBall.pos.x + 24 >= pilota.pos.x) && (multiBall.pos.x + 24 <= pilota.pos.x + 24)))) {
							pilota.nora.behera = 0;
							multiBall.nora.behera = 1;
						}

						if (multiBall.pos.x > 595) multiBall.nora.ezkerrera = 1;

						if (multiBall.pos.y < 15) multiBall.nora.behera = 1;

						if (multiBall.pos.x < 20) multiBall.nora.ezkerrera = 0;

						if (multiBall.pos.y > 480) {
							pwUP = 0;
							multiballon = 0;
						}
						if (pilota.pos.y > 480) 
						{
							pilota.pos = multiBall.pos;
							multiBall.pos.x = 4000;
							multiBall.pos.y = 4000;					
							pwUP = 0;
							multiballon = 0;
							pilota.nora.ezkerrera = multiBall.nora.ezkerrera;
							pilota.nora.behera = multiBall.nora.ezkerrera;
						}
					}
			}
			else
			{
				for (int i = 0; i < 3; i++) 
				{
					irudiaMugitu(powerupak[i].id, 1000, -1000);
					powerupak[i].pos.x = 1000;
					powerupak[i].pos.y = -1000;
				}
			}

			if (pilota.pos.y == 377)
			{
				pilota.nora.behera = jokalariaErrebote(pilota.pos, jokalaria.pos);
				pilota.nora.ezkerrera = jokalariaErreboteNoranzkoa(pilota.pos, jokalaria.pos, pilota.nora.ezkerrera);
				if (jokalaria.egoera == GOD)
				{
					pwUP = 0;
					jokalaria.egoera = NORMAL;
				}
				if (jokalaria.egoera == GODON)
				{
					jokalaria.egoera = GOD;
				}
			}
			//MULTIBALL jokalari
			if (multiBall.pos.y == 377)
			{
				multiBall.nora.behera = jokalariaErrebote(multiBall.pos, jokalaria.pos);
				multiBall.nora.ezkerrera = jokalariaErreboteNoranzkoa(multiBall.pos, jokalaria.pos, multiBall.nora.ezkerrera);
			}
			////BARRAREN ALDEAN ERREBOTEA
			if ((pilota.pos.x + 24 == jokalaria.pos.x) && (pilota.pos.y > 400) && (pilota.pos.y < 423)) pilota.nora.ezkerrera = 1;
			if ((pilota.pos.x == jokalaria.pos.x + 106) && (pilota.pos.y > 400) && (pilota.pos.y < 423)) pilota.nora.ezkerrera = 0;
			////////////////////////////LO MISMO CON MULTIBALL
			if ((multiBall.pos.x + 24 == jokalaria.pos.x) && (multiBall.pos.y > 400) && (multiBall.pos.y < 427)) multiBall.nora.ezkerrera = 1;
			if ((multiBall.pos.x == jokalaria.pos.x + 106) && (multiBall.pos.y > 400) && (multiBall.pos.y < 427)) multiBall.nora.ezkerrera = 0;
			////////////////////////////
		}

		///////////////////////////////////////////////////////////////MUGIMENDUA LIMITATUTA
		//////////////////////////////////////////////////////////////ERREBOTEAK PARETETAN
		if (pilota.pos.x > 595) pilota.nora.ezkerrera = 1;

		if (pilota.pos.y < 15) pilota.nora.behera = 1;

		if (pilota.pos.x < 20) pilota.nora.ezkerrera = 0;
		///////////////////////////////////////////////////////////////ERREBOTEAK PARETETAN
		///////////////////////////////////////////////////////////////BIZITZAK
		if (pilota.pos.y > 480 && multiBall.pos.y > 480)
		{
			bizitza--;
			bihotzaKendu(bizitza, bihotzArray);
			hasi = 0;
			pilota.nora.ezkerrera = 0;
			pilota.nora.behera = 0;
			jokalaria.pos.x = 280;
			jokalaria.pos.y = 400;
			pilota.pos.x = jokalaria.pos.x + 38;
			pilota.pos.y = jokalaria.pos.y - 23;
			for (int j = 1; j <= 6; j++)
			{
				Tiroak[j].pos.x = 4000;
				Tiroak[j].pos.y = 4000;
				Tiroak[j].jaurti = 1;
				irudiaMugitu(Tiroak[j].id, Tiroak[j].pos.x, Tiroak[j].pos.y);
			}
			zeinTiro = 6;
			for (int i = 0; i < 3; i++)
			{
				powerupak[i].pos.x = 1000;
				powerupak[i].pos.y = 1000;
				powerupak[i].zein = 0;
			}
			pwUP = 0;
		}
		///////////////////////////////////////////////////////////////BIZITZAK
		while (Blokeak[hutsik].apurtuta && hutsik < 129) hutsik++;
		egoera = JOKOA_egoera(jokalaria, pilota, bizitza, hutsik);
	} while (egoera == JOLASTEN);
	irudiaKendu(jokalaria.id);
	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}