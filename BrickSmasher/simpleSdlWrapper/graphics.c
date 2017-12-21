//Esto con un incude de include
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define GRAPHICS

#include "SDL_ttf.h"

#include "imagen.h"
#include "graphics.h"

SDL_Window* window = NULL;
SDL_Renderer* gRenderer;
int colorR, colorG, colorB;

SDL_Renderer* getRenderer(void) { return gRenderer; }

int sgHasieratu()
{
  int ret = 0;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    fprintf(stderr, "ezin SDL hasieratu: %s\n", SDL_GetError());
    return -1;
  }
  atexit(SDL_Quit);
  window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL)
  {
    fprintf(stderr, "Ezin lehioa sortu: %s\n", SDL_GetError());
    return -1;
  }
  gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  TTF_Init();
  atexit(TTF_Quit);
  return ret;
}


void sgItxi()
{
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void arkatzKoloreaEzarri(int red, int green, int blue)
{
  colorR = red;
  colorG = green;
  colorB = blue;
}


void zuzenaMarraztu(int x1, int y1, int x2, int y2)
{
  SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawLine(gRenderer, x1, y1, x2, y2);
}

void puntuaMarraztu(int x, int y)
{
  SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawPoint(gRenderer, x, y);
}

void zirkuluaMarraztu(int x, int y, int r)
{

  int i, h;

  SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
  for (i = x - r; i <= x + r; i++)
  {
    h = (int)llround(sqrt((double)(r*r - (i - x)*(i - x))));
    SDL_RenderDrawLine(gRenderer, i, y + h, i, y - h);
  }
}



int irudiaMarraztu(SDL_Texture* texture, SDL_Rect *pDest)
{
  SDL_Rect src;

  src.x = 0;
  src.y = 0;
  src.w = pDest->w;
  src.h = pDest->h;
  SDL_RenderCopy(gRenderer, texture, &src, pDest);
  return 0;
}

void pantailaGarbitu()
{
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(gRenderer);
}


void pantailaBerriztu()
{
  SDL_RenderPresent(gRenderer);
}