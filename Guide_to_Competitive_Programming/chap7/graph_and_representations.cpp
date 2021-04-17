/**
 *
 * The following two are the most commonly used representations of a graph.
 *
 * 1. Adjacency Matrix
 *     int adj[N][N]
 *
 * 2. Adjacency List
 *     vector<pair<int, int>> adj[N];
 *
 */

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[], int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
 
void printGraph(vector<pair<int,int>> adj[], int V) {
    for (int v = 0; v < V; ++v) {
        cout << "\n Adjacency list of vertex " << v << endl;
	
	for (const auto& x : adj[v] ) {
	    cout << v << "-> " << x.first << " ( " << x.second << " )";
	    cout << endl;
	}
	
    }
}
 
// Driver code
int main()
{
    int V = 5;
    vector<pair<int, int>> adj[V];

    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 4, 10);
    addEdge(adj, 1, 2, 5);
    addEdge(adj, 1, 3, 3);
    addEdge(adj, 1, 4, 2);
    addEdge(adj, 2, 3, 8);
    addEdge(adj, 3, 4, 7);

    printGraph(adj, V);

    return 0;
}
