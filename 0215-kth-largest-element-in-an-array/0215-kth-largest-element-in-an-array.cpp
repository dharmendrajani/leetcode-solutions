class Solution {
public:
    int partition(vector<int> &nums, int st,int end){
        int idx=st-1, pivot=nums[end];

        for(int j=st;j<end;j++){
            if(nums[j] < pivot){
                idx++;
                swap(nums[idx],nums[j]);
            }
        }
        idx++;
        swap(nums[end],nums[idx]);

        return idx;
    }

    int quickPartition(vector<int> &nums, int k,int tarIdx, int st, int end){
        if(st<end){
            int pivotIdx = partition(nums,st,end);
            if(pivotIdx == tarIdx){
                    return tarIdx;
            }else if (pivotIdx < tarIdx){
                return quickPartition(nums,k,tarIdx,pivotIdx+1,end);
            }else{
                return quickPartition(nums,k,tarIdx,st,pivotIdx-1);
            }
        }
        return st;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int tarIdx = nums.size()-k;
        int index = quickPartition(nums,k,tarIdx,0,nums.size()-1);

        return nums[index];
    }
};