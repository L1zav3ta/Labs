//function for filling in the matrix

#ifndef TheDirectedGraph
#define TheDirectedGraph

//Filling in matrix of 0:
void Matrix_Vertex(int **A, int countVert);

//Filling in the adjencency matrix:
void Adjencency_Matrix(int **A, int countVert, int startStr, int startCol);

//Output ajencency matrix:
void Output_Adjencency_Matrix(int **A, int countVert);

//Counts the number of edges
int Count_Edges(int **A, int countVert);

//Filling in the matrix of edges:
void Matrix_Edges(int **A1, int countVert, int *A2, int countEdg);



/*//Kruskal's algorithm:
void Kruskal_Algorithm(int **A, int countVert);*/

#endif // !TheDirectedGraph



