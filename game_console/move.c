
#include "console_header.h"

extern struct map game ;
extern struct player player1 ;
extern struct AI_player AI ;
extern struct position position ;
extern struct direction direction ;
extern int exit_game ;
extern int sound;

struct position move_raindb(struct position);

void move ( void ) {

    int i;

    for(i=game.raindb_num;i>0;i--)
        game.raindb[i]= move_raindb(game.raindb[i]);

    if ( player1.direction == direction.up )
        move_player(  0 , -1 ) ;

    else if ( player1.direction == direction.down )
        move_player( 0 , 1 ) ;

    else if ( player1.direction == direction.left )
        move_player( -1 , 0 ) ;

    else if ( player1.direction == direction.right )
        move_player( 1 , 0 ) ;

    int j,k=0;
    struct position opp[100];
    for(i=0;i<(game.row);i++){

        for(j=0;j<game.column;j++){

            if(game.screen[i][j]==AI.symbol){
                opp[k].x=j;
                opp[k].y=i;
                k++;
            }
        }
    }

    for(i=0;i<k;i++){
            AI_path(opp[i]);
    }

}



void move_player( int dx , int dy ) {


    int old_x = player1.position.x ;
    int old_y = player1.position.y ;

    char new_place = game.screen [ old_y + dy ] [ old_x + dx ] ;

    if ( new_place == game.deathblock ) {

        if(sound)
        Beep(800,800);
        exit_game=-1;

    }

    else if ( new_place == game.moveblock ) {


        if ( game.screen[old_y + dy +dy][old_x + dx +dx]==' ' ) {

        game.screen[old_y + dy +dy][old_x + dx +dx]==game.moveblock;
        game.screen [ old_y + dy ] [ old_x + dx ] = game.screen [ old_y ] [ old_x ] ;
        game.screen [ old_y ] [ old_x ] = ' ' ;
        player1.position.x = old_x + dx ;
        player1.position.y = old_y + dy ;

        }
        }

    else if ( new_place == ' ' ) {
        game.screen [ old_y + dy ] [ old_x + dx ] = game.screen [ old_y ] [ old_x ] ;
        game.screen [ old_y ] [ old_x ] = ' ' ;
        player1.position.x = old_x + dx ;
        player1.position.y = old_y + dy ;
    }

    else if ( new_place == game.rpoint ) {

        if(sound)
        printf("\a");

        game.screen [ old_y + dy ] [ old_x + dx ] = game.screen [ old_y ] [ old_x ] ;
        game.screen [ old_y ] [ old_x ] = ' ' ;
        player1.position.x = old_x + dx ;
        player1.position.y = old_y + dy ;

        player1.score += game.score_point ;
        random_position(game.rpoint,1);

    }

    else if ( new_place == game.target ) {

        if(sound)
        Beep(500,800);

        exit_game=1 ;
    }

    else if ( new_place == game.object ) {

        if ( game.screen[old_y + dy +dy][old_x + dx +dx]==' ' || game.screen[old_y + dy +dy][old_x + dx +dx]==game.target) {

        if(game.screen[old_y + dy +dy][old_x + dx +dx]==game.target){

            exit_game=1;
        }
        game.screen[old_y + dy +dy][old_x + dx +dx]=game.object;
        game.screen [ old_y + dy ] [ old_x + dx ] = game.screen [ old_y ] [ old_x ] ;
        game.screen [ old_y ] [ old_x ] = ' ' ;
        player1.position.x = old_x + dx ;
        player1.position.y = old_y + dy ;

    }

    }

}


struct position move_raindb(struct position d){

    d.y+=1;

    if(game.screen[d.y][d.x]==' '){
        game.screen[d.y-1][d.x]=' ';
        game.screen[d.y][d.x]=game.deathblock;

    }

    else if(game.screen[d.y][d.x]==player1.symbol){
        game.screen[d.y-1][d.x]=' ';
        game.screen[d.y][d.x]=game.deathblock;
        exit_game=-1;

        }

    else{
        game.screen[d.y-1][d.x]=' ';
        d.y=1;//check
        d.x=rand()%(game.column-2)+1;
    }

    return d;

}
struct position move_AI(int dx,int dy ,struct position AI_pop){

    int old_x =AI_pop.x ;
    int old_y = AI_pop.y ;

    char new_place = game.screen [ old_y + dy ] [ old_x + dx ] ;

    if ( new_place == ' ' ) {

        game.screen [ old_y + dy ] [ old_x + dx ] = game.screen [ old_y ] [ old_x ] ;
        game.screen [ old_y ] [ old_x ] = ' ' ;
        AI_pop.x = old_x + dx ;
        AI_pop.y = old_y + dy ;

    }

    else if ( new_place == AI.goal ) {

            exit_game=-1 ;

    }
    return AI_pop;
}
