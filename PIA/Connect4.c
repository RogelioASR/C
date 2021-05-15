#include<stdio.h>
#include"connect.h"

int main() {
	
	int a, b, again = 1, op;
	char one, two;
	
	do {
		printf("Welcome to the Connect four game.\n");
		printf("-------------------------------------------\n");
		printf("Choose what option you want:\n1. Read the rules\n");
		printf("2. Single player mode\n3. Two player mode\n");
		printf("-------------------------------------------\n");
		scanf("%i", &op);

		switch(op) {
			case 1: 
				printf("\n\t***RULES***\n");
				printf("---------------------------------\n");
				printf("Connect Four is a two-player game in which players alternately place \n");
				printf("pieces on a vertical board 7 columns across and 6 rows high.\n\n");
				printf("Each player uses particular pieces, and the object is to be the\n"); 
				printf("first to obtain four pieces in a horizontal, vertical, or diagonal \n");
				printf("line.\n\nBecause the board is vertical, pieces inserted in a given column always\ndrop");
				printf(" to the lowest unoccupied row of that column.\n\n");
				printf("As soon as a column contains 6 pieces, it is full and no other piece can\nbe placed in the column.");
				printf("\n\nSo, the game ends when someone conects a 4 line or when the board is full\n");
				printf("---------------------------------------------------\n\n\n"); break;
			case 2: mode = 1;
				printf("\nYou have selected single player mode.\nIn what difficulty do you want to play?");
				printf("\n1. Hard\n2. Normal\n3. Easy\nOption: "); 
				scanf("%i", &dif);
				if(dif != 1 && dif != 2 && dif != 3)
					printf("\nInvalid option\n\n");
				else {
					again = 0;
					printf("\n\nWhat's your name?\n");
					scanf("%s", nom);
					printf("\n\n(Recomended 'X' and 'O')\n");
					printf("%s, choose the symbol you want to use: ", nom);
					scanf("%c", &one); scanf("%c", &one);
					printf("Now, choose the symbol of your oponent: ");
					scanf("%c", &two); scanf("%c", &two);
					if(dif == 3) dif = 4;
				} break;	
			case 3: again = 0; mode = 2;
				printf("\nYou have selected two player mode.\nHave fun!");
				printf("\n\nPlayer one, What's your name?\n");
				scanf("%s", nom);
				printf("\nPlayer two, What's your name?\n");
				scanf("%s", nom2);
				printf("\n\n(Recomended 'X' and 'O')\n");
				printf("%s, choose your symbol: ", nom);
				scanf("%c", &one); scanf("%c", &one);
				printf("%s, choose your symbol: ", nom2);
				scanf("%c", &two); scanf("%c", &two);
				break;
			default: printf("\nInvalid option\n\n"); return 0;
		}
	} while(again);
	
	do {
		printf("\n\n\n");
		for(a = 0; a < 6; a++) {
			printf("\t|");
			for(b = 0; b < 7; b++) {
				switch(game[a][b]) {
					case 0: printf("   |"); break;
					case 1: printf(" %c |", one); break;
					case 2: printf(" %c |", two); break;
					case 3: printf("!%c!|", '*'); break;
				}
			}
			printf("\n");
			if(a == 5) {
				printf("\t ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯\n");
				printf("\t  1   2   3   4   5   6   7 \n");
			}	
		}
		if(win())
			break;
  
	} while(get(mode));
	
	printf("\n\n\n");
	for(a = 0; a < 6; a++) {
		printf("\t|");
		for(b = 0; b < 7; b++) {
			switch(game[a][b]) {
				case 0: printf("   |"); break;
				case 1: printf(" %c |", one); break;
				case 2: printf(" %c |", two); break;
				case 3: printf("!%c!|", '*'); break;
			}
		}
		printf("\n");
		if(a == 5) {
			printf("\t ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯\n");
			printf("\t  1   2   3   4   5   6   7 \n");
		}	
	}
	
	if(winner == 1 && mode == 1)
		printf("\nCongratulations %s, You Won!\n", nom);
	else if (mode == 1)
		printf("\nCongratulations, You Lost!\n");
		
	if(winner == 1 && mode == 2)
		printf("\nCongratulations, %s has won!\n", nom);
	else if (mode == 2)
		printf("\nCongratulations, %s has won!\n", nom2);
	return 0;
}
