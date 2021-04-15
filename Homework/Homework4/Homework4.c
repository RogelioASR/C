#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "library.h"

main() {

	int type;
	double op2;
	char s[MAXOP];
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER: push(atof(s)); break;
			case '+': push(pop() + pop()); break;
			case '*': push(pop() * pop()); break;
			case '-': op2 = pop(); push(pop() - op2); break;
			case '/': op2 = pop(); 
				if (op2 != 0.0) 
					push(pop() / op2); 
				else
					printf("error: zero divisor\n"); break;
			case '%': op2 = pop(); 
				if (op2 != 0.0) 
					push((int)pop() % (int)op2); 
				else
					printf("error: zero divisor\n"); break;
			case '\n': printf("      =\t%.8g\n", pop()); break;
			default: if(strlen(s) > 1 && (s[0] != 'a' && s[1] != 'n' && s[2] != 's'))
				printf("error: unknown command %s\n", s); break;
		}
	}
	
	return 0;
} 

