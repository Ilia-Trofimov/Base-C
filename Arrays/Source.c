#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void FillArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 50;
}

void PrintArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void DeleteRepElements(int* arr, int* size)
{
	int UniqCount = 0;
	int f;
	int tmp;
	for (int i = 0; i < *size; i++)
	{
		f = 1;
		for (int j = 0; j < *size; j++)
		{
			if (i != j && arr[i] == arr[j])
			{
				f = 0;
				break;
			}
		}
		if (f == 1)
		{
			tmp = arr[i];
			for (int j = i; j > UniqCount; j--)
				arr[i] = arr[i - 1];
			arr[UniqCount] = tmp;
			UniqCount++;
		}
	}
	*size = UniqCount;
}

void main()
{
	setlocale(0, "ru");
	srand(time(0));
	int* arr;
	int size;
	printf("¬ведите размер массива: ");
	scanf("%d", &size);
	// ¬ыделение пам€ти дл€ массива
	// (int*) приведение типа void* к типу int*
	// sizeof() - функци€, определ€юща€ размер типа в байтах
	// malloc() - функци€, выдел€юща€ пам€ть размера size
	arr = (int*)malloc(sizeof(int) * size);

	FillArray(arr, size);
	PrintArray(arr, size);
	DeleteRepElements(arr, &size);
	PrintArray(arr, size);
}