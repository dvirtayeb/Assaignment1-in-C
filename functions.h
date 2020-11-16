#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

void printArr(int* arr,int size);
int* setArray(int* arr,int size);
void menu(int* arr, int size);
void selecting(int choose, int* arr, int size);
int* moveByClockwise(int* arr, int size);
int* moveAgainstClock(int* arr, int size);
int* moveHorizontal(int* arr, int size);
int* moveVertical(int* arr, int size);
void swap(int* a, int* b);
//void numGame(
int moveLeft(int* arr,int n,int m,int* zeroIndex);
int moveRight(int* arr,int n,int m,int* zeroIndex);
int moveDown(int* arr,int n,int m,int* zeroIndex);
int moveUp(int* arr,int m,int* zeroIndex);
int* setArrayForNumGame(int* arr,int size);
int* shuffleArray(int* arr,int n,int m,int* zeroIndex);
void printMatrix(int* arr,int n,int m);


#endif
