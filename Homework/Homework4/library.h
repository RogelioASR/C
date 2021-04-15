#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>

#define MAXOP 100 
#define NUMBER '0' 
#define MAXVAL 100 
#define BUFSIZE 100

void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
int options(int, char []);
