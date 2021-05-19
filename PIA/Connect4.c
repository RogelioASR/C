/* How to compile:
Go to onlineGDB or other compiler and add the 3 files:
connect4.c
connect.h
four.c */

#include<stdio.h>
#include<time.h>
#include"connect.h"

int main() {
	
	time_t tiempo = time(0);
    struct tm *timp = localtime(&tiempo);
	int mode;
	
	do {    //MENU
		printf("Welcome to the Connect four game.\n");
		printf("-------------------------------------------\n");
		printf("Choose what option you want:\n1. Single player mode");
		printf("\n2. Two player mode\n3. Read the rules\n");
		printf("-------------------------------------------\n");
		scanf("%i", &mode);

        switch(mode) { //Options of MENU
        	
        	case 1: //Select difficulty
				printf("\nYou have selected single player mode.\nIn what difficulty ");
				printf("do you want to play?\n1. Hard\n2. Normal\n3. Easy\nOption: "); 
				scanf("%i", &dif);
				if(dif < 1 || dif > 3) {
				    printf("\nInvalid option\n\n");
					return 0;
				} break;	
			
			case 2: printf("\nYou have selected two player mode.\nHave fun!");
				break;
				
            case 3: 
				printf("\n\t***RULES***\n");
				printf("---------------------------------\n");
				printf("Connect Four is a two-player game in which players alternately place \n");
				printf("pieces on a vertical board 7 columns across and 6 rows high.\n\n");
				printf("Each player uses particular pieces, and the object is to be the\n"); 
				printf("first to obtain four pieces in a horizontal, vertical, or diagonal\nline.");
				printf("\n\nBecause the board is vertical, pieces inserted in a given column always\n");
				printf("drop to the lowest unoccupied row of that column.\n\nAs soon as a column ");
				printf("contains 6 pieces, it is full and no other piece can\nbe placed in the column.");
				printf("\n\nSo, the game ends when someone conects a 4 line or when the board is full\n");
				printf("---------------------------------------------------\n\n\n"); 
				break;
				
			default: printf("\nInvalid option\n\n"); return 0;
		}
	} while(mode == 3);
	
	//Players information
	printf("\n\nPlayer one, What's your name?\n");
	scanf("%s", pone.name);
	if(mode == 2) {
	    printf("\nPlayer two, What's your name?\n");
	    scanf("%s", ptwo.name); 
	}
	printf("\n\nType ONE character and press Enter (Recomended 'X' and 'O')\n");
	printf("%s, choose your symbol: ", pone.name);
	scanf("%c", &pone.sym); scanf("%c", &pone.sym);
	if(mode == 2) 
	    printf("%s, choose your symbol: ", ptwo.name);
	else
	    printf("Now, choose the symbol of your oponent: ");
	scanf("%c", &ptwo.sym); scanf("%c", &ptwo.sym); 
	
	do { //start game
        
        board(); //prints board
        
		if(win()) //check if win
			break;
        
        if(!full()) { //check if its full
            printf("\nThe board is full, it's a tie\n");
            return 0;
        }
	} while(get(mode)); //gets next move
	
    board();
	
	//Winner
	if(pone.winn == 1)
		printf("\nCongratulations %s, You Won!\n", pone.name);
	else if (mode == 1)
		printf("\nCongratulations %s, You Lost!\n", pone.name);
	else if (mode == 2)
		printf("\nCongratulations %s, You won!\n", ptwo.name);
	
	FILE*record = fopen("file.txt", "a+"); //Saves a record in a file 
    fprintf(record,"----------------------------------------");
    fprintf(record,"\nLAST GAME PLAYED");
    fprintf(record,"\n\t\t %02d/%02d/%d", timp->tm_mday-1, timp->tm_mon+1, timp->tm_year+1900);
    fprintf(record,"\n\t\t    %d:%02d", timp->tm_hour+7, timp->tm_min+1); 
    fprintf(record,"\n\t%s", (mode == 1) ? "Single player game" : "Two player game");
    if(mode == 2) {
        fprintf(record, "\t%s vs %s", pone.name, ptwo.name);
        fprintf(record,"\n\tWinner: %s", (pone.winn) ? pone.name : ptwo.name);
    } else
        fprintf(record,"\n\tWinner: %s", (pone.winn) ? pone.name : "Program");
    fprintf(record,"\n\t\tThanks for playing\n"); 
    fclose(record);
      
	return 0;
}
