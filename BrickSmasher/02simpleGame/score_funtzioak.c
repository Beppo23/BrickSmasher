#include "imagen.h"
#include "graphics.h"
#include "score.h"

void markagailua(int kontScore[], JOKO_ELEMENTUA zenbakiak, int zenbakiArray[])
{
	int i, j, posizioax = 500, posizioay = 450;

	i = kontScore[0];
	scoreBorratu(i, zenbakiArray);

	if (i >= 1000)
	{
		i /= 1000;
		zenbakiak.id = zifra(posizioax, posizioay, i);
		zenbakiArray[0] = zenbakiak.id;
		i = kontScore[0] - i * 1000;
		zifra(posizioax + 16, posizioay, 0);
	}
	posizioax += 16;

	if (i >= 100)
	{
		j = i;
		i /= 100;
		zenbakiak.id = zifra(posizioax, posizioay, i);
		zenbakiArray[1] = zenbakiak.id;
		i = j - i * 100;
		zifra(posizioax + 16, posizioay, 0);
	}
	posizioax += 16;

	if (i >= 10)
	{
		i /= 10;
		zenbakiak.id = zifra(posizioax, posizioay, i);
		zenbakiArray[2] = zenbakiak.id;
	}
}
void scoreBorratu(int kontScore, int zenbakiArray[])
{
	if (kontScore > 1000) irudiaKendu(zenbakiArray[0]);

	else if (kontScore > 100) irudiaKendu(zenbakiArray[1]);

	else if (kontScore > 10) irudiaKendu(zenbakiArray[2]);
}
void puntuazioaMarraztu()
{
	zifra(548, 450, 0);
	zifra(532, 450, 0);
	zifra(516, 450, 0);
	zifra(500, 450, 0);
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

void finalScore(int scoreArray[])
{
	int i, j, posizioax = 280, posizioay = 210;
	i = scoreArray[0];

	if (i >= 1000)
	{
		j = i;
		i /= 1000;
		zifra(posizioax, posizioay, i);
		j -= 1000;
		i = j;
		zifra(posizioax + 16, posizioay, 0);
	}
	posizioax += 16;

	if (i >= 100)
	{
		j = i;
		i /= 100;
		zifra(posizioax, posizioay, i);
		i = j - i * 100;
		zifra(posizioax + 16, posizioay, 0);
	}
	posizioax += 16;

	if (i >= 10)
	{
		i /= 10;
		zifra(posizioax, posizioay, i);
	}

	posizioax += 16;
	zifra(posizioax, posizioay, 0);
}