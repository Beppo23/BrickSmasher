#ifndef SCORE_H
#define SCORE_H
#include "OurTypes.h"

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

void markagailua(int kontScore[], JOKO_ELEMENTUA zenbakiak, int zenbakiArray[]);
void scoreBorratu(int kontScore, int zenbakiArray[]);
void puntuazioaMarraztu();
int zifra(int posizioax, int posizioay, int kontScore);
void finalScore(int scoreArray[], int posizioax, int posizioay);
#endif