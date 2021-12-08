#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int lookForMax(int*, int);
int sumAfterMax(int*, int);

int main()
{
	int* arr;
	int amountOfElements, maximum, sumarize;
	printf("Please enter an amount of elements: ");
	scanf_s("%d", &amountOfElements);
	if(amountOfElements <= 0){
		printf("Wrong amount of elements\a");
	} else{
		arr = (int*)malloc(sizeof(int) * amountOfElements);//Динамическое выделение памяти под массив
		if (arr == NULL) {
			printf("An error in memory allocation has occured\a");
			free(arr);
			return 0;
		}
		for (int i = 0; i < amountOfElements; i++){
			printf("array[%d] = ", i);
			scanf_s("%d", &*(arr + i));
		}
		sumAfterMax(arr, amountOfElements);
		free(arr);
		printf("\n");
	}
	return 0;
}

int lookForMax(int* arrayName, int arraySize)
{
	int indexOfMax = 0, max = *(arrayName + 0);
	for (int i = 1; i < arraySize; i++){
		if (*(arrayName + i) > max){
			max = *(arrayName + i);
			indexOfMax = i;
		}
	}
	return(indexOfMax);
}

int sumAfterMax(int* arrayName, int arraySize)
{
	int maxIndex, sum = 0;
	maxIndex = lookForMax(arrayName, arraySize);
	int i = maxIndex + 2;
	if (i > arraySize - 1){
		printf("There are not enough elements to find sum");
	}
	else
	{
		while (i < arraySize) {
			if (*(arrayName + i) > *(arrayName + maxIndex) / 2) {
				sum = sum + *(arrayName + i);
			}
			i = i + 2;
		}
		printf("Sum = %d, index of maximum = %d", sum, maxIndex);
	}
	return 0;
}