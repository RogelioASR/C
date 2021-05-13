#include<stdio.h>

int get();

char game[7][6];

main() {
	
	int a, b;
	char one, two;
	
//	printf("Player one, choose your symbol: ");
//	scanf("%s", &one);
//	printf("Player  two, choose your symbol: ");
//	scanf("%s", &two);
	
	do {
		printf("\n\n");
		for(a = 0; a < 6; a++) {
			printf("\t|");
			for(b = 0; b < 7; b++) {
				switch(game[a][b]) {
					case 0: printf("   |"); break;
					case 1: printf(" %c |", one); break;
					case 2: printf(" %c |", two); break;
				}
			}
			printf("\n");
			if(a == 5)
				printf("\t ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯\n");
		}
	} while(get());
	
}

int get() {
	
	return 0;
}

void win() {
	
}
