#include<stdio.h>
#include<math.h>

#define OUT 0
#define IN 1
#define K 25 /*Constant*/

int zeros (int bytes);
void binary (int prime, int bytes);

int main () {
	
	int st; //tells if it's prime or not
	int cont, j = 1; //counters
	int prime[K]; //saves the prime number
	int bytes;
	
	for (cont = 1; j != (K + 1); cont++) { //if any number is devided by the first prime numbers
		if (cont != 2 && (cont % 2) == 0) //and not equal to zero is also a prime number
			st = OUT;
		else if (cont != 3 && (cont % 3) == 0)
			st = OUT;
		else if (cont != 5 && (cont % 5) == 0)
			st = OUT;
		else if (cont != 7 && (cont % 7) == 0)
			st = OUT;
		else if (cont != 11 && (cont % 11) == 0)
			st = OUT;
			else 
				st = IN;
		if (st) {
			prime[j] = cont; //saves the value of every prime in an array
			j++;
		}
	}
	
	bytes = zeros(prime[K]); //gets the number of byts of the maximum number
	
	for (j = 1; j <= K; j++)
		binary (prime[j], bytes);//passes the primes and prints them in binary
	
	return 0;
}


int zeros (int bytes) {
	
	int i;
	for (i = 0; bytes >= 1; i++) //obtain the byts by deviding into 2 
		bytes /= 2;					//until obtain 1 or less 

	return i;
}


void binary (int prime, int bytes) {
	
	int twos = pow(2, (bytes - 1));//binary goes with 2 and increases in its powers
	
	while (prime > 1 || twos != 1) {//it starts with the biggest value of the position 
		if ((prime - twos) >= 0) {//of the last byte
			prime -= twos; 
			printf ("1");
		} else
			printf ("0");
			
		twos /= 2;//then divide to get the value of the byte before that and so on
	}	
		if (prime == 1)//the last number isn't multiple of two so just add 1 
			printf ("1\n");//if it letfover (that's why of the subtraction of 
		else				//one at the beginning)
			printf ("0\n");
	
}//end :)
	
