#ifndef GAME_H
#define GAME_H

// Libraries
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <assert.h>
#include "position.h"
#include "obstacle.h"
#include "random.h"


// Define Char
#define SNAKE_CHAR 'x'
#define VOID_CHAR ' '

// structure principale GAME_T
typedef struct game_t {
    char** board;
    int border;
    int life;
    int level;
    position_t dimension;
    position_t* snake_position;
    int snake_size;
    position_t direction;
    position_t* direction_obstacles;
    position_t* track_direction_obstacles;
    obstacle_t* obstacles;
    int* obstacle_hit_wall;
    int obstacles_count;
} game_t;

// move the cursor
void gotoXY(int x, int y);

// initialise the struct game
game_t* game_create(int height, int width);

// create the matrix
void game_map(game_t* game);

// create the maze
void game_maze(game_t* game);

// keeps the characters moving
void game_move(game_t* game, position_t offset);

// keep moving
void game_keep_moving(game_t* game);

// move up
void game_up(game_t* game);

// move down
void game_down(game_t* game);

// move left
void game_left(game_t* game);

// move right
void game_right(game_t* game);

// make the character bigger as the levels progress
void game_snake_size_up(game_t* game);

// obstacles
void game_add_obstacle(game_t* game, obstacle_t obstacle);

// to kill the character if it is touched by a different character other than P
void game_snake_cut(game_t* game,int index);

// 0 if untouched, or else contact index is returned when clashing into obstacles
int game_snake_hit_no_head(game_t* game, obstacle_t* obstacle);

// true if the game is over
bool game_snake_hit_snake(game_t* game);

// removesobstacle
void remove_obstable(game_t* game,int index);

// returns the contact index
bool game_has_hit(game_t* game, obstacle_t* obstacle,int* index);

// full game display. very imp function
void game_display(game_t* game);

// free space at the end of a game
void game_free(game_t* game);

//how many times a wall was hit
void check_obstacle_hit_wall (game_t* game);

//obstacle moving
void game_obstacle_move( game_t* game, int index);

// obstacle move at double speed 
void game_obstacle_move_diverty( game_t* game , int ctr);

// obstacle tracking measurement so that nothing clashes
int minimun_distance_obstacle(int d1, int d2, int d3, int d4);

//Obstacles tracking ai
void obstacle_tracking(game_t* game);

// fruit display
void print_apples(game_t* game, int nb_apple);

// ghost display
void print_ennemies(game_t* game, int nb_ghost);

#endif /* end of include guard: GAME_H */
