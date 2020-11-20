#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<time.h>

#include "exe.h"
#include "functions.h"



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
	
	int arr[n][m];
	int *pointerArr = &arr[0][0];
	int zeroIndex=n*m-1;
	runGame(pointerArr,n,m,&zeroIndex);
	
	printf("That Was The Number Game!!\n");
}
void recursion (int n)
{
	int arr[n];
	int counter=0;
	recHelper(n,&arr[0],0,&counter);
	printf("Number of sub-Groups are:%d",counter);

}

void recHelper(int n,int* arr,int index,int* counter) // !0 = true 0 = false;
{
	if(!n)
	{
		print2DArr(arr,index);
		(*counter)++;
		return ;
	}
	if(n<0)
		return;
	for(int i=1;i<=n;i++)
	{
		*(arr+index)=i;
		recHelper(n-i,arr,index+1,counter);
	}

}

void print2DArr(int* arr,int length)
{
	printf("[");
	for(int i=0;i<length;i++)
	{
		printf("%d",*(arr+i));
		if(i!=length-1)
			printf(",");
	}
	printf("]\n");

}


