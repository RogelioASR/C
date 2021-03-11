#include<stdio.h> /* Made by Rogelio Salinas */
#include<ctype.h>
//I did all of those defines just to not confuse myself when doing it
#define NO 0
#define YES 1
#define NUMBER 2
#define DONE 5
#define ONE 12

main () {  
	
	int c, skip, numb, all, quo;
	
	while ((c = getchar()) != EOF) {
		if ((c == '"' || c == '\'') && quo == NO) { //start quotes
			all = YES;
			quo = ONE;
		} else if ((c == '"' || c == '\'' || c == '\n') && quo == ONE) { //finish quotes
			all = NO; 
			quo = NO;
		}	
		if (c == '<') //start parenthesis
			all = 1;
		else if ((c == '>' || c == '\n') && all == 1) //end parenthesis
			all = 2;
		if (c == '(') //start parenthesis
			all = 3;
		else if ((c == ')' || c == '\n') && all == 3) //end parenthesis
			all = 4;
		if (c == '{') //start parenthesis
			all = 5;
		else if ((c == '}' || c == '\n') && all == 5) //end parenthesis
			all = 6;
		if (c == '[') //start parenthesis
			all = 7;
		else if ((c == ']' || c == '\n') && all == 7) //end parenthesis
			all = 8;
	
		if (c == ',' || c == '.' || c == ':' || c == ';' || c == '?' || c == '!' || c == '_') //remove punctuation
			skip = NO;
		else 
			skip = YES;
			
		if ((all % 2) == NO) { //chages the digits to X
			if (isdigit(c))
				skip = NUMBER;
			if (!isdigit(c) && numb == DONE && !ispunct(c))
				numb = YES;
			
			if (skip == YES)
				putchar (c);
			else if (skip == NUMBER && numb != DONE) {
				putchar ('X');
				numb = DONE;
			}
		}
		
		if ((all % 2) != NO && skip == YES)//prints everything exept puntuation
			putchar (c);		
	} 
} //Credits by colaboration with Antonio Cortes
