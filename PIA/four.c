#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"connect.h"

int get(int mode) {
	
	int col;
	static int turns;
	
	do {
		if(!turns) {
			printf("\n%s, select the column you want to play: ", nom);
			scanf("%i", &col);
			if(col < 8 && col > 0)
				turns = 1;		
		} else if(mode == 1) {
			col = random2();
			turns = 0;
		} else {
			printf("\n%s, select the column you want to play: ", nom2);
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

void insert(int row, int col, int player) {

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

int win() {
	
	int a, b, win = 0;
	
	for(a = 0; a < 6; a++) {
		for(b = 0; b < 8; b++) {
			if(game[a][b] != 0) {
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
		winner = p, x++;
		game[a][b] = 3;
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
		winner = p, x++;
		game[a][b] = 3;
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
		winner = p, x++;
		game[a][b] = 3;
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
		
	if(a > 2 && !w)
		return 0;
		
	if(game[a][b] == 3)
		return 0;
		
	if(game[a+1][b+1] == p) {
		w++;
		diagonal2(a+1, b+1, p);	
	}
	
	if(w == 3) {
		winner = p, x++;
		game[a][b] = 3;
		return 1;
	} else {
		w = 0;
		return 0;
	}
}

int random2() {
	
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
					if(!(rand() % dif)) col = b+1;
				if(game[a-1][b+1] == 1 && game[a-2][b+2] == 1 && game[a-3][b+3] == 0 && game[a-2][b+3] != 0) 
					if(!(rand() % dif)) col = b+4;
				if(game[a-1][b-1] == 1 && game[a-2][b-2] == 1 && game[a-3][b-3] == 0 && game[a-2][b-3] != 0) 
					if(!(rand() % dif)) col = b-2;
			}
		}	
	}
	
	while(col == 0 || col > 7) {
		col = (rand() % 8);
		if(game[0][col] != 0)
			col = 0;
	} 
		
	printf("\nProgram: %d", col);	
	
	return col;
}
