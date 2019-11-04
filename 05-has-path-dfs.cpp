

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool hasPathDFS(int** edges, int n, int sv, int ev, bool* visited)
{
    visited[sv] = true;
    if (sv == ev)
        return true;
    
    for (int j = 0; j < n; j++)
    {
        if (edges[sv][j] == 1 && !visited[j])
        {
            if (hasPathDFS(edges, n, j, ev, visited))
            {
                return true;
            }
        }
    }
    return false;
    
}

bool hasPath(int** edges, int n, int sv, int ev)
{
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    return hasPathDFS(edges, n, sv, ev, visited);
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
    
    int sv, ev;
    cin >> sv >> ev;
    
    
    if (hasPath(edges, V, sv, ev))
        cout << "true";
    else
        cout << "false";
    
    return 0;
}
/*
 Sample Input 1 :
 4 4
 0 1
 0 3
 1 2
 2 3
 1 3
 Sample Output 1 :
 true
 Sample Input 2 :
 6 3
 5 3
 0 1
 3 4
 0 3
 Sample Output 2 :
 false
 */
