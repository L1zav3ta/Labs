#pragma once

#define down 10
#define left -1
#define right 1
#define up -10

using namespace std;

//route search
bool search(int **matrix, int n, int m, stack<pair<int, int>>& route, int dir);

//launches route search recursion
stack<pair<int, int>> findRoute(int **matrix, int n, int m, int begin);

//print route of people
void solve(int **matrix, int n, int m);