#include "arkanoid.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define BOTON_ITZULI ".\\img\\itzuli.bmp"
#define JOKATU ".\\img\\joka.bmp"
#define TUTORIALA ".\\img\\noljoka.bmp"
#define NOLA_JOKATU "Barra bat daukazu, hau mugitzeko geziak erabiltzen dira. "
#define NOLA1_JOKATU "Ezkerrera joateko gezi hau erabiltzen duzu:"
#define NOLA2_JOKATU "Pilota barratik jaurtitzeko <space> teklari eman."
#define NOLA3_JOKATU "Eskumara joateko gezi hau erabiltzen duzu:"
#define KREDITUAK ".\\img\\kredituak.bmp"
#define KREDITOAK_IMAGE ".\\img\\krekre.bmp"
#define ITXI ".\\img\\itxijokua.bmp"
#define MENU_BACKGROUD_IMAGE ".\\img\\men.bmp"
#define TECLA_BARRA ".\\img\\espacio.bmp"
#define TECLA_EZKERRA ".\\img\\ezkerra.bmp"
#define TECLA_ESKUMA ".\\img\\eskuma.bmp"
#define JOKOA_SOUND ".\\sound\\arkanoid_audio.wav"
#define JOKOA_PLAYER_IMAGE ".\\img\\barra1.bmp"
#define JOKOA_PELOTA_IMAGE ".\\img\\pelota.bmp"
#define JOKOA_BIHOTZAK_IMAGE ".\\img\\bihotza.bmp"
#define JOKOA_BACKGROUND_IMAGE ".\\img\\arkanoid_fondo.bmp"
#define JOKOA_ENERGIA_IMAGE ".\\img\\barra_energia.bmp"
#define JOKOA_TIROA_IMAGE ".\\img\\Tiroa.bmp"
#define JOKOA_SOUND_WIN ".\\sound\\you_win.wav"
#define JOKOA_SOUND_LOOSE ".\\sound\\you_lose.wav" 
#define BUKAERA_SOUND_1 ".\\sound\\arkanoid_audio.wav"
#define BUKAERA_IMAGE ".\\img\\gameOver_3.bmp"

#define ZENBAKIA_0 ".\\img\\0zenbakia.bmp"
#define ZENBAKIA_1 ".\\img\\1zenbakia.bmp"
#define ZENBAKIA_2 ".\\img\\2zenbakia.bmp"
#define ZENBAKIA_3 ".\\img\\3zenbakia.bmp"
#define ZENBAKIA_4 ".\\img\\4zenbakia.bmp"
#define ZENBAKIA_5 ".\\img\\5zenbakia.bmp"
#define ZENBAKIA_6 ".\\img\\6zenbakia.bmp"
#define ZENBAKIA_7 ".\\img\\7zenbakia.bmp"
#define ZENBAKIA_8 ".\\img\\8zenbakia.bmp"
#define ZENBAKIA_9 ".\\img\\9zenbakia.bmp"
#define FINAL_SCORE "SCORE XD"

#define BOTON_MENU ".\\img\\joan.bmp"
#define LAUKIZUZENA1_1BMP ".\\img\\Bloke1_1.bmp"
#define LAUKIZUZENA1_2BMP ".\\img\\Bloke1_2.bmp"
#define LAUKIZUZENA1_3BMP ".\\img\\Bloke1_3.bmp"
#define MENU_AUDIO ".\\sound\\menu_audio.wav"
#define S_YELLOW_POWERUP ".\\img\\s_Yellow.bmp"
#define X_PURPLE_POWERUP ".\\img\\x_Purple.bmp"
#define N_GREEN_POWERUP ".\\img\\n_Green.bmp"

