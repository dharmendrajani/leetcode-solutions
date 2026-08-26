class Solution {
public:
    void merge(vector<pair<int,int>> &nums, int st, int mid, int end,vector<int> &counts){
        int i=st, j=mid+1;
        vector<pair<int,int>> temp;
        int rightSmaller = 0;
        while(i<=mid && j<=end){
            if(nums[i].first>nums[j].first){
                temp.push_back(nums[j]);
                rightSmaller++;
                j++;
            }else{
                temp.push_back(nums[i]);
                counts[nums[i].second] += rightSmaller;
                i++;
            }
            
        }
        while(i<=mid){
            counts[nums[i].second] += rightSmaller;
            temp.push_back(nums[i]);
            i++;
        }

        while(j<=end){
            temp.push_back(nums[j]);
            j++;
        }

        for(int idx=0;idx<temp.size();idx++){
            nums[idx+st] = temp[idx];
        }
    }

    void mergeSelect(vector<pair<int,int>> &nums, int st, int end,vector<int> &counts){
        if(st<end){
            int mid = st+(end-st)/2;

            mergeSelect(nums,st,mid,counts);
            mergeSelect(nums,mid+1,end,counts);
            merge(nums,st,mid,end,counts);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> counts(n, 0);
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++){
            ans.push_back({nums[i],i});
        }

        mergeSelect(ans,0,n-1,counts);

        return counts;
    }
};