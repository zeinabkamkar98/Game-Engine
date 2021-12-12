
#include "console_header.h"

extern struct map game;
extern struct time game_time;
extern int exit_game;
struct player player1;

int theme ;
int sound ;

void menu () {

    int to_do ;
    int option ;

    game_time.speed_factor=3;
    sound=1;

    system("COLOR 3f");

    system("cls") ;

    printf("\n\n\n\thi ... :) \n\n\twhat's your name:\n\t ") ;

    scanf("%s",player1.name);

    while(1){

    system("cls") ;

    printf("\n\n\n\t1.start\n\t2.setting\n\t3.Exit\n\t ") ;

    scanf("%d", & to_do) ;

    if ( to_do == 1 ) {

        system("cls") ;

        printf("\n\n\n\tdefualt game:\n\n\tmaze\n\tpullbox\n\tpacman\n\trallyx\n\tflight\n\tyour game name\n\n\tplease enter game name:");


        break;
    }

    else if ( to_do == 2 ) {

        system("cls") ;

        printf("\n\n\n\tchoose one of these\n") ;
        printf("\t1.theme\n\t2.speed\n\t3.sound\n\t") ;

        scanf("%d", &option) ;

        if ( option == 1 ) {

        system("cls") ;

        printf("\n\n\n\twhich theme you want ?\n") ;
        printf("\t0.default \n\t1.light \n\t2.dark\n\t") ;

        scanf("%d", &theme ) ;

        }

        else if ( option == 2 ) {

            system("cls") ;

            int a;
            printf("\n\n\n\twhich speed do you want ?(1-5)\n") ;
            printf("\t1.fast\n\t2.medium \n\t3.slow\n\t") ;

            scanf("%d", &a ) ;
            game_time.speed_factor=a*2;

        }

        else if ( option == 3 ) {
            system("cls") ;

            printf("\n\n\n\twould you like have sound in game??\n\t 0.No \n\t 1.yes\n\t") ;

            scanf("%d", &sound ) ;
        }

    }
        else if (to_do == 3 ){

        system("cls");
        int i;
        printf("\n\n\n\n\t\tbye...  :)\n\n\n\n\n\n\n\n\n");
        for(i=0;i<40;i++)
            printf("\n");

        exit(1);
        }
    }


}
