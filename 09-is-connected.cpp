
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void DFS_H(int** edges, int n, int sv, bool* visited)
{
    
    visited[sv] = true;
    
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
            DFS_H(edges, n, i, visited);
    }
}

bool allVisited(bool* visited, int N)
{
    for (int i = 0; i < N; i++)
        if (!visited[i])
            return false;
    return true;
}

int main()
{
    int V, E;
    cin >> V >> E;
    
    /*
     
     Write Your Code Here
     Complete the Rest of the Program
     You have to take input and print the output yourself
     
     */
    
    int** edges = new int*[V];
    for (int i = 0; i < V; i++)
    {
        edges[i] = new int[V];
        for (int j = 0; j < V; j++)
            edges[i][j] = 0;
    }
    
    for (int i = 0; i < E; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    int sv = 0;
    DFS_H(edges, V, sv, visited);
    
    if (allVisited(visited, V))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    
    return 0;
}

/*
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3
0 3
Sample Output 2:
false
*/
