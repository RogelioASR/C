#include<stdio.h>

int binsearch(int x, int v[], int n);

main() {
	
	int x, b, n = 20;
	int v[20] = {1, 3, 4, 7, 9, 23, 25, 33, 38, 46, 52, 56, 63, 64, 74, 77, 81, 90, 99, 100};
	
	printf("Enter a number the number from 1 to 100: ");
	scanf("%i", &x);
	
	printf("\nThe number %i is ", x);
	binsearch(x, v, n) >= 0 ? printf("in the position: %i\n", binsearch(x, v, n)) : printf("not in the data\n");
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {

	int low = 0, high = n - 1, mid;

	while (low <= high) {
		mid = (low + high) / 2;	
		if (x < v[mid]) 
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* found match */
			return mid;
	}
	
	return -1; /* no match */

} 
 
