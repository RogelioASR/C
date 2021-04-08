#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100  /*OPTIONS*/
enum opts { NUM = '0', MTH, SIN, COS, TAN, EXP, SQR, POW, DUP, NONE, SWP, CLR, PNT };

void 	push(double); 				//saves number
double 	pop(void); 					//takes out the number
int 	getop(char []); 			//get characters, numbers or operands
int 	getcharf(void); 			//takes the imput
void 	ungetch(int); 				//gets last unsaved charracter
int 	options(int, char[]); 		//check for functions or commands
int 	strinx(char s[], char t[]); //functions

double 	val[MAX]; 					//stack
int 	sp = 0; 					//val counter
char 	buf[MAX]; 					//last characters
int 	bufp = 0; 					//buf counter
char 	var;						//variable
double 	variables[1000]; 			//assign 1 digit variables
int 	op1, op3;					//indicators to variables

/* reverse Polish calculator */
main() {

	int c; 
	double op2, op4; //for operations
	char chars[MAX];
	/*MENU*/
	printf("-------------------------------\n    AVAILABLE OPERATIONS\n + = adition\n - = substraction");
	printf("\n * = multplication\n / = division\n %% = division residue\nsin = sine\ncos = cosine\ntan = tangent");
	printf("\nexp = exponential\nsqrt = square root\npow = power\n-------------------------------");
	printf("\n\tCOMMANDS\npx = print the top value\ndup = duplicate the top value\nsw = swap the ");
	printf("top 2 values\ncl = clear stack\nans = use previous answer\n-------------------------------\n\n");
	
	while ((c = getop(chars)) != EOF) {
		switch (c) {
			
			case '+': push(pop() + pop()); break;
			case '*': push(pop() * pop()); break;
			case '-': op2 = pop(); push(pop() - op2); break;
			case '/': op2 = pop(); 
				op2 != 0.0 ? push(pop() / op2) : printf("error: zero divisor\n"); break;
			case '%': op2 = pop(); 
				op2 != 0 ? push(((int) pop()) % ((int) op2)) : printf("error: zero divisor\n"); break;  
			case CLR: sp = 0; break;
			case SIN: push(sin(pop())); break;
			case COS: push(cos(pop())); break;
			case TAN: push(tan(pop())); break;
			case EXP: push(exp(pop())); break;
			case SQR: push(sqrt(pop())); break;
			case NUM: push(atof(chars)); break;
			case DUP: op2 = pop(); push(op2); push(op2); break;
			case POW: op2 = pop(); push(pow(pop(), op2)); break;
			case PNT: op2 = pop(); printf("\t%g\n", op2); push(op2); break;
			case SWP: op2 = pop(); op4 = pop(); push(op2); push(op4); break;
			case '\n': printf("      =\t%.8g\n", pop()); op1 = 0; op3 = 0; var = 0; break;
			default: if(chars[0] != '=' && strlen(chars) > 1 && chars[0] != ':')
						printf("error: unknown command %s\n", chars); break;
		}
	}
	
	return 0;
} 

void push(double f) {
	
	int ops;
	if (sp < MAX)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
	
	if(op1 && var != 0) {
		if(variables[var] == 0 || op3 == 1)
			variables[var] = f;
		else {
			printf("[Warning] There is already a value in the variable: %c\n", var);
			printf("Are you sure you want to change its value? 0.- NO 1.- YES\n");
			scanf("%i", &ops);
			if(ops)
				 variables[var] = f;
		}
	op1 = 0;		
	}		
}

double pop(void) {
	
	variables['$'] = val[sp - 1];
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
	
} 

int getop(char chars[]) {

	int i, c;	
	
	while ((chars[0] = c = getcharf()) == ' ' || c == '\t');
	chars[1] = '\0';

	i = 0;
	if (c == '-')                     
		if (!isdigit(chars[++i] = c = getcharf())) {
			ungetch(c);               
			c = chars[0];
		}
	
	if (c == ':') {
		chars[++i] = c = getcharf();
		op3 = 1;
	}
	
	if (c == '=') {
		chars[++i] = c = getcharf();
		op1 = 1;
	}
	
	if (isalpha(c))
		return options(c, chars);
		
	if (!isdigit(c) && c != '.')
		return c; 
	
	if (isdigit(c)) {
		while (isdigit(chars[++i] = c = getcharf()));
	}
	if (c == '.') 
		while (isdigit(chars[++i] = c = getcharf()));

	if (c != EOF)
		ungetch(c);
	
	return NUM;
	
}

int getcharf(void) {

	return (bufp > 0) ? buf[--bufp] : getchar();
	
}

void ungetch(int c) {

	if (bufp >= MAX)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;

}

int options(int c, char chars[]) {
	
	int i = 0, o;
	double op2, n = 0;
	
	chars[i] = c;
	while (isalpha(chars[++i] = c = getcharf()));
	chars[i] = '\0';
	ungetch(c);
	
	if(i == 1)
		var = tolower(chars[0]);
	else 
		var = 0;
	if(variables[var] != 0)
		push(variables[var]);
	if(strinx(chars, "ans")) {
		push(variables['$']);
		var = '$';
	}
	
	if (strinx(chars, "sin"))
		return SIN;
	if (strinx(chars, "cos"))
		return COS;
	if (strinx(chars, "tan"))
		return TAN;
	if (strinx(chars, "exp"))
		return EXP;		
	if (strinx(chars, "sqrt"))
		return SQR;
	if (strinx(chars, "pow"))
		return POW;
	if (strinx(chars, "dup"))
		return DUP;
	if (strinx(chars, "sw"))
		return SWP;
	if (strinx(chars, "cl"))
		return CLR;
	if (strinx(chars, "px"))
		return PNT;
	
	return NONE;
}

int strinx(char s[], char t[]) {
	
	int i, k;
	
	for (i = 0, k = 0; t[k] != '\0' && s[i] == t[k]; i++, k++);
		if (k > 0 && t[k] == '\0' && s[i] == '\0')
			return i + 1;

	return 0;
}
