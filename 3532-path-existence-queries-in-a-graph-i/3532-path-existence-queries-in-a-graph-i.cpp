class Solution {
public:
    vector<int> par;
    vector<int> rank;

    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unite(int u, int v){
        int parA=find(u);
        int parB=find(v);

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        }else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        }else{
            par[parA] = parB;
        }

    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;

        par.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            par[i] = i;
        }

        for(int i = 0; i < n-1; i++) {
            if(nums[i+1] - nums[i] <= maxDiff) {
                unite(i, i+1);
            }
        }
        for(int i=0;i<queries.size();i++){
            if(find(queries[i][0]) == find(queries[i][1])) {
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }    
        }

        return ans;
    }
};