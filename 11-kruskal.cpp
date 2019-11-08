#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

int findParent(int v, int* parentOf) {
    if (parentOf[v] == v) {
        return v;
    }
    else {
        return findParent(parentOf[v], parentOf);
    }
}

bool compareEdgesWeight(Edge a, Edge b) {
    return a.weight < b.weight;
}

// UNDIRECTED 
void printKruskal(Edge* edgeList, int E, int V) {
    sort(edgeList, edgeList + E, compareEdgesWeight);
    
    int* parentOf = new int[V]; // every vertex parent is that vertex only
    for (int i = 0; i < E; i++) {
        parentOf[i] = i; // initially there are no cycles
    }
    
    Edge* outputMST = new Edge[V - 1];
    int count = 0;
    
    for (int i = 0; i < E; i++) {
        
        int parentSource = findParent(edgeList[i].source, parentOf);
        int parentDestination = findParent(edgeList[i].destination, parentOf);
        
        if (parentSource == parentDestination)
            continue;
        else {
            outputMST[count++] = edgeList[i];
            // BUG parentOf[edgeList[i].source] = edgeList[i].destination; // union find set any one;s parent to the other
            parentOf[parentSource] = parentDestination; // make both the parents As the New Parent NOT the source, desitination
        }
        
        if (count == V - 1)
            break;
    }
    
    for (int i = 0; i < count; i++) {
        cout << min(outputMST[i].source, outputMST[i].destination) << " " << max(outputMST[i].source, outputMST[i].destination) << " " << outputMST[i].weight << endl;
    }
    
    
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    
    Edge* edgeList = new Edge[E];
    for (int i = 0; i < E; i++)
    {
        int s; int d; int w;
        cin >> s >> d >> w;
        edgeList[i] = {s, d, w};
    }
    
    printKruskal(edgeList, E, V);
    
    return 0;
}


/*
 Sample Input 1 :
 4 4
 0 1 3
 0 3 5
 1 2 1
 2 3 8
 Sample Output 1 :
 1 2 1
 0 1 3
 0 3 5
 */
