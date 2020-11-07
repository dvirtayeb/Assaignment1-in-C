#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "functions.h"

void printArr(int* arr,int size)
{
	int* tempArr = arr;
	for(int i = 0; i < size; i++)
	{
		printf("{");
		for(int j =0; j<size ; j++)
			printf("%d ",*(tempArr +i*size +j));
		printf("}\n");
	}
}

int* setArray(int* arr,int size)
{
	int* tempArr = arr;
	int i,j;
	for(i = 0; i < size; i++)
		for(j=0 ; j< size; j++)
		 	*(tempArr + i*size +j) = rand()%100;
	return tempArr;
}

void menu(int* arr,int* temp,int size)
{
	int choose;
	do{
		printf("Please choose one of the following options:\n 1 - 90 degree clockwise\n 2 - 90 degree counter clockwise\n 3 - flip Horizontal\n 4 - Flip Vertical\n-1 - Quit\n");
		do{
		scanf("%d", &choose);
		if(choose <-1 || choose >4)
			printf("Wrong input, try again: \n");
		}while(isspace(choose) || choose < -1 || choose > 4);
		if(choose == 1)
		{
			printf("----- after move clockwise ------\n");
			arr = moveByClockwise(arr, temp, size);
			printArr(arr, size);
		}
		else if(choose == 2)
		{
			printf("----- after move against the clock ------\n");
			arr = moveAgainstClock(arr, temp, size);
			printArr(arr, size);
		}
		else if(choose == 3)
		{}
		else if(choose == 4)
		{}
		else
			printf("Game is over.");
	}while(choose != -1);
			
}

int* moveByClockwise(int* arr,int* temp, int size)
{
	int* tempArr = arr;
	int* tempArr2 = temp;
	int i,j;
	for(i = 0; i < size; i++)
		for(j=0 ; j< size; j++)
			*(tempArr2 + ((size-1)-i) +j*size)= *(tempArr + i*size +j);	
	return tempArr2;
}

int* moveAgainstClock(int* arr,int* temp,int size)
{
	int* tempArr = arr;
	int* tempArr2 = temp;
	int i,j;
	for(i = 0; i < size; i++)
		for(j=0 ; j< size; j++)
			*(tempArr2 + i*size +j) = *(tempArr + ((size-1)-i) +j*size);
	return tempArr2;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b= temp;
}

