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

#define MENU_BACKGROUD_IMAGE ".\\img\\men.bmp"
#define JOKOA_SOUND ".\\sound\\arkanoid_audio.wav"
#define JOKOA_PLAYER_IMAGE ".\\img\\barra1.bmp"
#define JOKOA_PELOTA_IMAGE ".\\img\\pelota.bmp"
#define JOKOA_ENERGIA_IMAGE ".\\img\\barra_energia.bmp"
#define JOKOA_TIROA_IMAGE ".\\img\\tiroa.bmp"
#define JOKOA_SOUND_WIN ".\\sound\\you_win.wav"
#define JOKOA_SOUND_LOSE ".\\sound\\you_lose.wav" 
#define BUKAERA_SOUND_1 ".\\sound\\arkanoid_audio.wav"
#define BUKAERA_IMAGE ".\\img\\gameOver_3.bmp"
#define IRABAZI_IMAGE ".\\img\\IRABAZI.bmp"
#define TIROA_SOUND ".\\sound\\Tiro.wav"
#define MEZUA "Sakatu return jokoa amaitzeko."
#define PAUSA2 ".\\img\\pause.bmp"

int zein = 1;
int pwUP = 0;
int apurtu = 0;
int irten = 0;

int JOKOA_jokalariaIrudiaSortu();
int JOKOA_barraIrudiaSortu();
int JOKOA_pilotaIrudiaSortu();
int jokoa_pause();
EGOERA JOKOA_egoera(JOKALARIA_ELEMENTUA jokalaria, JOKO_ELEMENTUA pilota, int bizitza, int hutsik);
//int  BUKAERA_menua(EGOERA egoera);
int BUKAERA_irudiaBistaratu(int scoreArray[]);
int IRABAZI_irudiaBistaratu(int scoreArray[]);




