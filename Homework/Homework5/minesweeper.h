#define forloop(i, x) for(i = 0; i != x; i++)//i used it a lot so just to make it easier
#define BOMB -1 //set bombs
#define AMBOMBS 15//amount of bombs
#define CONTL 10 //number of rows and columns (counter line)

#define LOST 'l' 
#define WON 'O'
#define OK '?'

void bombs();
void neighbours(int); 
int open();
void kaboom();
void empty(int, int);
