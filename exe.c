#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "exe.h"
#include "functions.h"

void pictureManipulation()
{
	int n;
	printf("Choose number between 2-4: ");
	do{
		scanf("%d",&n);
	}while(isspace(n) || n>4 || n<2);
	int arr[n][n], temp[n][n];
	int *pointerArr = &arr[0][0];
	int *pointertemp = &temp[0][0];
	pointerArr = setArray(pointerArr,n);
	printArr(pointerArr,n);
	menu(pointerArr, pointertemp, n);
}
void numberGame()
{
	printf("numberGame!\n");
}


