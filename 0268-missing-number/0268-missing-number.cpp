class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int currsum=0, actSum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            currsum+=nums[i];
        }
        for(int i=1;i<=n;i++){
            actSum+=i;
        }

        int missing = actSum-currsum;

        return missing;
    }
};