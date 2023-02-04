#include <iostream>
#include <vector>
#include "functions/FunctionsForGraphsCMake.h"

using namespace std;

//неор - неориентированный, не взеш - не взвешенный

//Матрица смежности в Список ребер (неор, не взвеш граф)
vector <vector <int> > adjacencyMatrixToListOfEdges(vector <vector <int> > am)
{
    //am - матрица смежности (Adjacency Matrix)
    //loe - список ребер (List of Edges)
    vector <vector <int> > loe;
    /*for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (am[i][j] == 1)
            {
                counter++;
            }
        }
    }
    int** sr = new int* [counter];
    for (int i = 0; i < counter; i++)
    {
        sr[i] = new int[2];
    }*/
    for (int i = 0; i < am.size(); i++)
    {
        for (int j = i + 1; j < am[i].size(); j++)
        {
            if (am[i][j] == 1)
            {
                vector <int> temp = { i , j };
                loe.push_back(temp);
            }
        }
    }

    return loe;
}

//Матрица смежности в Cписок смежности (неор, не взвеш граф)
vector <vector <int> > adjacencyMatrixToAdjacencyList(vector <vector <int> > am)
{
    //al - список смежности (Adjacency List)
    //am - матрица смежности (Adjacency Matrix)
    vector <vector <int> > al(3);
    for (int i = 0; i < am.size(); i++)
    {
        for (int j = 0; j < am[i].size(); j++)
        {
            if (am[i][j] >= 1)
            {
                for (int k = 0; k < am[i][j]; k++)
                    al[i].push_back(j);
            }
        }
    }

    return al;
}

//Список смежности в Матрицу смежности (неор, не взвеш граф)
vector <vector <int> > adjacencyListToAdjacenctMatrix(vector <vector <int> > al)
{
    //al - список смежности (Adjacency List)
    //am - матрица смежности (Adjacency Matrix)
    vector <int> temp(al.size());
    vector <vector <int>> am(al.size());
    for (int i = 0; i < al.size(); i++)
    {
        am[i] = temp;
    }
    for (int i = 0; i < al.size(); i++)
    {
        for (int j = 0; j < al[i].size(); j++)
        {
            /*
                Список смежности - представление графа, где i - тый список это вершины, с которыми связана i - ая вершина
                Тогда просто обратимся к той же i-ой вершине в матрице смежности, и если в списке смежности у i-ого списка
                имеется вершина k (иначе говоря в al на позиции [i][j] стоит вершина k), тогда позиция этой вершины в МС будет [i][ al[i][j] ]
            */
            am[i][al[i][j]]++;
        }
    }
    return am;
}

//Список смежности в Список ребер (неор, не взвеш граф)
vector <vector <int> > adjacencyListToListOfEdges(vector <vector <int> > al)
{
    //al - список смежности (Adjacenct List)
    //loe - список ребер (List of Edges)
    vector <vector <int> > loe;
    vector <int> temp(2);
    for (int i = 0; i < al.size(); i++)
    {
        for (int j = 0; j < al[i].size(); j++)
        {
            temp[0] = i;
            temp[1] = al[i][j];
            if (temp[1] >= i) // чтобы не было повторов по типу [0, 1] и [1, 0], т.к. граф неор
            {
                loe.push_back(temp);
            }
        }
    }
    return loe;
}

//Список ребер в Матрицу смежности (неор, не взвеш граф)
vector <vector <int> > listOfEdgesToAdjacencyMatrix(vector <vector <int> > loe)
{
    //am - матрица смежности (Adjacency Matrix)
    //loe - список ребер (List of Edges)
    int maximum = -1;
    for (int i = 0; i < loe.size(); i++) //холостой пробег, чтобы найти кол-во вершин в графе
    {
        if (loe[i][1] > maximum)
        {
            maximum = loe[i][1];
        }
    }

    vector <vector <int> > am(maximum + 1);
    vector <int> temp(maximum + 1);
    for (int i = 0; i < loe.size(); i++)
        am[i] = temp;
    for (int i = 0; i < loe.size(); i++)
    {
        am[loe[i][0]][loe[i][1]]++;
        am[loe[i][1]][loe[i][0]]++;
    }
    return am;
}