EGOERA jokatu(int scoreArray[])
{
	int mugitu = 0;
	int mugituEZK = 0;
	int posx = 0;
	int posy = 0;
	int hasi = 0;
	int multiballhasi = 0;
	int rebote = 0;
	int goian = 0;
	int rebotemulti = 0;
	int goianmulti = 0;
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
	JOKO_ELEMENTUA pilota,  fondoa, barra, bihotzak, zenbakiak;
	JOKALARIA_ELEMENTUA jokalaria, multiballa;
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

	multiballa.pos.x = 4000;
	multiballa.pos.y = 4000;

	
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
	multiballa.id = JOKOA_pilotaIrudiaSortu(4000, 4000);
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
			irudiaMugitu(multiballa.id, multiballa.pos.x, multiballa.pos.y);
		}

		else
		{
			irudiaMugitu(pilota.id, jokalaria.pos.x + 38, jokalaria.pos.y - 23);
			irudiaMugitu(multiballa.id, multiballa.pos.x, multiballa.pos.y);
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
				rebote = 1;
			}
			hasi = 1;
		}
		/////////////////////////////////////////////////////////////////////PILOTA JAURTI DA
		/////////////////////////////////////////////////////////////////////////////TIROAK
		if (ebentu == TECLA_q && Tiroak[zeinTiro].jaurti == 0)
		{
			playSound(tiroaid);
			Tiroak[zeinTiro].pos.x = jokalaria.pos.x + 45;
			Tiroak[zeinTiro].pos.y = jokalaria.pos.y - 12;
			Tiroak[zeinTiro].jaurti = 1;
			irudiaAldatu(barra.id, 1);

		}
		if (Tiroak[zeinTiro].jaurti == 1) {
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

		if ((ebentu == TECLA_RIGHT) && (jokalaria.pos.x < 520)) mugitu = 1;

		else if ((ebentu == TECLA_LEFT)	&& (jokalaria.pos.x > 35)) mugituEZK = 1;

		else if (ebentu != TECLA_RIGHT || ebentu != TECLA_LEFT)
		{
			mugitu = 0;
			mugituEZK = 0;
		}
		if (hasi == 0)
		{
			if (mugitu) 
			{
				aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
				jokalaria.pos.x = aux.x;
			}
			if (mugituEZK)
			{
				aux = ERREALITATE_FISIKOA_mugimenduaEZK(jokalaria.pos);
				jokalaria.pos.x = aux.x;
			}
			pilota.pos.x = jokalaria.pos.x + 38;
			pilota.pos.y = jokalaria.pos.y - 23;
		}
		else
		{
			pilota.pos = pilotaMugitu(goian, rebote, pilota.pos, aux);

			if ((pilota.pos.y + 24 >= 50) && (pilota.pos.y <= 250) && (pilota.pos.x + 24 >= 60) && (pilota.pos.x <= 580))
			{		
				id = Id_aurkitu(pilota.pos.x, pilota.pos.y, goian, rebote);

				if (id >= 0 && id <= 129) 
				{
					if (Blokeak[id].apurtuta != 1)
					{
						if (jokalaria.egoera != GOD)
						{
							if ((pilota.pos.x + 21 <= Blokeak[id].pos.x) && (pilota.pos.x + 27 >= Blokeak[id].pos.x)) rebote = 1;
							else if (pilota.pos.x == Blokeak[id].pos.x + 40) rebote = 0;
							else if ((pilota.pos.y + 21 <= Blokeak[id].pos.y) && (pilota.pos.y + 27 >= Blokeak[id].pos.y)) goian = 0;
							else if (pilota.pos.y == Blokeak[id].pos.y + 20) goian = 1;
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
			if (powerupak[0].pos.y > 500 || powerupak[1].pos.y > 500 || powerupak[2].pos.y > 500 || powerupak[3].pos.y > 500)
			{
				pwUP = 0;
				powerupak[0].zein = 0;
				powerupak[1].zein = 0;
				powerupak[2].zein = 0;
				powerupak[3].zein = 0;

			}
				if (pwUP == 1)
				{
					if (powerupak[0].zein == 1)
					{
						aux = ERREALITATE_FISIKOA_mugimenduaPOWERUP(powerupak[0].pos);
						powerupak[0].pos.y = aux.y;
					}
					if (powerupak[1].zein == 1)
					{
						aux = ERREALITATE_FISIKOA_mugimenduaPOWERUP(powerupak[1].pos);
						powerupak[1].pos.y = aux.y;
					}
					if (powerupak[2].zein == 1)
					{
						aux = ERREALITATE_FISIKOA_mugimenduaPOWERUP(powerupak[2].pos);
						powerupak[2].pos.y = aux.y;
					}
					if (powerupak[3].zein == 1)
					{
						aux = ERREALITATE_FISIKOA_mugimenduaPOWERUP(powerupak[3].pos);
						powerupak[3].pos.y = aux.y;
					}
					//amarillo 0 morado 1 berde 2 COJER EL PWUP
					if ((powerupak[0].pos.y == 390) || (powerupak[1].pos.y == 390) || (powerupak[2].pos.y == 390) || (powerupak[3].pos.y == 390))
					{
						if (powerupak[0].zein == 1)
						{
							if ((powerupak[0].pos.x > jokalaria.pos.x) && (powerupak[0].pos.x < (jokalaria.pos.x + 106)))
							{

								irudiaMugitu(powerupak[0].id, 4000, -4000);
								powerupak[0].pos.x = 4000;
								powerupak[0].pos.y = -4000;
								jokalaria.egoera = MULTIBALL;
							}
						}
						else if (powerupak[1].zein == 1)
						{
							if (((powerupak[1].pos.x > jokalaria.pos.x) && (powerupak[1].pos.x < (jokalaria.pos.x + 106))) /*|| ((powerupak[1].pos.x+29 > jokalaria.pos.x) && (powerupak[1].pos.x+29 < (jokalaria.pos.x + 106)))*/)
							{
								irudiaMugitu(powerupak[1].id, 4000, -4000);
								powerupak[1].pos.x = 4000;
								powerupak[1].pos.y = -4000;
								jokalaria.egoera = TIROAK;
								for (int i = 1; i <= 6; i++)
								{
									Tiroak[i].jaurti = 0;
								}
							}
						}
						else if (powerupak[2].zein == 1)
						{
							if ((powerupak[2].pos.x > jokalaria.pos.x) && (powerupak[2].pos.x < (jokalaria.pos.x + 106)))
							{

								irudiaMugitu(powerupak[2].id, 4000, -4000);
								powerupak[2].pos.x = 4000;
								powerupak[2].pos.y = -4000;
								jokalaria.egoera = ITSATSITA;
							}
						}
						else if (powerupak[3].zein == 1)
						{
							if ((powerupak[3].pos.x > jokalaria.pos.x) && (powerupak[3].pos.x < (jokalaria.pos.x + 106)))
							{

								irudiaMugitu(powerupak[3].id, 4000, -4000);
								powerupak[3].pos.x = 4000;
								powerupak[3].pos.y = -4000;
								if (pilota.pos.y >= 250 && goian == 1)
								{
									jokalaria.egoera = GODON;
								}
								else
								{
									jokalaria.egoera = GOD;
								}

							}
						}

					}
					if (jokalaria.egoera == TIROAK) 
					{
						irudiaAldatu(barra.id, 0);
						powerupak[1].zein = 0;
						for (int i = 1; i <= 6; i++)
						{
							Tiroak[i].jaurti = 0;
						}
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
							rebote = 0;
							goian = 0;
							pwUP = 0;
							jokalaria.egoera = NORMAL;
						}
						if (pilota.pos.y == 480) {
							jokalaria.egoera = NORMAL;
							pwUP = 0;
						}
					}
					if (jokalaria.egoera == MULTIBALL) {
						//pwUP = 0;
						//irudiaAldatu(barra.id, 0);
						multiballon = 1;
						multiballhasi = 0;
						powerupak[0].zein = 0;
						irudiaMugitu(multiballa.id, pilota.pos.x + 24, pilota.pos.y);
						/*multiballa.pos.x = pilota.pos.x+24;
						multiballa.pos.x = pilota.pos.y;*/
						jokalaria.egoera = NORMAL;
					}
					//MULTIBALL ACTIVADO
					if (multiballon == 1)
					{
						if (multiballhasi == 0)
						{
							multiballa.pos = pilota.pos;
							multiballhasi = 1;
							//ARRIBA IZQUIERDA
							if (!goian && rebote) {
								goianmulti = 1;
								rebotemulti = 0;
							}
							//ARRIBA DERECHAa
							else if (!goian && !rebote) {
								goianmulti = 1;
								rebotemulti = 1;
							}
							//ABAJO DERECHA
							else if (goian && !rebote) {
								goianmulti = 0;
								rebotemulti = 1;
							}
							//ABAJO IZQUIERDA
							else if (goian && rebote) {
								goianmulti = 0;
								rebotemulti = 0;
							}
						}
						
						multiballa.pos = pilotaMugitu(goianmulti, rebotemulti, multiballa.pos, aux);

						if ((multiballa.pos.y + 24 >= 50) && (multiballa.pos.y <= 250) && (multiballa.pos.x + 24 >= 60) && (multiballa.pos.x <= 580))
						{
							id = Id_aurkitu(multiballa.pos.x, multiballa.pos.y, goianmulti, rebotemulti);

							if (id >= 0 && id <= 129)
							{
								if (Blokeak[id].apurtuta != 1)
								{
									if ((multiballa.pos.x + 21 <= Blokeak[id].pos.x) && (multiballa.pos.x + 27 >= Blokeak[id].pos.x)) rebotemulti = 1;
									else if (multiballa.pos.x == Blokeak[id].pos.x + 40) rebotemulti = 0;
									else if ((multiballa.pos.y + 21 <= Blokeak[id].pos.y) && (multiballa.pos.y + 27 >= Blokeak[id].pos.y)) goianmulti = 0;
									else if (multiballa.pos.y == Blokeak[id].pos.y + 20) goianmulti = 1;

									Blokeak[id].apurtuta = 1;
									irudiaKendu(id + lehenLaukizuzen);
									kontScore += 10;
									scoreArray[0] = kontScore;
									markagailua(scoreArray, zenbakiak, zenbakiArray);


								}
							}
						}
						//REBOTE ENTRE PELOTAS
						
						if ((pilota.pos.x >= multiballa.pos.x + 21) && (pilota.pos.x <= multiballa.pos.x + 27) && (((pilota.pos.y <= multiballa.pos.y + 24) && (pilota.pos.y >= multiballa.pos.y)) || ((pilota.pos.y + 24 >= multiballa.pos.y) && (pilota.pos.y + 24 <= multiballa.pos.y + 24))))
						{
							rebotemulti = 1;
							rebote = 0;
						}
						else if ((multiballa.pos.x >= pilota.pos.x + 21) && (multiballa.pos.x <= pilota.pos.x + 27) && (((multiballa.pos.y <= pilota.pos.y + 24) && (multiballa.pos.y >= pilota.pos.y)) || ((multiballa.pos.y + 24 >= pilota.pos.y) && (multiballa.pos.y + 24 <= pilota.pos.y + 24)))) {
							rebotemulti = 0;
							rebote = 1;
						}
						else if ((pilota.pos.y >= multiballa.pos.y + 21) && (pilota.pos.y <= multiballa.pos.y + 27) && (((pilota.pos.x <= multiballa.pos.x + 24) && (pilota.pos.x >= multiballa.pos.x)) || ((pilota.pos.x + 24 >= multiballa.pos.x) && (pilota.pos.x + 24 <= multiballa.pos.x + 24))))
						{
							goian = 1;
							goianmulti = 0;
						}
						else if ((multiballa.pos.y >= pilota.pos.y + 21) && (multiballa.pos.y <= pilota.pos.y + 27) && (((multiballa.pos.x <= pilota.pos.x + 24) && (multiballa.pos.x >= pilota.pos.x)) || ((multiballa.pos.x + 24 >= pilota.pos.x) && (multiballa.pos.x + 24 <= pilota.pos.x + 24)))) {
							goian = 0;
							goianmulti = 1;
						}



						if (multiballa.pos.x > 595) rebotemulti = 1;

						if (multiballa.pos.y < 15) goianmulti = 1;

						if (multiballa.pos.x < 20) rebotemulti = 0;

						if (multiballa.pos.y > 480) {
							pwUP = 0;
							multiballon = 0;
						}
						if (pilota.pos.y > 480) {
							pilota.pos.x = multiballa.pos.x;
							pilota.pos.y = multiballa.pos.y;
							multiballa.pos.x = 4000;
							multiballa.pos.y = 4000;					
							pwUP = 0;
							multiballon = 0;
							if (rebotemulti == 1) rebote = 1;
							if (rebotemulti == 0) rebote = 0;
							if (goianmulti == 1) goian = 1;
							if (goianmulti == 0) goian = 0;
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
				goian = jokalariaErrebote(pilota.pos, jokalaria.pos);
				rebote = jokalariaErreboteNoranzkoa(pilota.pos, jokalaria.pos, rebote);
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
			if (multiballa.pos.y == 377)
			{
				goianmulti = jokalariaErrebote(multiballa.pos, jokalaria.pos);
				rebotemulti = jokalariaErreboteNoranzkoa(multiballa.pos, jokalaria.pos, rebotemulti);
			}

			////BARRAREN ALDEAN ERREBOTEA
			if ((pilota.pos.x+24 == jokalaria.pos.x) && (pilota.pos.y > 400) && (pilota.pos.y < 423)) rebote = 1;
			if ((pilota.pos.x == jokalaria.pos.x + 106) && (pilota.pos.y > 400) && (pilota.pos.y < 423)) rebote = 0;
			////////////////////////////LO MISMO CON MULTIBALL
			if ((multiballa.pos.x == jokalaria.pos.x) && (multiballa.pos.y > 400) && (multiballa.pos.y < 427)) rebotemulti = 1;
			if ((multiballa.pos.x == jokalaria.pos.x + 106) && (multiballa.pos.y > 400) && (multiballa.pos.y < 427)) rebotemulti = 0;
			////////////////////////////

			if (mugitu)
			{
				aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
				jokalaria.pos.x = aux.x;
			}
			if (mugituEZK)
			{
				aux = ERREALITATE_FISIKOA_mugimenduaEZK(jokalaria.pos);
				jokalaria.pos.x = aux.x;
			}
		}

		///////////////////////////////////////////////////////////////MUGIMENDUA LIMITATUTA
		//////////////////////////////////////////////////////////////ERREBOTEAK PARETETAN
		if (pilota.pos.x > 595) rebote = 1;

		if (pilota.pos.y < 15) goian = 1;

		if (pilota.pos.x < 20) rebote = 0;
		///////////////////////////////////////////////////////////////ERREBOTEAK PARETETAN
		///////////////////////////////////////////////////////////////BIZITZAK
		if (pilota.pos.y > 480 && multiballa.pos.y > 480)
		{
			bizitza--;
			bihotzaKendu(bizitza, bihotzArray);
			hasi = 0;
			rebote = 0;
			goian = 0;
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
/////////////////////////////////////////////////////////////////////////JOKOAREN AMAIERA
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

/////////////////////////////////////////////////////////////////////////JOKOAREN AMAIERA
int JOKOA_jokalariaIrudiaSortu() 
{
  int barraId = -1;
  barraId = irudiaKargatu(JOKOA_PLAYER_IMAGE);
  irudiaMugitu(barraId, 10, 239);
  pantailaGarbitu();
  irudiakMarraztu();
  pantailaBerriztu();
  return barraId;
}

int JOKOA_barraIrudiaSortu()
{
	int energiaId = -1;
	energiaId = irudiaKargatu(JOKOA_ENERGIA_IMAGE);
	irudiaMugitu(energiaId, 10, 239);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return energiaId;
}
int JOKOA_TiroaIrudiaSortu()
{
	int tiroaID = -1;
	tiroaID = irudiaKargatu(JOKOA_TIROA_IMAGE);
	irudiaMugitu(tiroaID, 1000, 1000);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return tiroaID;
}
int jokoa_pause()
{
	int pilotaId = -1;
	pilotaId = irudiaKargatu(PAUSA2);
	irudiaMugitu(pilotaId, 130, 240);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pilotaId;
}

int JOKOA_pilotaIrudiaSortu()
{
	int pilotaId = -1;
	pilotaId = irudiaKargatu(JOKOA_PELOTA_IMAGE);
	irudiaMugitu(pilotaId, 10, 239);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pilotaId;
}

int  jokoAmaierakoa(EGOERA egoera, int scoreArray[])
{
	int ebentu = 0, id;
	int idAudioGame;

	if (egoera == IRABAZI) {
		idAudioGame = loadSound(JOKOA_SOUND_WIN);
		playSound(idAudioGame);
		id = IRABAZI_irudiaBistaratu(scoreArray);
	}
	else {
		idAudioGame = loadSound(JOKOA_SOUND_LOSE);
		playSound(idAudioGame);
		id = BUKAERA_irudiaBistaratu(scoreArray);
	}
	do
	{
		ebentu = ebentuaJasoGertatuBada();
	} while ((ebentu != TECLA_RETURN) && (ebentu != SAGU_BOTOIA_ESKUMA));
	/*audioTerminate();*/
	irudiaKendu(id);
	return (ebentu != TECLA_RETURN) ? 1 : 0;
}

int IRABAZI_irudiaBistaratu(int scoreArray[])
{
	int id = -1;
	id = irudiaKargatu(IRABAZI_IMAGE);
	irudiaMugitu(id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	textuaIdatzi(50, 400, MEZUA);
	pantailaBerriztu();
	return id;
}

int BUKAERA_irudiaBistaratu(int scoreArray[])
{
	int id = -1;
	id = irudiaKargatu(BUKAERA_IMAGE);
	irudiaMugitu(id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	finalScore(scoreArray);
	textuaIdatzi(50, 400, MEZUA);
	pantailaBerriztu();
	return id;
}