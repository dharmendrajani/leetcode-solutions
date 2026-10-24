class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        queue<pair<int,pair<int,int>>> q;

        q.push({1,{0,0}});
        grid[0][0]=1;

        int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int dist = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            if(row == n-1 && col == n-1){
                return dist;
            }

            for (int i = 0; i < 8; i++) {
                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0) {
                    q.push({dist + 1, {newRow, newCol}});
                    grid[newRow][newCol] = 1;
                }
            }    
        }
        return -1;
    }
};