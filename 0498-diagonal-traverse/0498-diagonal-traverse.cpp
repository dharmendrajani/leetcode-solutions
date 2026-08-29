class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<int> ans;
        int row=0,col=0;
        while (row < m && col < n) {
            while (row >= 0 && col < n) {
                ans.push_back(mat[row][col]);
                row--;
                col++;
            }
            if (col == n) {
                row += 2;
                col--;
            }
            else {
                row++;
            }

            while (row < m && col >= 0) {
                ans.push_back(mat[row][col]);
                row++;
                col--;
            }
            if (row == m) {
                row--;
                col += 2;
            }
            else {
                col++;
            }
        }
        return ans;
    }
};