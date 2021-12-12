

#include "console_header.h"

extern struct time game_time;
extern struct map game;
extern struct direction direction;
extern struct player player1;
extern struct AI_player AI ;
extern int exit_game;
extern int last_move;

extern int theme;
extern int sound;

void print_screen(void){

    register int i,j,k;

    system("cls");

    if(theme==0)
        for(i=0;i<game.row;i++){
            for(k=0;k<(230-game.column)/16;k++)
            printf("\t");
            printf("%s",game.screen[i]);
        }

    else{

    for(i=0;i<(game.row);i++){

           printf("\n");
            k=0;

        for(k=0;k<(230-game.column)/16;k++)
            printf("\t");

        for(j=0;j<(game.column);j++){

            if ( theme==1 ){ // light

                if ( game.screen [i][j] == game.solidblock )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),251);

                else if ( game.screen [i][j] == game.deathblock )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252);

                else if ( game.screen [i][j] == game.moveblock )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),248);

                else if ( game.screen [i][j] == game.rpoint )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253);

                else if ( game.screen [i][j] == game.wall )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),249);

                else if ( game.screen [i][j] == player1.symbol )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),250);

                else if ( game.screen [i][j] == game.target )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),242);

                else if ( game.screen [i][j] == game.object )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),242);

                else if ( game.screen [i][j] == AI.symbol )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),246);
            }

            else if ( theme==2 ){ // dark

                if ( game.screen [i][j] == game.solidblock )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);

                else if ( game.screen [i][j] == game.deathblock )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);

                else if ( game.screen [i][j] == game.moveblock )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);

                else if ( game.screen [i][j] == game.rpoint )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);

                else if ( game.screen [i][j] == game.wall )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

                else if ( game.screen [i][j] == player1.symbol )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);

                else if ( game.screen [i][j] == game.target )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);

                else if ( game.screen [i][j] == game.object )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);

                else if ( game.screen [i][j] == AI.symbol )
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
            }

            printf("%c",game.screen[i][j]);

        }

    }

    }

    printf("\n\n");

    for(k=0;k<(230-game.column)/16;k++)
        printf("\t");

    printf("time=%.1f",game_time.delay/10);

    if(game.score_point){

    printf("\n");

    for(k=0;k<(230-game.column)/16;k++)
        printf("\t");

    printf("%s score: %d\n",player1.name,player1.score);

    }
return 0;
}


void print_result(void){

        int i;

        while(!kbhit()){

        if ( exit_game == 1 ) {

            system("cls");
            for(i=0;i<25;i++)
                printf("\n");
            for(i=0;i<110;i++)
            printf(" ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
            printf("YOU WIN!") ;
            Sleep(100);

            system("cls");
            for(i=0;i<25;i++)
                printf("\n");
            for(i=0;i<110;i++)
                printf(" ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),243);

            printf("YOU WIN !");
            Sleep(100);

        }

        else if ( exit_game == -1 ) {

            system("cls");
            for(i=0;i<25;i++)
                printf("\n");
            for(i=0;i<110;i++)
                printf(" ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),79);
            printf("YOU LOST!") ;
            Sleep(100);

            system("cls");
            for(i=0;i<25;i++)
                printf("\n");
            for(i=0;i<110;i++)
                printf(" ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
            printf("YOU LOST!");
            Sleep(100);


        }
        else{

            system("cls");
            for(i=0;i<25;i++)
                printf("\n");
            for(i=0;i<110;i++)
                printf(" ");
            if(game.rpoint)
                printf("your score :%d",player1.score);
            else
            printf(" :(");
            Sleep(2000);
            break;
        }

    }

}

void write_result(void){

    FILE *result;
    FILE *new_result;


    char player_name[20];
    char game_name[20];

    int total_game=0;
    int Successful_game=0;

    char * check_result;

    result=fopen("‫result.txt‬‬","r");
    new_result=fopen("new.txt","w");


    while(fscanf(result,"%s %s %d %d",&player_name,&game_name,&total_game,&Successful_game)>0){

        if( (strcmp(player_name,player1.name)==0) && (strcmp(game.name,game_name)==0)){

        }
        else{
        fprintf(new_result,"%s %s %d %d",&player_name,&game_name,total_game,Successful_game);

        }
    }

    if(exit_game==1)
        Successful_game++;

    fprintf(new_result,"%s %s %d %d",&player1.name,&game.name,total_game+1,Successful_game);

    fclose(new_result);
    fclose(result);

   char oldname[] = "new.txt";
   char newname[] = "result.txt";

    remove("result.txt");
    rename(oldname, newname);

}


