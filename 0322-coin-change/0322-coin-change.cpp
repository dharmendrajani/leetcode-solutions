class Solution {
public:
    int solve(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp){

        if(amount == 0) return 0;
        if(idx<0) return 1e9;

        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }

        int a=1e9,b=1e9;

        if(coins[idx] <= amount){
            a = 1+solve(coins, amount-coins[idx], idx,dp);
        }
        b = solve(coins, amount ,idx-1,dp);

        return dp[idx][amount] = min(a,b);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        if(n==0) return 0;
        int ans = solve(coins, amount, n-1, dp);

        if(ans == 1e9) return -1;
        
        return ans;
    }
};