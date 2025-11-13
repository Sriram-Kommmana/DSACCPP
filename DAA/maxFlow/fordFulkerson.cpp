#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int t, vector<int>& parent, vector<vector<int>>& residual, vector<bool>& visited) {
    visited[u] = true;

    if (u == t) return true;

    for (int v = 0; v < residual.size(); v++) {
        if (!visited[v] && residual[u][v] > 0) {
            parent[v] = u;
            if (dfs(v, t, parent, residual, visited))
                return true;
        }
    }
    return false;
}

int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    int n = graph.size();

    vector<vector<int>> residual = graph;  // residual graph
    vector<int> parent(n);
    int maxFlow = 0;

    while (true) {
        vector<bool> visited(n, false);

        // find path using DFS
        bool foundPath = dfs(s, t, parent, residual, visited);

        if (!foundPath)
            break;

        // find minimum residual capacity (bottleneck)
        int pathFlow = INT_MAX;
        int v = t;
        while (v != s) {
            int u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
            v = u;
        }

        // update residual capacities
        v = t;
        while (v != s) {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow; // reverse edge
            v = u;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int s = 0, t = 5;

    cout << "Maximum Flow = " << fordFulkerson(graph, s, t);
}
