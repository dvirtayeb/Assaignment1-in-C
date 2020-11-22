#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<time.h> 

#include "functions.h"
#include "functions2.h"


int* setArray(int* arr,int size)
{
	srand(time(0)); 
	int i,j;
	for(i = 0; i < size; i++)
		for(j=0 ; j< size; j++)
		 	*(arr + i*size +j) = rand()%100;
	return arr;
}


void menu(int* arr,int size)
{
	int choose;
	do{
		printf("Please choose one of the following options:\n 1 - 90 degree clockwise\n 2 - 90 degree counter clockwise\n 3 - flip Horizontal\n 4 - Flip Vertical\n-1 - Quit\n");
		do{
		scanf("%d", &choose);
		if(choose <-1 || choose >4)
			printf("Wrong input, try again: \n");
		}while(isspace(choose) || choose < -1 || choose > 4);
		selecting(choose, arr, size);
	}while(choose != -1);
			
}

void selecting(int choose, int* arr, int size)
{
		if(choose == 1)
		{
			printf("----- after move clockwise ------\n");
			arr = moveByClockwise(arr, size);
			printMatrix(arr, size,size);
		}
		else if(choose == 2)
		{
			printf("----- after move against the clock ------\n");
			arr = moveAgainstClock(arr, size);
			printMatrix(arr, size,size);
		}
		else if(choose == 3)
		{
			arr = moveHorizontal(arr,size);
			printMatrix(arr, size,size);
			
		}
		else if(choose == 4)
		{
			arr = moveVertical(arr,size);
			printMatrix(arr, size,size);
		}
		else
		{
			printf("Game is over.");
		}
}

 int* moveByClockwise(int* arr, int size)
{
	int i,j;
	for(i = 0; i < (size/2); i++)
		{
			for(j = i ; j < (size-i-1); j++)
			{
				int temp = *(arr + i*size +j);
				*(arr+i*size+j)= *(arr+((size-1-j)*size)+i);
				*(arr+((size-1-j)*size)+i) = *(arr+((size-1-i)*size)+(size-1-j));
				*(arr+((size-1-i)*size)+(size-1-j)) = *(arr+(j*size)+(size-1-i));
				*(arr+(j*size)+(size-1-i)) = temp;	
			
			}
		}
	return arr;
}

int* moveAgainstClock(int* arr, int size)
{
	int i,j;
	for(i = 0; i < size/2; i++)
		for(j = i ; j < (size-i-1); j++)
		{
			int temp = *(arr + i*size +j);
			*(arr+i*size+j)= *(arr+(j*size)+(size-1-i));
			*(arr+(j*size)+(size-1-i)) = *(arr+((size-1-i)*size)+(size-1-j));
			*(arr+((size-1-i)*size)+(size-1-j)) = *(arr+((size-1-j)*size)+i);
			*(arr+((size-1-j)*size)+i) = temp;
		}
	return arr;
}

int* moveVertical(int* arr, int size)
{
	int i,j;
	for(i = 0; i < size/2; i++)
		for(j = 0; j < size ; j++)
		{
			int temp = *(arr+j*size+i);
			*(arr+j*size+i) = *(arr+(j*size)+((size-1)-i));
			*(arr+(j*size)+((size-1)-i)) = temp;
		}
	return arr;
}

int* moveHorizontal(int* arr, int size)
{
	int i,j;
	for(i = 0; i < size/2; i++)
		for(j = 0; j < size ; j++)
		{
			int temp = *(arr + i*size +j);
			*(arr+i*size+j)= *(arr+(((size-1)-i)*size)+(j));
			*(arr+((size-1)-i)*size+(j)) = temp;
		}
	return arr;
}

