#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void main()
{
	int num1 = 45;
	int num2 = 898;
	printf("num1 = %d num2 = %d\n", num1, num2);
	swap(&num1, &num2);
	printf("num1 = %d num2 = %d", num1, num2);
}