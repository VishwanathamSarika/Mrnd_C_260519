#include<stdio.h>
#include<stdlib.h>
void transpose();

void transpose()
{
	int m, n,i,j;
	printf("\nEnter the size of matrix: ");
	scanf_s("%d %d", &m, &n);
	int **original = (int **)malloc(m*sizeof(int *));
	for (i = 0; i < m; i++){
		original[i] = (int *)malloc(n*sizeof(int));
	}
	int **transpose = (int **)malloc(n*sizeof(int *));
	for (i = 0; i < n; i++){
		transpose[i] = (int *)malloc(m*sizeof(int));
	}
	printf("\nEnter the data for the matrix: ");
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			printf("\nEnter value of [%d][%d]: ", i, j);
			scanf_s("%d", &original[i][j]);
			transpose[j][i] = original[i][j];
		}
	}
	printf("\nOriginal matrix is:\n");
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			printf("\t%d", original[i][j]);
		}
		printf("\n");
	}
	printf("\nTranspose matrix is:\n");
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			printf("\t%d", transpose[i][j]);
		}
		printf("\n");
	}
	return;
}
