
#include "console_header.h"


extern struct map game;
extern struct direction direction;
extern struct player player1;
extern struct AI_player AI ;
extern struct time game_time;

extern int exit_game;

char * insert_substring(char *main_string,char *substring,int position);

void get_game(void){

    FILE *game_map;
    FILE *game_instruction;

    char *game_ins_name;
    char *game_map_name;

    game_ins_name=insert_substring("game-().txt",game.name,6);
    game_map_name=insert_substring("map-().txt",game.name,5);

    game_map=fopen(game_map_name,"r");
    game_instruction=fopen(game_ins_name,"r");

    if(game_map ==NULL || game_instruction==NULL){
        printf("can't read file");
        exit_game=2;
    }
    else{

        fscanf(game_map,"%d%*c%d\n",&game.column,&game.row);

        int i;

        for(i=0;i<game.row;i++)
            fgets(game.screen[i],1000,game_map);

        //get instruction
        char *ins;

        while(!feof(game_instruction)){

            fgets(ins,50,game_instruction);

           if(strncmp(ins,"solidblock",10)==0)
                sscanf(ins,"solidblock=%c",&game.solidblock);

           else if(strncmp(ins,"deathblock",10)==0)
                sscanf(ins,"deathblock=%c",&game.deathblock);

           else if(strncmp(ins,"moveblock",9)==0)
                sscanf(ins,"moveblock=%c",&game.moveblock);

           else if(strncmp(ins,"rpoint",6)==0){

               int num_of_rpoint;

               sscanf(ins,"rpoint=%c,%d,%d",&game.rpoint,&game.score_point,&num_of_rpoint);
               random_position(game.rpoint,num_of_rpoint);

           }
           else if(strncmp(ins,"wall",4)==0)
                sscanf(ins,"wall=%c",&game.wall);


           else if(strncmp(ins,"target",6)==0)
                sscanf(ins,"target=%c",&game.target);


           else if(strncmp(ins,"object",6)==0)
                sscanf(ins,"object=%c",&game.object);

           else if(strncmp(ins,"attack",6)==0)
                sscanf(ins,"attack=%d",&game.attack);

           else if(strncmp(ins,"raindb",6)==0){

                sscanf(ins,"raindb=%d",&game.raindb_num);
                int j=game.raindb_num;

                while(game.raindb_num--){

                    game.raindb[game.raindb_num].x=rand()%(game.column-2)+1;
                    game.raindb[game.raindb_num].y=1;
                    game.screen[game.raindb[game.raindb_num].y][game.raindb[game.raindb_num].x]=game.deathblock;

                }
                game.raindb_num=j;

           }
           else if(strncmp(ins,"Exit",4)==0)
                sscanf(ins,"Exit=%c",&game.exit_char);

           else if(strncmp(ins,"down",4)==0)
                sscanf(ins,"down=%c",&direction.down);

           else if(strncmp(ins,"up",2)==0)
                sscanf(ins,"up=%c",&direction.up);

           else if(strncmp(ins,"left",4)==0)
                sscanf(ins,"left=%c",&direction.left);

           else if(strncmp(ins,"right",5)==0)
                sscanf(ins,"right=%c",&direction.right);

           else if(strncmp(ins,"character",9)==0){
                sscanf(ins,"character=%c",&player1.symbol);
                player1.position=find_symbol(player1.symbol,player1.position);

           }
           else if(strncmp(ins,"opp",3)==0){

                sscanf(ins,"opp=%c,%c",&AI.symbol,&AI.goal);

           }
           else if(strncmp(ins,"time",4)==0)
                sscanf(ins,"time=%d",&game_time.gametime);

           else if(strncmp(ins,"put",3)==0)
                sscanf(ins,"put=%c,%c,%d",&game.put_deathblock.key_symbol,&game.put_deathblock.symbol,&game.put_deathblock.number);


        }

        fclose(game_instruction);
        fclose(game_map);

    }
}

char * insert_substring(char *main_string,char *substring,int position){

    char *new_string;
    int substring_len=strlen(substring);
    int main_string_len=strlen(main_string);

    int i;

    new_string=(char *)malloc(100*sizeof(char));

    for(i=0;i<position;i++)
        new_string[i]=main_string[i];

    for(i=0;i<substring_len;i++)
        new_string[i+position]=substring[i];

    for(i=position;i<main_string_len;i++)
        new_string[i+substring_len]=main_string[i];

    new_string[i+substring_len]='\0';

    return new_string;

}

