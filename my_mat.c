#include <stdio.h>
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
#include <limits.h>
#include "my_mat.h"

int mat[n][n];
void recive_mat() 
{
	//Recive the mat
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &mat[i][j]);
			//The diagonal stays zeros, 
			//and the othor zeroz become (MaxInt / 2) represent infinty
			if (i!=j && mat[i][j]==0)
			{
				mat[i][j] = INT_MAX/2;
			}
		}
	}
	//The Floyd Warshall Algorithm
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			//skip the k'th row
			if (k == i)
				continue;
			for (int j = 0; j < n; j++)
			{
				//skip the k'th colmn and the diagonal 
				if (i == j && k == j)
					continue;
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
}
//in O(1) prints if there is a path or not
void hasPath(int i, int j) 
{
	if (i == j || mat[i][j] == INT_MAX / 2)
	{
		printf("False\n");
	}
	else
	{
		printf("True\n");
	}
}
//in O(1) prints the shorthest path or -1 if no path is exist
void shortestPath(int i, int j) 
{
	if (i==j || mat[i][j] == INT_MAX / 2)
	{
		printf("-1\n");
	}
	else 
	{
		printf("%d\n", mat[i][j]);
	}
}
