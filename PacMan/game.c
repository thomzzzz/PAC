#include "game.h"


//Moves the cursor (x,y)
void gotoXY(int x, int y){
	COORD mycoord;
	mycoord.X = x;
	mycoord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}

//Structure called game
game_t* game_create(int height, int width){

    // memory alloc
    game_t* game = (game_t*) malloc(sizeof(game_t));


    // allocation of the game board 
	//height
    game->board = malloc(height*sizeof(char*));

	//width
    for(int i=0 ; i<height ; i++){
        game->board[i] = malloc(width*sizeof(char));
        for(int j=0 ; j<width ; j++){
            game->board[i][j] = VOID_CHAR;
        }
    }

    // initialisation of dimension, border, life, level
    game->dimension.x = width;
    game->dimension.y = height;
	game->border=0;
	game->life=5;
	game->level=1;

	// allocate memory for every co-ordinate that counts as the body
    game->snake_size = 1;
    game->snake_position = malloc(game->snake_size*sizeof(position_t));

    // start position of pacman. this is assigned randomly
    do{
    	game->snake_position[0] = position_create(randomX(width),randomY(height));
    }while (game->snake_position[0].x!=' ');

	// random direction of the snake
	game->direction = randomdirection();

	// number of obstacles initially
    game->obstacles_count = 0;

	// return the struct game
    return game;
}

// creating borders of the board
void game_map(game_t* game){

	// variables
	int i=0, j=0;

	// walls on the game board
	for (i = 0; i < game->dimension.y; i++){
        game->board[i][0] = 186; // left wall '║'
        game->board[i][game->dimension.x-1] = 186 ; // right wall '║'
	}

	for (j = 0; j < game->dimension.x; j++){
        game->board[0][j] = 205;// top wall  '═'
		game->board[game->dimension.y-1][j] = 205; // buttom wall  '═'
	}

	//top left angle '╔'

	game->board[0][0] = 201;

	//top right angle '╗'
	game->board[0][game->dimension.x-1] = 187;

	//buttom left angle '╚'
	game->board[game->dimension.y-1][0] = 200;

	//buttom right angle '╝'
	game->board[game->dimension.y-1][game->dimension.x-1] = 188;

}

// creating a maze on the board
void game_maze(game_t* game){

	// variable
	int i=0;

	//placement of the walls yet again
	game->board[0][12] = 203;
	for (i = 1; i < 7; i++){
        game->board[i][12] = 186;
	}
	game->board[7][12] = 200;
	for (i = 13; i < 23; i++){
        game->board[7][i] = 205;
	}
	game->board[7][23] = 187;
	for (i = 8; i < 13; i++){
        game->board[i][23] = 186;
	}

	for (i = 21; i < 31; i++){
        game->board[3][i] = 205;
	}
	game->board[3][31] = 187;
	for (i = 4; i < 7; i++){
        game->board[i][31] = 186;
	}
	game->board[7][31] = 200;
	for (i = 32; i < 41; i++){
        game->board[7][i] = 205;
	}
	for (i = 3; i < 7; i++){
        game->board[i][41] = 186;
	}
	game->board[7][41] = 185;
	for (i = 8; i < 16; i++){
        game->board[i][41] = 186;
	}

	for (i = 5; i < 12; i++){
        game->board[i][6] = 186;
	}
	game->board[12][6] = 200;

	for (i = 7; i < 11; i++){
        game->board[12][i] = 205;
	}
	game->board[12][11] = 203;
	for (i = 13; i < 18; i++){
        game->board[i][11] = 186;
	}

	for (i = 12; i < 17; i++){
        game->board[12][i] = 205;
	}
	game->board[12][17] = 187;
	for (i = 13; i < 17; i++){
        game->board[i][17] = 186;
	}
	game->board[16][17] = 200;
	for (i = 18; i < 30; i++){
        game->board[16][i] = 205;
	}
	game->board[16][30] = 188;
	for (i = 13; i < 16; i++){
        game->board[i][30] = 186;
	}
	game->board[13][30] = 204;
	for (i = 31; i < 37; i++){
        game->board[13][i] = 205;
	}
	for (i = 10; i <13 ; i++){
        game->board[i][30] = 186;
	}
}

