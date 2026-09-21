class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        //1st wind
        // for(int i=0;i<k;i++){
        //     while(dq.size()>0 && nums[dq.back()] <= nums[i]){
        //         dq.pop_back();
        //     }
        //     dq.push_back(i);
        // }

        // for(int i=k; i<nums.size();i++){
        //     res.push_back(nums[dq.front()]);
            
        //     while(dq.size() >0 && dq.front()<=i-k){
        //         dq.pop_front();
        //     }

        //     while(dq.size()>0 && nums[dq.back()] <= nums[i]){
        //         dq.pop_back();
        //     }
        //     dq.push_back(i);
        // }
        //      res.push_back(nums[dq.front()]);

        for(int i = 0; i < nums.size(); i++) {

            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            if(i >= k-1) {
                res.push_back(nums[dq.front()]);

            if(dq.front() <= i-k+1)
                dq.pop_front();
            }
        }

             return res;
    }
};