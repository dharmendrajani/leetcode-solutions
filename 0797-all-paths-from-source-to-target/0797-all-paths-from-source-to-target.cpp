class Solution {
public:
    void dfs(int src,int tar,vector<int> &path, vector<vector<int>> &ans, vector<vector<int>>& graph){
        path.push_back(src);

        if(src == tar){
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for(int u : graph[src]){
            dfs(u,tar,path,ans,graph);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> path;
        vector<vector<int>> ans;

        int tar = n-1;
        dfs(0,tar,path,ans,graph);

        return ans;
    }
};