//nonstop movement of the ghosts and pacman
void game_move(game_t* game, position_t offset){

	// variables
	position_t new_pos;
	position_t old_pos;

	// ghost only moves forward
	if (game->snake_size>=2){
            if(offset.x==-game->direction.x && offset.y==-game->direction.y)
                return;
    }

	// remember the position of the ghost at every instant 
	old_pos.x = game->snake_position[0].x;
	old_pos.y = game->snake_position[0].y;

	// diff between new pos and old pos
	new_pos.x = old_pos.x + offset.x;
	new_pos.y = old_pos.y + offset.y;


	if (new_pos.x != game->dimension.x-1 && new_pos.x != 0 && new_pos.y != game->dimension.y-1 && new_pos.y != 0 ){
			// si les nouvelles positions sont des murs
			if (game->board[new_pos.y][new_pos.x] != ' '
			&& game->board[new_pos.y][new_pos.x] != 'P'
			&& game->board[new_pos.y][new_pos.x] != 'E'
			&& game->board[new_pos.y][new_pos.x] != '*'
			&& game->board[new_pos.y][new_pos.x] != SNAKE_CHAR){

				// pacman can't move through a wall
				new_pos.x=old_pos.x;
				new_pos.y=old_pos.y;

			}
		}

	//if pacman moves off the border he comes from the other end of the board
    if(new_pos.x>=game->dimension.x-1){
		if (game->border==1){ game->life--;}
        new_pos.x = 1;
    } else if(new_pos.x<1){
		if (game->border==1){ game->life--;}
        new_pos.x = game->dimension.x-2;
    } else if(new_pos.y>=game->dimension.y-1){
		if (game->border==1){ game->life--;}
        new_pos.y = 1;
    } else if(new_pos.y<1){
		if (game->border==1){ game->life--;}
        new_pos.y = game->dimension.y-2;
    }

	// new pos update to pointer
    game->board[new_pos.y][new_pos.x] = SNAKE_CHAR;

	// if free to move forward
	if(new_pos.x != old_pos.x || new_pos.y != old_pos.y){
		// body moves with head. second link follows its link before it
		for(int i=0; i<game->snake_size; i++){
	        position_t tmp = game->snake_position[i];
	        game->snake_position[i] = new_pos;
	        new_pos = tmp;
		}
		// delete the body link after moving forawrd
		game->board[new_pos.y][new_pos.x] = VOID_CHAR;
	}
	game->direction = offset;
}

void game_keep_moving(game_t* game){
    game_move(game, game->direction);
}

void game_up(game_t* game){
    game_move(game, position_create(0,-1));
}

void game_down(game_t* game){
    game_move(game, position_create(0,1));
}

void game_left(game_t* game){
    game_move(game, position_create(-1,0));
}

void game_right(game_t* game){
    game_move(game, position_create(1,0));
}

void game_snake_size_up(game_t* game){

	
	position_t new_pos;
	position_t ll_pos;
	position_t l_pos;

    game->snake_size++;

	l_pos = game->snake_position[game->snake_size-2];//penser à que game->size a augmenté mais n'est pas encore actif sur les coordonnées d'ou le dernier est N-2
	ll_pos = game->snake_position[game->snake_size-3];//penser à que game->size a augmenté mais n'est pas encore actif sur les coordonnées d'ou l'avant dernier est N-3

	game->snake_position = realloc(game->snake_position, game->snake_size*sizeof(position_t));

    //managing the movement of the character if size is greater than 2
	if(game->snake_size>2){

        if(ll_pos.x==l_pos.x && ll_pos.y<l_pos.y){
            new_pos = position_create(l_pos.x, l_pos.y+1);
        } else if(ll_pos.x==l_pos.x && ll_pos.y>l_pos.y){
            new_pos = position_create(l_pos.x, l_pos.y-1);
        } else if(ll_pos.y==l_pos.y && ll_pos.x<l_pos.x){
            new_pos = position_create(l_pos.x+1, l_pos.y);
        } else if(ll_pos.y==l_pos.y && ll_pos.x>l_pos.x){
            new_pos = position_create(l_pos.x-1, l_pos.y);
        }
    }
	
	else{
        new_pos = game->snake_position[game->snake_size-2];
        new_pos.x -= game->direction.x;
        new_pos.y -= game->direction.y;
    }
    game->snake_position[game->snake_size-1] = new_pos;
    game->board[new_pos.y][new_pos.x] = SNAKE_CHAR;
}

