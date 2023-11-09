
#include "menu.h"

// Display array for the entry menu
char menu[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|****************************************************************|",
"\t|  &&&&&&      &       &&&&&&       &     &      &      &     &  |",
"\t|  &    &     & &      &            & & & &     & &     & &   &  |",
"\t|  &&&&&&    &   &     &            &  &  &    &   &    &  &  &  |",
"\t|  &        & & & &    &            &     &   & & & &   &   & &  |",
"\t|  &       &       &   &&&&&&       &     &  &       &  &     &  |",
"\t|****************************************************************|",
"\t|                                                                |",
"\t|            _____  uuuuuuuuuu                                   |",
"\t|     ___________ uuuuuuu  uuuuu                                 |",
"\t|   ____________ uuuuuuuu  uuuuuu                                |",
"\t|   ___________ uuuuuuuuuuuu                                     |",
"\t|     ________  uuuuuuuuuu   .      .  ~Press any key~    .     .|",
"\t|      ________ uuuuuuuuuuuu                                     |",
"\t|        ________uuuuuuuuuuuuuuuu                                |",
"\t|             ____ uuuuuuuuuuuuu                                 |",
"\t|               ____ uuuuuuuuu                                   |",
"\t|________________________________________________________________|",
"                                                                    ",
"                                                                    ",


};

// Display array for the options menu
char menu1[MAX][LARG] ={
"\t ________________________________________________________________",
"\t| up => 8                                           right => 6   |",
"\t| down  => 2                                         left => 4   |",
"\t|                                                                |",
"\t|                _                                               |",
"\t|               |_|   Start a new game                           |",
"\t|                _                                               |",
"\t|               |_|   Resume the game                            |",
"\t|                _                                               |",
"\t|               |_|   Choose difficulty                          |",
"\t|                _                                               |",
"\t|               |_|   Game Rules                _______________  |",
"\t|                _                             (_____________(o) |",
"\t|      /|       |_|   Quit                     /           /     |",
"\t|      |/                                     /           /      |",
"\t|      |/                                    /    MENU   /       |",
"\t|      |/                                   /           /        |",
"\t|     _|_                                  /___________/         |",
"\t|    (___)                                (__________(o)         |",
"\t|________________________________________________________________|"
};

// Display array for the difficulty choices
char menudiff[MAX][LARG] ={
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|                                                                |",
"\t|           1. Starting speed                                    |",
"\t|                _                                               |",
"\t|               |_|  Slow Pacman                                 |",
"\t|                _                                               |",
"\t|               |_|  Medium Pacman (defaut)                      |",
"\t|                _                                               |",
"\t|               |_|  Fast Pacman                                 |",
"\t|                                                                |",
"\t|            2.Borders                          _______________  |",
"\t|                _                             (_____________(o) |",
"\t|      /|       |_|  OFF (defaut)              /           /     |",
"\t|      |/        _                            /           /      |",
"\t|      |/       |_|  ON                      /  OPTION   /       |",
"\t|      |/                                   /           /        |",
"\t|     _|_                                  /___________/         |",
"\t|    (___)                                (__________(o)         |",
"\t|________________________________________________________________|"
};

// Display array for the rules
char menuregle[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|                ~Welcome to the PACMAN game~                    |",
"\t|                                                                |",
"\t|   By controlling Pacman, symbolized by an X, you will need to  |",
"\t|   eat lots of diamonds But be careful, as you progress,the     |",
"\t|   difficulty will increase, and ghosts will be there to block  |",
"\t|   your path.Fortunately, you will have 5 lives to escape them  |",
"\t|   For the best among you who have the courage to reach the end |",
"\t|   you will challenge yourself in a maze transformed into       |",
"\t|   a snake.                                                     |",
"\t|   Enjoy the game, and watch out for your tail!_______________  |",
"\t|                                              (_____________(o) |",
"\t|      /|                                      /           /     |",
"\t|      |/                                     /           /      |",
"\t|      |/                                    /    RULES  /       |",
"\t|      |/                                   /           /        |",
"\t|     _|_           ~Press any key~        /___________/         |",
"\t|    (___)                                (__________(o)         |",
"\t|________________________________________________________________|"
};

