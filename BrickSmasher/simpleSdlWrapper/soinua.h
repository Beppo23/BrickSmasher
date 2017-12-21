#ifndef SOINUA_H
#define SOINUA_H

#define MAX_SOUNDS 10

#include <SDL_mixer.h>

void audioInit();
int loadSound(char *fileName);
int loadTheMusic(char *fileName);
int playSound(int idSound);
int playMusic(void);
void toggleMusic(void);
void audioTerminate();



#endif