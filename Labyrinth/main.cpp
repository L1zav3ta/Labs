#include <iostream>
#include <utility>
#include "Utils.h"

using namespace std;

int main() {
	int i, n, m;
	int **matrix = NULL;

	cout << "Enter size labyrinth (NxM)" << endl;
	cin >> n >> m;
	if (!(is_correct_size(n, m)))
		return 0;

	if (!(matrix = init_matrix(matrix, n, m)))
		return 1;

	if (!(matrix = fill_matrix(matrix, n, m)))
		return 0;

	print_matrix(n, m, matrix);

	system("pause");
	return 0;
}
	