void game_add_obstacle(game_t* game, obstacle_t obstacle){

	// variables
	position_t pos = obstacle.pos;

    assert(pos.x>=0 && pos.x<game->dimension.x && pos.y>=0 && pos.y<game->dimension.y);

    game->board[pos.y][pos.x] = obstacle.obstacle_type;

	if(game->obstacles_count==0){
        game->obstacles_count = 1;
        game->obstacles = malloc(sizeof(obstacle_t));
		game->obstacle_hit_wall = malloc(sizeof(int));
		game->direction_obstacles = malloc(sizeof(position_t));
		game->track_direction_obstacles = malloc(sizeof(position_t));

    }
	else{
        game->obstacles_count++;

        game->obstacles = realloc(game->obstacles, game->obstacles_count*sizeof(obstacle_t));
		game->obstacle_hit_wall = realloc(game->obstacle_hit_wall, game->obstacles_count*sizeof(int));
		game->direction_obstacles = realloc(game->direction_obstacles, game->obstacles_count*sizeof(position_t));
		game->track_direction_obstacles = realloc(game->track_direction_obstacles, game->obstacles_count*sizeof(position_t));

    }
    game->obstacles[game->obstacles_count-1] = obstacle;
	game->obstacle_hit_wall[game->obstacles_count-1] = 0;
	game->direction_obstacles[game->obstacles_count-1] = position_create(0,0);
	game->track_direction_obstacles[game->obstacles_count-1] = position_create(0,0);

}

void game_snake_cut(game_t* game,int index){

	//variables
	int i=0;

	for(i=index; i<game->snake_size;i++){
		game->board[game->snake_position[i].y][game->snake_position[i].x] = VOID_CHAR;
	}
    game->snake_size=index;
    game->snake_position = realloc(game->snake_position, game->snake_size*sizeof(position_t));
}

int game_snake_hit_no_head(game_t* game, obstacle_t* obstacle){

	//variables
	int index = 0;
	int i=0, j=0;

	for (i=1; i<game->snake_size; i++){
	    for(j=0 ; j<game->obstacles_count ; j++){
	        if(game->snake_position[i].x==game->obstacles[j].pos.x && game->snake_position[i].y==game->obstacles[j].pos.y){
				*obstacle = game->obstacles[j];
	            index=i;
	        }
	    }
	}
	return index;
}

bool game_snake_hit_snake(game_t* game){
	if(game->board[game->snake_position[0].y+game->direction.y]
		[game->snake_position[0].x+game->direction.x]==SNAKE_CHAR){
			return true;
	}else return false;
}

void remove_obstable(game_t* game,int index){

	//variables
	obstacle_t tmp;
	int i=0;

	obstacle_t* new_liste=malloc ( (game->obstacles_count-1)* sizeof(obstacle_t));

    for(i=0; i<index; i++){
		new_liste[i]=game->obstacles[i];
	}
	for(i=(index+1); i<game->obstacles_count; i++){
		new_liste[i-1]=game->obstacles[i];
	}
	for (i=0;i<game->obstacles_count;i++){
        game->obstacles[i]=new_liste[i];
	}
    game->obstacles_count--;
//free the extra space
	free(new_liste);
}

bool game_has_hit(game_t* game, obstacle_t* obstacle, int* index){

	// variables
	position_t pos = game->snake_position[0];
	obstacle_t obs;
	int i=0;

    for(i=0 ; i<game->obstacles_count ; i++){
		obs = game->obstacles[i];
        if(pos.x==obs.pos.x && pos.y==obs.pos.y){
			*index=i;
            *obstacle = obs;
            return true;
        }
    }
    return false;
}

void game_display(game_t* game){

	//variables
	int i=0, j=0, k=9;

    for(i=0 ; i<game->dimension.y ; i++)
    {
        gotoXY(10, 5+i);
        for(j=0; j<game->dimension.x; j++)
      {
      	if (game->board[i][j]==SNAKE_CHAR) // si  pacman
      	{
				Color(14,0); 
                printf("%c", game->board[i][j]); 
           		Color(12,0); 
      	}

      	else if (game->board[i][j]== 'E') 
      	{

      			Color(11,0);
                printf("%c", game->board[i][j]); 
           		Color(12,0); 

      	}
      	else if (game->board[i][j]== 'P') 
      	{
      		Color(2,0); 
      		printf("%c", game->board[i][j]); 
      		Color(12,0);
      	}
      	else if(game->board[i][j]== '*') 
      	{
      		Color(k,0); 
      		printf("%c", game->board[i][j]);
      		Color(12,0);
      		k++ ; 
      	}
      	else
      	{
      		printf("%c", game->board[i][j]);// imprime
      	}

      }
        printf("\n");
    }
}

