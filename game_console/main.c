

#include "console_header.h"

struct time game_time;
struct map game;
struct direction direction;
struct player player1;
struct AI_player AI ;
int exit_game;
int last_move;


int main(){

    while(1){

        menu();

        scanf("%s",game.name);

        getchar();

        get_game();

        game_time.start=clock();

        while(exit_game==0){

            handle_keyboard();

            if(time_delay()){

                move();

                print_screen();



            }

        }

         print_result();
         write_result();

         reset_all_variable();

    }

    return 0;

}

struct time r_game_time;
struct map r_game;
struct direction r_direction;
struct player r_player1;
struct AI_player r_AI;

void reset_all_variable(void){

        game_time=r_game_time;

        game=r_game;

        direction=r_direction;

        player1=r_player1;

        AI=r_AI;

        exit_game=0;
        last_move=0;

        fflush(stdin);
        fflush(stdout);

}



