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

#define MENU_BACKGROUD_IMAGE ".\\img\\men.bmp"
#define JOKOA_SOUND ".\\sound\\arkanoid_audio.wav"
#define JOKOA_PLAYER_IMAGE ".\\img\\barra1.bmp"
#define JOKOA_PELOTA_IMAGE ".\\img\\pelota.bmp"
#define JOKOA_ENERGIA_IMAGE ".\\img\\barra_energia.bmp"
#define JOKOA_TIROA_IMAGE ".\\img\\Tiroa.bmp"
#define JOKOA_SOUND_WIN ".\\sound\\you_win.wav"
#define JOKOA_SOUND_LOOSE ".\\sound\\you_lose.wav" 
#define BUKAERA_SOUND_1 ".\\sound\\arkanoid_audio.wav"
#define BUKAERA_IMAGE ".\\img\\gameOver_3.bmp"
#define IRABAZI_IMAGE ".\\img\\IRABAZI.bmp"
#define TIROA_SOUND ".\\sound\\Tiro.wav"
#define S_YELLOW_POWERUP ".\\img\\s_Yellow.bmp"
#define X_PURPLE_POWERUP ".\\img\\x_Purple.bmp"
#define N_GREEN_POWERUP ".\\img\\n_Green.bmp"

int zein = 1;
int pwUP = 0;
int apurtu = 0;
int irten = 0;
int JOKOA_jokalariaIrudiaSortu();
int JOKOA_barraIrudiaSortu();
int zifra(int posizioax, int posizioay, int kontScore);
int JOKOA_pilotaIrudiaSortu();
int JOKOA_SYPowerUPIrudiaSortu(POWERUP_ELEMENTUA pow, POWERUP_ELEMENTUA powerupak[]);
int Id_aurkitu(int x, int y);
int tiroaPuxkatu(TIROA_ELEMENTUA tiroa, LAUKIZUZENA_ELEMENTUA Blokeak[], int lehenlaukia);

EGOERA JOKOA_egoera(JOKALARIA_ELEMENTUA jokalaria, JOKO_ELEMENTUA pilota, int bizitza, int hutsik);
int zeinPOWER(JOKO_ELEMENTUA zein, int posx, int posy);
int zeinPOWERY(JOKO_ELEMENTUA zein, int posx, int posy);
int rng(int zenb);
void powerupSortu(POWERUP_ELEMENTUA pow, POWERUP_ELEMENTUA powerupak[]);
//int  BUKAERA_menua(EGOERA egoera);
int BUKAERA_irudiaBistaratu(int scoreArray[]);
int IRABAZI_irudiaBistaratu(int scoreArray[]);


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

