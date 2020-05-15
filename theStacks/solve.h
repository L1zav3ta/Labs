#pragma once
#include <iostream>
#include <stack>

bool search(int **matrix, int n, int m, stack<pair<int, int>>& route, int dir);

stack<pair<int, int>> findRoute(int **matrix, int n, int m, int begin);