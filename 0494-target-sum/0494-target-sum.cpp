class Solution {
public:
    int solve(vector<int>& nums, int target, int idx, int sum, vector<vector<int>>& dp, int totalSum){
        int n=nums.size();

        if(idx == nums.size()) {
            return sum == target;
        }

        if(dp[idx][sum+totalSum] != -1){
            return dp[idx][sum + totalSum];
        }

        int add = solve(nums,target , idx+1, sum+nums[idx], dp,totalSum);
        int substract = solve(nums, target, idx+1, sum-nums[idx], dp, totalSum);

        return dp[idx][sum + totalSum] = add+substract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1));

        return solve(nums, target, 0, 0,dp,totalSum);
    }
};