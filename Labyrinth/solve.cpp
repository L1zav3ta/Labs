#include <iostream>
#include <stack>
#include <utility>
#include "solve.h"
#include "Utils.h"

using namespace std;

//gives an answer whether it is possible to create a route for a person
bool search(int **matrix, int n, int m, stack<pair<int, int>>& route, int dir) {
	int* priorityDirs = NULL; //массив приоритетных шагов
	bool found = true; //есть ли путь
	pair<int, int> npos = make_pair(dir / 10 + route.top().first, dir % 10 + route.top().second);

	if (npos.first < 0 || npos.first >= n || npos.second < 0 || npos.second >= m || matrix[npos.first][npos.second] != 0)
		return false;
	else {
		route.push(npos);
		matrix[npos.first][npos.second] = 1; //чтобы при построении маршрута нельзя было вернутся в предыдущие вершины
		if (npos.first == n - 1) //если это последняя строка, то мы дошли до выхода
			return true; // успех
		else {

			switch (dir) {
			case down:
				priorityDirs = new int[3]{ left, down, right };
				break;
			case left:
				priorityDirs = new int[3]{ left, down, up };
				break;
			case right:
				priorityDirs = new int[3]{ down, right, up };
				break;
			case up:
				priorityDirs = new int[3]{ left, right, up };
				break;
			}

			for (int i = 0; i < 3; i++) {
				found = search(matrix, n, m, route, priorityDirs[i]);
				if (found) //если успешно дошли до финиша
					return true;
			}
			matrix[npos.first][npos.second] = 0; //если ячейка не подходит, убираем ее из маршрута (освобождаем)
			route.pop();
			return false;
		}
	}
}

//launches route search recursion
stack<pair<int, int>> findRoute(int **matrix, int n, int m, int begin) {
	stack<pair<int, int>> route;

	route.push(make_pair(0, begin));
	if (n != 1 && !search(matrix, n, m, route, down))
		throw - 1;

	return route;
}

//print route of people and answer for ??
void solve(int **matrix, int n, int m) {
	int i;

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
		print_route(n, m, matrix);

	return;
}