// Display array in case of defeat
char gameover[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|      &&&&&&&        &        &      &     & & & &              |",
"\t|      &             & &       & &  & &     &                    |",
"\t|      &  &&&&      &   &      &  &&  &     & & & &              |",
"\t|      &     &     & & & &     &      &     &                    |",
"\t|      &&&&&&&    &       &    &      &     & & & &              |",
"\t|                                                                |",
"\t|                    & & & & &  &        &  & & & &    & & &     |",
"\t|                    &       &   &      &   &          &   &     |",
"\t|                    &       &    &    &    & & & &    & & &     |",
"\t|                    &       &     &  &     &          &  &      |",
"\t|        ____        & & & & &      &&      & & & &    &   &     |",
"\t|      ,'    `,                                                  |",
"\t|     /        \\                                                |",
"\t|     \\ ()  () /                                                |",
"\t|      `. /\\ ,'                                                 |",
"\t|   8====| "" |====8                                             |",
"\t|        `LLLU'                 ~Press any key~                  |",
"\t|________________________________________________________________|"
};

char tableau1[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|            _____  uuuuuuuuuu                                   |",
"\t|     ___________ uuuuuuu  uuuuu                                 |",
"\t|   ____________ uuuuuuuu  uuuuuu                                |",
"\t|   ___________ uuuuuuuuuuuu                                     |",
"\t|     ________  uuuuuuuuuu   .   .   . ~ TABLE 1 ~  .   .   .    |",
"\t|      ________ uuuuuuuuuuuu                                     |",
"\t|        ________uuuuuuuuuuuuuuuu                                |",
"\t|             ____ uuuuuuuuuuuuu                                 |",
"\t|               ____ uuuuuuuuu                                   |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                     ~Press any key~                            |",
"\t|                                                                |",
"\t| The 'q' key is used to quit, and the 'p' key is used to pause. |",
"\t|________________________________________________________________|",
};

char tableau2[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                uuuuuuuuu                                       |",
"\t|              uuuuuuuuuuuuu                                     |",
"\t|             uu   uuuuu   uu                                    |",
"\t|            uuu   uuuuu   uuu                                   |",
"\t|            uuu O uuuuu O uuu  .  .  .  ~ TABLE 2 ~  .   .  .   |",
"\t|            uuuuuuuuuuuuuuuuu                                   |",
"\t|            uu uuuuu uuuuu uu                                   |",
"\t|            u   uuu   uuu   u                                   |",
"\t|            u   uuu   uuu   u                                   |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                     ~Press any key~                            |",
"\t|                                                                |",
"\t|________________________________________________________________|",
};


char tableau3[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                uuuuuuuuu                                       |",
"\t|              uuuuuuuuuuuuu                                     |",
"\t|             uu   uuuuu   uu                                    |",
"\t|            uuuO  uuuuuO  uuu                                   |",
"\t|            uuu   uuuuu   uuu  .  .  .  ~ TABLE 3 ~  .   .  .   |",
"\t|            uuuuuuuuuuuuuuuuu                                   |",
"\t|            uu uuuuu uuuuu uu                                   |",
"\t|            u   uuu   uuu   u                                   |",
"\t|            u   uuu   uuu   u                                   |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                     ~Press any key~                            |",
"\t|                                                                |",
"\t|________________________________________________________________|",
};

char tableau4[MAX][LARG] = {
"\t ________________________________________________________________",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                uuuuuuuuu                                       |",
"\t|              uuuuuuuuuuuuu                                     |",
"\t|             uu O uuuuu O uu                                    |",
"\t|            uuu   uuuuu   uuu                                   |",
"\t|            uuu   uuuuu   uuu  .  .  .  ~ TABLE 4 ~  .   .  .   |",
"\t|            uuuuuuuuuuuuuuuuu                                   |",
"\t|            uu uuuuu uuuuu uu                                   |",
"\t|            u   uuu   uuu   u                                   |",
"\t|            u   uuu   uuu   u                                   |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                                                                |",
"\t|                      ~Press any key~                           |",
"\t|                                                                |",
"\t|________________________________________________________________|",
};


void affichetableau1(){

    int i,j;
    for(i=0;i<MAX;i++) 
    {
        for(j=0;j<LARG;j++) 
        {
              if (i >= 2 && i<=14 && j >=2 && j<=33 ) 
            {
                Color(14,0); 
                printf("%c",tableau1[i][j]); 
                Color(12,0); 
            }

            else if (i>= 17 && i<=18 && j >=2 && j<=65)
            {
                Color(5,0); 
                printf("%c",tableau1[i][j]); 
                Color(12,0); 
            }
            else { // pour le reste
                printf("%c",tableau1[i][j]); 
            }

        }
        printf("\n"); 
    }
}

