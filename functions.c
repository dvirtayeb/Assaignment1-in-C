#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<time.h> 

#include "functions.h"

#define SHUFFLE_TIMES 3

void printArr(int* arr,int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("{");
		for(int j =0; j<size ; j++)
			printf("%d ",*(arr +i*size +j));
		printf("}\n");
	}
}

void printMatrix(int* arr,int n,int m)
{
	for(int i=0; i<n;i++)
	{
	printf("{");
	for(int j=0; j<m ; j++)
		printf("%d ",*(arr+i*m+j));
	printf("}\n");
	}
}

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
			printArr(arr, size);
		}
		else if(choose == 2)
		{
			printf("----- after move against the clock ------\n");
			arr = moveAgainstClock(arr, size);
			printArr(arr, size);
		}
		else if(choose == 3)
		{
			arr = moveHorizontal(arr,size);
			printArr(arr, size);
			
		}
		else if(choose == 4)
		{
			arr = moveVertical(arr,size);
			printArr(arr, size);
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
int* setArrayForNumGame(int* arr,int size)
{
	int i;
	for(i = 0; i < size-1; i++)
		 *(arr+i) = i+1;
	*(arr+size-1)=0;
	
	return arr;
	
}
int* shuffleArray(int* arr,int n,int m,int* zeroIndex)
{	
	int dice;
	int invalidMove;
	do{
		
		dice=rand() % 100;
		
		if(dice<25){
			invalidMove=moveUp(arr,m,zeroIndex);
			//printf("up");
			}
		else if(dice<50){
			invalidMove=moveDown(arr,n,m,zeroIndex);
			//printf("down");
			}
		else if(dice<75){
			invalidMove=moveRight(arr,n,m,zeroIndex);
			//printf("Right");
			}
		else if(dice<100){
			invalidMove=moveLeft(arr,n,m,zeroIndex); 
			//printf("Left");
			}
	}
	while (!invalidMove);	
	return arr;
}
int moveUp(int* arr,int m,int* zeroIndex){ 
	int tempIndex=*zeroIndex-m;
	if(*zeroIndex>0&&*zeroIndex<m)
		return 0;
	
	swap((arr+(*zeroIndex)),(arr+(*zeroIndex-m)));
	*zeroIndex=tempIndex;
	
	return 1;	
}
int moveDown(int* arr,int n,int m,int* zeroIndex){ 
	int tempIndex=*zeroIndex+m;
	if(*zeroIndex>((n*m)-m)&&*zeroIndex<n*m)
		return 0;
	
	swap((arr+(*zeroIndex)),(arr+(*zeroIndex+m)));
	*zeroIndex=tempIndex;
	
	return 1;	
}
int moveRight(int* arr,int n,int m,int* zeroIndex){ 
	int tempIndex=*zeroIndex+1;
	if(checkRight(arr,n,m,0))
		return 0;
	
	swap((arr+(*zeroIndex)),(arr+(*zeroIndex+1)));
	*zeroIndex=tempIndex;
	
	return 1;	
}
int moveLeft(int* arr,int n,int m,int* zeroIndex){ 
	int tempIndex=*zeroIndex-1;
	if(checkLeft(arr,n,m,0))
		return 0;
	
	swap((arr+(*zeroIndex)),(arr+(*zeroIndex)-1));
	*zeroIndex=tempIndex;
	
	return 1;	
}
int checkLeft(int* arr,int n,int m,int num) {
	for(int i=0; i<n;i++)
	{
		if((*(arr+(m*i)))==num)
			return 1;
	}
	return 0;
}
int checkRight(int* arr,int n,int m,int num) {
	for(int i=0; i<n;i++)
	{
		if((*(arr+((m*i)-1))==num))
			return 1;
	}
	return 0;
}


void runGame(int* arr,int n,int m,int* zeroIndex){
	int numToSwitch;
	int checkWin=0;
	arr=setArrayForNumGame(arr,n*m);
	//printf("STOP SIGN");
	for(int i=0;i<SHUFFLE_TIMES;i++)
	{
	arr=shuffleArray(arr,n,m,zeroIndex);
	}
	printMatrix(arr,n,m);
	printf("Welcome to the Number-Game \n In each step, you choose a number that is near the '0',\n in order to get the 0 into the bottom right corner with all the numbers are set by order\n");
	while(!checkWin)
	{
		printf("Your Step:\n");
		do{
			scanf("%d",&numToSwitch);

		}while(isspace(numToSwitch));
		int validStep=moveZeroToNum(arr,n,m,zeroIndex,numToSwitch);
		printf("valid Step = %d \n",validStep);
		if(!validStep)
		{	
			printf("0:%d \n",*zeroIndex);
			printf("Invalid Step!\n");
		} 
		else 
		{
			printf("0:%d \n",*zeroIndex);
			printMatrix(arr,n,m);
			checkWin=checkGameOver(arr,n*m);
		}
	
	}

}
int moveZeroToNum(int* arr,int n,int m,int* zeroIndex,int num){
	if(num>=n*m||num<=0)
		return 0;
	int numIndex = Search(arr,n*m,num);
	printf("the required number index : %d \n",numIndex);
	int check= *zeroIndex - numIndex;
	int left=checkLeft(arr,n,m,0);
	int right=checkRight(arr,n,m,0);
	if((check==1&&!left)||(check==-1&&!right)||check==m||check==-m)
	{
		swap(arr+(*zeroIndex),arr+numIndex);
		*zeroIndex=numIndex;
		return 1;
	}  
	return 0;
	

}
int checkGameOver(int* arr,int size){
	for(int i=0;i<size-1;i++)
	{
		if(*(arr+i)!=i+1)
			return 0;
	}
	if(*(arr+size-1))
	{
		printf("Congrationlations! YOU ARE A GENIUS ! YOU WON !");
		return 1;
	}
	return 0;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b= temp;
}
int Search(int* arr, int size, int find) {
  	for(int i=0;i<size;i++)
  	{
  		if(*(arr+i)==find)
  			return i;
  	}
  	return -1;	
}



