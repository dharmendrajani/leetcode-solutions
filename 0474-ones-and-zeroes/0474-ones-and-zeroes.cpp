class Solution {
public:
    pair<int,int> zeroOne(vector<string>& strs, int i){
        int zero = 0, one = 0;
        for(int j = 0; j < strs[i].size(); j++) {
            if(strs[i][j] == '0') zero++;
            else if(strs[i][j] == '1') one++;
        }
        return {zero,one};
    }    

    int solve(vector<string>& strs, int m, int n, int idx,vector<vector<vector<int>>>& dp){
        if(strs.size() == idx) return 0;

        if(dp[idx][m][n] != -1){
            return dp[idx][m][n];
        }
        auto [zero, one] = zeroOne(strs, idx);
        int include =0, exclude=0;

        if(zero<=m && one<=n){
            include = 1+solve(strs, m-zero, n-one, idx+1,dp);
        }
        exclude = solve(strs,m,n,idx+1,dp);

        return dp[idx][m][n] = max(include,exclude);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        return solve(strs,m,n, 0,dp);
    }
};