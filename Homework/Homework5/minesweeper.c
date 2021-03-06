#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include "minesweeper.h"

static char hash[CONTL][CONTL]; //showed array
static int nums[CONTL][CONTL]; //mines and numbers array

int open() {

	int wait = 1, did, save;
	int use = 1, use2 = 1;
	int c, pos, block, a, b;
	
	while(wait) { //if the imput was invalid it reapeats
		pos = block = did = save = 0, use = use2 = 1;
		printf("\nPlease, Enter the row and column: ");	
		while((c = getchar()) != EOF && c != '\n' && wait) { //takes imput
			if(c == '0' && save)
				pos += 90, save = 0;
			else if(c == '1')
				save = 1;
			else if(isdigit(c) && use && c != '0')
				pos += (c-'1')*10, use = 0;
			else if(toupper(c) >= 'A' && toupper(c) <= 'J' && use2)
				pos += (toupper(c) - 'A'), use2 = 0, save = 0;
			else if(tolower(c) == 'm')
				block = 1;
			else if(c != ' ') {
				printf("Invalid location\n");
				did = 1;
			}	
		}	
		a = pos/10, b = pos%10;
		if(hash[a][b] == '-' && !block)
			did = 1, printf("Space Blocked\n");
		if(hash[a][b] != '#' && hash[a][b] != '-')
			did = 1, printf("Already opened\n");	
		if(!did)
			wait = 0;
	}
	printf("\n");

	if(nums[a][b] == -1 && hash[a][b] != '-' && !block) {
		kaboom();
		return LOST;
	}
	
	if(hash[a][b] != '-') //if is not blocked
		hash[a][b] = nums[a][b] + '0';
	
	if(hash[a][b] == '0')
		hash[a][b] = ' ';
		
	if(block && hash[a][b] == '-')
		hash[a][b] = '#';
	else if (block)
		hash[a][b] = '-';
	
	forloop(use2, CONTL*CONTL) //check if you won
		if(hash[use2/10][use2%10] != '#' || (hash[use2/10][use2%10] == '#' && nums[use2/10][use2%10] == -1))
			use++;
	if(use == 100){
		printf("\nCongratulations! You won");
		return WON;
	}
	if(nums[a][b] == 0)
		empty(a, b);
		
	return OK;
}

char field(int a, int b) {
	return hash[a][b];
}

void set (int a, int b, char hsh) {
	hash[a][b] = hsh;
}

void kaboom() { 

	int i;
	forloop(i, CONTL*CONTL)
		if(nums[i/10][i%10] == -1 && hash[i/10][i%10] != '-')
			hash[i/10][i%10] = 'X';
			
}

void bombs(int k) {

	int te, i, limit = CONTL*CONTL;
	srand(time(NULL));

	forloop(i, k) {
		te = (rand() % (limit + 1));
		if(nums[te/10][te%10] == BOMB) {
			i--; continue; 
		}
		nums[te/10][te%10] = BOMB;
	}
    	
}

void neighbours(int imp) {
	
	int a, b;
	int esp = 0;
	a = imp/10, b = imp%10;
	if(nums[a][b] == BOMB)
		return;
	if(nums[a-1][b-1] == BOMB && imp > 10 && imp%10)
		esp++;
	if(nums[a-1][b] == BOMB && imp > 10)
		esp++;
	if(nums[a-1][b+1] == BOMB && imp > 10 && (imp-9)%10)
		esp++;
	if(nums[a][b-1] == BOMB && imp%10)
		esp++;
	if(nums[a][b+1] == BOMB && (imp+1)%10)
		esp++;
	if(nums[a+1][b-1] == BOMB && (imp+9) < 99 && imp%10)
		esp++;
	if(nums[a+1][b] == BOMB && (imp+10) < 100)
		esp++;
	if(nums[a+1][b+1] == BOMB && (imp+11) < 100 && (imp+1)%10)
		esp++;
		
	nums[a][b] = esp;
		
}

void empty(int a, int b) { //recursive function
    
	static char x[CONTL][CONTL];
	x[a][b] = 1;
	
	if((a-1) >= 0 && b > 0) {
		hash[a-1][b-1] = nums[a-1][b-1] + '0';
		if(!nums[a-1][b-1]) 
			hash[a-1][b-1] = ' ';
	}	
	if((a-1) >= 0) {
		hash[a-1][b] = nums[a-1][b] + '0';
		if(!nums[a-1][b]) 
			hash[a-1][b] = ' ';
	}
	if((a-1) >= 0 && (b+1) < 10) {
		hash[a-1][b+1] = nums[a-1][b+1] + '0';
		if(!nums[a-1][b+1]) 
			hash[a-1][b+1] = ' ';
	}		
	if(b != 0 ) {
		hash[a][b-1] = nums[a][b-1] + '0';
		if(!nums[a][b-1]) 
			hash[a][b-1] = ' ';
	}		
	if((b+1) < 10) {
		hash[a][b+1] = nums[a][b+1] + '0';
		if(!nums[a][b+1]) 
			hash[a][b+1] = ' ';
	}	
	if((a+1) < 10 && b != 0) {
		hash[a+1][b-1] = nums[a+1][b-1] + '0';
		if(!nums[a+1][b-1]) 
			hash[a+1][b-1] = ' ';
	}		
	if((a+1) < 10) {
		hash[a+1][b] = nums[a+1][b] + '0';
		if(!nums[a+1][b]) 
			hash[a+1][b] = ' ';
	}	
	if((a+1) < 10 && (b+1)%10) {
		hash[a+1][b+1] = nums[a+1][b+1] + '0';
		if(!nums[a+1][b+1]) 
			hash[a+1][b+1] = ' ';
	}
	if(nums[a-1][b] == 0 && hash[a-1][b] == ' ' && !x[a-1][b])
		empty((a-1), b);
	if(nums[a-1][b+1] == 0 && hash[a-1][b+1] == ' ' && !x[a-1][b+1])
		empty((a-1), (b+1));
	if(nums[a][b-1] == 0 && hash[a][b-1] == ' ' && !x[a][b-1])
		empty(a, (b-1));
	if(nums[a][b+1] == 0 && hash[a][b+1] == ' ' && !x[a][b+1])
		empty(a, (b+1));
	if(nums[a+1][b-1] == 0 && hash[a+1][b-1] == ' ' && !x[a+1][b-1])
		empty((a+1), (b-1));
	if(nums[a+1][b] == 0 && hash[a+1][b] == ' ' && !x[a+1][b])
		empty((a+1), b);
	if(nums[a+1][b+1] && hash[a+1][b+1] == ' ' && !x[a+1][b+1])
		empty((a+1), b);
}
