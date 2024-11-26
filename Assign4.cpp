


#include <iostream>
#include<bits/stdc++.h>
using namespace std ;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2] ;
}

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i ;
        rank[i] = 0 ;
    }
    
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] != node)
    {
        parent[node] = findParent(parent, parent[node]) ;
    }
    
    return parent[node] ;
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u) ;
    v = findParent(parent, v) ;

    if (u != v)
    {
        if (rank[u] < rank[v])
        {
            parent[u] = v ;
        }
        else if (rank[v] < rank[u])
        {
            parent[v] = u ;
        }
        else
        {
            parent[v] = u ;
            rank[u]++ ;
        } 
    }
    
}

pair<int, vector<vector<int> > > minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp) ;
    vector<int> parent(n) ;
    vector<int> rank(n) ;
    makeSet(parent, rank, n) ;

    int minWeight = 0 ;
    vector<vector<int>> mstEdges ;

    for(auto edge : edges)
    {
        int u = findParent(parent, edge[0]) ;
        int v = findParent(parent, edge[1]) ;
        int wt = edge[2] ;
    

        if (u != v)
        {
            minWeight += wt ;
            mstEdges.push_back(edge) ;
            unionSet(u, v, parent, rank) ;
        }
    }

    return {minWeight, mstEdges} ;
    
}

int main()
{
    int n, m ;
    cout << "Enter the number of nodes and edges : " ;
    cin >> n >> m ;

    vector<vector<int>> edges ;
    cout << "Enter the edges (u, v, weight) : " << endl ;
    for (int i = 0; i < m; i++)
    {
        int u , v, wt ;
        cin >> u >> v >> wt ;
        edges.push_back({u, v, wt}) ;
    }
    
    auto result = minimumSpanningTree(edges, n) ;
    cout << "Total weight of the minimum spanning tree : " << result.first << endl;
    cout << "Edges in the Minimum Spanning Tree : " << endl ;
    for(auto edge : result.second)
    {
        cout << edge[0] << " -> " << edge[1] << " : " << edge[2] << endl ;
    }

    return 0 ;
}