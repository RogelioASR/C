#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include"connect.h"

int game[6][7]; //values of positions in the board

void board() { //print board
    int a, b;
    
    printf("\n\n\n");
	for(a = 0; a < 6; a++) {
		printf("\t|");
		for(b = 0; b < 7; b++) {
			switch(game[a][b]) {
				case 0: printf("   |"); break;
				case 1: printf(" %c |", pone.sym); break;
				case 2: printf(" %c |", ptwo.sym); break;
				case 3: printf("!%c!|", '*'); break;
			}
		}
		printf("\n");
		if(a == 5) {
			printf("\t ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯\n");
			printf("\t  1   2   3   4   5   6   7 \n");
		}	
	}
}

int full() { //check if it is full
    int a, b, count = 0;
    
    for(a = 0; a < 6; a++) {
		for(b = 0; b < 7; b++) {
		    if(game[a][b] == 0)
		        count++;
		}
    }
    return count;
}

int get(int mode) {//asks for column
	int col;
	static int turns;
	
	do {
		if(!turns) {
			printf("\n%s, select the column you want to play: ", pone.name);
			scanf("%i", &col);
			if(col < 8 && col > 0)
				turns = 1;		
		} else if(mode == 1) {
			col = program_block();
			turns = 0;
		} else {
			printf("\n%s, select the column you want to play: ", ptwo.name);
			scanf("%i", &col);
			if(col < 8 && col > 0)
				turns = 0;
		}
		if(col > 7 || col < 1) 
		    printf("\nInvalid option, Try again");
	} while(col > 7 || col < 1);
	col -= 1;
	
	insert(5, col, turns);
	return 1;
}

void insert(int row, int col, int player) {//insert in given column

	if(game[row][col] == 0 && row >= 0) {
		if(player == 1)
			game[row][col] = 1;
		else
			game[row][col] = 2;
	} else if(row >= 0)
		insert(row-1, col, player);
	else {
		printf("\nInvalid option, Column Full\n");
		printf("Please, insert another coloumn: ");
		scanf("%i", &col), col -= 1;
		insert(5, col, player);
	}
	return;
}

int win() {//check the board in case of a win
	int a, b, win = 0;
	
	for(a = 0; a < 6; a++) {
		for(b = 0; b < 8; b++) {
			if(game[a][b] != 0) { //different chances of winning
				win += horizontal(a, b, game[a][b]);
				win += vertical(a, b, game[a][b]);
				win += diagonal(a, b, game[a][b]);
				win += diagonal2(a, b, game[a][b]);
			}
		}	
	}
	if(win) 
		return 1;
	else
		return 0;
}

int horizontal(int a, int b, int p) {
	static int w, x;
	
	if(x == 4)
		w = x = 0;
		
	if((b > 3 && !w))
		return 0;
		
	if(game[a][b+1] == p) {
		w++;
		horizontal(a, b+1, p);	
	}
	
	if(w == 3) {
	   if(p == 1) pone.winn = 1;
	   else ptwo.winn = 1;
		game[a][b] = 3, x++;
		return 1;
	} else {
		w = 0;
		return 0;
	}
		
}

int vertical(int a, int b, int p) {
	static int w, x;
	
	if(a > 2 && !w)
		return 0;
		
	if(x == 4)
		w = x = 0;
	
	if(game[a+1][b] == p && a < 5) {
		w++;
		vertical(a+1, b, p);	
	}
	if(w == 3) {
	    if(p == 1) pone.winn = 1;
	    else ptwo.winn = 1;
		game[a][b] = 3, x++;
		return 1;
	} else {
		w = 0;
		return 0;
	}
}

int diagonal(int a, int b, int p) {
	static int w, x;
	
	if(x == 4)
		w = x = 0;
		
	if(b > 3 && !w)
		return 0;
		
	if(game[a-1][b+1] == p) {
		w++;
		diagonal(a-1, b+1, p);	
	}
	
	if(w == 3) {
		if(p == 1) pone.winn = 1;
	    else ptwo.winn = 1;
		game[a][b] = 3, x++;
		return 1;
	} else {
		w = 0;
		return 0;
	}
}

