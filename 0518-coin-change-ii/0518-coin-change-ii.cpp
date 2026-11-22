class Solution {
public:
    int solve(int amount, vector<int> &coins, vector<vector<int>> &dp, int idx){

        if(amount == 0 ) return 1;
        if(idx < 0) return 0;

        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }
        int a=0,b=0;
        if(coins[idx] <= amount){
            a = solve(amount-coins[idx], coins, dp, idx);
        }
        b= solve(amount, coins, dp, idx-1);

        return dp[idx][amount] = a+b;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1, -1));

        if(n==0) return 0;

        return solve(amount, coins, dp, n-1);
    }
};