void game_free(game_t* game){

	// variables
	int i=0 ;

    for(i=0 ; i<game->dimension.y ; i++){
        free(game->board[i]);
    }
	free(game->board);
    free(game->snake_position);
    free(game->obstacles);
	free(game->obstacle_hit_wall);
	free(game->direction_obstacles);
	free(game->track_direction_obstacles);
    free(game);
}

void check_obstacle_hit_wall (game_t* game){

	//variables
	int i=0;

	for (i=0; i< game->obstacles_count;i++)
	{
		if (game->direction_obstacles->x==1 || game->direction_obstacles->x==-1){
			if (game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x+1] != ' '
			&& game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x+1] != game->obstacles->obstacle_type
			&& game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x+1] != SNAKE_CHAR){
					game->obstacle_hit_wall[i]++;
			}
			if (game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x-1] != ' '
			&& game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x-1] != game->obstacles->obstacle_type
			&& game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x-1] != SNAKE_CHAR){
					game->obstacle_hit_wall[i]++;
			}
		}
		if (game->direction_obstacles->y==1 || game->direction_obstacles->y==-1){
			// verifie s'il y a un mur au dessus de lui, si oui, augmente de 1 obstacle_hit_wall
			if (game->board[game->obstacles[i].pos.y+1][game->obstacles[i].pos.x] != ' '
			&& game->board[game->obstacles[i].pos.y+1][game->obstacles[i].pos.x] != game->obstacles->obstacle_type
			&& game->board[game->obstacles[i].pos.y+1][game->obstacles[i].pos.x] != SNAKE_CHAR){
					game->obstacle_hit_wall[i]++;
			}
			if (game->board[game->obstacles[i].pos.y-1][game->obstacles[i].pos.x] != ' '
			&& game->board[game->obstacles[i].pos.y-1][game->obstacles[i].pos.x] != game->obstacles->obstacle_type
			&& game->board[game->obstacles[i].pos.y-1][game->obstacles[i].pos.x] != SNAKE_CHAR){
					game->obstacle_hit_wall[i]++;
			}
		}
	}
}

void game_obstacle_move( game_t* game, int index){

	// Variables
	position_t new_pos;
    position_t old_pos;
    position_t offset;
    position_t random_offset;
    position_t track_offset;
	int i=0;



	if (game->obstacles[index].obstacle_type =='E'){


		if (game->level<=2){
			random_offset= randomdirection();
		}

		else if( game->level>2){ ;
			track_offset=game->track_direction_obstacles[index];
		}

	
		if (game->obstacle_hit_wall[i] % 2 == 0) {

				// cas random
			if (game->level<=2){
            	offset.x= random_offset.x;
				offset.y= random_offset.y;
			}
			else if( game->level>2){
				offset.x= track_offset.x;
				offset.y= track_offset.y;
           }
		}
		else{
				// cas random
            if (game->level<=2){
				offset.x= -random_offset.x;
				offset.y= -random_offset.y;
            }
			else if(game->level>2){
					// cas IA pas besoin de rebondir
				offset.x= track_offset.x;
				offset.y= track_offset.y;
            }
		}


		old_pos.x = game->obstacles[index].pos.x;
        old_pos.y = game->obstacles[index].pos.y;
		new_pos.x=old_pos.x+offset.x;
        new_pos.y=old_pos.y+offset.y;


		if (game->border==1){
			if (game->board[new_pos.y][new_pos.x] != ' '
			&& game->board[new_pos.y][new_pos.x] != SNAKE_CHAR){
						new_pos.x=old_pos.x-offset.x;
						new_pos.y=old_pos.y-offset.y;
					}
		}

		else if(game->border==0){


			if (new_pos.x != game->dimension.x-1
				&& new_pos.x != 0 && new_pos.y != game->dimension.y-1
				&& new_pos.y != 0 ){

					if (game->board[new_pos.y][new_pos.x] != ' '
					&& game->board[new_pos.y][new_pos.x] != SNAKE_CHAR){
								new_pos.x=old_pos.x-offset.x;
								new_pos.y=old_pos.y-offset.y;
							}
			}
			else{
			
				if(new_pos.x>=game->dimension.x-1){ new_pos.x = 1;}
				else if(new_pos.x<1){ new_pos.x = game->dimension.x-2;}
				else if(new_pos.y>=game->dimension.y-1){ new_pos.y = 1;}
				else if(new_pos.y<1){ new_pos.y = game->dimension.y-2;}
			}
		}
		game->obstacles[index].pos=new_pos;
		game->board[old_pos.y][old_pos.x] = VOID_CHAR;
		game->board[new_pos.y][new_pos.x] = game->obstacles[index].obstacle_type;

			// cas random
		if (game->level<=2){
			game->direction_obstacles[index]=offset;
		}
		else if(game->level>2){
			game->track_direction_obstacles[index]=offset;
		}
	}
}

