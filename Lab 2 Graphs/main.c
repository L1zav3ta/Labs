//lab #2 on the toopic of Graphs
/*The user sets a directed graph,
each edge is assigned the cost of the path between the vertices. Kruskal's algorithm.*/
//by Medvedeva Elizaveta IVT-13BO

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "TheDirectedGraph.h"

int main() {
	int **adjencencyMatrix, i, countVert, startStr, startCol, countEdg = 0;
	Edges_t *arrayEdges = NULL;

	printf("Enter the number of vertexes:\n");
	if (scanf("%d", &countVert) == 0 || countVert <= 0) {
		printf("input error\n\n");
		system("pause");
		return 0;
	}

	//Memory allocation for the adjencency matrix:
	if (!(adjencencyMatrix = (int**)malloc(countVert * sizeof(int*))))
		return NULL;
	for (i = 0; i < countVert; i++)
		if(!(adjencencyMatrix[i] = (int*)malloc(countVert * sizeof(int))))
			return NULL;

	//Sample output: 
	printf("\nYour matrix look like:\n");
	Init_Adjencency_Matrix(adjencencyMatrix, countVert);

	//Filling adjencency matrix
	Create_Adjencency_Matrix(adjencencyMatrix, countVert, startStr = 0, startCol = 0);

	//Output adjencency matrix:
	printf("\nYour matrix for graph:\n");
	Output_Adjencency_Matrix(adjencencyMatrix, countVert);

	//Counts the number of edges:
	countEdg = Count_Edges(adjencencyMatrix, countVert);
	printf("\n\nNumber of edges: %2d", countEdg);
	if (!countEdg) return 0;

	if (!(arrayEdges = (Edges_t*)malloc(countEdg * sizeof(Edges_t))))
		return 0;

	printf("\n\nArray of edges:\n");
	Matrix_Edges(adjencencyMatrix, countVert, arrayEdges);

	Kruskal_Algorithm(arrayEdges, countEdg);

	printf("\n\n");

	// clear memory
	for (i = 0; i < countVert; i++)
		if (adjencencyMatrix[i]) free(adjencencyMatrix[i]);
	if (adjencencyMatrix) free(adjencencyMatrix);
	if (arrayEdges) (arrayEdges);

	system("pause");
	return 0;
}
