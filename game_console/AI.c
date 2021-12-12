


#include "console_header.h"


extern struct map game;
extern struct player player1;
extern struct AI_player AI;
extern int last_move;

int find_goal(int ,int ,int ,int );
struct position move_AI(int dx,int dy ,struct position AI_pop);

void AI_path(struct position opp){

    struct position goal;
    float distance_up;
    float distance_goal;
    float distance_down;
    float distance_left;
    float distance_right;
    float dis[4];

    goal=find_symbol(AI.goal,opp);

    dis[0]=distance_up=sqrt(pow(goal.x-(opp.x),2)+pow(goal.y-(opp.y-1),2));
    dis[1]=distance_down=sqrt(pow(goal.x-(opp.x),2)+pow(goal.y-(opp.y+1),2));
    dis[2]=distance_left=sqrt(pow(goal.x-(opp.x-1),2)+pow(goal.y-(opp.y),2));
    dis[3]=distance_right=sqrt(pow(goal.x-(opp.x+1),2)+pow(goal.y-(opp.y),2));

    bubbleSort(dis,4);
    int i;
    for(i=0;i<4;i++){

        if(dis[i]==distance_up){

            if(is_free(0,-1,opp)  ){
                move_AI(0,-1,opp);
                last_move=1;
                return;
            }
        }

        else if(dis[i]==distance_down && last_move!=1){

            if(is_free(0,1,opp)){
                move_AI(0,1,opp);
                last_move=2;
                return;

            }
        }
        else if(dis[i]==distance_right && last_move!=4){

            if(is_free(1,0,opp)){
                move_AI(1,0,opp);
                last_move=3;
                return;


            }
        }
        else if(dis[i]==distance_left && last_move!=3){

            if(is_free(-1,0,opp)){
                move_AI(-1,0,opp);
                last_move=4;
                return;


            }
        }
        }

            if(is_free(-1,0,opp) && last_move!=3){
                move_AI(-1,0,opp);
                last_move=4;
                return;


            }
            else if(is_free(1,0,opp)&& last_move!=4){
                move_AI(1,0,opp);
                last_move=3;
                return;


            }

            else if(is_free(0,1,opp) && last_move!=1){
                move_AI(0,1,opp);
                last_move=2;
                return;


            }
            else if(is_free(0,-1,opp) && last_move!=2){
                move_AI(0,-1,opp);
                last_move=1;
                return;

            }
}

int is_free(int x,int y,struct position AI_pop){

    if( game.screen[AI_pop.y+y][AI_pop.x+x] ==' ' || game.screen[AI_pop.y+y][AI_pop.x+x] ==AI.goal )
        return 1;

    return 0;

}
void bubbleSort(float arr[], int n) {

   int i, j;
   float temp;

   for (i = 0; i < n-1; i++)
         for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1]) {

                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
           }

}

struct position find_symbol(char symbol ,struct position player){

    struct position goal;
    goal.x=0;
    goal.y=0;


    int i , j ;

    for( i=1 ; i<game.row*game.column ; i++ ){

        for( j=0 ; j<=i ; j++){

            if( game.screen[player.y+j][player.x-i+j]==symbol && player.x-i+j>=0 && player.y+j>=0 ){

                goal.y=player.y+j;
                goal.x=player.x-i+j;

                return goal;

            }
            if( game.screen[player.y-j][player.x-i+j]==symbol && player.x-i+j>=0 && player.y-j>=0){

                goal.y=player.y-j;
                goal.x=player.x-i+j;

                return goal;
            }
            if( game.screen[player.y+j][player.x+i-j]==symbol && player.x+i-j>=0 && player.y+j>=0){

                goal.y=player.y+j;
                goal.x=player.x+i-j;

                return goal;
            }
            if( game.screen[player.y-j][player.x+i-j]==symbol && player.x+i-j>=0 && player.y-j>=0 ){

                goal.y=player.y-j;
                goal.x=player.x+i-j;

                return goal;
            }

        }
    }
return goal;

}
