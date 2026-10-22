class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& vis) {

        if (vis[node] == 1)
            return true;  // Cycle detected

        if (vis[node] == 2)
            return false; // Already proven safe

        vis[node] = 1;

        for (int neighbor : graph[node]) {
            if (dfs(neighbor, graph, vis))
                return true;
        }

        vis[node] = 2;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!dfs(i, graph, vis)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};