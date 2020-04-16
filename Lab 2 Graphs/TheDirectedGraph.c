//function, need for work

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Fills the matrix with 0:
void Matrix_Vertex (int **A, int countVert){
	int i, j;
	
	for (i = 0; i < countVert; i++) {
		for (j = 0; j < countVert; j++)
			A[i][j] = 0;
	}

	for (i = 0; i < countVert; i++)
		printf("%3c ", 'A' + i);

	for (i = 0; i < countVert; i++) {
		printf("\n%c", 'A' + i);
		for (j = 0; j < countVert; j++)
			printf(" %d  ", A[i][j]);
	}
	return;
} 

//Reads the length of the paths from "a" to "b":
void Adjencency_Matrix(int **A, int countVert,int startStr, int startCol) {
	int i, j, len ;	//len

	for (i = startStr; i < countVert; i++) {
		for (j = startCol; j < countVert; j++) {
			if (i < j) {
				printf("\n Enter the way length from %c to %c ( between 0 and 99) ", 'A' + i, 'A' + j); 
				
				if (!(scanf("%d", &len)) || len < 0 || len > 99) { // !!!ќ“Ћјƒ»“№!!!! чтобы можно было повторить попытку при вводе не числа
					printf("\nLength error, try again\n");
					len = 0;
					system("pause");
					Adjencency_Matrix(A, countVert,i,j);
				}

				A[i][j] = len;
				A[j][i] = len;
			}
		}
	}

	return;
}
				
//Outputs an ajencency matrix with path lengths:
void Output_Adjencency_Matrix(int **A, int countVert) {
	int i, j;

	for (i = 0; i < countVert; i++)
		printf(" %2c", 'A' + i);

	for (i = 0; i < countVert; i++) {
		printf("\n%c", 'A' + i);
		for (j = 0; j < countVert; j++)
			printf(" %2d", A[i][j]);
	}
	return;
}

//Counts the number of non-zero elements 
//	in the upper-triangular matrix = the number of edges:
int Count_Edges(int **A, int countVert) {
	int i, j, count = 0;

	for (i = 0; i < countVert; i++) {
		for (j = 0; j < countVert; j++) {
			if (i < j && A[i][j] != 0)
				count++;
		}
	}
	return count;
}

//Matrix of edges:
void Matrix_Edges(int **A1, int countVert, int *A2, int countEdg) {
	int  p=0, i, j; 

	for (i = 0; i < countVert; i++) {
		for (j = 0; j < countVert; j++) {
			if (i < j && A1[i][j] != 0) {
				A2[p] = A1[i][j];
				printf("%2d", A2[p]);
				p++;
			}
		}
	}
	return;
}
	


			

			
			
/*//Kruskal's algorithm:
void Kruskal_Algorithm(int **A, int countVert) {
	int i, j, min;

}*/