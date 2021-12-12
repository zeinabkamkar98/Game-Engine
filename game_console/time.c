
#include "console_header.h"


extern struct time game_time;
extern int exit_game;
extern struct map game;

int time_delay(void){

    game_time.stop=clock();

    game_time.delay=(10*(float)(game_time.stop - game_time.start) / CLOCKS_PER_SEC);

    if (game_time.gametime==0){

    }

    else if(game_time.delay>=game_time.gametime*10){
        if(game.score_point)
        exit_game=2;
        else
        exit_game=-1;
    }
     if(game_time.delay>=game_time.passed_time ){

        game_time.passed_time=game_time.passed_time+game_time.speed_factor;

        return 1;
    }


return 0;

}

