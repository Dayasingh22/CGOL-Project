/*
 ============================================================================
 Name        : CGOL.c
 Author      : Dayanidhee Singh
 Version     : 1.00
 Copyright   : @Daya
 Description : Program of CGOL which I made for the Project using all the rules of CGOL
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Global function
void nextLife(int arr[100][100], int r, int c);
// Global Variable
int futureLife[100][100], arr[100][100];

int main(void) {

	//Used to get the print statement first while using scanf function
	setbuf(stdout, NULL);
	// Variables
	int r,c, i, j;
	char run;
	printf("Enter the no of rows of the Array:\n");
	scanf("%d", &r);
	printf("Enter the no of columns of the Array:\n");
	scanf("%d", &c);


	printf("0 is the dead cell and 1 is the alive cell, so enter according to it \n");
	printf("Enter the CGOL Array:\n");

	//Taking the input from the user
	for(i = 0; i<r; i++){
		for(j=0; j<c; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	//Calling the function and printing next life when user enter y
	do {
		nextLife(arr, r, c);
		printf("Enter the y for getting the next Generation of "
				"CGOL OR Enter any other character to stop the program: \n");
		scanf(" %c", &run);
	} while (run == 'y');

	//When user enter any other character then y, loop stops and print below message
	printf("Thank you for playing the game");

	return 0;
}

//Function which contain the logic for the next generation of CGOL
void nextLife(int arr[100][100], int r, int c){


	int i,j,k,l;

	// Loop through every cell of the every row and column
	for(i=1; i<r-1; i++){
		for(j=1; j<c-1; j++){

			// Find how many cells are alive
			int aliveCell = 0;
			for(k=-1; k<=1; k++)
				for(l=-1; l<=1; l++)
					aliveCell = aliveCell + arr[i+k][j+l];

			aliveCell = aliveCell - arr[i][j];

			// If cell is lonely then it dies
			if((arr[i][j] == 1) && (aliveCell < 2)){
				futureLife[i][j] = 0;
			}

			// If cell is overpopulated it dies
			else if((arr[i][j] == 1) && (aliveCell > 3)){
				futureLife[i][j] = 0;
			}

			// A new cell is born as 3 adjacent cells are alive
			else if((arr[i][j] == 0) && (aliveCell ==3)){
				futureLife[i][j] = 1;
			}

			// Nothing happens so it remains same
			else{
				futureLife[i][j] = arr[i][j];
			}
		}
	}

	printf("\n");
	printf("Next Life is: \n");

	// Printing the next life
	for(k=0; k<r; k++){
		for(l=0; l<c; l++){
			printf("%d ", futureLife[k][l]);
		}
		printf("\n");
	}

	//Assigning the next life to the main array to print further generation
	for (k = 0; k < r; k++) {
		for (l = 0; l < c; l++) {
			arr[k][l] = futureLife[k][l];
		}
	}
}
