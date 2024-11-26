#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to solve TSP using Dynamic Programming with bitmasking
int tsp_dp(int mask, int pos, const vector<vector<int>>& tsp, vector<vector<int>>& dp, int n) {
    // If all cities have been visited, return the distance to the starting city
    if (mask == (1 << n) - 1) {
        return (tsp[pos][0] != -1) ? tsp[pos][0] : INT_MAX;
    }

    // If this subproblem has already been solved, return the stored value
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    // Try to go to an unvisited city
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0 && tsp[pos][city] != -1) {
            int newAns = tsp[pos][city] + tsp_dp(mask | (1 << city), city, tsp, dp, n);
            ans = min(ans, newAns);
        }
    }

    // Store and return the result
    return dp[mask][pos] = ans;
}

int main() {
    int n;  // Number of cities
    cout << "Enter the number of cities: ";
    cin >> n;

    // Distance matrix (adjacency matrix representation)
    vector<vector<int>> tsp(n, vector<int>(n));

    cout << "Enter the distance matrix (-1 for no path):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tsp[i][j];
        }
    }

    // DP memoization table
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    // Start solving the TSP from city 0
    int minCost = tsp_dp(1, 0, tsp, dp, n);

    // Output the result
    if (minCost == INT_MAX) {
        cout << "No valid tour exists!" << endl;
    } else {
        cout << "Minimum cost of TSP tour: " << minCost << endl;
    }

    return 0;
}
