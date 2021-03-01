#include <stdio.h>

#define MAXLINE 1000 

int max; /* m�xima longitud vista hasta el momento */
char line [MAXLINE]; /* l�nea de entrada actual */
char longest [MAXLINE]; /* la l�nea m�s larga se guarda aqu� */
int getline(void);
void copy (void);
/* imprime la l�nea de entrada m�s larga; versi�n especializada */

main() {

	int len;
	extern int max;
	extern char longest [];
	max = 0;

	while ((len = getline( )) > 0)
		if (len > max) {
			max = len;
			copy( );
	}
	
	if (max > 0) /* hubo una l�nea */
		printf("%s", longest);
	
	return 0;
}


/* getline: versi�n especializada */
int getline(void) {
	
	int c, i;
	extern char line[];
	
	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
		line [i] = c;
	
	if (c == '\n') {
		line [i] = c;
		++i;
	}

	line[i] = '\0';

	return i;
}


/* copy: versi�n especializada */
void copy(void) {
	
	int i;
	extern char line[], longest[];
	i = 0;
	
	while ((longest[i] = line[i]) != '\0')
		++i;
		
}

