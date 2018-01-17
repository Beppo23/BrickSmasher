#ifndef MENUA_H
#define MENUA_H
#include "OurTypes.h"

#define BOTON_ITZULI ".\\img\\itzuli.bmp"
#define JOKATU ".\\img\\joka.bmp"
#define TUTORIALA ".\\img\\noljoka.bmp"
#define NOLA_JOKATU "Barra bat daukazu, hau mugitzeko geziak erabiltzen dira. "
#define NOLA1_JOKATU "Ezkerrera joateko gezi hau erabiltzen duzu:"
#define NOLA2_JOKATU "Pilota barratik jaurtitzeko <space> teklari eman."
#define NOLA3_JOKATU "Eskumara joateko gezi hau erabiltzen duzu:"
#define NOLA4_JOKATU "Power up morea jasotzen duzunean 6 tiro dituzu."
#define NOLA5_JOKATU "Hau gauzatzeko tekla hau erabili:"
#define TECLA_Q ".\\img\\qtecla.bmp"
#define KREDITUAK ".\\img\\kredituak.bmp"
#define KREDITOAK_IMAGE ".\\img\\krekre.bmp"
#define ITXI ".\\img\\itxijokua.bmp"
#define MENU_BACKGROUD_IMAGE ".\\img\\men.bmp"
#define JOKOA_BACKGROUND_IMAGE ".\\img\\arkanoid_fondo.bmp"
#define TECLA_BARRA ".\\img\\espacio.bmp"
#define TECLA_EZKERRA ".\\img\\ezkerra.bmp"
#define TECLA_ESKUMA ".\\img\\eskuma.bmp"
#define MENU_AUDIO ".\\sound\\menu_audio.wav"

int JOKOA_fondoaSortu();
int JOKOA_itzuli();
int JOKOA_teclaEzkerra();
int JOKOA_teclaEskuma();
int JOKOA_barra();
int JOKOA_KreditoakSortu();
int JOKOA_backSortu();
int JOKOA_jokatu();
int JOKOA_tutoriala();
int JOKOA_kreditoak();
int JOKOA_itxi();
int JOKOA_q();
void sarreraMezuaIdatzi();
#endif