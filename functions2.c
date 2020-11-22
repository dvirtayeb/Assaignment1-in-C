#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<time.h> 

#include "functions2.h"

#define SHUFFLE_TIMES 20

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
			}
		else if(dice<50 && dice >= 25){
			invalidMove=moveDown(arr,n,m,zeroIndex);
			}
		else if(dice<75 && dice >=50){
			invalidMove=moveRight(arr,n,m,zeroIndex);
			}
		else if(dice<100 && dice >= 75){
			invalidMove=moveLeft(arr,n,m,zeroIndex);
			}
	}
	while (!invalidMove);	
	return arr;
}
int moveUp(int* arr,int m,int* zeroIndex){ 
	int tempIndex=*zeroIndex-m;
	if((*zeroIndex>0) && (*zeroIndex<m))
	{
		return 0;
	}
	
	swap((arr+(*zeroIndex)),(arr+(*zeroIndex-m)));
	*zeroIndex=tempIndex;
	return 1;	
}
int moveDown(int* arr,int n,int m,int* zeroIndex){ 
	int tempIndex=*zeroIndex+m;
	if((*zeroIndex>=((n*m)-m)) && (*zeroIndex<n*m))
	{
		return 0;
	}
	swap((arr+(*zeroIndex)),(arr+(*zeroIndex+m)));
	*zeroIndex=tempIndex;
	
	return 1;	
}
int moveRight(int* arr,int n,int m,int* zeroIndex){ 
	int tempIndex=*zeroIndex+1;
	if(checkRight(arr,n,m,0))
	{
		return 0;
	}
	
	swap((arr+(*zeroIndex)),(arr+(*zeroIndex)+1));
	*zeroIndex=tempIndex;
	return 1;	
}
int moveLeft(int* arr,int n,int m,int* zeroIndex){ 
	int tempIndex=*zeroIndex-1;
	if(checkLeft(arr,n,m,0))
	{
		return 0;
	}
	
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
		if((*(arr+((m*i)+((m-1))))==num))
			return 1;
	}
	return 0;
}



void runGame(int* arr,int n,int m,int* zeroIndex){
	srand(time(0));
	
	arr=setArrayForNumGame(arr,n*m);
	printf("Init Array:\n");
	printMatrix(arr,n,m);
	printf("-------------------\n");
	for(int i=0;i<SHUFFLE_TIMES;i++)
	{
	arr=shuffleArray(arr,n,m,zeroIndex);
	}
	printf("The Matrix Shuffled:\n");
	printMatrix(arr,n,m);
	printf("Welcome to the Number-Game \nIn each step, you choose a number that is near the '0',\nin order to get the 0 into the bottom right corner with all the numbers are set by order\n");
	
	startTheSteps(arr,n,m,zeroIndex);
}
void startTheSteps(int* arr,int n,int m,int* zeroIndex)
{
	int numToSwitch;
	int checkWin=0;
	
	while(!checkWin)
	{
		printf("Your Step: ");
		scanf("%d",&numToSwitch);
		int validStep=moveZeroToNum(arr,n,m,zeroIndex,numToSwitch);
		if(!validStep)
		{	
			printf("Invalid Step!\n");
		} 
		else 
		{
			printMatrix(arr,n,m);
			checkWin=checkGameOver(arr,n*m);
		}
	}

}
int moveZeroToNum(int* arr,int n,int m,int* zeroIndex,int num){
	if(num>=n*m||num<=0)
		return 0;
	int numIndex = Search(arr,n*m,num);
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
		if(*(arr+i) != (i+1))
			return 0;
	}
	if(*(arr+size-1)==0)
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

