#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int shortestCycle = n + 1; // Initialize with a value greater than any possible cycle length

        for (int startNode = 0; startNode < n; startNode++) {
            vector<int> distance(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;
            q.push(startNode);
            distance[startNode] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (distance[v] == -1) {
                        q.push(v);
                        distance[v] = distance[u] + 1;
                        parent[v] = u;
                    } else if (parent[u] != v) {
                        // Found a cycle
                        int cycle_length = distance[u] + distance[v] + 1;
                        shortestCycle = min(shortestCycle, cycle_length);
                    }
                }
            }
        }

        if (shortestCycle == n + 1) {
            return -1; // No cycle found
        }

        return shortestCycle;
    }
};
