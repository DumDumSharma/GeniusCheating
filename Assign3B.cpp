#include <bits/stdc++.h>
using namespace std;

class FlightGraph {
    unordered_map<string, vector<string>> adjList; // Adjacency List to store cities and their neighbors

public:
    // Add a flight between two cities
    void addFlight(string cityA, string cityB) {
        adjList[cityA].push_back(cityB);
        adjList[cityB].push_back(cityA); // Assuming the graph is undirected
    }

    // Check if the graph is connected using DFS
    bool isConnected() {
        if (adjList.empty()) return true;

        unordered_set<string> visited;
        string startCity = adjList.begin()->first; // Start from any city
        dfs(startCity, visited);

        return visited.size() == adjList.size(); // If all cities are visited
    }

    // DFS traversal to mark visited cities
    void dfs(string city, unordered_set<string>& visited) {
        visited.insert(city);
        for (string neighbor : adjList[city]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, visited);
            }
        }
    }

    // Print the adjacency list (flight network)
    void printGraph() {
        for (auto city : adjList) {
            cout << city.first << " -> ";
            for (string neighbor : city.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    FlightGraph graph;

    // Add flight paths between cities (no cost included for simplicity)
    graph.addFlight("Mumbai", "Delhi");
    graph.addFlight("Mumbai", "Bangalore");
    graph.addFlight("Delhi", "Chennai");
    graph.addFlight("Chennai", "Kolkata");
    graph.addFlight("Bangalore", "Kolkata");

    // Print the flight network
    cout << "Flight Network:\n";
    graph.printGraph();

    // Check if the flight network is connected
    if (graph.isConnected()) {
        cout << "The flight network is connected.\n";
    } else {
        cout << "The flight network is not connected.\n";
    }

    return 0;
}

