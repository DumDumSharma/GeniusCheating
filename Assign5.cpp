#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <climits>
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source) {
    // Create adjacency list for the graph
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Distance vector to store shortest path distances
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Set to keep track of the nodes and their current shortest distances
    set<pair<int, int>> st;
    st.insert(make_pair(0, source));

    // Dijkstra's algorithm main loop
    while (!st.empty()) {
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
        st.erase(st.begin());

        // Visit all neighbors of the current node
        for (auto neighbor : adj[topNode]) {
            if (nodeDistance + neighbor.second < dist[neighbor.first]) {
                auto record = st.find(make_pair(dist[neighbor.first], neighbor.first));
                if (record != st.end()) {
                    st.erase(record);
                }

                dist[neighbor.first] = nodeDistance + neighbor.second;
                st.insert(make_pair(dist[neighbor.first], neighbor.first));
            }
        }
    }

    return dist;
}

int main() {
    int vertices, edges;
    
    // Input number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> edgesInput(edges, vector<int>(3));

    // Input edges (u, v, w)
    cout << "Enter edges (u v w for each edge):\n";
    for (int i = 0; i < edges; i++) {
        cin >> edgesInput[i][0] >> edgesInput[i][1] >> edgesInput[i][2];
    }

    // Input source and destination
    int source, destination;
    cout << "Enter source vertex: ";
    cin >> source;
    cout << "Enter destination vertex: ";
    cin >> destination;

    // Call Dijkstra's algorithm
    vector<int> dist = dijkstra(edgesInput, vertices, edges, source);

    // Output the shortest distance from source to destination
    if (dist[destination] == INT_MAX) {
        cout << "No path exists between " << source << " and " << destination << endl;
    } else {
        cout << "Shortest path from " << source << " to " << destination << " is: " << dist[destination] << endl;
    }

    return 0;
}
