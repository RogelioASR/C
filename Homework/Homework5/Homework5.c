//ingresa la columna y fila de la casilla que se desea abrir, si deseas cambiar la cantidad de minas modifica el valor de k = '#'
#include <stdio.h>
#include "minesweeper.h"

int main() {
	
	int pos, lett, c; //numero de casilla y letra de arriba	
	int flag = 1, i, a, b, k = 15;
	
	bombs(k); //generates bombs and number of positions
	forloop(i, CONTL*CONTL) //sets numbers to mine neighbours
		neighbours(i); 
	forloop(i, CONTL*CONTL) //creates array	
		set((i/10), (i%10), '#');
	/*RULES*/
	printf("\tHow to play:\nEnter the number and row of the coloumn to open it\n");
	printf("Example: \"c3\" or \"3c\"\nTo set a flag enter the location + \"m\"\n");
	printf("Example: \"8dm\" \"md8\" \"8md\"\nAnd to remove it do it again\n\n");
	do { //prints board
		for(lett = 'A', i = 0; i != CONTL; i++, lett++)
			printf("\t %c", lett), flag = 1;
		for(pos = 0; pos != 100; pos++) {
			flag ? printf("\n      ") : printf("\n     |");
			for(lett = 0; lett != CONTL; lett++)
				flag ? printf("_______ ") : printf("_______|");
			flag = 0;
			printf("\n     |");
			forloop(i, CONTL)
				printf("       |");	
			printf("\n%2i   |", (pos/CONTL)+1);
			do {
				a = pos/10, b = pos%10;
				field(a, b) == '-' ? printf("  -1   |") : printf("   %c   |", field(a, b)); //VALUE
				pos++;
			} while((pos%CONTL) != 0);
			pos--;
		}
		printf("\n     |");
		forloop(i, CONTL)
			printf("_______|");
		printf("\n");
		if(c == LOST) {
			printf("\nYou lost!\n");
			break;
		}	
	} while((c = open()) != EOF && c != WON);
		
	return 0;
}
