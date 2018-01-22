#ifndef IRUDIAKSORTU_H
#define IRUDIAKSORTU_H
#include "OurTypes.h"

#define BOTON_ITZULI ".\\img\\itzuli.bmp"
#define JOKATU ".\\img\\joka.bmp"
#define TUTORIALA ".\\img\\noljoka.bmp"
#define TECLA_Q ".\\img\\qtecla.bmp"
#define KREDITUAK ".\\img\\kredituak.bmp"
#define KREDITOAK_IMAGE ".\\img\\krekre.bmp"
#define ITXI ".\\img\\itxijokua.bmp"
#define MENU_BACKGROUD_IMAGE ".\\img\\men.bmp"
#define JOKOA_BACKGROUND_IMAGE ".\\img\\arkanoid_fondo.bmp"
#define BACKGROUND_LEVEL2 ".\\img\\background_2.bmp"
#define TECLA_BARRA ".\\img\\espacio.bmp"
#define TECLA_EZKERRA ".\\img\\ezkerra.bmp"
#define TECLA_ESKUMA ".\\img\\eskuma.bmp"
#define HURRENGOA ".\\img\\power.bmp"
#define S_YELLOW_POWERUP ".\\img\\s_Yellow.bmp"
#define X_PURPLE_POWERUP ".\\img\\x_Purple.bmp"
#define N_GREEN_POWERUP ".\\img\\n_Green.bmp"
#define S_RED_POWERUP ".\\img\\s_red.bmp"
#define JOKOA_TIROA_IMAGE ".\\img\\tiroa.bmp"
#define JOKOA_PELOTA_IMAGE ".\\img\\pelota.bmp"
#define BUKAERA_IMAGE ".\\img\\gameOver_3.bmp"
#define IRABAZI_IMAGE ".\\img\\IRABAZI.bmp"
#define JOKOA_PLAYER_IMAGE ".\\img\\barra1.bmp"
#define JOKOA_ENERGIA_IMAGE ".\\img\\barra_energia.bmp"
#define PAUSA2 ".\\img\\pause.bmp"
#define MUTE "Mute->M"
#define PAUSA "Pausa->ESC"

int JOKOA_fondoaSortu();
int JOKOA_fondoaSortu2();
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
int JOKOA_power();
int powermorea();
int powerberdea();
int powerhoria();
int powergorria();
void sarreraMezuaIdatzi();
int JOKOA_pilotaIrudiaSortu();
int JOKOA_TiroaIrudiaSortu();
int JOKOA_barraIrudiaSortu();
int JOKOA_jokalariaIrudiaSortu();
int BUKAERA_irudiaBistaratu(int scoreArray[]);
int IRABAZI_irudiaBistaratu(int scoreArray[]);
#endif