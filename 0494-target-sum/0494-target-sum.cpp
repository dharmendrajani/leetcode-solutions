class Solution {
public:
    int solve(vector<int>& nums, int target, int idx, int sum){
        int n=nums.size();

        if(idx == nums.size()) {
            return sum == target;
        }

        int add = solve(nums,target , idx+1, sum+nums[idx]);
        int substract = solve(nums, target, idx+1, sum-nums[idx]);

        return add+substract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        

        return solve(nums, target, 0, 0);
    }
};