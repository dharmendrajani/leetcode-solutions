class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph, vector<bool> &vis, vector<bool> &resPath){
        vis[src] = true;
        resPath[src] = true;

        for(int v : graph[src]){
            if(!vis[v]){
                if(dfs(v,graph,vis,resPath)){
                    return true;
                }
            }else if(resPath[v]){
                return true;
            }
        }
        resPath[src] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n,false);
        vector<bool> resPath(n,false);
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,resPath);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!resPath[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};