class Solution {
private:
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    bool moveRight(int i, int j){
        return j + 1 < (int)grid[0].size();
    }
    bool moveLeft(int i, int j){
        return j - 1 > -1;
    }
    bool moveUp(int i, int j){
        return i - 1 > -1;
    }
    bool moveDown(int i, int j){
        return i + 1 < (int)grid.size();
    }
    int left = 0;
    int right = 1;
    int up = 3;
    int down = 4;
    void spiralMove(vector<int>& ans, int i, int j, int type){
        ans.push_back(grid[i][j]);
        visited[i][j] = true;
        if(type == right && moveRight(i, j) && !visited[i][j + 1])
            spiralMove(ans, i, j + 1, right);
        else if(moveDown(i, j) && !visited[i + 1][j])
            spiralMove(ans, i + 1, j, down);
        
        if(type == down && moveDown(i, j) && !visited[i + 1][j])
            spiralMove(ans, i + 1, j, down);
        else if(moveLeft(i, j) && !visited[i][j - 1])
            spiralMove(ans, i, j - 1, left);
        
        if(type == left && moveLeft(i, j) && !visited[i][j - 1])
            spiralMove(ans, i, j - 1, left);
        else if(moveUp(i, j) && !visited[i - 1][j])
            spiralMove(ans, i - 1, j, up);
        
        if(type == up && moveUp(i, j) && !visited[i - 1][j])
            spiralMove(ans, i - 1, j, up);
        else if(moveRight(i, j) && !visited[i][j + 1])
            spiralMove(ans, i, j + 1, right);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        grid = matrix;
        visited = vector<vector<bool>>((int)matrix.size(), vector<bool>((int)matrix[0].size()));
        vector<int> ans;
        spiralMove(ans, 0, 0, right);
        return ans;
    }
};
