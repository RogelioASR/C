#include<stdio.h>

void expand(char s1[], char s2[]) { 
	
	int i; //contador de s1
	int k; //contador de s2
	char u; //letra final
	char v; //letra inicial/contador
	int p; //replica de i
	
	for (i = 0; s1[i] != '\0'; i++) {
		if(s1[i] >= 'a' && s1[i] <= 'z') {
			p = i + 1;
			if(s1[p++] == '-') {
				u = s1[p];
				for(v = s1[i]; v != (u + 1); v++) {
					s2[k++] = v;
				}
			}	
		//	else {
		//		p--;
		//		s2[p] = s1[k];
		//		k++;
		//	}
		/*		if(s1[p++] == '-') {
				if (s1[i] > s1[p]) {
				}
					u = s1[p];
					for(v = s1[i]; v != (u + 1); v++) {
						s2[k++] = v;
					}
				else 
					for(p = i; k != p; p++) {
						s2[k++] = s1[p];
				}
			}*/
		}
	}
/*		switch (s1[i]) {
			
			case 'a': while ()
			case 'a': if (x == 0) x = 1; break;
			case 'A': if (x == 0) x = 3; break;
			case '0': if (x == 0) x = 5; break;	
			
			case '-': if ((x % 2) == 1) x++; else s2[k++] = s1[i]; break;
			
			case 'z': if (x == 2) for(j = 'a'; j != ('z' + 1); j++) s2[k++] = j; else s2[k++] = s1[i]; x = 0; break;
			case 'Z': if (x == 4) for(j = 'A'; j != ('Z' + 1); j++) s2[k++] = j; else s2[k++] = s1[i]; x = 0; break;
			case '9': if (x == 6) for(j = '0'; j != ('9' + 1); j++) s2[k++] = j; else s2[k++] = s1[i]; x = 0; break;	
		
			default : if(x == 1) s2[k++] = 'a'; if(x == 3) s2[k++] = 'A'; if(x == 5) s2[k++] = '1'; 
				if(x == 2) { s2[k++] = 'a'; } if(x == 4) { s2[k++] = 'A'; s2[k++] = '-'; }
				if(x == 6) { s2[k++] = '0'; s2[k++] = '-'; }
				s2[k++] = s1[i];  x = 0; break;
		}
	}*/
		
	printf("\n%s", s2);
	
}

main() {

	int c, i = 0;
	char s1[500], s2[1000];

	for (i = 0; (c = getchar()) != EOF && c != '\n' ; i++) 
			s1[i] = c;

	s1[i++] = '\0';

	expand(s1, s2);

} 
