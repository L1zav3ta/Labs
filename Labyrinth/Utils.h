#pragma once

using namespace std;

//matrix initialization
int **init_matrix(int **matrix, int n, int m);

//matrix filling
int **fill_matrix(int **matrix, int n, int m);

//validation of input matrix size
bool is_correct_size(int n, int m);

//matrix output to the screen
void print_matrix(int n, int m, int** matrix);

