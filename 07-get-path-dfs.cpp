
#include <iostream>
#include <vector>
using namespace std;

// healthy if breathe
// vp->
// if you are passing through a pointer DO NOT assign ptr to new thing
vector<int>* getPath(int ** A, int n, int sv, int ev, bool* visited)
{
    visited[sv] = true;
    
    if (sv == ev)
    {
        vector<int>* vp = new vector<int>;
        vp->push_back(ev);
        return vp;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (A[sv][i] == 1 && !visited[i])
        {
            vector<int>* vp = getPath(A, n, i, ev, visited); // i as the starting vertex
            if (vp != NULL)
            {
                vp->push_back(sv);
                return vp; // not doing return was a BUG BUG BUG
            }
        }
    }
    return NULL;
}

vector<int>* getPathDFS(int** A, int n, int sv, int ev)
{
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    
    return getPath(A, n, sv, ev, visited);
}

int main()
{
    int n, m, tempX, tempY;
    cin >> n >> m;
    
    /*
     
     Write Your Code Here
     Complete the Rest of the Program
     You have to Print the output yourself
     
     */
    int** A = new int*[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        for (int j = 0; j < n; j++)
            A[i][j] = 0;
    }
    
    for (int i = 0; i < m; i++)
    {
        int v1; int v2;
        cin >> v1 >> v2;
        A[v1][v2] = A[v2][v1] = 1;
    }
    
    int sv; int ev;
    cin >> sv >> ev;
    
    
    //vector<int>* vp = NULL;
    vector<int>* vp = getPathDFS(A, n, sv, ev);
    
    if (vp)
    {
        for (int i = 0; i < vp->size(); i++)
            cout << vp->at(i) << " ";
    }
    
    
    
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