void affichetableau2(){

    int i,j;
    for(i=0;i<MAX;i++) 
    {
        for(j=0;j<LARG;j++) 
        {
              if (i >= 2 && i<=14 && j >=2 && j<=32 )
            {
                Color(5,0); 
                printf("%c",tableau2[i][j]); 
                Color(12,0); 
            }
            else { 
                printf("%c",tableau2[i][j]); 
            }

        }
        printf("\n"); 
    }
}
void affichetableau3(){

    int i,j;
    for(i=0;i<MAX;i++) 
    {
        for(j=0;j<LARG;j++) 
        {
              if (i >= 2 && i<=14 && j >=2 && j<=32 ) 
            {
                Color(6,0);
                printf("%c",tableau3[i][j]); 
                Color(12,0);
            }
            else { 
                printf("%c",tableau3[i][j]); 
            }

        }
        printf("\n"); 
    }
}

void affichetableau4(){

    int i,j;
    for(i=0;i<MAX;i++) 
    {
        for(j=0;j<LARG;j++) 
        {
              if (i >= 2 && i<=14 && j >=2 && j<=32 ) 
            {
                Color(11,0); 
                printf("%c",tableau4[i][j]); 
                Color(12,0); 
            }
            else { 
                printf("%c",tableau4[i][j]); 
            }

        }
        printf("\n"); 
    }
}



void affichegameover(){

    int i,j;
    for(i=0;i<MAX;i++) 
    {
        for(j=0;j<LARG;j++)
        {
              if (i >= 3 && i<=5 && j >=2 && j<=65 ) 
            {
                Color(14,0); 
                printf("%c",gameover[i][j]);
                Color(12,0); 
            }

            else if (i >= 9 && i<=11 && j >=2 && j<=65 ) 
            {

                Color(14,0);
                printf("%c",gameover[i][j]); 
                Color(12,0); 
            }

            else if (i >= 10 && i<=18 && j >=2 && j<=19 ) 
            {

                Color(14,0); 
                printf("%c",gameover[i][j]); 
                Color(12,0); 
            }
            else 
            {
                printf("%c",gameover[i][j]);
            }

        }
        printf("\n"); 
    }
}

void Color(int colorTexte,int colorFond){
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,colorFond*16+colorTexte); 
}

void Locate(int x,int y){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD C; 
    C.X=(SHORT)x;
    C.Y=(SHORT)y;
    SetConsoleCursorPosition(H,C); 
}
void affiche(){

    int i,j;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<LARG;j++) 
        {
              if (i >= 2 && i<=18 && j >=2 && j<=65 ) 
            {
                Color(14,0); 
                printf("%c",menu[i][j]); 
                Color(12,0); 
            }
            else { 
                printf("%c",menu[i][j]); 
            }

        }
        printf("\n"); 
    }
}


void afficheregle(){

    int i,j;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<LARG;j++) 
        {
             if (i >= 13 && i<=18 && j >=2 && j<=11 ) 
            {
                Color(14,0); 
                printf("%c",menuregle[i][j]);
                Color(12,0);  
            }
            else if (i >= 11 && i<=18 && j >=43 && j<=64 )
            {

                Color(14,0); 
                printf("%c",menuregle[i][j]); 
                Color(12,0);  
            }

            else { 
                printf("%c",menuregle[i][j]); 
            }
        }
        printf("\n");
    }
}

void Afficher(int x,int y){

    int i,j;
    Locate(0,0);
    for(i=0;i<MAX;i++) 
    {
        for(j=0;j<LARG;j++) 
        {
            if (i==x && j==y) 
            {
                Color(14,0); 
                printf("X"); 
                Color(12,0);
            }
            else if (i >= 13 && i<=18 && j >=2 && j<=11 )
            {
                Color(14,0);
                printf("%c",menu1[i][j]); 
                Color(12,0);
            }
            else if (i >= 11 && i<=18 && j >=40 && j<=64 )
            {

                Color(14,0);
                printf("%c",menu1[i][j]); 
                Color(12,0);
            }
            else 
                printf("%c",menu1[i][j]); 


        }
        printf("\n"); // retour a la ligne
    }
}

