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
#define JOKOA_BACKGROUND_IMAGE ".\\img\\arkanoid_fondo.bmp"
#define JOKOA_SOUND_WIN ".\\sound\\you_win.wav"
#define JOKOA_SOUND_LOOSE ".\\sound\\you_lose.wav" 
#define BUKAERA_SOUND_1 ".\\sound\\arkanoid_audio.wav"
#define BUKAERA_IMAGE ".\\img\\gameOver_1.bmp"

void sarreraMezuaIdatzi();
int JOKOA_jokalariaIrudiaSortu();
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa);
POSIZIOA ERREALITATE_FISIKOA_mugimenduaEZK(POSIZIOA posizioa);
//int  BUKAERA_menua(EGOERA egoera);
int BUKAERA_irudiaBistaratu();

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
  EGOERA  egoera = JOLASTEN;
  int ebentu = 0;
  JOKO_ELEMENTUA zirkulua, jokalaria, fondoa;
  POSIZIOA aux;
  zirkulua.pos.x = 325;
  zirkulua.pos.y = 390;

  jokalaria.pos.x = 280;
  jokalaria.pos.y = 400;


  fondoa.pos.x = 0;
  fondoa.pos.y = 0;

  audioInit();
  loadTheMusic(JOKOA_SOUND);
  playMusic();
  fondoa.id = JOKOA_fondoaSortu();
  jokalaria.id = JOKOA_jokalariaIrudiaSortu();
  zirkulua.id = JOKOA_pilotaIrudiaSortu();
  

  do {
    Sleep(2);
    pantailaGarbitu();
    arkatzKoloreaEzarri(0, 0, 0xFF);
	irudiaMugitu(zirkulua.id, jokalaria.pos.x + 38, jokalaria.pos.y - 23);
    irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
    irudiakMarraztu();
    pantailaBerriztu();
    ebentu = ebentuaJasoGertatuBada();
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
    if (mugitu) {
      aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
      jokalaria.pos.x = aux.x;
	  zirkulua.pos.x = aux.x + 45;
    }
	if (mugituEZK)
	{
		aux = ERREALITATE_FISIKOA_mugimenduaEZK(jokalaria.pos);
		jokalaria.pos.x = aux.x;
		zirkulua.pos.x = aux.x + 45;
	}
	///////////////////////////////////////////////////////////////MUGIMENDUA LIMITATUTA
    egoera = JOKOA_egoera(jokalaria, zirkulua);
  } while (egoera == JOLASTEN);
  irudiaKendu(jokalaria.id);
  toggleMusic();
  audioTerminate();
  pantailaGarbitu();
  pantailaBerriztu();
  return egoera;
}

EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa) {
  EGOERA  ret = JOLASTEN;
  if (jokalaria.pos.x >oztopoa.pos.x - 20 && jokalaria.pos.x <oztopoa.pos.x + 20 && jokalaria.pos.y >oztopoa.pos.y - 20 && jokalaria.pos.y <oztopoa.pos.y + 20) {
    //ret = IRABAZI;
  }
  else if (jokalaria.pos.x > 600) {
	  //ret = GALDU;
  }

  return ret;
}

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

POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa) {
  //posizioa.y = posizioa.y + 1;
  posizioa.x = posizioa.x + 15;
  return posizioa;
}

POSIZIOA ERREALITATE_FISIKOA_mugimenduaEZK(POSIZIOA posizioa) {
	//posizioa.y = posizioa.y + 1;
	posizioa.x = posizioa.x - 15;
	return posizioa;
}

int  jokoAmaierakoa(EGOERA egoera)
{
  int ebentu = 0, id;
  int idAudioGame;

  loadTheMusic(BUKAERA_SOUND_1);
  if (egoera == IRABAZI) {
    idAudioGame = loadSound(JOKOA_SOUND_WIN);
    playSound(idAudioGame);
  }
  else {
    idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
    playSound(idAudioGame);
  }
  id=BUKAERA_irudiaBistaratu();
  do 
  {
    ebentu = ebentuaJasoGertatuBada();
  } while ((ebentu!= TECLA_RETURN) && (ebentu!= SAGU_BOTOIA_ESKUMA));
  audioTerminate();
  irudiaKendu(id);
  return (ebentu != TECLA_RETURN) ? 1 : 0;
}

int BUKAERA_irudiaBistaratu() {
  int id = -1;
  id = irudiaKargatu(BUKAERA_IMAGE);
  irudiaMugitu(id, 200, 200);
  pantailaGarbitu();
  irudiakMarraztu();
  pantailaBerriztu();
  return id;
}

