#include "levels.h"


//pausing every millisecond
void delay(int number_of_miliseconds){
	clock_t start_time = clock();
	while (clock() < start_time + number_of_miliseconds);
}

// registering the life and level at every checkpoint. it is saved in save.txt
void save(game_t* game){

	
    FILE *file;

	
    file = fopen("save.txt", "w");

    if ( file == NULL)
    {
        printf("Error\n");

    }
    else 
    {
		fprintf(file, "%d\n", game->level);
		fprintf(file, "%d", game->life);

    fclose(file);
    }
}

int read_save(int index){

	//Variables
	FILE *file;
	int level[2];


    file = fopen("save.txt", "r");

    if ( file == NULL)
    {
        printf("Error\n");

    }
    else 
    {
		fscanf(file,"%d",&level[0]);
		fscanf(file,"\n%d",&level[1]);
    	fclose(file);
	}
	if (index==0){
		return level[0];
	}
	else if (index==1){
		return level[1];
	}
}

void clear_board(game_t* game){

		for (int j=0; j<game->dimension.y;j++)
        {
            for (int k=0; k<game->dimension.x;k++)
            {
                game->board[j][k]=' ';
            }
        }

}

void niveaux(game_t* game, int vitesse)
{

	int height = 20,width = 50;
	int nb_apple = 5;
	int nb_gost = 4;
	int rX = 0, rY = 0;
	int i = 0;
	int ctr=0;
	int ctr_for_snake = 1;
	int score=0, duree=0;
	int orignal_speed=vitesse;
	int dub=0;



	obstacle_t hit;
	int index_obs_hit;
	int counter_obstacle_hit_border=0;
	char touch=0;
	int can_keep_moving;


    clear_board(game);

	system("cls");
	printf("border %d",game->border);
	if (game->border==1){game_map(game);}


    while(game->level<5){


	if(game->level==1){
        system("cls");
        affichetableau1();
        getch();
        system("cls");
        vitesse=orignal_speed;
		print_apples(game, nb_apple);
	}



	do{

		save(game);    
        duree++;
		can_keep_moving=1;

        if (kbhit()){                       
			touch = getch();

            if(touch=='2'){
				can_keep_moving=0;
            	game_down(game);
            } else if(touch=='8'){
				can_keep_moving=0;
            	game_up(game);
            } else if(touch=='6'){
				can_keep_moving=0;
            	game_right(game);
            } else if(touch=='4'){
				can_keep_moving=0;
            	game_left(game);
            } else if(touch=='p'){
                getch();
            }else if(touch=='q'){
				free(game);
                system("cls");
                return;

            }
		}

		if (can_keep_moving==1){
			game_keep_moving(game);
		}


		check_obstacle_hit_wall(game);      //check borders

		game_display(game);            


		//check head contact
        if(game_has_hit(game,&hit,&index_obs_hit)){
			if(hit.obstacle_type=='E'){                 

				game->life--;
			}
			if(hit.obstacle_type=='P'){                
				remove_obstable(game, index_obs_hit);
                score+=10;
            }
		}
        if (game->life==0){   //game over
			save(game);
            system("cls");
            affichegameover();
            getch();
            return;}

		if (score>=(nb_apple*10)){game->level=2;}   //next level


		gotoXY(10,3);
		printf(" _____________");
		gotoXY(10,4);
		printf("|");
		Color(15,0);
		printf("  Niveau : %d ", game->level);
		Color(12,0);
		printf("|");
		gotoXY(10,25);
		printf(" _________\t\t\t _______");
		gotoXY(10,26);
		printf("|");
		Color(15,0);
        printf("Score: %d ",score);
        Color(12,0);
        printf("|");
        printf("\t\t\t");
        printf("|");
        Color(15,0);
        printf("vies=%d ",game->life);
        Color(12,0);
        printf("|");

        delay(vitesse);
		ctr++;

	}while ((game->level==1));






	if (game->level == 2){
        system("cls");
        affichetableau2(); 
        getch();
        system("cls");
        vitesse=orignal_speed;
		score=50;
        print_ennemies(game, nb_gost); 
        print_apples(game, nb_apple); 
        //repositionnement du X
        game->board[game->snake_position[0].y][game->snake_position[0].x]=' ';
        do{
    	game->snake_position[0] = position_create(randomX(width),randomY(height));
        }while (game->snake_position[0].x!=' ');
	}


    do {

		save(game); 
        duree++;
		can_keep_moving=1; 

        if (kbhit()){
			touch = getch(); 

            if(touch=='2'){
				can_keep_moving=0; 
            	game_down(game);	
            } else if(touch=='8'){
				can_keep_moving=0;
            	game_up(game);		
            } else if(touch=='6'){
				can_keep_moving=0;
            	game_right(game);	
            } else if(touch=='4'){
				can_keep_moving=0;
            	game_left(game);	
            } else if(touch=='p'){
                getch();			
            }else if(touch=='q'){
				free(game);			//quitter
                system("cls");
                return;
            }
		}

		if (can_keep_moving==1){
			game_keep_moving(game);
		}


		check_obstacle_hit_wall(game);
		obstacle_tracking(game);

		for(int i=0; i<game->obstacles_count; i++){
			game_obstacle_move(game,i);
		}

		game_display(game);


		//check head contact
        if(game_has_hit(game,&hit,&index_obs_hit)){
			if(hit.obstacle_type=='E'){ 
				game->life--;
			}
			if(hit.obstacle_type=='P'){ 
				remove_obstable(game, index_obs_hit);
                score+=10; // ajoute 10 de score

            }
		}
		 if (game->life==0){ 
            system("cls");
            affichegameover();// afficher l ecran de game over
            getch();
            return;}

		if (score>=(20*nb_apple)){game->level=3;}


		gotoXY(10,3); 
		printf(" ___________");
		gotoXY(10,4);
		printf("|");
		Color(15,0);
		printf("  Niveau : %d ", game->level);
		Color(12,0);
		printf("|");
		gotoXY(10,25);
		printf(" ________\t\t\t ______");
		gotoXY(10,26);
		printf("|");
		Color(15,0);
        printf("Score: %d ",score);
        Color(12,0);
        printf("|");
        printf("\t\t\t");
        printf("|");
        Color(15,0);
        printf("vies=%d ",game->life);
        Color(12,0);
        printf("|");

        delay(vitesse);	
		ctr++;
	}while (game->level==2); 

	if (game->level==3){
        system("cls");
        affichetableau3();
        getch();
        system("cls");

        game_maze(game);                    
		score=100;

        print_apples(game, nb_apple);
        game->board[game->snake_position[0].y][game->snake_position[0].x]=' ';
        do{
    	game->snake_position[0] = position_create(randomX(width),randomY(height));
        }while (game->snake_position[0].x!=' ');

	}


	do{

		save(game);

        duree++;
		can_keep_moving=1;

        if (kbhit()){
			touch = getch();

            if(touch=='2'){
				can_keep_moving=0;
            	game_down(game);
            } else if(touch=='8'){
				can_keep_moving=0;
            	game_up(game);
            } else if(touch=='6'){
				can_keep_moving=0;
            	game_right(game);
            } else if(touch=='4'){
				can_keep_moving=0;
            	game_left(game);
            } else if(touch=='p'){
                getch();
            }else if(touch=='q'){
				free(game);
                system("cls");
                return;
            }
		}

		if (can_keep_moving==1){
			game_keep_moving(game);
		}


		check_obstacle_hit_wall(game);
		obstacle_tracking(game);


		
		if (ctr % ctr_for_snake == 0){
			game_obstacle_move_diverty(game, ctr);
		}
		//speed of pacman increases every time he eats a fruit
		if (ctr % ctr_for_snake == 1){
			//ghost move faster as well
			game_obstacle_move_diverty(game, ctr);
		}

		game_display(game);



		//check head contact
        if(game_has_hit(game,&hit,&index_obs_hit)){
			if(hit.obstacle_type=='E'){
				game->life--;
			}
			if(hit.obstacle_type=='P'){
				remove_obstable(game, index_obs_hit);
                score+=10;
				ctr_for_snake+=1;
				vitesse-=20;
            }
		}
		 if (game->life==0){
            system("cls");
            affichegameover();
            getch();
            return;}

		if (score>=(30*nb_apple)){game->level=4;}


		gotoXY(10,3);
		printf(" _____________");
		gotoXY(10,4);
		printf("|");
		Color(15,0);
		printf("  Niveau : %d ", game->level);
		Color(12,0);
		printf("|");
		gotoXY(10,25);
		printf(" _________\t\t\t _______");
		gotoXY(10,26);
		printf("|");
		Color(15,0);
        printf("Score: %d ",score);
        Color(12,0);
        printf("|");
        printf("\t\t\t");
        printf("|");
        Color(15,0);
        printf("vies=%d ",game->life);
        Color(12,0);
        printf("|");


        delay(vitesse);
		ctr++;

	}while(game->level==3);



	if (game->level==4){
        system("cls");
        affichetableau4();
        getch();
        system("cls");
        game_maze(game);
		score=150;
		vitesse=orignal_speed;
		ctr_for_snake=1;

		print_apples(game, nb_apple);





		game->board[game->snake_position[0].y][game->snake_position[0].x]=' ';
        do{
    	game->snake_position[0] = position_create(randomX(width),randomY(height));
        }while (game->snake_position[0].x!=' ');

	 }

    int temps=duree;

	do{
		save(game);
        duree++;


		if (duree%15==0){
			for (i=0;i<3;i++){    
		        do{
				rX = randomX(width);
				rY = randomY(height);
			}while(game->board[rY][rX] != ' ' || rX==game->dimension.x-1 || rX==0 || rY==game->dimension.y-1 || rY==0);
				game_add_obstacle(game, obstacle_create('*',rX,rY));
		        }
		}

        if (duree%25==1){         
            for (int i=0; i<game->obstacles_count; i++){
                if(game->obstacles[i].obstacle_type=='*'){
                    game->board[game->obstacles[i].pos.y][game->obstacles[i].pos.x]=' ';
					remove_obstable(game,i);
                }
            }
        }






		can_keep_moving=1;

        if (kbhit()){
			touch = getch();

            if(touch=='2'){
				can_keep_moving=0;
            	game_down(game);
            } else if(touch=='8'){
				can_keep_moving=0;
            	game_up(game);
            } else if(touch=='6'){
				can_keep_moving=0;
            	game_right(game);
            } else if(touch=='4'){
				can_keep_moving=0;
            	game_left(game);
            } else if(touch=='p'){
                getch();
            }else if(touch=='q'){
				free(game);
                system("cls");
                return;
            }
		}

		if (can_keep_moving==1){
			game_keep_moving(game);
		}


		check_obstacle_hit_wall(game);
		obstacle_tracking(game);

		//speed is the same if no fruit is eaten
		if (ctr % ctr_for_snake == 0){
			
			game_obstacle_move_diverty(game, ctr);
		}
		
		if (ctr % ctr_for_snake == 1){
			game_obstacle_move_diverty(game, ctr);
		}

		game_display(game);



		//check head contact
        if(game_has_hit(game,&hit,&index_obs_hit)){
			if(hit.obstacle_type=='E'){
                game->life--;
                score=nb_apple*30;
			}
			if(hit.obstacle_type=='P'){
				remove_obstable(game, index_obs_hit);
                score+=10;
                dub+=1;  //compteur du nombre de pommes mangees

				game_snake_size_up(game);               // transformation en snake
				ctr_for_snake+=1;
				vitesse-=20;
            }
            if(hit.obstacle_type=='*'){
				for (i=0;i<5;i++){game_snake_size_up(game);}
				remove_obstable(game, index_obs_hit);
                score+=50;
            }
		}

		if (dub==5){ ;        
		game->level=1;
		printf("\tVICTORY");
		nb_apple*=2;
		score=0;
		game->snake_size=1;
		clear_board(game);
		getch();
		system("cls");}



		//check body contact
		if(game_snake_hit_no_head(game,&hit)!=0){    
			if(hit.obstacle_type=='E'){
				// cut the snake at the impact position
				game_snake_cut(game,game_snake_hit_no_head(game,&hit));
			}
		}



         if (game->life==0){
            system("cls");
            score=0;
            game->level=1;
            affichegameover();
            getch();
            return;}


		gotoXY(10,3);
		printf(" _____________");
		gotoXY(10,4);
		printf("|");
		Color(15,0);
		printf("  Niveau : %d ", game->level);
		Color(12,0);
		printf("|");
		gotoXY(10,25);
		printf(" _________\t\t\t _______");
		gotoXY(10,26);
		printf("|");
		Color(15,0);
        printf("Score: %d ",score);
        Color(12,0);
        printf("|");
        printf("\t\t\t");
        printf("|");
        Color(15,0);
        printf("vies=%d ",game->life);
        Color(12,0);
        printf("|");


        delay(vitesse);
		ctr++;



	}while(game->level==4);
}
	game_free(game);
}
