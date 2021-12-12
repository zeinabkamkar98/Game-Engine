#include "console_header.h"


extern struct map game ;
extern struct player player1;
extern struct AI_player AI ;
extern struct position position ;
extern struct direction direction ;
extern int exit_game;

extern int sound;


void attack ( int dx,int dy ) {

    int i ;

    int my_x = player1.position.x;
    int my_y = player1.position.y ;
    int n=abs(dx)+abs(dy);

    int x,y;

    if(dx)
        x=dx/abs(dx);
    else
        x=0;

    if(dy)
        y=dy/abs(dy);
    else
        y=0;


    for ( i = 1 ; i <= n ; i++ ) {

        if ( game.screen [ my_y + (i*y) ] [ my_x + (i*x)] == game.deathblock || game.screen [ my_y + (i*y) ] [ my_x + (i*x)] == AI.symbol )
             game.screen [ my_y + (i*y) ] [ my_x + (i*x)] = ' ' ;

    }

}


void handle_keyboard ( void ) {

    int c ;

    while(1) {

        if ( kbhit() ){

                c=getch();

                if ( c == 0xE0 ){

                    if(sound)
                    Beep(200,100);

                    int ch = getch() ;

                    switch ( ch ) {
                        case 72 :
                            attack(0,-game.attack) ;
                            break ;
                        case 80 :
                            attack(0,game.attack) ;

                            break ;
                        case 75 :
                            attack(-game.attack,0) ;

                            break ;
                        case 77 :
                            attack(game.attack,0) ;

                            break ;
                    }
                }
                else{
                        if(c==direction.down || c==direction.up || c==direction.right || c==direction.left )
                            player1.direction=c;

                        else if(c==game.exit_char)
                            exit_game=2;

                        else if(c==game.put_deathblock.key_symbol && game.put_deathblock.number!=0){

                            struct position d=player1.position;
                            move();
                            game.screen [ d.y ] [d.x ]=game.deathblock;

                        }


                }
        }
        else
            break;
    }


}