//Список ребер в Список смежности (неор, не взвеш граф)
vector <vector <int> > listOfEdgesToAdjacencyList(vector <vector <int> > loe)
{
    int maximum = -1;
    for (int i = 0; i < loe.size(); i++) //холостой пробег, чтобы найти кол-во вершин в графе
    {
        if (loe[i][1] > maximum)
        {
            maximum = loe[i][1];
        }
    }

    vector <vector <int> > al(maximum + 1);
    for (int i = 0; i < loe.size(); i++)
    {
        al[loe[i][0]].push_back(loe[i][1]);
        al[loe[i][1]].push_back(loe[i][0]);
    }
    return al;
}

//Связаны ли две вершины. Проверка по матрице смежности
bool isVerticesConnectedAM(vector <vector <int> > am, int v, int u)
{
    if ((am[v][u] >= 1) || (am[u][v] >= 1))
    {
        return true;
    }
    return false;
}

//Связаны ли две вершины. Проверка по списку ребер
bool isVerticesConnectedLOE(vector <vector <int> > loe, int v, int u)
{
    vector <int> temp = { u , v };
    vector <int> temp1 = { v, u };
    for (int i = 0; i < loe.size(); i++)
    {
        if ((loe[i] == temp) || (loe[i] == temp1))
        {
            return true;
        }
    }
    return false;
}

//Связаны ли две вершины. Проверка по списку смежности
bool isVerticesConnectedAL(vector <vector <int> > al, int v, int u)
{
    for (int i = 0; i < al[v].size(); i++)
    {
        if (al[v][i] == u)
        {
            return true;
        }
    }
    for (int i = 0; i < al[u].size(); i++)
    {
        if (al[u][i] == v)
        {
            return true;
        }
    }
    return false;
}

//Количество ребер по матрице смежности (неор, не взвеш граф)
int countEdgesAM(vector <vector <int> > am)
{
    int counter = 0;
    for (int i = 0; i < am.size(); i++)
    {
        for (int j = 0; j < am.size(); j++)
        {
            if (am[i][j] >= 1)
            {
                counter++;
            }
        }
    }
    return counter / 2;
}

//Количество ребер по списку ребер
int countEdgesLOE(vector <vector <int> > loe)
{
    return loe.size();
}

//Количество ребер по списку смежности
int countEdgesAL(vector <vector <int> > al)
{
    int counter = 0;
    for (int i = 0; i < al.size(); i++)
    {
        for (int j = 0; j < al[i].size(); j++)
        {
            if (al[i][j] >= i)
            {
                counter++;
            }
        }
    }
    return counter;
}

//Степень вершины по матрице смежности (неор, не взвеш граф)
int vertexDegreeAM(vector <vector <int> > am, int v)
{
    int counter = 0;
    for (int i = 0; i < am[v].size(); i++)
    {
        counter += am[v][i];
    }
    return counter;
}

//Степень вершины по списку смежности
int vertexDegreeAL(vector <vector <int> > al, int v)
{
    return al[v].size();
}

//Существует эйлеров путь. Проверка по матрице смежности
bool isThereEulirianPathAM(vector <vector <int> > am)
{
    int counter = 0;
    for (int i = 0; i < am.size(); i++)
    {
        if (vertexDegreeAM(am, i) % 2 == 1)
        {
            counter++;
        }
    }
    if ((counter == 0) || (counter == 2))
    {
        return true;
    }
    return false;
}

//Существует эйлеров путь. Проверка по списку смежности
bool isThereEulirianPathAL(vector <vector <int> > al)
{
    int counter = 0;
    for (int i = 0; i < al.size(); i++)
    {
        if (vertexDegreeAL(al, i) % 2 == 1)
        {
            counter++;
        }
    }
    if ((counter == 0) || (counter == 2))
    {
        return true;
    }
    return false;
}

//Содержит ли петлю. Проверка по матрице смежности 
bool containsLoopAM(vector <vector <int> > am)
{
    for (int i = 0; i < am.size(); i++)
    {
        if (am[i][i] >= 1)
        {
            return true;
        }
    }
    return false;
}

