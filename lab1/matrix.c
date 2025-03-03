/* 	matrix.c: 	multiplying two 2x2 matrices 		*/
/* 	author: 	Jonathan Lin 						*/
/* 	date: 		1/14/2025							*/

#include <stdio.h>

void inputMatrix(int n, int a[n][n], int b[n][n]) {

}

void validate() {
	return 0;
}

void axb(int n, int a[n][n], int b[n][n], int c[n][n]) {
	c[0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
	c[1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
	c[2] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
	c[3] = a[1][0]*b[0][1] + a[1][1]*b[1][1];	

}

int main (void) { 

	/* variable declarations */
	int a[2][2] = {0};
	int b[2][2] = {0}; 		// b[0][0]=b11 , b[0][1]=b12 , b[1][0]=b21 , b[1][1]=b22 
	int c[2][2]	= {0};		// resulting matrix from multiplication	
	int n = 2;
	int index = 0;			// keep track of array index
	char arr = 'a';		
	int printed = 0;
	
	/* 	Input section 	*/
	printf("Enter the first matrix(a) that will be multiplied:\n");	


	do {
		if (index == 0 || index == 4){
			if (index == 4) {
				if (!printed) {
					printf("\nEnter the second matrix(b) that will be multiplied:\n");
					printed = 1;
					arr = 'b';
				}
				
			}
		} else if (index == 1 || index == 5) {	
			pos = 12;
		} else if (index == 2 || index == 6) {
			pos = 21;

		} else if (index == 3 || index == 7 ) {
			pos = 22; 
		}
		printf("%c%d = ", arr, index);

		int userinput;
		char term;
		if ( scanf("%d%c", &userinput, &term) != 2 || term != '\n') {		// the trailing char term should be '\n' for valid input
			printf("ERROR: Invalid input. Please enter numbers only!\n");
			while (getchar() != '\n'); 	// clear the input buffer 
			continue; 					// take input again
		}
		else {
			if (arr == 'a') {
				a[index] = userinput;
			} else if (arr == 'b') {
				b[index-4] = userinput;
			}
			
			index ++;			// valid input was stored, increment index
		}

	} while ( (index != 8) );  	// loop while both matrix have not yet been filled completely   


	/* 		Compute 	*/
	axb(a, b, c, n);

	/* 		Output 		*/
	printf("\nResult:\n");
	printf("%d ", c[0]);	
	printf("%d", c[1]);
	printf("\n%d ", c[2]);
	printf("%d", c[3]);

} /* End of main function */

/* EOF */
