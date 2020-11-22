#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<time.h>

#include "exe.h"
#include "functions.h"
#include "functions2.h"


void pictureManipulation()
{
	int n;
	printf("Choose number between 2-4: ");
	do{
		scanf("%d",&n);
	}while(isspace(n) || n>8 || n<2);
	int arr[n][n];
	int *pointerArr = &arr[0][0];
	pointerArr = setArray(pointerArr,n);
	printMatrix(pointerArr,n,n);
	menu(pointerArr, n);
}
void numberGame()
{	
	srand(time(0));
	int n, m;
	printf("Choose Vertical size for the game board: ");
	do{
		scanf("%d",&n);
	}while(isspace(n) || n<0);
	printf("Choose Horizonal size for the game board: ");                                             
	do{
		scanf("%d",&m);
	}while(isspace(m) || m<0);
	
	int arr[n][m];
	int *pointerArr = &arr[0][0];
	int zeroIndex=n*m-1;
	runGame(pointerArr,n,m,&zeroIndex);
	
	printf("That Was The Number Game!!\n");
}