EGOERA jokatu(int scoreArray[])
{
	int mugitu = 0;
	int mugituEZK = 0;
	int posx = 0;
	int posy = 0;
	int hasi = 0;
	int rebote = 0;
	int goian = 0;
	int bizitza = 3, bihotzArray[3];
	int kontScore = 0, zenbakiArray[3];
	int random;
	int zeinTiro = 0;
	int biak = 0;
	int id = 0;
	int lehenLaukizuzen = 0;
	int hutsik = 0;
	int tiroaid;

	EGOERA  egoera = JOLASTEN;
	int ebentu = 0;
	JOKO_ELEMENTUA pilota,  fondoa, barra, bihotzak, zenbakiak;
	JOKALARIA_ELEMENTUA jokalaria;
	POWERUP_ELEMENTUA powerup;
	POWERUP_ELEMENTUA powerupak[3];
	LAUKIZUZENA_ELEMENTUA Laukizuzena;
	TIROA_ELEMENTUA  tiroa;
	POSIZIOA aux;
	LAUKIZUZENA_ELEMENTUA Blokeak[130];
	TIROA_ELEMENTUA Tiroak[7];

	jokalaria.pos.x = 280;
	jokalaria.pos.y = 400;
	jokalaria.egoera = NORMAL;
	
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
	barra.id = JOKOA_barraIrudiaSortu();
	puntuazioaMarraztu();
	powerupSortu(powerup, powerupak);
	tiroakSortu(tiroa, Tiroak);

	do
	{
		Sleep(8);
		pantailaGarbitu();
		arkatzKoloreaEzarri(0, 0, 0xFF);
		hutsik = 0;

		if (hasi) irudiaMugitu(pilota.id, pilota.pos.x, pilota.pos.y);

		else
		{
			irudiaMugitu(pilota.id, jokalaria.pos.x + 38, jokalaria.pos.y - 23);
			irudiaAldatu(barra.id, 2);
		}
		irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		irudiaMugitu(barra.id, jokalaria.pos.x - 5, jokalaria.pos.y + 20);
		for (int i = 0; i < 3; i++)
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
		if (zeinTiro == 6) {
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

		if (ebentu == TECLA_RIGHT) mugitu = 1;

		else if (ebentu == TECLA_LEFT)	mugituEZK = 1;

		else if (ebentu != TECLA_RIGHT || ebentu != TECLA_LEFT)
		{
			mugitu = 0;
			mugituEZK = 0;
		}
		if (jokalaria.pos.x > 533)
		{
			mugitu = 0;
			mugituEZK = 1;
		}
		if (jokalaria.pos.x < 20)
		{
			mugitu = 1;
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
			if (goian == 1)
			{
				aux = ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEGOI(pilota.pos);
				pilota.pos.y = aux.y;

				if (rebote == 0)
				{
					aux = ERREALITATE_FISIKOA_mugimenduaPILOTA(pilota.pos);
					pilota.pos.x = aux.x;
				}
				else if (rebote == 1)
				{
					aux = ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEESK(pilota.pos);
					pilota.pos.x = aux.x;
				}
			}
			else
			{
				if (rebote == 0)
				{
					aux = ERREALITATE_FISIKOA_mugimenduaPILOTA(pilota.pos);
					pilota.pos.y = aux.y;
					pilota.pos.x = aux.x;
				}
				else if (rebote == 1)
				{
					aux = ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEESK(pilota.pos);
					pilota.pos.y = aux.y;
					pilota.pos.x = aux.x;
				}
			}
			if ((pilota.pos.y + 24 >= 50) && (pilota.pos.y <= 250) && (pilota.pos.x + 24 >= 60) && (pilota.pos.x <= 580))
			{				
				if (!goian && rebote) id = Id_aurkitu(pilota.pos.x, pilota.pos.y);
				else if (!goian && !rebote) id = Id_aurkitu((pilota.pos.x + 24), pilota.pos.y);
				else if (goian && !rebote && (pilota.pos.x + 24 <= 580)) id = Id_aurkitu((pilota.pos.x + 24), (pilota.pos.y + 24));
				else if (goian && rebote) id = Id_aurkitu(pilota.pos.x, (pilota.pos.y + 24));

				if (id >= 0 && id <= 129) 
				{
					if (Blokeak[id].apurtuta != 1)
					{
						if ((pilota.pos.x + 21 <= Blokeak[id].pos.x) && (pilota.pos.x + 27 >= Blokeak[id].pos.x)) rebote = 1;
						else if (pilota.pos.x == Blokeak[id].pos.x + 40) rebote = 0;
						else if ((pilota.pos.y + 21 <= Blokeak[id].pos.y) && (pilota.pos.y + 27 >= Blokeak[id].pos.y)) goian = 0;
						else if (pilota.pos.y == Blokeak[id].pos.y + 20) goian = 1;

						Blokeak[id].apurtuta = 1;
						irudiaKendu(id + lehenLaukizuzen);
						kontScore += 10;
						scoreArray[0] = kontScore;
						markagailua(scoreArray, zenbakiak, zenbakiArray);

						if (pwUP == 0)
						{
							random = rng(4);
							switch (random)
							{
							case 1:
								pwUP = 1;
								powerupak[2].pos.x = Blokeak[id].pos.x + 20;
								powerupak[2].pos.y = Blokeak[id].pos.y + 10;
								powerupak[2].zein = 1;
								break;
							case 2:
								pwUP = 1;
								powerupak[0].pos.x = Blokeak[id].pos.x + 20;
								powerupak[0].pos.y = Blokeak[id].pos.y + 10;
								powerupak[0].zein = 1;
								break;
							case 3:
								pwUP = 1;
								powerupak[1].pos.x = Blokeak[id].pos.x + 20;
								powerupak[1].pos.y = Blokeak[id].pos.y + 10;
								powerupak[1].zein = 1;
								break;
							}
						}
					}
				}
			}
			if (powerupak[0].pos.y > 500 || powerupak[1].pos.y > 500 || powerupak[2].pos.y > 500)
			{
				pwUP = 0;
				powerupak[0].zein = 0;
				powerupak[1].zein = 0;
				powerupak[2].zein = 0;
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
					//amarillo 0 morado 1 berde 2 COJER EL PWUP
					if ((powerupak[0].pos.y >= 390) || (powerupak[1].pos.y == 390) || (powerupak[2].pos.y == 390))
					{
						if (powerupak[0].zein == 1)
						{
							if ((powerupak[0].pos.x > jokalaria.pos.x) && (powerupak[0].pos.x < (jokalaria.pos.x + 106)))
							{
								irudiaAldatu(barra.id, 0);
								pwUP = 0;
								powerupak[0].zein = 0;
								irudiaMugitu(powerupak[0].id, 4000, -4000);
								powerupak[0].pos.x = 4000;
								powerupak[0].pos.y = -4000;
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
					}
					if (jokalaria.egoera == TIROAK) 
					{
						irudiaAldatu(barra.id, 0);
						powerupak[1].zein = 0;
						for (int i = 0; i < 6; i++)
						{
							Tiroak[i].jaurti = 0;
						}
						biak = 0;
						zeinTiro = 0;
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

			if ((pilota.pos.y == 377) && (pilota.pos.x > jokalaria.pos.x - 15) && (pilota.pos.x < (jokalaria.pos.x + 106)))
			{
				goian = 0;
				if (pilota.pos.x + 12 >= jokalaria.pos.x + 53) rebote = 0;
				if (pilota.pos.x  + 12 < jokalaria.pos.x + 53) rebote = 1;

				if (rebote == 0)
				{
					aux = ERREALITATE_FISIKOA_mugimenduaPILOTA(pilota.pos);
					pilota.pos.x = aux.x;
					pilota.pos.y = aux.y;
				}
				else if (rebote == 1)
				{
					aux = ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEESK(pilota.pos);
					pilota.pos.x = aux.x;
					pilota.pos.y = aux.y;
				}
			}

			////BARRAREN ALDEAN ERREBOTEA
			if ((pilota.pos.x == jokalaria.pos.x) && (pilota.pos.y > 400) && (pilota.pos.y < 427)) rebote = 1;
			if ((pilota.pos.x == jokalaria.pos.x + 106) && (pilota.pos.y > 400) && (pilota.pos.y < 427)) rebote = 0;
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
		if (pilota.pos.y > 480)
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
			irudiaKendu(Tiroak[zeinTiro].id);
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
int tiroaPuxkatu(TIROA_ELEMENTUA tiroa, LAUKIZUZENA_ELEMENTUA Blokeak[], int lehenlauki) 
{
	int id = 0, apurtu = 0;
	id = Id_aurkitu(tiroa.pos.x+3, tiroa.pos.y);

	if (id >= 0 && id <= 130) 
	{
		if (Blokeak[id].apurtuta != 1)
		{
			tiroa.pos.x = 4000;
			tiroa.pos.y = 4000;
			Blokeak[id].apurtuta = 1;
			Blokeak[id].pos.x = 4000;
			Blokeak[id].pos.y = 4000;
			irudiaKendu(id + lehenlauki);
			irudiaKendu(tiroa.id);
			tiroa.puxkatu = 1;
			apurtu = 1;
		}
	}
	return apurtu;
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

void tiroakSortu(TIROA_ELEMENTUA  tiroa, TIROA_ELEMENTUA  Tiroak[])
{
	int i, posy = 430, posx = 30;
	for (i = 1; i <= 6; i++) 
	{
		tiroa.id = JOKOA_TiroaIrudiaSortu();
		tiroa.jaurti = 1;
		tiroa.zein = i;
		tiroa.puxkatu = 0;
		Tiroak[i - 1] = tiroa;
	}
}
int Id_aurkitu(int x, int y) 
{
	int id = 0, xtxiki = 60, ytxikia = 50;

	if (x < 60 || x > 580 || y < 50 || y > 250) id = 1000;

	while ((x<xtxiki || x > xtxiki + 40) && (xtxiki < 600))
	{
		xtxiki += 40;
		id++;
	}
	while ((y < ytxikia || y > ytxikia + 20) && (ytxikia < 260))
	{
		ytxikia += 20;
		id += 13;
	}
	return id;
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
		idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
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
	/*JOKOA_itxi2();*/
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
	/*JOKOA_itxi2();*/
	finalScore(scoreArray);
	pantailaBerriztu();
	return id;
}

////////////////////////////////////////////////////PowerUp
int zeinPOWER(JOKO_ELEMENTUA zein, int posx, int posy)
{
	irudiaMugitu(zein.id, posx, posy);
	zein.pos.x = posx;
	return zein.pos.x;
}
int zeinPOWERY(JOKO_ELEMENTUA zein, int posx, int posy)
{
	irudiaMugitu(zein.id, posx, posy);
	zein.pos.y = posy;
	return zein.pos.y;
}
void powerupSortu(POWERUP_ELEMENTUA pow, POWERUP_ELEMENTUA powerupak[])
{
	for (int i = 1; i <= 3; i++)
	{
		if (i == 1)	pow.koloreak = HORIA;

		else if (i == 2) pow.koloreak = MOREA;
		
		else if (i == 3) pow.koloreak = BERDEA;

		pow.id = JOKOA_SYPowerUPIrudiaSortu(pow, powerupak);
	}
}
int JOKOA_SYPowerUPIrudiaSortu(POWERUP_ELEMENTUA pwup, POWERUP_ELEMENTUA powerupak[])
{
	int balio = 0;
	pwup.id = -1;
	if (pwup.koloreak == HORIA)
	{
		pwup.id = irudiaKargatu(S_YELLOW_POWERUP);
		powerupak[0] = pwup;
	}
	else if (pwup.koloreak == MOREA)
	{
		pwup.id = irudiaKargatu(X_PURPLE_POWERUP);
		powerupak[1] = pwup;
	}
	else if (pwup.koloreak == BERDEA)
	{
		pwup.id = irudiaKargatu(N_GREEN_POWERUP);
		powerupak[2] = pwup;
	}

	irudiaMugitu(pwup.id, 1000, 1000);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pwup.id;
}

////////////////////////////////////////////////RNG
int rng(int zenb)
{
	int num;
	num = rand();
	num = num % zenb;
	return num;
}