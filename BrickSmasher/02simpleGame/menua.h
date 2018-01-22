#ifndef MENUA_H
#define MENUA_H
#include "OurTypes.h"

#define NOLA_JOKATU "Barra bat daukazu, hau mugitzeko geziak erabiltzen dira. "
#define NOLA1_JOKATU "Ezkerrera joateko gezi hau erabiltzen duzu:"
#define NOLA2_JOKATU "Pilota barratik jaurtitzeko <space> teklari eman."
#define NOLA3_JOKATU "Eskumara joateko gezi hau erabiltzen duzu:"
#define NOLA4_JOKATU "Power up morea jasotzen duzunean 6 tiro dituzu."
#define NOLA5_JOKATU "Hau gauzatzeko tekla hau erabili:"
#define NOLA6_JOKATU "Power up berdea jasotzen duzunean pilota barran itsatsita geratzen da:"
#define NOLA7_JOKATU "Pilota jaurtitzeko <space> teklari eman."
#define NOLA8_JOKATU "Power up horia jasotzen duzunean jokuak bi pilota sortzen ditu."
#define NOLA9_JOKATU "Horrela bloke gehiago puskatu al dituzu."
#define NOLA10_JOKATU "Power up gorria lortzen baduzu,honekin hainbat bloke puskatu al dituzu."
#define MENU_AUDIO ".\\sound\\menu_audio.wav"
#define JOKOA_SOUND_WIN ".\\sound\\you_win.wav"
#define JOKOA_SOUND_LOSE ".\\sound\\you_lose.wav"

int jokoaAurkeztu();
int  jokoAmaierakoa(EGOERA egoera, int scoreArray[]);
EGOERA JOKOA_egoera(JOKALARIA_ELEMENTUA jokalaria, JOKO_ELEMENTUA pilota, int bizitza, int hutsik, int scoreArray[]);
EGOERA JOKOA_egoera2(JOKALARIA_ELEMENTUA jokalaria, JOKO_ELEMENTUA pilota, int bizitza, int hutsik);
#endif