void affichediff(int x,int y){

    int i,j;
    Locate(0,0); 
    for(i=0;i<MAX;i++) 
    {
        for(j=0;j<LARG;j++)
        {
            if (i==x && j==y) 
            {
                Color(14,0);
                printf("X"); 
                Color(12,0);
            }
            else if (i >= 13 && i<=18 && j >=2 && j<=11 )
            {
                Color(14,0);
                printf("%c",menudiff[i][j]); 
                Color(12,0);
            }
            else if (i >= 11 && i<=18 && j >=40 && j<=64 )
            {

                Color(14,0);
                printf("%c",menudiff[i][j]); 
                Color(12,0);
            }
            else 
                printf("%c",menudiff[i][j]);
        }
        printf("\n"); 
    }
}

void TryMove(int* x,int* y,int vx,int vy){

    if (menu1[*x+vx][*y+vy]=='|') 
        return; 

    (*x)+=vx;
    (*y)+=vy;
}

void TryMovediff(int* x,int* y,int vx,int vy){

    if (menudiff[*x+vx][*y+vy]=='|') 
        return; 

    (*x)+=vx;
    (*y)+=vy;
}

void mouvement(char touche,int* x, int* y){
            switch(touche) 
         {
            case '8': 
            TryMove(x,y,-2,0); 
            break; 

            case '2': 
            TryMove(x,y,2,0); 
            break; 
        }
}

void mouvementdiff(char touche,int* x, int* y){
            switch(touche) 
         {

            case '8':
            TryMovediff(x,y,-2,0); 
            break; 
            case '2': 
            TryMovediff(x,y,2,0);
            break; 

#define MAX 23 
#define LARG 69 
        }
}

void menu_fct(game_t* game){

    int vitesse=100; 
    int bord=0; 
    int height = 20,width = 50;
    int nb_ghost=4;

    Color(12,0);
    affiche(); 
    int x = 5; 
    int y = 18; 
    char touche = 0;
    touche = getch(); 
    if (touche){ 

        system("cls");                  
        while(touche!=27){               
           Afficher(x,y);               
           if(kbhit){               
               touche = getch();                
            }
            mouvement(touche,&x,&y);                
            if (x==15){x=5;}                 
            if (x==3){x=13;}                
            if(x == 13 && touche =='\r' ){              
                return EXIT_SUCCESS;                 
            }



            if (x== 5  &&  touche=='\r'){ 
                 game_t* game = game_create(height,width); 
                game->level=1;
                game->life=5; 
                game->border=bord;

                niveaux(game,vitesse);}




            if (x==  7 &&   touche=='\r'){
                game_t* game = game_create(height,width); 

                game->level=read_save(0);
                game->life=read_save(1);
                game->border=bord;
                if ((game->level==3) || (game->level==4)){print_ennemies(game,nb_ghost);}
                niveaux(game,vitesse);}


            if(x == 11 && touche =='\r' ){              

                system("cls");           
                afficheregle(x,y);          
                 while(touche!=121){             
                     if (touche){                

                        touche = getch();                
                        touche = 121;                    
                     }
                 }
            }

            if(x == 9 && touche =='\r' ){                       
                x=5 ;                                   
                y=18;                             

                while(touche!=126){                                             //as long as del isn't pressed
                    affichediff(x,y);                                       
                    touche = getch();                                                     
                    mouvementdiff(touche,&x,&y);                                                
                    if (x==11){x=5;}                                               
                    if (x==3){x=9;}                                            
                    int choix =0; 

                    if(x == 5 && touche == '\r' ){ 
                        choix = 1; 
                        vitesse=200;} 

                    if(x == 7 && touche == '\r' ) { 
                        choix = 1;
                        vitesse=100;} 

                    if(x == 9 && touche == '\r' ) { 
                        choix = 1; 
                        vitesse=50;} 

                    if(choix == 1 ){ 

                        x=13; 

                        while(touche!=126){ //as long as del in not pressed

                            affichediff(x,y); 
                            touche = getch(); 
                            mouvementdiff(touche,&x,&y); 

                            if (x==17){x=13;} 
                            if (x==11){x=15;} 

                            if(x==13 && touche == '\r') {//border off if enter is pressed
                                bord=0;
                                touche = 126; 
                                x=5;
                            }

                            if(x==15 && touche == '\r') { //border on if enter is pressed
                                bord=1; 
                                touche = 126; 
                                x=5; 
                            }
                        }
                    }
                }
            }
        }
    }
}
