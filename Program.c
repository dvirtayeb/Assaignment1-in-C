#include <stdio.h>
#include <ctype.h>
#include "exe.h"

int main() {
	//recursion(4);
	char n;
	do
	{
		printf("Hello, plaese choose one of the following options\n");
		printf("P/p - Picture Manipultion\nN/n - Number Game\nE/e - Quit\n");
		do
		{
			scanf("%c",&n);
		}while(isspace(n));
		switch(n)
			{
			case 'p': case 'P':
				pictureManipulation();
				printf("If you want to exit press the char E/e\n");
				break;
			case 'n': case 'N':
				numberGame();
				printf("If you want to exit press the char E/e\n");
				break;
			case 'e': case 'E':
				printf("Bye bye\n");
				return 0;
			default:
				printf("Wrong input, please try again\n");
			}
	}while((n != 'e') || (n != 'E'));
	return 0;
}
