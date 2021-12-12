
#include "console_header.h"

extern struct map game;
extern struct direction direction;
extern struct player player1;
extern struct AI_player AI ;
extern struct time game_time;

struct position get_random_number(void);

struct position random_position(char symbol,int number){

    struct position random;
    while( number-- > 0 ){

        random=get_random_number();
        game.screen[random.y][random.x]=symbol;
    }

return random;

}

struct position get_random_number(void){

    struct position random;

    srand(time(0));

    while(1){

        random.y=(rand()%(game.row));
        random.x=(rand()%(game.column));

        if( game.screen[random.y][random.x] == ' ')
            return random;

        else
            continue;
    }

}



