//function, need for work

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "TheDirectedGraph.h"

//Fills the matrix with 0:
void Init_Adjencency_Matrix(int **adjencencyMatrix, int countVert) {
	int i, j;

	for (i = 0; i < countVert; i++) {
		for (j = 0; j < countVert; j++)
			adjencencyMatrix[i][j] = 0;
	}

	for (i = 0; i < countVert; i++)
		printf("%3c ", 'A' + i);

	for (i = 0; i < countVert; i++) {
		printf("\n%c", 'A' + i);
		for (j = 0; j < countVert; j++)
			printf(" %d  ", adjencencyMatrix[i][j]);
	}
	return;
}

//Reads the weight of the paths from "arrayEdges" to "b":
void Create_Adjencency_Matrix(int **adjencencyMatrix, int countVert, int startStr, int startCol) {
	int i, j, weight;	
	for (i = startStr; i < countVert; i++) {
		for (j = startCol; j < countVert; j++) {
			if (i < j) {
				printf("\n Enter the way weight from %c to %c ( between 0 and 99) ", 'A' + i, 'A' + j);

				if (!(scanf("%d", &weight)) || weight < 0 || weight > 99) {
					printf("\nweight error, try again\n");
					system("pause");
					return;
					//Create_Adjencency_Matrix(adjencencyMatrix, countVert, i, j);
				}

				adjencencyMatrix[i][j] = weight;
				adjencencyMatrix[j][i] = weight;
			}
		}
	}

	return;
}

//Outputs an ajencency matrix with path weights:
void Output_Adjencency_Matrix(int **adjencencyMatrix, int countVert) {
	int i, j;

	for (i = 0; i < countVert; i++)
		printf(" %2c", 'A' + i);

	for (i = 0; i < countVert; i++) {
		printf("\n%c", 'A' + i);
		for (j = 0; j < countVert; j++)
			printf(" %2d", adjencencyMatrix[i][j]);
	}
	return;
}

//Counts the number of non-zero elements 
//	in the upper-triangular matrix = the number of edges:
int Count_Edges(int **adjencencyMatrix, int countVert) {
	int i, j, count = 0;

	for (i = 0; i < countVert; i++) {
		for (j = 0; j < countVert; j++) {
			if (i < j && adjencencyMatrix[i][j] != 0)
				count++;
		}
	}
	return count;
}

//Matrix of edges:
void Matrix_Edges(int **adjencencyMatrix, int countVert, Edges_t *arrayEdges) {
	int i, j, p;

	p = 0; 
	for (i = 0; i < countVert; i++) {
		for (j = 0; j < countVert; j++) {
			if (i < j && adjencencyMatrix[i][j] != 0) {
				arrayEdges[p].weight = adjencencyMatrix[i][j];
				arrayEdges[p].idxStart = i;
				arrayEdges[p].idxFinish = j;
				printf("%c -> %c = %d\n", 'A' + arrayEdges[p].idxStart, 'A'+ arrayEdges[p].idxFinish, arrayEdges[p].weight);
				p++;
			}
		}
	}
	return;
}
				
//Sort for arrayEdges:
Edges_t* Sort_Array_Edg(Edges_t *arrayEdges, int countEdg) {
	int i, j, tmp;

	for (i = 0; i < countEdg; i++) {
		for (j = i + 1; j < countEdg; j++) {
			if (arrayEdges[i].weight > arrayEdges[j].weight) {
				tmp = arrayEdges[i].idxStart;
				arrayEdges[i].idxStart = arrayEdges[j].idxStart;
				arrayEdges[j].idxStart = tmp;

				tmp = arrayEdges[i].weight;
				arrayEdges[i].weight = arrayEdges[j].weight;
				arrayEdges[j].weight = tmp;


				tmp = arrayEdges[i].idxFinish;
				arrayEdges[i].idxFinish = arrayEdges[j].idxFinish;
				arrayEdges[j].idxFinish = tmp;

			}
		}
	}
	
	return arrayEdges;
}

//Kruskal's algorithm:
void Kruskal_Algorithm(Edges_t *arrayEdges, int countEdges) {
	int i;
	
	arrayEdges = Sort_Array_Edg(arrayEdges, countEdges);
	
	printf("Sorted an array of edges:\n");
	for (i = 0; i < countEdges; i++) 
		printf("%c -> %c = %d\n", 'A' + arrayEdges[i].idxStart, 'A' + arrayEdges[i].idxFinish, arrayEdges[i].weight);
	
	printf("Minimum spanning tree:\n");
	//output first edge:
	printf("%c -> %c = %d\n", 'A' + arrayEdges[0].idxStart, 'A' + arrayEdges[0].idxFinish, arrayEdges[0].weight);
	
	//output tree without first edge:
	for (i = 0; i < countEdges; i++) {
		if (arrayEdges[i].idxFinish != arrayEdges[0].idxStart &&
				arrayEdges[i].idxFinish != arrayEdges[0].idxFinish &&
					arrayEdges[i].idxStart != arrayEdges[0].idxFinish) {
			printf("%c -> %c = %d\n", 'A' + arrayEdges[i].idxStart, 'A' + arrayEdges[i].idxFinish, arrayEdges[i].weight);
		}
	}
	return;
}
