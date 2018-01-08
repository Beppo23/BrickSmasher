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
#define NOLA_JOKATU "Barra bat daukazu, hau mugitzeko <- ->geziak erabiltzen dira. "
#define NOLA2_JOKATU "Pilota barratik jaurtitzeko <space> teklari eman."
#define KREDITUAK ".\\img\\kredituak.bmp"
#define KREDITOAK_IMAGE ".\\img\\krekre.bmp"
#define ITXI ".\\img\\itxijokua.bmp"
#define MENU_BACKGROUD_IMAGE ".\\img\\men.bmp"
#define JOKOA_SOUND ".\\sound\\arkanoid_audio.wav"
#define JOKOA_PLAYER_IMAGE ".\\img\\barra1.bmp"
#define JOKOA_PELOTA_IMAGE ".\\img\\pelota.bmp"
#define JOKOA_BIHOTZAK_IMAGE ".\\img\\bihotza.bmp"
#define JOKOA_2BIHOTZAKENDU_IMAGE ".\\img\\2bihotza_tapatu.bmp"
#define JOKOA_3BIHOTZAKENDU_IMAGE ".\\img\\3bihotza_tapatu.bmp"
#define JOKOA_BACKGROUND_IMAGE ".\\img\\arkanoid_fondo.bmp"
#define JOKOA_ENERGIA_IMAGE ".\\img\\barra_energia.bmp"
#define JOKOA_SOUND_WIN ".\\sound\\you_win.wav"
#define JOKOA_SOUND_LOOSE ".\\sound\\you_lose.wav" 
#define BUKAERA_SOUND_1 ".\\sound\\arkanoid_audio.wav"
#define BUKAERA_IMAGE ".\\img\\gameOver_3.bmp"
#define FINAL_SCORE "SCORE XD"
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
void sarreraMezuaIdatzi();
int JOKOA_jokalariaIrudiaSortu();
int JOKOA_barraIrudiaSortu();
int BihotzakMarraztu(posx, posy);
int aurkituYKoordenatuak(int id);
int aurkituXKoordenatuak(int id);
int JOKOA_LaukizuzenaIrudiaSortu(int posx, int posy, int zein);
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA pilota, int bizitza);
int zeinPOWER(JOKO_ELEMENTUA zein, int posx, int posy);
int zeinPOWERY(JOKO_ELEMENTUA zein, int posx, int posy);
int rng(int zenb);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaEZK(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPILOTA(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEESK(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEGOI(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPOWERUP(POSIZIOA posizioa);
//int  BUKAERA_menua(EGOERA egoera);
int BUKAERA_irudiaBistaratu();
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
			textuaIdatzi(100, 100, NOLA_JOKATU);
			textuaIdatzi(100, 200, NOLA2_JOKATU);
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
  int bizitza = 3;
  int random;

  EGOERA  egoera = JOLASTEN;
  int ebentu = 0;
  JOKO_ELEMENTUA pilota, jokalaria, fondoa, barra, bihotzak, sY, xP, nG;
  LAUKIZUZENA_ELEMENTUA Laukizuzena;
  POSIZIOA aux;
  LAUKIZUZENA_ELEMENTUA Blokeak[130];

  jokalaria.pos.x = 280;
  jokalaria.pos.y = 400;

  Laukizuzena.pos.x = 280;
  Laukizuzena.pos.y = 400;

  bihotzak.pos.x = 280;
  bihotzak.pos.y = 400;

  pilota.pos.x = jokalaria.pos.x + 38;
  pilota.pos.y = jokalaria.pos.y - 23;
  barra.pos.x = jokalaria.pos.x;
  barra.pos.y = jokalaria.pos.y + 23;

  fondoa.pos.x = 0;
  fondoa.pos.y = 0;

  sY.pos.x = 1000;
  sY.pos.y = 1000;
  xP.pos.x = 1000;
  xP.pos.y = 1000;
  nG.pos.x = 1000;
  nG.pos.y = 1000;

  audioInit();
  loadTheMusic(JOKOA_SOUND);
  //playMusic();    /////////////////////////Comentado para que no de la brasa durante el testeo, quitar para la publicación final
  fondoa.id = JOKOA_fondoaSortu();
  laukizuzenakEzarri(Laukizuzena, Blokeak);
  bihotzakEzarri(bihotzak, bizitza);
  jokalaria.id = JOKOA_jokalariaIrudiaSortu();
  pilota.id = JOKOA_pilotaIrudiaSortu();
  barra.id = JOKOA_barraIrudiaSortu();
  sY.id = JOKOA_SYPowerUPIrudiaSortu(1);
  xP.id = JOKOA_SYPowerUPIrudiaSortu(2);
  nG.id = JOKOA_SYPowerUPIrudiaSortu(3);

  do 
  {
    Sleep(2);
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
	irudiaMugitu(sY.id, sY.pos.x, sY.pos.y);
	irudiaMugitu(xP.id, xP.pos.x, xP.pos.y);
	irudiaMugitu(nG.id, nG.pos.x, nG.pos.y);
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
		if (ebentu == TECLA_SPACE)	irudiaAldatu(barra.id, 1);

		else if (ebentu == TECLA_g) ///////////////////////////////////////////////PROVISIONAL INSERTAR POWER UP
		{
			irudiaAldatu(barra.id, 0);
		}
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

			if (id >= 6 && id <= 135) {
				if (Blokeak[id].apurtuta != 1)
				{
					blokeEzk = aurkituXKoordenatuak(id);
					blokeEsk = blokeEzk + 40;
					blokeGoi = aurkituYKoordenatuak(id);
					blokeBehe = blokeGoi + 20;

					if (pilota.pos.x == blokeEzk) rebote = 1;
					if (pilota.pos.x == blokeEsk) rebote = 0;
					if (pilota.pos.y + 24 == blokeGoi) goian = 0;
					if (pilota.pos.y == blokeBehe) goian = 1;

					Blokeak[id].apurtuta = 1;
					Blokeak[id].pos.x = 4000;
					Blokeak[id].pos.y = 4000;
					irudiaMugitu(id, Blokeak[id].pos.x, Blokeak[id].pos.y);
					
					if (!pwUP)
					{
						random = rng(51);
						switch (random)
						{
						case 0:
							pwUP = 1;
							nG.pos.x = blokeEzk + 20;
							nG.pos.y = blokeGoi + 10;
							zein = 3;
							break;
						case 1:
							pwUP = 1;
							sY.pos.x = blokeEzk + 20;
							sY.pos.y = blokeGoi + 10;
							zein = 1;
							break;
						case 2:
							pwUP = 1;
							xP.pos.x = blokeEzk + 20;
							xP.pos.y = blokeGoi + 10;
							zein = 2;
							break;
						}
					}
				}
			}
		}
		if (sY.pos.y == 500 || xP.pos.y == 500 || nG.pos.y == 500)
		{
			pwUP = 0;
			zein = 0;
		}
		if (pwUP)
		{
			if (zein == 1)
			{
				aux = ERREALITATE_FISIKOA_mugimenduaPOWERUP(sY.pos);
				sY.pos.y = aux.y;
			}
			else if (zein == 2)
			{
				aux = ERREALITATE_FISIKOA_mugimenduaPOWERUP(xP.pos);
				xP.pos.y = aux.y;
			}
			else if (zein == 3)
			{
				aux = ERREALITATE_FISIKOA_mugimenduaPOWERUP(nG.pos);
				nG.pos.y = aux.y;
			}
		}
		else
		{
			irudiaMugitu(sY.id, 1000, 1000);
			sY.pos.x = 1000;
			sY.pos.y = 1000;
			irudiaMugitu(xP.id, 1000, 1000);
			xP.pos.x = 1000;
			xP.pos.y = 1000;
			irudiaMugitu(nG.id, 1000, 1000);
			nG.pos.x = 1000;
			nG.pos.y = 1000;
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
		if (bizitza == 2) hiruBihotzaKendu();
		else biBihotzaKendu();
		hasi = 0;
		rebote = 0;
		goian = 0;
		jokalaria.pos.x = 280;
		jokalaria.pos.y = 400;
		pilota.pos.x = jokalaria.pos.x + 38;
		pilota.pos.y = jokalaria.pos.y - 23;
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
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA pilota, int bizitza) {
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
int Id_aurkitu(int x, int y) 
{
	int id = 6, xtxiki = 60, ytxikia = 50;

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
void bihotzakEzarri(JOKO_ELEMENTUA bihotzak, int bizitza)
{
	int i, posy = 430, posx = 30;
	for (i = 0; i < bizitza; i++) 
	{
		bihotzak.id = BihotzakMarraztu(posx, posy);
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

int biBihotzaKendu()
{
	int kenduId = -1;
	kenduId = irudiaKargatu(JOKOA_2BIHOTZAKENDU_IMAGE);
	irudiaMugitu(kenduId, 60, 430);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kenduId;
}

int hiruBihotzaKendu()
{
	int kenduId = -1;
	kenduId = irudiaKargatu(JOKOA_3BIHOTZAKENDU_IMAGE);
	irudiaMugitu(kenduId, 90, 430);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kenduId;
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
/////////////////////////////////////////////////////////////////////////BARRA + PILOTA mugimenduak

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
  id=BUKAERA_irudiaBistaratu();
  do 
  {
    ebentu = ebentuaJasoGertatuBada();
  } while ((ebentu!= TECLA_RETURN) && (ebentu!= SAGU_BOTOIA_ESKUMA));
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
  finalScore();
  pantailaBerriztu();
  return id;
}

int JOKOA_SYPowerUPIrudiaSortu(int zein)
{
	int sYId = -1, balio = 0;
	if (zein == 1)
	{
		balio = S_YELLOW_POWERUP;
	}
	else if (zein == 2)
	{
		balio = X_PURPLE_POWERUP;
	}
	else if (zein == 3)
	{
		balio = N_GREEN_POWERUP;
	}
	sYId = irudiaKargatu(balio);
	irudiaMugitu(sYId, 1000, 1000);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return sYId;
}

//////////////////////////////////////////////////score

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

////////////////////////////////////////////////RNG
int rng(int zenb)
{
	int num;
	num = rand();
	num = num % zenb;
	return num;
}

