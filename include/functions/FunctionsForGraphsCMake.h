#pragma once

#include <iostream>
#include <vector>
using namespace std;
//неор - неориентированный, не взвеш - не взвешенный

//Матрица смежности в Список ребер (неор, не взвеш граф)
vector <vector <int> > adjacencyMatrixToListOfEdges(vector <vector <int> > am);

//Матрица смежности в Cписок смежности (неор, не взвеш граф)
vector <vector <int> > adjacencyMatrixToAdjacencyList(vector <vector <int> > am);

//Список смежности в Матрицу смежности (неор, не взвеш граф)
vector <vector <int> > adjacencyListToAdjacenctMatrix(vector <vector <int> > al);

//Список смежности в Список ребер (неор, не взвеш граф)
vector <vector <int> > adjacencyListToListOfEdges(vector <vector <int> > al);

//Список ребер в Матрицу смежности (неор, не взвеш граф)
vector <vector <int> > listOfEdgesToAdjacencyMatrix(vector <vector <int> > loe);

//Список ребер в Список смежности (неор, не взвеш граф)
vector <vector <int> > listOfEdgesToAdjacencyList(vector <vector <int> > loe);

//Связаны ли две вершины. Проверка по матрице смежности
bool isVerticesConnectedAM(vector <vector <int> > am, int v, int u);

//Связаны ли две вершины. Проверка по списку ребер
bool isVerticesConnectedLOE(vector <vector <int> > loe, int v, int u);

//Связаны ли две вершины. Проверка по списку смежности
bool isVerticesConnectedAL(vector <vector <int> > al, int v, int u);

//Количество ребер по матрице смежности (неор, не взвеш граф)
int countEdgesAM(vector <vector <int> > am);

//Количество ребер по списку смежности
int countEdgesAL(vector <vector <int> > al);

//Степень вершины по матрице смежности (неор, не взвеш граф)
int vertexDegreeAM(vector <vector <int> > am, int v);

//Степень вершины по списку смежности
int vertexDegreeAL(vector <vector <int> > al, int v);

//Существует эйлеров путь. Проверка по матрице смежности
bool isThereEulirianPathAM(vector <vector <int> > am);

//Существует эйлеров путь. Проверка по списку смежности
bool isThereEulirianPathAL(vector <vector <int> > al);

//Содержит ли петлю. Проверка по матрице смежности 
bool containsLoopAM(vector <vector <int> > am);

//Поиск в глубину по матрице смежности
bool DFS_am(vector <vector <int> > am, int v, int u, bool* visited = NULL);

//Поиск в глубину по списку смежности
bool DFS_al(vector <vector <int> > al, int v, int u, bool* visited = NULL);

//Поиск в ширину по матрице смежности
bool BFS_am(vector <vector <int> > am, int v, int u);

//Поиск в ширину по списку смежности
bool BFS_al(vector <vector <int> > al, int v, int u);

//Алгоритм Дейкстры (оч крутой чувак кста) (не работает с отриц весами ребер)
vector <int> dijkstra(vector <vector <int> > am, int v);

//Вывод представления графа по Матрице смежности/Списку смежности/Списку ребер
void print(vector <vector <int> > vec);