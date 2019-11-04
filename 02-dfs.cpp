#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // create am adjacenvy matrix and fill it up witg all zeroes
    // created points in space(conceptually)
    int** A = new int*[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        for (int j = 0; j < n; j++)
            A[i][j] = 0;
    }
    // fill up the adjacency matrix
    for (int i = 0; i < m; i++)
    {
        int r, c;
        cin >> r >> c;
        A[r][c] = A[c][r] = 1;
    }
    
    // create the visited array
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    // push the sv into the queue and then automate it  (like an assembyly line)
    int sv = 0;
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int frontNode = q.front(); q.pop();
        cout << frontNode << " ";
        for (int j = 0; j < n; j++)
        {
            // 1 ---> pushing all the ones in 
            if ( A[frontNode][j] == 1 && !visited[j] )
            {
                // push the vertex not      the valuue          q.push(A[frontNode][j]);

                q.push(j);
                visited[j] = true;
            }
        }
        
    }
    
    
    
  return 0;
}

/*
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/
