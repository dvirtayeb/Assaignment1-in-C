#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<time.h>

#include "exe.h"
#include "functions.h"

#define SHUFFLE_TIMES 10

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
	printArr(pointerArr,n);
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
	
	int size=n*m;
	int arr[n][m];
	int *pointerArr = &arr[0][0];
	int zeroIndex=n*m-1;
	pointerArr=setArrayForNumGame(pointerArr,size);
	//printf("STOP SIGN");
	for(int i=0;i<SHUFFLE_TIMES;i++)
	{
	pointerArr=shuffleArray(pointerArr,n,m,&zeroIndex);
	printMatrix(pointerArr,n,m);
	}
	
	
	
	//runGame(n,m);
	
	printf("numberGame!\n");
}