int diagonal2(int a, int b, int p) {
	static int w, x;
	
	if(x == 4)
		w = x = 0;
		
	if((a > 2 && !w) || (b > 3 && !w))
		return 0;
		
	if(game[a][b] == 3)
		return 0;
		
	if(game[a+1][b+1] == p) {
		w++;
		diagonal2(a+1, b+1, p);	
	}
	
	if(w == 3) {
		if(p == 1) pone.winn = 1;
	    else ptwo.winn = 1;
		game[a][b] = 3, x++;
		return 1;
	} else {
		w = 0;
		return 0;
	}
}

int program_block() { //program blocks you if you are about to win 
	
	int a, b, temp, col;
	srand(time(NULL));
	for(a = 0; a < 6; a++) {
		for(b = 0; b < 7; b++) {
			if(game[a][b] == 1) {
				if(game[a][b+1] == 1 && game[a][b+2] == 1 && game[a][b+3] == 0 && b < 4 && (game[a+1][b+3] != 0 || a == 5))
					if(!(rand() % dif)) col = (b+4);
				if(game[a][b-1] == 1 && game[a][b-2] == 1 && game[a][b-3] == 0 && b > 2 && (game[a+1][b-3] != 0 || a == 5))
					if(!(rand() % dif)) col = b-2;
				if(game[a-1][b] == 1 && game[a-2][b] == 1 && game[a-3][b] == 0) 
					if(!(rand() % dif) && (a-3) > 0) col = b+1;
				if(game[a-1][b+1] == 1 && game[a-2][b+2] == 1 && game[a-3][b+3] == 0 && game[a-2][b+3] != 0) 
					if(!(rand() % dif) && (a-3) > 0) col = b+4;
				if(game[a-1][b-1] == 1 && game[a-2][b-2] == 1 && game[a-3][b-3] == 0 && game[a-2][b-3] != 0) 
					if(!(rand() % dif) && (a-3) > 0) col = b-2;
			    if(program_win()) 
			        col = program_win();
			}
		}	
	}
	
	while(col == 0 || col > 7) {
		col = (rand() % 8);
		if(game[0][col-1] != 0 && col > 0)
			col = 0;
	} 
		
	printf("\nProgram: %d", col);	
	
	return col;
}

int program_win() { //program puts the final piece to win
    
    int a, b, col = 0;
    srand(time(NULL));
    for(a = 0; a < 6; a++) {
		for(b = 0; b < 7; b++) {
			if(game[a][b] == 2) {
				if(game[a][b+1] == 2 && game[a][b+2] == 2 && game[a][b+3] == 0 && b < 4 && (game[a+1][b+3] != 0 || a == 5))
					if(!(rand() % dif)) col = (b+4); 
				if(game[a][b-1] == 2 && game[a][b-2] == 2 && game[a][b-3] == 0 && b > 2 && (game[a+1][b-3] != 0 || a == 5))
					if(!(rand() % dif)) col = b-2; 
				if(game[a-1][b] == 2 && game[a-2][b] == 2 && game[a-3][b] == 0) 
					if(!(rand() % dif) && (a-3) > 0) col = b+1; 
				if(game[a-1][b+1] == 2 && game[a-2][b+2] == 2 && game[a-3][b+3] == 0 && game[a-2][b+3] != 0) 
					if(!(rand() % dif) && (a-3) > 0) col = b+4;
				if(game[a-1][b-1] == 2 && game[a-2][b-2] == 2 && game[a-3][b-3] == 0 && game[a-2][b-3] != 0) 
					if(!(rand() % dif) && (a-3) > 0) col = b-2; 
			}
		}	
	}
	
	return col;
}
