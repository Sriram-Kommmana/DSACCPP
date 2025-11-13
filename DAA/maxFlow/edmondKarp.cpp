#include <bits/stdc++.h>
using namespace std;

bool bfs(int s, int t, vector<int>& parent, vector<vector<int>>& residual) {
    int n = residual.size();
    vector<bool> visited(n, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && residual[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;

                if (v == t)
                    return true; // reached sink
            }
        }
    }
    return false;
}

int edmondKarp(vector<vector<int>>& graph, int s, int t) {
    int n = graph.size();

    vector<vector<int>> residual = graph;  // residual capacity graph
    vector<int> parent(n);
    int maxFlow = 0;

    while (bfs(s, t, parent, residual)) {

        // find minimum residual capacity in the found path
        int pathFlow = INT_MAX;
        int v = t;

        while (v != s) {
            int u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
            v = u;
        }

        // update residual capacities (forward and reverse edges)
        v = t;
        while (v != s) {
            int u = parent[v];

            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;

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

    cout << "Maximum Flow = " << edmondKarp(graph, s, t);
}