//Поиск в глубину по матрице смежности
//bool DFS_am(vector <vector <int> > am, int v, int u, bool* visited = NULL)
//{
//    if (u >= am.size())
//    {
//        return false;
//    }
//
//    if (visited == NULL)
//    {
//        delete[] visited;
//        visited = new bool[am.size()];
//        for (int i = 0; i < am.size(); i++)
//        {
//            visited[i] = false;
//        }
//    }
//
//    visited[v] = true;
//    for (int i = 0; i < am[v].size(); i++)
//    {
//        if ((!visited[i]) && (am[v][i] >= 1))
//        {
//            DFS_am(am, i, u, visited);
//        }
//    }
//
//    if (visited[u])
//    {
//        return true;
//    }
//    return false;
//}
//
////Поиск в глубину по списку смежности
//bool DFS_al(vector <vector <int> > al, int v, int u, bool* visited = NULL)
//{
//    if (u >= al.size())
//    {
//        return false;
//    }
//
//    if (visited == NULL)
//    {
//        delete[] visited;
//        visited = new bool[al.size()];
//        for (int i = 0; i < al.size(); i++)
//        {
//            visited[i] = false;
//        }
//    }
//
//    visited[v] = true;
//    for (int i = 0; i < al[v].size(); i++)
//    {
//        if (!visited[al[v][i]])
//        {
//            DFS_am(al, al[v][i], u, visited);
//        }
//    }
//
//    if (visited[u])
//    {
//        return true;
//    }
//    return false;
//}

//Поиск в ширину по матрице смежности
bool BFS_am(vector <vector <int> > am, int v, int u)
{
    const int first = 0;
    int currentVertex;
    vector <int> queue;
    bool* visited = new bool[am.size()];
    for (int i = 0; i < am.size(); i++)
    {
        visited[i] = false;
    }
    queue.push_back(v);
    while (queue.size() > 0)
    {
        currentVertex = queue[0];
        visited[currentVertex] = true;
        queue.erase(queue.begin());
        if (currentVertex == u)
        {
            return true;
        }
        for (int i = 0; i < am[currentVertex].size(); i++)
        {
            if ((am[v][i] >= 1) && (!visited[i]))
            {
                queue.push_back(i);
                visited[i] = true;
            }
        }
        for (int i : queue)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return false;
}

//Поиск в ширину по списку смежности
bool BFS_al(vector <vector <int> > al, int v, int u)
{
    const int first = 0;
    int currentVertex;
    vector <int> queue;
    bool* visited = new bool[al.size()];
    for (int i = 0; i < al.size(); i++)
    {
        visited[i] = false;
    }
    queue.push_back(v);
    while (queue.size() > 0)
    {
        currentVertex = queue[0];
        visited[currentVertex] = true;
        queue.erase(queue.begin());
        if (currentVertex == u)
        {
            return true;
        }
        for (int i : al[currentVertex])
        {
            if (!visited[i])
            {
                queue.push_back(i);
                visited[i] = true;
            }
        }
    }
    return false;
}

//Алгоритм Дейкстры (оч крутой чувак кста) (не работает с отриц весами ребер)
vector <int> dijkstra(vector <vector <int> > am, int v)
{
    const int inf = INT_MAX;
    int minVertex, minDistance;
    bool* visited = new bool[am.size()];
    vector <int> distance(am.size());

    for (int i = 0; i < am.size(); i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < am.size(); i++)
    {
        distance[i] = inf;
    }
    distance[v] = 0;
    for (int i = 0; i < am.size(); i++)
    {
        minVertex = -1;
        minDistance = inf;
        for (int j = 0; j < am.size(); j++)
        {
            if ((distance[j] < minDistance) && (!visited[j]))
            {
                minVertex = j;
                minDistance = distance[j];
            }
        }
        if (minDistance == inf)
        {
            break;
        }

        for (int j = 0; j < am[minVertex].size(); j++)
        {
            if ((!visited[j]) && (am[minVertex][j] > 0))
            {
                distance[j] = min(distance[j], distance[minVertex] + am[minVertex][j]);
            }
        }
        visited[i] = true;
    }
    return distance;
}


void print(vector <vector <int> > vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}