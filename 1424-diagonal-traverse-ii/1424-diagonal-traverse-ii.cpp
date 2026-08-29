class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        vector<int> ans;

        int maxCol = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxCol = max(maxCol, (int)nums[i].size());
        }

        vector<vector<int>> diagonal(nums.size() + maxCol);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                diagonal[i + j].push_back(nums[i][j]);
            }
        }

        for (auto &d : diagonal) {
            for (int i = d.size() - 1; i >= 0; i--) {
                ans.push_back(d[i]);
            }
        }

        return ans;
    }
};