void game_obstacle_move_diverty( game_t* game , int ctr){

	// variables
	int i=0;

	for (i=0; i<game->obstacles_count; i++){

		if (i%2==1){
			
			if (ctr%3==1){
				game_obstacle_move(game,i);
			}
		}
		else{
			game_obstacle_move(game,i);
		}
	}
}

int minimun_distance_obstacle(int d1, int d2, int d3, int d4){

	// Variables
	int tab[4]={d1, d2, d3, d4};
	int min= tab[0];
	int i=0;

	// compare the minimum distance
	for(i=0; i<3; i++){
		if (tab[i+1]<tab[i]){
			min=tab[i+1];
		}
	}
	return min;
}

void obstacle_tracking(game_t* game){

	// Variables
	int obs_x_right=0, obs_x_left=0, obs_x=0, obs_y_over=0, obs_y_under=0, obs_y=0;
	int dist_right=0, dist_left=0, dist_over=0, dist_under=0;
	position_t opt_dir;
	int snake_pos_x;
	int snake_pos_y;
	int i=0;

	for (i=0; i<game->obstacles_count; i++){
		if(game->obstacles->obstacle_type=='E'){

			snake_pos_x = game->snake_position[0].x;
			snake_pos_y = game->snake_position[0].y;

			// memorise left and right pos
			obs_x= game-> obstacles[i].pos.x;
			obs_x_right= obs_x+1;
			obs_x_left= obs_x-1;

			obs_y= game-> obstacles[i].pos.y;
			obs_y_under= obs_y+1;
			obs_y_over= obs_y-1;

			dist_right=sqrt(pow((obs_x_right-snake_pos_x),2)+ pow((obs_y-snake_pos_y),2));
			dist_left=sqrt(pow((obs_x_left-snake_pos_x),2)+ pow((obs_y-snake_pos_y),2));
			dist_over=sqrt(pow((obs_x-snake_pos_x),2)+pow((obs_y_over-snake_pos_y),2));
			dist_under=sqrt(pow((obs_x-snake_pos_x),2)+pow((obs_y_under-snake_pos_y),2));

			if (minimun_distance_obstacle(dist_right,dist_left,dist_over,dist_under)==dist_right) {
				// alors la direction optimale est vers la droite donc déplacement (x=1, y=0)
				opt_dir=position_create(1,0);

			}
			else if (minimun_distance_obstacle(dist_right,dist_left,dist_over,dist_under)==dist_left) {
				// alors la direction optimale est vers la gauche donc déplacement (x=-1, y=0)
				opt_dir=position_create(-1,0);

			}
			else if (minimun_distance_obstacle(dist_right,dist_left,dist_over,dist_under)==dist_over) {
				// alors la direction optimale est vers le haut donc déplacement (x=0, y=-1)
				opt_dir=position_create(0,-1);

			}
			else if (minimun_distance_obstacle(dist_right,dist_left,dist_over,dist_under)==dist_under) {
				// alors la direction optimale est vers le bas donc déplacement (x=0, y=1)
				opt_dir=position_create(0,1);

			}
			game->track_direction_obstacles[i] = opt_dir;
		}
	}
}

void print_apples(game_t* game, int nb_apple){

	// variables
	int rX=0, rY=0, i=0;

	// fruit ina random place
	for (i=0;i<nb_apple;i++){
		do{
			rX = randomX(game->dimension.x);
			rY = randomY(game->dimension.y);
		}while(game->board[rY][rX] != ' ' || rX==game->dimension.x-1 || rX==0 || rY==game->dimension.y-1 || rY==0);
	game_add_obstacle(game, obstacle_create('P',rX,rY));
	}
}

void print_ennemies(game_t* game, int nb_ghost){
	int rX=0, rY=0, i=0;

	// ghost in a random place
	for (i=0;i<nb_ghost;i++)
	{
	   do{
		   rX = randomX(game->dimension.x);
		   rY = randomY(game->dimension.y);
   }while(game->board[rY][rX] != ' ' || rX==game->dimension.x-1 || rX==0 || rY==game->dimension.y-1 || rY==0);
	  game_add_obstacle(game, obstacle_create('E',rX,rY));
	}
}
