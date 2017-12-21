#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>


#define SOINU_KOP 5
char * soundFiles[] = { ".\\sound\\128GBVHR_01.wav", ".\\sound\\128NIGHT_01.wav", ".\\sound\\132TRANCE_02.wav",
                        ".\\sound\\BugleCall.wav",  ".\\sound\\terminator.wav" };

typedef struct S_GURE_GAUZAK
{
  int idSounds[SOINU_KOP];
  int idIrudi;
}GURE_GAUZAK;

GURE_GAUZAK gureGauzak;

int hasieratu(void);

int main(int argc, char * str[]) 
{
  int ebentu = 0, irten=0;
  POSIZIOA pos;
 
  hasieratu();
  while(!irten)
  {
    ebentu = ebentuaJasoGertatuBada();
    if (ebentu == SAGU_BOTOIA_EZKERRA)
    {
      pos=saguarenPosizioa();
      if ((pos.x > 300) && (pos.x < 300 + 40) && (pos.y>200) && (pos.y < 200 + 38)) irten = 1;
    }
    if (ebentu == TECLA_ESCAPE) irten = 1;
    else if((ebentu >= TECLA_0) &&(ebentu < TECLA_0+SOINU_KOP))
      playSound(gureGauzak.idSounds[ebentu - TECLA_0]);
    else if (ebentu == TECLA_RETURN) toggleMusic();
  }
  audioTerminate();
  sgItxi();
  return 0;
}


int hasieratu(void)
{
  int i;
  char str[128];
  double d= 7.3;

  if (sgHasieratu() == -1)
  {
    fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
    return 0;
  }
  audioInit();
  for (i = 0; i < SOINU_KOP; i++)
  {
    if ((gureGauzak.idSounds[i] = loadSound(soundFiles[i])) == -1)
    {
      fprintf(stderr, "Unable to load sound %s\n", SDL_GetError());
      return 0;
    }
  }
  if (!loadTheMusic(".\\sound\\beat.wav"))
  {
    fprintf(stderr, "Unable to load music %s\n", SDL_GetError());
    return 0;
  }
  textuaGaitu();
  pantailaGarbitu();
  
  gureGauzak.idIrudi=irudiaKargatu(".\\img\\hexagono.bmp");
  
  textuaIdatzi(10, 20, "Return: musika ON/OFF");
  textuaIdatzi(10, 40, "[0,4]:  soinu bat");
  textuaIdatzi(10, 60, "ESC:    amaitzeko");
  textuaIdatzi(10, 80, "arratoia hexagonoan: amaitu");
  sprintf(str,"%lf", d);
  textuaIdatzi(10, 100, str);
  irudiaMugitu(gureGauzak.idIrudi, 300, 200);
  irudiakMarraztu();
  arkatzKoloreaEzarri(0xFF, 0xFF, 0xFF);
  zuzenaMarraztu(0, SCREEN_HEIGHT * 2 / 3, SCREEN_WIDTH, SCREEN_HEIGHT * 2 / 3);
  zirkuluaMarraztu(500, 400, 10);
  pantailaBerriztu();
  ;


  return 0;
}


