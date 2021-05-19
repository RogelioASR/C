#include<stdio.h>
//basic game funtions
void board(); 
int win();
int full();
//funtions for place the the pices
int get(int);
void insert(int, int, int);
//funtions to check if someone won in any possible way
int vertical(int, int, int);
int horizontal(int, int, int);
int diagonal(int, int, int);
int diagonal2(int, int, int);
//Funtions to sinle player mode
int program_block(); 
int program_win(); 

struct game { //Struct for playar one and player two
    char name[20];
    char sym;
    int winn;
} pone, ptwo;

int dif; //global
