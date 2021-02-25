#include <stdio.h>
#include <string.h> // strstr

#define MAX 300

char linea[MAX];

int main() {
  extern char linea[];
  int c, i = 0;
  int sc = 0;
  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '>';) {
    if (c == '<') {
      sc++;
      if (sc == 1) {
	i--;
      }
    } else if (sc < 1) {
      sc = 0;
    }
    if (sc < 2) {
      linea[i++] = c;
    }
  }
  linea[i] = '\0'; // caracter de terminacion de string
  return c == EOF;
}

int saca (){

    int c, cc = 0;
    c = getchar();
    while (c =! EOF){
         if (c = a '<'){
            cc = 1;
         } else {
            cc = 0;
         } if (cc = 0) {
            putchar (c);
         } else {
            putchar (' ');
         } if (c == '>'){
            cc = 0;
         }

    putchar (c);
    }

}
