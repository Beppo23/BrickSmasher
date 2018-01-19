#ifndef OURTYPES_H
#define OURTYPES_H

#include "ebentoak.h"

typedef enum { JOLASTEN, GALDU, IRABAZI }EGOERA;
typedef enum { IRUDIA, MARGOA, TESTUA } MOTA;
typedef enum { NORMAL, TIROAK, ITSATSITA, MULTIBALL , GOD, GODON}PWUP_EGOERA;
typedef enum { HORIA, MOREA, BERDEA, GORRIA } KOLOREA;

typedef struct
{
  POSIZIOA pos;
  int id;
  MOTA mota;
  NORA nora;
}JOKO_ELEMENTUA;
typedef struct
{
	POSIZIOA pos;
	int id;
	PWUP_EGOERA egoera;
	MOTA mota;
}JOKALARIA_ELEMENTUA;
typedef struct
{
	POSIZIOA pos;
	int id;
	int apurtuta;
	MOTA mota;
}LAUKIZUZENA_ELEMENTUA;
typedef struct
{
	POSIZIOA pos;
	int id;
	int zein;
	int jaurti;
	int puxkatu;
	MOTA mota;
}TIROA_ELEMENTUA;
typedef struct
{
	POSIZIOA pos;
	int zein;
	int id;
	KOLOREA koloreak;
}POWERUP_ELEMENTUA;
#endif