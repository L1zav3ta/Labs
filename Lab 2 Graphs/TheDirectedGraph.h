//function for filling in the matrix

#ifndef TheDirectedGraph
#define TheDirectedGraph

typedef struct Edges {
	int idxStart;
	int idxFinish;
	int weight;
}Edges_t;

//Filling in matrix of 0:
void Init_Adjencency_Matrix(int **adjencencyMatrix, int countVert);

//Filling in the adjencency matrix:
void Create_Adjencency_Matrix(int **adjencencyMatrix, int countVert, int startStr, int startCol);

//Output ajencency matrix:
void Output_Adjencency_Matrix(int **adjencencyMatrix, int countVert);

//Counts the number of edges
int Count_Edges(int **adjencencyMatrix, int countVert);

//Filling in the matrix of edges:
void Matrix_Edges(int **adjencencyMatrix, int countVert, Edges_t *arrayEdges);

//Sort for arrayEdges:
Edges_t* Sort_Array_Edg(Edges_t *arrayEdges, int countEdg);

//
void Kruskal_Algorithm(Edges_t *arrayEdges, int countEdg);

#endif // !TheDirectedGraph


