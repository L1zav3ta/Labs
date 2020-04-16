//lab #2 on the toopic of Graphs
/*The user sets a directed graph, 
	each edge is assigned the cost of the path between the vertices. Kruskal's algorithm.*/
//by Medvedeva Elizaveta IVT-13BO

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//#include "TheDirectedGraph.h"

int main() {
	int **arr1, *arr2, i, j, countVert, countEdg = 0;

	printf("Enter the number of vertexes:\n");
	if (scanf("%d", &countVert) == 0 || countVert <= 0) {
		printf("input error\n\n");
		system("pause");
		return;
	}

	//Memory allocation for the adjencency matrix:
	if (!(arr1 = (int**)malloc(countVert * sizeof(int*))))
		return;
	for (i = 0; i < countVert; i++)
		arr1[i] = (int*)malloc(countVert * sizeof(int));

	//Sample output: 
	printf("\nYour matrix look like:\n");
	Matrix_Vertex(arr1, countVert);
	
	i = 0;
	j = 0;

	//Filling adjencency matrix
	Adjencency_Matrix(arr1, countVert, i,j);
	
	//Output adjencency matrix:
	printf("\nYour matrix for graph:\n");
	Output_Adjencency_Matrix(arr1, countVert);
	
	//Counts the number of edges:
	countEdg = Count_Edges(arr1, countVert);
	printf("\n\nNumber of edges: %2d", countEdg);

	//Memory allocation for the matrix of edges:
	if (!(arr2 = (int*)malloc(countEdg * sizeof(int))))
		return;
	
	printf("\n\nArray of edges:\n");
	Matrix_Edges(arr1, countVert, arr2, countEdg);

	

	printf("\n");
	free(arr1);
	free(arr2);
	system("pause");
	return;
}
	
		





	

