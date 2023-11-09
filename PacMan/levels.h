#ifndef LEVELS_H_INCLUDED
#define LEVELS_H_INCLUDED
#include <conio.h>
#include <time.h>
#include "game.h"
#include <math.h>




void delay(int number_of_miliseconds);


void clear_board(game_t* game);



void niveaux(game_t* game, int vitesse);

void save(game_t* game);
int read_save();
#endif // LEVELS_H_INCLUDED
