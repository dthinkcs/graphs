
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>* getComp(int** A, int n, int sv, bool* visited)
{
    visited[sv] = true;
    
    vector<int>* vp = new vector<int>;
    for (int i = 0; i < n; i++)
    {
        if (A[sv][i] && !visited[i])
        {
            //count++
            vector<int>* smallVector = getComp(A, n, i, visited);
            for (int i = 0; i < smallVector->size(); i++)
                vp->push_back(smallVector->at(i));
            //return vp;
        }
        // base case
        //if (i == n - 1 && count == 0)
        //{
        //    vp->push_back(sv);
        //    return vp;
        //}
    }
    vp->push_back(sv);
    return vp;
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
    
    
    // for every possible starting vertex i
    for (int sv = 0; sv < V; sv++)
    {
        if (!visited[sv])
        {
            vector<int>* vp = getComp(edges, V, sv, visited);
            sort(vp->begin(), vp->end());
            for (int i = 0; i < vp->size(); i++)
                cout << (*vp)[i] <<  " ";
            cout << endl;
            //set<int> s;
            //DFS_H(edges, V, sv, visited, s);
            //for (set<int>::iterator it = s.begin(); it != s.end(); it++)
            //    cout << *it << " ";
            //cout << endl;
        }
    }
    
    
    return 0;
}

/*
 Sample Input 1:
 4 2
 0 1
 2 3
 Sample Output 1:
 0 1
 2 3
 Sample Input 2:
 4 3
 0 1
 1 3
 0 3
 Sample Output 2:
 0 1 3
 2
 */
