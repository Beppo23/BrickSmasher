#include "irudiaksortu.h"
#include "imagen.h"
#include "graphics.h"
#include "score.h"
#include "text.h"

int JOKOA_jokalariaIrudiaSortu()
{
	int barraId = -1;
	barraId = irudiaKargatu(JOKOA_PLAYER_IMAGE);
	irudiaMugitu(barraId, 10, 239);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return barraId;
}

int JOKOA_barraIrudiaSortu()
{
	int energiaId = -1;
	energiaId = irudiaKargatu(JOKOA_ENERGIA_IMAGE);
	irudiaMugitu(energiaId, 10, 239);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return energiaId;
}
int JOKOA_TiroaIrudiaSortu()
{
	int tiroaID = -1;
	tiroaID = irudiaKargatu(JOKOA_TIROA_IMAGE);
	irudiaMugitu(tiroaID, 1000, 1000);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return tiroaID;
}
int jokoa_pause()
{
	int pilotaId = -1;
	pilotaId = irudiaKargatu(PAUSA2);
	irudiaMugitu(pilotaId, 130, 240);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pilotaId;
}
int JOKOA_pilotaIrudiaSortu()
{
	int pilotaId = -1;
	pilotaId = irudiaKargatu(JOKOA_PELOTA_IMAGE);
	irudiaMugitu(pilotaId, 4000, -4000);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pilotaId;
}

int IRABAZI_irudiaBistaratu(int scoreArray[])
{
	int id = -1;
	id = irudiaKargatu(IRABAZI_IMAGE);
	irudiaMugitu(id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	finalScore(scoreArray, 288, 360);
	textuaIdatzi(50, 400, MEZUA);
	pantailaBerriztu();
	return id;
}

int BUKAERA_irudiaBistaratu(int scoreArray[])
{
	int id = -1;
	id = irudiaKargatu(BUKAERA_IMAGE);
	irudiaMugitu(id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	finalScore(scoreArray, 280, 210);
	textuaIdatzi(50, 400, MEZUA);
	pantailaBerriztu();
	return id;
}
void sarreraMezuaIdatzi()
{
	pantailaGarbitu();
	JOKOA_backSortu();
	JOKOA_jokatu();
	JOKOA_tutoriala();
	JOKOA_kreditoak();
	JOKOA_itxi();
	textuaIdatzi(15, 5, MUTE);
	textuaIdatzi(530, 5, PAUSA);
	pantailaBerriztu();
}
int JOKOA_fondoaSortu()
{
	int fondoaId = -1;
	fondoaId = irudiaKargatu(JOKOA_BACKGROUND_IMAGE);
	irudiaMugitu(fondoaId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return fondoaId;
}
int JOKOA_jokatu()
{
	int jokatuId = -1;
	jokatuId = irudiaKargatu(JOKATU);
	irudiaMugitu(jokatuId, 260, 120);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return jokatuId;
}
int JOKOA_tutoriala()
{
	int tutoId = -1;
	tutoId = irudiaKargatu(TUTORIALA);
	irudiaMugitu(tutoId, 260, 210);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return tutoId;
}
int JOKOA_kreditoak()
{
	int kreId = -1;
	kreId = irudiaKargatu(KREDITUAK);
	irudiaMugitu(kreId, 260, 300);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kreId;
}

int JOKOA_itxi()
{
	int itxId = -1;
	itxId = irudiaKargatu(ITXI);
	irudiaMugitu(itxId, 260, 390);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return itxId;
}
//int JOKOA_itxi2()
//{
//	int itxId = -1;
//	itxId = irudiaKargatu(ITXI);
//	irudiaMugitu(itxId, 440, 370);
//	pantailaGarbitu();
//	irudiakMarraztu();
//	pantailaBerriztu();
//	return itxId;
//
//}
int powermorea()
{
	int powId = -1;
	powId = irudiaKargatu(X_PURPLE_POWERUP);
	irudiaMugitu(powId, 50, 40);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return powId;
}
int powerberdea()
{
	int powId = -1;
	powId = irudiaKargatu(N_GREEN_POWERUP);
	irudiaMugitu(powId, 50, 160);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return powId;
}
int powerhoria()
{
	int powId = -1;
	powId = irudiaKargatu(S_YELLOW_POWERUP);
	irudiaMugitu(powId, 50, 250);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return powId;
}
int powergorria()
{
	int powId = -1;
	powId = irudiaKargatu(S_RED_POWERUP);
	irudiaMugitu(powId, 50, 310);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return powId;
}
int JOKOA_power()
{
	int powId = -1;
	powId = irudiaKargatu(HURRENGOA);
	irudiaMugitu(powId, 440, 430);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return powId;
}

int JOKOA_itzuli()
{
	int itzulId = -1;
	itzulId = irudiaKargatu(BOTON_ITZULI);
	irudiaMugitu(itzulId, 50, 430);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return itzulId;
}
int JOKOA_teclaEzkerra()
{
	int teclaId = -1;
	teclaId = irudiaKargatu(TECLA_EZKERRA);
	irudiaMugitu(teclaId, 360, 108);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return teclaId;
}
int JOKOA_teclaEskuma()
{
	int teclaId = -1;
	teclaId = irudiaKargatu(TECLA_ESKUMA);
	irudiaMugitu(teclaId, 360, 170);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return teclaId;
}
int JOKOA_q()
{
	int teclaId = -1;
	teclaId = irudiaKargatu(TECLA_Q);
	irudiaMugitu(teclaId, 300, 115);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return teclaId;
}
int JOKOA_barra()
{
	int barraId = -1;
	barraId = irudiaKargatu(TECLA_BARRA);
	irudiaMugitu(barraId, 400, 250);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return barraId;
}
//int JOKOA_menu()
//{
//	int menuraId = -1;
//	menuraId = irudiaKargatu(BOTON_MENU);
//	irudiaMugitu(menuraId, 50, 370);
//	pantailaGarbitu();
//	irudiakMarraztu();
//	pantailaBerriztu();
//	return menuraId;
//}

int JOKOA_backSortu()
{
	int backId = -1;
	backId = irudiaKargatu(MENU_BACKGROUD_IMAGE);
	irudiaMugitu(backId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return backId;
}
int JOKOA_KreditoakSortu()
{
	int kredId = -1;
	kredId = irudiaKargatu(KREDITOAK_IMAGE);
	irudiaMugitu(kredId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kredId;
}