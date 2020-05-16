#include <iostream>
#include "Utils.h"

using namespace std;

//check for correct elem
bool is_correct_element(int element) {
	if ((element < 0) || (element > 1)) {
		cout << "Incorrect value element" << endl;
		system("pause");
		return false;
	}

	return true;
}

//matrix initialization
int **init_matrix(int **matrix, int n, int m) {
	int i;

	matrix = new (nothrow) int*[n];
	if (!matrix) {
		cout << "Could not allocate memory";
		system("pause");
	}

	for (i = 0; i < n; i++) {
		matrix[i] = new (nothrow) int[m];
		if (!matrix[i]) {
			cout << "Could not allocate memory";
			system("pause");
			break;
		}

	}

	return matrix;
}

//filling matrix
int **fill_matrix(int **matrix, int n, int m) {
	int i, j;

	cout << "Filling matrix size of: " << n << "x" << m << endl;
	cout << "1 = wall, 0 = free way" << endl;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> matrix[i][j];
			if (!(is_correct_element(matrix[i][j])))
				return NULL;
		}
	}

	return matrix;
}

//check for correct input size
bool is_correct_size(int n, int m) {
	if (n <= 0 || m <= 0) {
		cout << "Incorrect size labyrinth" << endl;
		system("pause");
		return false;
	}

	return true;
}

//matrix output to the screen
void print_matrix(int n, int m, int** matrix) {
	int i, j;

	cout << "Your Labyrinth:" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (matrix[i][j] == 0 || matrix[i][j] == 1)
				cout << matrix[i][j] << " ";
			else
				cout << (char)matrix[i][j] << " ";
		}
		cout << endl;
	}
}
