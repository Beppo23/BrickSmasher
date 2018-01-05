#include "arkanoid.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define ONGI_ETORRI_MEZUA "Sakatu return hasteko..."
#define JOKOA_SOUND ".\\sound\\arkanoid_audio.wav"
#define JOKOA_PLAYER_IMAGE ".\\img\\barra1.bmp"
#define JOKOA_PELOTA_IMAGE ".\\img\\pelota.bmp"
#define JOKOA_BIHOTZAK_IMAGE ".\\img\\bihotza.bmp"
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

int posx = 0;
int posy = 0;
int zein = 1;
void sarreraMezuaIdatzi();
int JOKOA_jokalariaIrudiaSortu();
int JOKOA_barraIrudiaSortu();
int BihotzakMarraztu(posx, posy);
int JOKOA_LaukizuzenaIrudiaSortu(int posx, int posy, int zein);
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA pilota, int bizitza);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaEZK(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPILOTA(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEESK(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaPILOTAREBOTEGOI(POSIZIOA posizioa);
//int  BUKAERA_menua(EGOERA egoera);
int BUKAERA_irudiaBistaratu();
void finalScore();

void jokoaAurkeztu(void)
{
  int ebentu = 0;

  sarreraMezuaIdatzi();
  do
  {
    ebentu = ebentuaJasoGertatuBada();
  } while (ebentu != TECLA_RETURN);
  pantailaGarbitu();
  pantailaBerriztu();
}

void sarreraMezuaIdatzi()
{
  pantailaGarbitu();
  textuaIdatzi(225, 200, ONGI_ETORRI_MEZUA);
  pantailaBerriztu();
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

  EGOERA  egoera = JOLASTEN;
  int ebentu = 0;
  JOKO_ELEMENTUA pilota, Laukizuzenak, jokalaria, fondoa, barra, bihotzak;
  POSIZIOA aux;

  jokalaria.pos.x = 280;
  jokalaria.pos.y = 400;

  Laukizuzenak.pos.x = 280;
  Laukizuzenak.pos.y = 400;

  bihotzak.pos.x = 280;
  bihotzak.pos.y = 400;

  pilota.pos.x = jokalaria.pos.x + 38;
  pilota.pos.y = jokalaria.pos.y - 23;
  barra.pos.x = jokalaria.pos.x;
  barra.pos.y = jokalaria.pos.y + 23;

  fondoa.pos.x = 0;
  fondoa.pos.y = 0;

  audioInit();
  loadTheMusic(JOKOA_SOUND);
  //playMusic();    /////////////////////////Comentado para que no de la brasa durante el testeo, quitar para la publicación final
  fondoa.id = JOKOA_fondoaSortu();
  laukizuzenakEzarri(Laukizuzenak);
  bihotzakEzarri(bihotzak, bizitza);
  jokalaria.id = JOKOA_jokalariaIrudiaSortu();
  pilota.id = JOKOA_pilotaIrudiaSortu();
  barra.id = JOKOA_barraIrudiaSortu();
  

  do {
    Sleep(2);
    pantailaGarbitu();
    arkatzKoloreaEzarri(0, 0, 0xFF);
	if (hasi)
	{
		irudiaMugitu(pilota.id, pilota.pos.x, pilota.pos.y);
	}
	else
	{
		irudiaMugitu(pilota.id, jokalaria.pos.x + 38, jokalaria.pos.y - 23);
		irudiaAldatu(barra.id, 2);
	}

    irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
	irudiaMugitu(barra.id, jokalaria.pos.x - 5, jokalaria.pos.y + 20);
    irudiakMarraztu();
    pantailaBerriztu();
    ebentu = ebentuaJasoGertatuBada();
	/////////////////////////////////////////////////////////////////////PILOTA JAURTI DA
	if (ebentu == TECLA_SPACE)
	{

		if (pilota.pos.x < 320 && hasi == 0) ////////////////// Si esta a la izquierda de la mitad lo lanza hacia la izquierda
		{
			rebote = 1;
		}
		hasi = 1;
	}
	/////////////////////////////////////////////////////////////////////PILOTA JAURTI DA

	////////////////////////////////////////////////////////////////////MUGIMENDUA LIMITATUA
	
    if (ebentu == TECLA_RIGHT) 
    {
      mugitu = 1;
    }
	else if (ebentu == TECLA_LEFT)
	{
		
		mugituEZK = 1;
		
	}
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
		if (ebentu == TECLA_SPACE)
		{
			irudiaAldatu(barra.id, 1);
		}
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
		if ((pilota.pos.y == 377) && (pilota.pos.x > jokalaria.pos.x) && (pilota.pos.x < (jokalaria.pos.x + 110)))
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
		if ((pilota.pos.y == 230) && (pilota.pos.x >60) && (pilota.pos.x < 580)) goian = 1;
		if ((pilota.pos.x == 50) && (pilota.pos.y < 230) && (pilota.pos.y > 50)) rebote = 1;
		if ((pilota.pos.y == 30) && (pilota.pos.x >60) && (pilota.pos.x < 580))	goian = 0;
		if ((pilota.pos.x == 580) && (pilota.pos.y < 230) && (pilota.pos.y > 50)) rebote = 0;

		if (mugitu) {
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
		bihotzakKendu(bihotzak, bizitza);
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

void laukizuzenakEzarri(JOKO_ELEMENTUA Laukizuzena) {
	
	int r = 1, maximoa = 0;
	
	for (int i = 0; i < 9; i++)
	{
		if (i == 0)	posy = 50;

		for (int t = 0; t < 13; t++)
		{
			if (t == 0)	posx = 60;

			Laukizuzena.id = JOKOA_LaukizuzenaIrudiaSortu(posx, posy, r);
			posx += 40;
		}
		
		posy += 20;
		if (r == 3)	maximoa = 1;

		else if (r == 1) maximoa = 0;

		if (maximoa == 1) r--;

		else r++;
	}
}

//////////////////////////////////////7 bihotzak
void bihotzakEzarri(JOKO_ELEMENTUA bihotzak, int bizitza)
{
	int i, posy = 430, posx = 30;
	for (i = 0; i < bizitza; i++) {
		bihotzak.id = BihotzakMarraztu(posx, posy);
		posx += 30;
	}
}

void bihotzakKendu(JOKO_ELEMENTUA bihotzak, int bizitza)
{
	int n = 133;

	while (n == bizitza + 131) { //gero 2, 3 eta 4 izango dira (ez 131, 132 eta 133)
		if (bihotzak.id == n)
		{
			posy += 300;
		}
		n--;
	}
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

int BUKAERA_irudiaBistaratu() {
  int id = -1;
  id = irudiaKargatu(BUKAERA_IMAGE);
  irudiaMugitu(id, 0, 0);
  pantailaGarbitu();
  irudiakMarraztu();
  finalScore();
  pantailaBerriztu();
  return id;
}

//////////////////////////////////////////////////score

void finalScore()
{
	textuaIdatzi(280, 210, FINAL_SCORE);
}

//////////////////////////////////////////////////score
