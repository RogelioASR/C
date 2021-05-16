#include<stdio.h>

int get(int);
void insert(int, int, int);
int win();
int vertical(int, int, int);
int horizontal(int, int, int);
int diagonal(int, int, int);
int diagonal2(int, int, int);
int random2();
int full();
int ganar();

int game[6][7];
int winner, mode, dif;
char nom[20], nom2[20];
