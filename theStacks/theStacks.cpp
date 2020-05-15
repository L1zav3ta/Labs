#include <iostream>
#include <utility>
#include <stack>
#include "Utils.h"

#define down 10
#define left -1
#define right 1
#define up -10

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

	bool possible = true;
	int symbol = -1;
	for (i = 0; i < m; i++) {
		if (matrix[0][i] == 0) {
			symbol++;
			try {
				stack<pair<int, int>> route = findRoute(matrix, n, m, i);
				while (!route.empty()) {
					pair<int, int> pos = route.top();
					matrix[pos.first][pos.second] = 'a' + symbol;
					route.pop();
				}
			}
			catch (...) {
				possible = false;
				break;
			}
		}
	}

	cout << (possible ? "YES" : "NO") << endl;

	if (possible)
		print_matrix(n, m, matrix);



	return 0;
}