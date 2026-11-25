class Solution {
public:
    int solve(vector<int>& stones, int idx,int tar,int sum, vector<vector<int>> & dp){
        int n=stones.size();

        if(idx == n) return sum;

        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }

        int add=0, sub=0;

        if(sum + stones[idx] <= tar){
            add = solve(stones, idx+1,tar, sum+stones[idx],dp);
        }
        sub = solve(stones, idx+1,tar, sum,dp);

        return dp[idx][sum] = max(add,sub);

    }

    int lastStoneWeightII(vector<int>& stones) {
        int totSum=0;
        for(int i=0;i<stones.size();i++){
            totSum+=stones[i];
        }
        int tar=totSum/2;

        vector<vector<int>> dp(stones.size()+1, vector<int>(tar+1, -1));

        int best = solve(stones,0,tar,0,dp);
        return totSum - 2 * best;
    }
};