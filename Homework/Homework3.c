#include<stdio.h>
#include<ctype.h>
//I did all of those defines just to not confuse myself when doing it
#define NO 0
#define YES 1
#define NUMBER 2
#define DONE 5
#define ADD 4
#define ONE 12

main () {  
	
	int c, skip, numb, all, quo;
	
	while ((c = getchar()) != EOF) {

		if ((c == '"' || c == '\'') && quo == NO) { //start quotes
			all = ADD;
			quo = ONE;
		}	else if ((c == '"' || c == '\'' || c == '\n') && quo == ONE) { //finish quotes
				all = NO; 
				quo = NO;
		}	
			
		if (c == '<' || c == '(' || c == '[' || c == '{') //start parenthesis
			all = ADD;
		else if (c == '>' || c == ')' || c == ']' || c == '}' || c == '\n') //finish parenthesis
			all = NO;
	
		if (c == ',' || c == '.' || c == ':' || c == ';' || c == '?' || c == '!' || c == '_') //remove punctuation
				skip = NO;
				else 
					skip = YES;
			
		if (all == NO) { //chages the digits to X
			if (isdigit(c))
				skip = NUMBER;
			if (!isdigit(c) && numb == DONE)
				numb = YES;
			
			if (skip == YES)
				putchar (c);
			else if (skip == NUMBER && numb != DONE) {
				putchar ('X');
				numb = DONE;
			}
		}
		
		if (all == ADD && skip == YES)//prints everything exept puntuation
			putchar (c);
			
	} 

}
