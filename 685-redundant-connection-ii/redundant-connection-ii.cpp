class DisjointSet {
public:
    vector<int> parent;
    DisjointSet(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    bool unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return false;
        parent[ulp_v] = ulp_u;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> first, second;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                first = {parent[v], v};
                second = {u, v};
                edge[1] = 0;  // Remove the edge temporarily
            }
        }

        DisjointSet ds(n);
        for (const auto& edge : edges) {
            if (edge[1] == 0) continue;
            int u = edge[0];
            int v = edge[1];
            if (!ds.unionBySize(u, v)) {
                if (first.empty()) {
                    return edge;
                } else {
                    return first;
                }
            }
        }
        return second;
    }
};
