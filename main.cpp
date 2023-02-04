#include <iostream>
#include <vector>
#include "functions/FunctionsForGraphsCMake.h"

using namespace std;

int main()
{
    /*int n;
    cout << "Enter amount of vertices" << endl;
    cin >> n;*/
    vector <vector <int> > am = {
                                  {0, 7, 9, 0, 0, 14},
                                 {7, 0, 10, 15, 0, 0},
                                 {9, 10, 0, 11, 0, 2},
                                 {0, 15, 11, 0, 6, 0},
                                 {0,  0,  0, 6, 0, 9},
                                 {14, 0,  2, 0, 9, 0},
    };
    cout << am.size() << endl;
    /*am.resize(n);
    int temp;
    for (int i = 0; i < am.size(); i++)
    {
        for (int j = 0; j < am.size(); j++)
        {
            cin >> temp;
            am[i].push_back(temp);
        }
    }*/

    //cout << "\n";
    cout << endl;
    vector <int> dist = dijkstra(am, 2);
    for (int i : dist)
    {
        cout << i << " ";
    }
    /*vector <vector <int> > loe = adjacencyMatrixToListOfEdges(am);
    print(loe);

    vector <vector <int> > al = adjacencyMatrixToAdjacencyList(am);
    print(al);*/

    /*cout << isThereEulirianPathAL(al) << endl;
    cout << isThereEulirianPathAM(am) << endl;
    cout << endl;
    cout << DFS_am(am, 0, 2);
    cout << endl;
    cout << DFS_al(al, 0, 2);*/

    /*cout << BFS_am(am, 0, 3) << endl;
    cout << BFS_al(al, 0, 3);*/
}