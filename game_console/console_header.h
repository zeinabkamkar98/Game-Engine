
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <dos.h>

void print_result(void);
void menu(void);
void get_game(void);
void print_screen(void);
void handle_keyboard(void);
int time_delay(void);
void move(void);
struct position find_symbol(char symbol ,struct position player);

void AI_path(struct position opp);
void write_result(void);

struct time{

    clock_t start;
    clock_t stop;
    float delay;
    int gametime;
    int passed_time;
    float speed_factor;


};

struct put{

    int number;
    char symbol;
    char key_symbol;

};

struct position{

    int x;
    int y;

};

struct map{

    char name[50];
    char screen[1000][1000];
    int row;
    int column;

    int attack;
    struct position raindb[50];
    int raindb_num;
    char solidblock;
    char deathblock;
    char moveblock;
    char target;
    char object;
    char rpoint;
    int score_point;
    char wall;
    char exit_char;
    struct  put put_deathblock ;

};

struct player{

    struct position position;
    char name[30];
    int score;
    char symbol;
    char direction;

};

struct AI_player{

    struct position pop[100];
    char symbol;
    char goal;
    int num_of_AI;

};

struct direction{

    char up;
    char down;
    char left;
    char right;

};


