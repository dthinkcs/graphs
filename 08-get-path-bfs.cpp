
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>* getPathBFS(int** A, int V, int sv, int ev)
{
    int * visited = new int[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;
    
    if (sv == ev)
    {
        vector<int>* vp = new vector<int>;
        vp->push_back(sv);
        return vp;
    }
    
    queue<int> q;
    q.push(sv);
    visited[sv] = 1;
    unordered_map<int, int> parent;
    while (!q.empty())
    {
        int frontNode = q.front(); q.pop();
        
        for (int i = 0; i < V; i++)
        {
            if (A[frontNode][i] && !visited[i])
            {
                parent[i] = frontNode;
                q.push(i);
                visited[i] = 1;
                if (i == ev)
                {
                    vector<int>* vp = new vector<int>;
                    int currNode = i;
                    while (true)
                    {
                        vp->push_back(currNode);
                        if (parent.count(currNode) == 0)
                            return vp;
                        currNode = parent[currNode];
                    }
                }
                
            }
        }
        
    }
    return NULL; // if you could not find anything
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    
    /*
     
     Write Your Code Here
     Complete the Rest of the Program
     You have to Print the output yourself
     
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
        edges[f][s] = edges[s][f] = 1;
    }
    
    int sv, ev;
    cin >> sv >> ev;
    
    
    vector<int>* vp = getPathBFS(edges, V, sv, ev);
    if (vp)
    {
        for (int i = 0; i < vp->size(); i++)
            cout << (*vp)[i] << " ";
    }
    
    
    // solution.cpp:94:25: error: 'class std::vector' has no member named 'get'
    //          cout << vp->get(i) << " ";
    
    
    
    // unordered_map<int, int> goBackMap;
    
    
    //     queue<int> q;
    //     q.push(sv);
    //     visited[sv] = 1;
    
    //     while (!q.empty())
    //     {
    //         int frontNode = q.front(); q.pop();
    //         if (frontNode == ev)
    //         {
    //             cout << ev << " ";
    //             //int count = 0;
    //             while ( goBackMap.find(ev) != goBackMap.end() )
    //             {
    //                 cout << goBackMap[ev] << " ";
    //                 ev = goBackMap[ev];
    
    //             }
    //             cout << endl;
    //             break;
    //         }
    
    //         for (int i = 0; i < V; i++)
    //         {
    //             if (edges[frontNode][i] == 1 && !visited[i])
    //             {
    //                 q.push(i);
    //                 goBackMap[i] = frontNode;
    //                 visited[i] = 1;
    //             }
    //         }
    //     }
    
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
 3 0 1
 */
