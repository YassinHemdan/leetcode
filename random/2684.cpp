class Solution {
private:
    int dx[3] {-1, 0, 1};
    vector<vector<int>> dp;
    bool isValidMove(int i, int j, int preI, int preJ, vector<vector<int>>& grid){
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();
        return i > -1 &&  j > -1 && i < rows && j < cols && grid[i][j] > grid[preI][preJ];
    }
    int maxMoves(int i, int j, vector<vector<int>>& grid){
        if(dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = 0;
        for(int d=0 ; d<3 ; ++d){
            int x = dx[d] + i;
            int y = j + 1;
            if(isValidMove(x, y, i, j, grid))
                dp[i][j] = max(dp[i][j], 1 + maxMoves(x, y, grid));
        }
        return dp[i][j];
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        dp = vector<vector<int>>(rows, vector<int>(cols, -1));
        int mx = 0;
        for(int i=0 ; i<rows; ++i){
            mx = max(mx, maxMoves(i, 0, grid));
        }
        return mx;
    }
};
