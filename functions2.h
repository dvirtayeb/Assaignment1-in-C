#ifndef FUNCTIONS2_H_
#define FUNCTIONS2_H_

void swap(int* a, int* b);
int moveLeft(int* arr,int n,int m,int* zeroIndex);
int moveRight(int* arr,int n,int m,int* zeroIndex);
int moveDown(int* arr,int n,int m,int* zeroIndex);
int moveUp(int* arr,int m,int* zeroIndex);
int* setArrayForNumGame(int* arr,int size);
int* shuffleArray(int* arr,int n,int m,int* zeroIndex);
void printMatrix(int* arr,int n,int m);
int moveZeroToNum(int* arr,int n,int m,int* zeroIndex,int num);
int checkGameOver(int* arr,int size);
int Search(int* arr, int size, int find);
void runGame(int* arr,int n,int m,int* zeroIndex);
int checkRight(int* arr,int n,int m,int num);
int checkLeft(int* arr,int n,int m,int num) ;
void startTheSteps(int* arr,int n,int m,int* zeroIndex);




#endif