int posx = 0;
int posy = 0;
int zein = 1;
int pwUP = 0;
int apurtu = 0;
void sarreraMezuaIdatzi();
int JOKOA_jokalariaIrudiaSortu();
int JOKOA_barraIrudiaSortu();
int BihotzakMarraztu(posx, posy);
int zifra(int posizioax, int posizioay, int kontScore);
int aurkituYKoordenatuak(int id);
int aurkituXKoordenatuak(int id);
int JOKOA_LaukizuzenaIrudiaSortu(int posx, int posy, int zein);
int JOKOA_fondoaSortu();
int JOKOA_itzuli();
int JOKOA_teclaEzkerra();
int JOKOA_teclaEskuma();
int JOKOA_barra();
int JOKOA_KreditoakSortu();
int JOKOA_backSortu();
int JOKOA_jokatu();
int JOKOA_tutoriala();
int JOKOA_kreditoak();
int JOKOA_itxi();
int JOKOA_pilotaIrudiaSortu();
void bihotzaKendu(int bizitza, int bihotzArray[]);
int JOKOA_SYPowerUPIrudiaSortu(POWERUP_ELEMENTUA pow, POWERUP_ELEMENTUA powerupak[]);
int Id_aurkitu(int x, int y);

EGOERA JOKOA_egoera(JOKALARIA_ELEMENTUA jokalaria, JOKO_ELEMENTUA pilota, int bizitza);
int zeinPOWER(JOKO_ELEMENTUA zein, int posx, int posy);
int zeinPOWERY(JOKO_ELEMENTUA zein, int posx, int posy);
int rng(int zenb);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaEZK(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPILOTA(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEESK(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEGOI(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaTIROA(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPOWERUP(POSIZIOA posizioa);
void powerupSortu(POWERUP_ELEMENTUA pow, POWERUP_ELEMENTUA powerupak[]);
//int  BUKAERA_menua(EGOERA egoera);
int BUKAERA_irudiaBistaratu();
void scoreKendu(JOKO_ELEMENTUA zenbakiak);
void finalScore();

void jokoaAurkeztu(void)
{
	int ebentu = 0, saguaclick = 0, barruan = 0;
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
			textuaIdatzi(50, 100, NOLA_JOKATU);
			textuaIdatzi(50, 170, NOLA1_JOKATU);
			textuaIdatzi(50, 230, NOLA3_JOKATU);
			textuaIdatzi(50, 300, NOLA2_JOKATU);
			pantailaBerriztu();
			break;
		case 3:pantailaGarbitu();
			saguaclick = 0;
			JOKOA_KreditoakSortu();
			JOKOA_itzuli();
			pantailaBerriztu();
			break;
		case 4:sgItxi();
			audioTerminate();
			saguaclick = 0;
			break;
		case 5:
			saguaclick = 0;
			barruan = 0;
			sarreraMezuaIdatzi();
			break;
		}
	} while (saguaclick != 999);
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
	irudiaMugitu(teclaId, 360, 140);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return teclaId;
}
int JOKOA_teclaEskuma()
{
	int teclaId = -1;
	teclaId = irudiaKargatu(TECLA_ESKUMA);
	irudiaMugitu(teclaId, 360, 200);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return teclaId;
}
int JOKOA_barra()
{
	int barraId = -1;
	barraId = irudiaKargatu(TECLA_BARRA);
	irudiaMugitu(barraId, 300, 340);
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

EGOERA jokatu(void)
{
	int mugitu = 0;
	int mugituEZK = 0;
	int posx = 0;
	int posy = 0;
	int hasi = 0;
	int rebote = 0;
	int goian = 0;
	int bizitza = 3, bihotzArray[3];
	int kontScore = 0, zenbakiArray[2];
	int random;
	int zeinTiro = 0;
	int biak = 0;


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
	TIROA_ELEMENTUA Tiroak[6];

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
	//playMusic();    /////////////////////////Comentado para que no de la brasa durante el testeo, quitar para la publicación final
	fondoa.id = JOKOA_fondoaSortu();
	laukizuzenakEzarri(Laukizuzena, Blokeak);
	bihotzakEzarri(bihotzak, bizitza, bihotzArray);
	jokalaria.id = JOKOA_jokalariaIrudiaSortu();
	pilota.id = JOKOA_pilotaIrudiaSortu();
	barra.id = JOKOA_barraIrudiaSortu();
	zifra(548, 450, 0);
	zifra(532, 450, 0);
	zifra(516, 450, 0);
	zifra(500, 450, 0);
	powerupSortu(powerup, powerupak);
	tiroakSortu(tiroa, Tiroak);

	do
	{
		Sleep(10);
		pantailaGarbitu();
		arkatzKoloreaEzarri(0, 0, 0xFF);

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
		}
		if ((Tiroak[zeinTiro].pos.y >= 50) && (Tiroak[zeinTiro].pos.y <= 250) && (Tiroak[zeinTiro].pos.x >= 60) && (Tiroak[zeinTiro].pos.x <= 580) && Tiroak[zeinTiro].puxkatu != 1)
		{
			apurtu = tiroaPuxkatu(Tiroak[zeinTiro], Blokeak, kontScore);
			if (apurtu == 1)
			{
				zeinTiro++;
			}

		}
		/*if (Tiroak[zeinTiro].pos.y == 0)
		{
			tiroa.pos.x = 4000;
			tiroa.pos.y = 4000;
			irudiaKendu(tiroa.id);
			tiroa.puxkatu = 1;
			apurtu = 1;
		}*/
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
			if (mugitu) {
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
			if ((pilota.pos.y >= 50) && (pilota.pos.y <= 250) && (pilota.pos.x >= 60) && (pilota.pos.x <= 580))
			{
				int id = 0, blokeGoi, blokeBehe, blokeEzk, blokeEsk;
				id = Id_aurkitu(pilota.pos.x, pilota.pos.y);

				if (id >= 0 && id <= 130) {
					if (Blokeak[id].apurtuta != 1)
					{
						blokeEzk = aurkituXKoordenatuak(id + 6);
						blokeEsk = blokeEzk + 40;
						blokeGoi = aurkituYKoordenatuak(id + 6);
						blokeBehe = blokeGoi + 20;

						if (pilota.pos.x == blokeEzk) rebote = 1;
						if (pilota.pos.x == blokeEsk) rebote = 0;
						if (pilota.pos.y + 24 == blokeGoi) goian = 0;
						if (pilota.pos.y == blokeBehe) goian = 1;

						Blokeak[id].apurtuta = 1;
						Blokeak[id].pos.x = 4000;
						Blokeak[id].pos.y = 4000;
						irudiaKendu(id + 6);
						kontScore += 10;
						markagailua(kontScore, zenbakiak, zenbakiArray);

						if (pwUP == 0)
						{
							random = rng(4);
							switch (3)
							{
							case 1:
								pwUP = 1;
								powerupak[2].pos.x = blokeEzk + 20;
								powerupak[2].pos.y = blokeGoi + 10;
								powerupak[2].zein = 1;
								break;
							case 2:
								pwUP = 1;
								powerupak[0].pos.x = blokeEzk + 20;
								powerupak[0].pos.y = blokeGoi + 10;
								powerupak[0].zein = 1;
								break;
							case 3:
								pwUP = 1;
								powerupak[1].pos.x = blokeEzk + 20;
								powerupak[1].pos.y = blokeGoi + 10;
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
							}
						}
						else if (powerupak[1].zein == 1)
						{
							if (((powerupak[1].pos.x > jokalaria.pos.x) && (powerupak[1].pos.x < (jokalaria.pos.x + 106))) /*|| ((powerupak[1].pos.x+29 > jokalaria.pos.x) && (powerupak[1].pos.x+29 < (jokalaria.pos.x + 106)))*/)
							{

								//irudiaMugitu(powerupak[1].id, 4000, 4000);
								jokalaria.egoera = TIROAK;
								irudiaKendu(powerupak[1].id);
						

							}
						}
						else if (powerupak[2].zein == 1)
						{
							if ((powerupak[2].pos.x > jokalaria.pos.x) && (powerupak[2].pos.x < (jokalaria.pos.x + 106)))
							{
								irudiaAldatu(barra.id, 0);
								pwUP = 0;
								powerupak[2].zein = 0;
							}
						}
					}
					if (jokalaria.egoera == TIROAK) {
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

				if (ebentu == TECLA_SPACE)	irudiaAldatu(barra.id, 1);
			}
			else
			{
				for (int i = 0; i < 3; i++) {
					irudiaMugitu(powerupak[i].id, 1000, -1000);
					powerupak[i].pos.x = 1000;
					powerupak[i].pos.y = -1000;
				}
			}

			if ((pilota.pos.y == 377) && (pilota.pos.x > jokalaria.pos.x - 15) && (pilota.pos.x < (jokalaria.pos.x + 121)))
			{
				goian = 0;
				if (pilota.pos.x > jokalaria.pos.x + 53) rebote = 0;
				if (pilota.pos.x < jokalaria.pos.x + 53) rebote = 1;

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
			for (int i = 0; i < 3; i++)
			{
				powerupak[i].pos.x = 1000;
				powerupak[i].pos.y = 1000;
				powerupak[i].zein = 0;
			}
			pwUP = 0;
		}
		///////////////////////////////////////////////////////////////BIZITZAK
		egoera = JOKOA_egoera(jokalaria, pilota, bizitza);
	} while (egoera == JOLASTEN);
	irudiaKendu(jokalaria.id);
	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}
/////////////////////////////////////////////////////////////////////////JOKOAREN AMAIERA
EGOERA JOKOA_egoera(JOKALARIA_ELEMENTUA jokalaria, JOKO_ELEMENTUA pilota, int bizitza) {
  EGOERA  ret = JOLASTEN;
  if (jokalaria.pos.x >pilota.pos.x - 20 && jokalaria.pos.x <pilota.pos.x + 20 && jokalaria.pos.y >pilota.pos.y - 20 && jokalaria.pos.y <pilota.pos.y + 20) {
    //ret = IRABAZI;
  }
  else if (bizitza == 0) {
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
int tiroaPuxkatu(TIROA_ELEMENTUA tiroa, LAUKIZUZENA_ELEMENTUA Blokeak[], int kontScore) {
	int id = 0, apurtu = 0;
	id = Id_aurkitu(tiroa.pos.x, tiroa.pos.y);

	if (id >= 0 && id <= 130) {
		if (Blokeak[id].apurtuta != 1)
		{
			tiroa.pos.x = 4000;
			tiroa.pos.y = 4000;
			Blokeak[id].apurtuta = 1;
			Blokeak[id].pos.x = 4000;
			Blokeak[id].pos.y = 4000;
			irudiaKendu(id + 6);
			irudiaKendu(tiroa.id);
			tiroa.puxkatu = 1;
			apurtu = 1;
		}
	}
	return apurtu;
}
int JOKOA_LaukizuzenaIrudiaSortu(int posizioax, int posizioay, int zein)
{
	int Laukizuzena = -1;
	switch (zein)
	{
	case 1:
		Laukizuzena = irudiaKargatu(LAUKIZUZENA1_1BMP);
		break;
	case 2:
		Laukizuzena = irudiaKargatu(LAUKIZUZENA1_2BMP);
		break;
	case 3:
		Laukizuzena = irudiaKargatu(LAUKIZUZENA1_3BMP);
		break;
	default:
		break;
	}
	irudiaMugitu(Laukizuzena, posizioax, posizioay);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return Laukizuzena;
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

void laukizuzenakEzarri(LAUKIZUZENA_ELEMENTUA Laukizuzena, LAUKIZUZENA_ELEMENTUA blokeak[]) {
	int r = 1, maximoa = 0, j = 0;
	
	for (int i = 0; i < 10; i++)
	{
		if (i == 0)	posy = 50;

		for (int t = 0; t < 13; t++)
		{
			if (t == 0)	posx = 60;
			Laukizuzena.id = JOKOA_LaukizuzenaIrudiaSortu(posx, posy, r);
			Laukizuzena.apurtuta = 0;
			Laukizuzena.pos.x = posx;
			Laukizuzena.pos.y = posy;
			Laukizuzena.apurtuta = 0;
			Laukizuzena.mota = IRUDIA;
			blokeak[j] = Laukizuzena;
			posx += 40;
			j++;
		}
		posy += 20;
		if (r == 3)	maximoa = 1;

		else if (r == 1) maximoa = 0;
		
		if (maximoa == 1) r--;
		
		else r++;
	}
}
void tiroakSortu(TIROA_ELEMENTUA  tiroa, TIROA_ELEMENTUA  Tiroak[])
{
	int i, posy = 430, posx = 30;
	for (i = 1; i <= 6; i++) {
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

	while (x<xtxiki || x > xtxiki + 40)
	{
		xtxiki += 40;
		id++;
	}
	while (y<ytxikia || y > ytxikia + 20)
	{
		ytxikia += 20;
		id += 13;
	}
	return id;
}
int aurkituXKoordenatuak(int id)
{
	int i = 0, xkoor = 20, ilarapos;
	id -= 5;
	while (id - (i + 1) * 13 > 0) i++;
	ilarapos = id - i * 13;
	xkoor += ilarapos * 40;
	return xkoor;
}
int aurkituYKoordenatuak(int id)
{
	int i = 1, ykoor = 30;
	id -= 5;
	while (id - i * 13 > 0) i++;
	ykoor += i * 20;
	return ykoor;
}
//////////////////////////////////////7 bihotzak
void bihotzakEzarri(JOKO_ELEMENTUA bihotzak, int bizitza, int bihotzArray[])
{
	int i, posy = 430, posx = 30;
	for (i = 0; i < bizitza; i++) {
		bihotzak.id = BihotzakMarraztu(posx, posy);
		bihotzArray[i] = bihotzak.id;
		posx += 30;
	}
}

int BihotzakMarraztu(int posizioax, int posizioay)
{
	int bihotzId = -1;
	bihotzId = irudiaKargatu(JOKOA_BIHOTZAK_IMAGE);
	irudiaMugitu(bihotzId, posizioax, posizioay);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return bihotzId;
}

void bihotzaKendu(int bizitza, int bihotzArray[])
{
	if (bizitza == 2) irudiaKendu(bihotzArray[2]);
	else irudiaKendu(bihotzArray[1]);
}

//////////////////////////////////////7 bihotzak

/////////////////////////////////////////////////////////////////////////BARRA + PILOTA mugimenduak
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
	posizioa.y = posizioa.y + 1;
	return posizioa;
}
POSIZIOA ERREALITATE_FISIKOA_mugimenduaTIROA(POSIZIOA posizioa)
{
	posizioa.y = posizioa.y - 1;
	return posizioa;
}
/////////////////////////////////////////////////////////////////////////BARRA + PILOTA mugimenduak
//void jokoabukatu(void)
//{
//	int eben = 0, saguaclik = 0, barru = 0;
//	POSIZIOA pos;
//	sarreraMezuaIdatzi();
//	do
//	{
//		pos = saguarenPosizioa();
//		eben = ebentuaJasoGertatuBada();
//		if (eben == SAGU_BOTOIA_EZKERRA && (pos.x >= 50) && (pos.x <= 175) && (pos.y >= 370) && (pos.y <= 403) && barru == 0)
//		{
//			saguaclik = 1;
//			barru = 1;
//		}
//		if (eben == SAGU_BOTOIA_EZKERRA && (pos.x >= 440) && (pos.x <= 565) && (pos.y >= 370) && (pos.y <= 403) && barru == 0)
//		{
//			saguaclik = 2;
//			barru = 1;
//
//		}
//		switch (saguaclik)
//		{
//		case 1:
//			jokoaAurkeztu();
//			break;
//
//		case 2:
//			saguaclik = 0;
//			sgItxi();
//			break;
//		}
//	} while (saguaclik != 999);
//
//}




int  jokoAmaierakoa(EGOERA egoera)
{
	int ebentu = 0, id;
	int idAudioGame;

	/* loadTheMusic(BUKAERA_SOUND_1);
	if (egoera == IRABAZI) {
	idAudioGame = loadSound(JOKOA_SOUND_WIN);
	playSound(idAudioGame);
	}
	else {
	idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
	playSound(idAudioGame);
	}*/
	id = BUKAERA_irudiaBistaratu();
	do
	{
		ebentu = ebentuaJasoGertatuBada();
	} while ((ebentu != TECLA_RETURN) && (ebentu != SAGU_BOTOIA_ESKUMA));
	/*audioTerminate();*/
	irudiaKendu(id);
	return (ebentu != TECLA_RETURN) ? 1 : 0;
}

int BUKAERA_irudiaBistaratu()
{
	int id = -1;
	id = irudiaKargatu(BUKAERA_IMAGE);
	irudiaMugitu(id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	/*JOKOA_menu();*/
	/*JOKOA_itxi2();*/
	finalScore();
	/*textuaIdatzi(50, 340, HASIERATU);*/
	pantailaBerriztu();
	return id;
}


//////////////////////////////////////////////////score

void markagailua(int kontScore, JOKO_ELEMENTUA zenbakiak, int zenbakiArray[])
{
	int i, posizioay = 450;
	i = kontScore;

	if (i >= 1000) {
		i /= 1000;
		zenbakiak.id = zifra(500, posizioay, i);
		zenbakiArray[0] = zenbakiak.id;
		i = kontScore - i * 1000;
	}
	else zifra(500, posizioay, 0);

	if (i >= 100) {
		i /= 100;
		zenbakiak.id = zifra(516, posizioay, i);
		zenbakiArray[1] = zenbakiak.id;
		i = kontScore - i * 100;
	}
	else zifra(516, posizioay, 0);

	if (i >= 10) {
		i /= 10;
		zenbakiak.id = zifra(532, posizioay, i);
		zenbakiArray[2] = zenbakiak.id;
		i = kontScore - i * 10;
	}
	else zifra(532, posizioay, 0);

}

int zifra(int posizioax, int posizioay, int kontScore)
{
	int zenbakia = -1;
	switch (kontScore)
	{
	case 1:
		zenbakia = irudiaKargatu(ZENBAKIA_1);
		break;
	case 2:
		zenbakia = irudiaKargatu(ZENBAKIA_2);
		break;
	case 3:
		zenbakia = irudiaKargatu(ZENBAKIA_3);
		break;
	case 4:
		zenbakia = irudiaKargatu(ZENBAKIA_4);
		break;
	case 5:
		zenbakia = irudiaKargatu(ZENBAKIA_5);
		break;
	case 6:
		zenbakia = irudiaKargatu(ZENBAKIA_6);
		break;
	case 7:
		zenbakia = irudiaKargatu(ZENBAKIA_7);
		break;
	case 8:
		zenbakia = irudiaKargatu(ZENBAKIA_8);
		break;
	case 9:
		zenbakia = irudiaKargatu(ZENBAKIA_9);
		break;
	default:
		zenbakia = irudiaKargatu(ZENBAKIA_0);
		break;
	}
	irudiaMugitu(zenbakia, posizioax, posizioay);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return zenbakia;
}

void scoreKendu(JOKO_ELEMENTUA zenbakiak)
{
	int i;
	for (i = 0; i < 3; i++) irudiaMugitu(zenbakiak.id, 1000, 1000);

}

void finalScore()
{
	textuaIdatzi(280, 210, FINAL_SCORE);
}

//////////////////////////////////////////////////score

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

		if (i == 1)
		{
			pow.koloreak = HORIA;

		}
		else if (i == 2)
		{
			pow.koloreak = MOREA;
		}
		else if (i == 3)
		{
			pow.koloreak = BERDEA;
		}
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

