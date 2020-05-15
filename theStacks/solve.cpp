#include <iostream>
#include <utility>
#include <stack>
#include "Utils.h"

bool search(int **matrix, int n, int m, stack<pair<int, int>> &route, int dir) {
	pair<int, int> npos = make_pair(dir / 10 + route.top().first, dir % 10 + route.top().second);

	if (npos.first < 0 || npos.first >= n || npos.second < 0 || npos.second >= m || matrix[npos.first][npos.second] != 0)
		return false;
	else {
		route.push(npos);
		matrix[npos.first][npos.second] = 1; //чтобы при построении маршрута нельз€ было вернутс€ в предыдущие вершины
		if (npos.first == n - 1)
			return true;
		else {
			int* priorityDirs = NULL;

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

			bool found = true;
			for (int i = 0; i < 3; i++) {
				found = search(matrix, n, m, route, priorityDirs[i]);
				if (found)
					return true;
			}
			matrix[npos.first][npos.second] = 0; //если €чейка не подходит, убираем ее из маршрута (освобождаем)
			route.pop();
			return false;
		}
	}
}

stack<pair<int, int>> findRoute(int **matrix, int n, int m, int begin) {
	stack<pair<int, int>> route;

	route.push(make_pair(0, begin));
	if (n != 1 && !search(matrix, n, m, route, down))
		throw - 1;

	return route;
}
