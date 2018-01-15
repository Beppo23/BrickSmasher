/*#include "orokorrak.h"
#include "sarrera.h"
#include "errealitateFisikoa.h"
#include "jokoa.h"
#include "bukaera.h"*/

//---------------------------------------------------------------------------------
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
//---------------------------------------------------------------------------------

#include <stdio.h>

#include "ourTypes.h"
#include "arkanoid.h"


int main(int argc, char * str[]) {
	int jarraitu = 0, scoreArray[1];
	EGOERA egoera;
 
  if (sgHasieratu() == -1) 
  {
    fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
    return 1;
  }
  textuaGaitu(); 
  do
  {
    jokoaAurkeztu();
	egoera = jokatu(scoreArray);
	jarraitu = jokoAmaierakoa(egoera, scoreArray);
  } while (jarraitu);
  sgItxi();
  return 0;
}

