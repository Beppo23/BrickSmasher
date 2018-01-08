#ifndef OURTYPES_H
#define OURTYPES_H

#include "ebentoak.h"

typedef enum { JOLASTEN, GALDU, IRABAZI }EGOERA;
typedef enum { IRUDIA, MARGOA, TESTUA } MOTA;

typedef struct
{
  POSIZIOA pos;
  int id;
  MOTA mota;
}JOKO_ELEMENTUA;
typedef struct
{
	POSIZIOA pos;
	int id;
	int apurtuta;
	MOTA mota;
}LAUKIZUZENA_ELEMENTUA;
#endif