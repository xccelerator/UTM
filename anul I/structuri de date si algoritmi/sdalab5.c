#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int n){
	int *arr = (int*)malloc(n * sizeof(int));
	if(arr == NULL){
		printf("\nNu sa primit de alocat memoria.\n");
		return;
	}
	int temp;

	for(int i = 0; i < n; i++)
		arr[i] = rand() % n;

	/*
	printf("Tabloul nesortat:\n");
	for(int i = 0; i < n; i++)
		printf("%d ",arr[i]);
	*/

	clock_t begin = clock();

	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < n - i - 1; j++)
			if(arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}

	clock_t end = clock();

	printf("Tabloul a fost sortat in %f secunde.\n\n", (float)(end - begin) / CLOCKS_PER_SEC);

	/*
	printf("\nTabloul sortat:\n");
	for(int i = 0; i < n; i++)
		printf("%d ",arr[i]);
	*/
	free(arr);
}

void merge(int arr[], int l, int m, int r){
	int n1 = m - l + 1; 
	int n2 = r - m;

	int L[n1], R[n2];

	for(int i = 0; i < n1; i++)
		L[i] = arr[l + i];

	for(int i = 0; i < n2; i++)
		R[i] = arr[m + 1 + i];

	int i = 0, j = 0, k = l;

	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r){
	if(l < r){
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void mergeSortFunc(int n){
	int *arr = (int*)malloc(n * sizeof(int));
	if(arr == NULL){
		printf("\nNu sa primit de alocat memoria.\n");
		return;
	}
	int temp;

	for(int i = 0; i < n; i++)
		arr[i] = rand() % n;

	/*
	printf("Tabloul nesortat:\n");
	for(int i = 0; i < n; i++)
		printf("%d ",arr[i]);
	*/

	clock_t begin = clock();

	mergeSort(arr, 0, n - 1);

	clock_t end = clock();

	printf("Tabloul a fost sortat in %f secunde.\n\n", (float)(end - begin) / CLOCKS_PER_SEC);

	/*
	printf("\nTabloul sortat:\n");
	for(int i = 0; i < n; i++)
		printf("%d ",arr[i]);
	*/
	free(arr);
}

int main(){
	srand(time(NULL));

	printf("Merge sort cu 100 elemente:\n");
	mergeSortFunc(100);
	printf("Merge sort cu 1000 elemente:\n");
	mergeSortFunc(1000);
	printf("Merge sort cu 10000 elemente:\n");
	mergeSortFunc(10000);
	printf("Merge sort cu 100000 elemente:\n");
	mergeSortFunc(100000);

	printf("Bubble sort cu 100 elemente:\n");
	bubbleSort(100);
	printf("Bubble sort cu 1000 elemente:\n");
	bubbleSort(1000);
	printf("Bubble sort cu 10000 elemente:\n");
	bubbleSort(10000);
	printf("Bubble sort cu 100000 elemente:\n");
	bubbleSort(100000);

	return 0;
}
