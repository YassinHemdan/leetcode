class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = (int)triangle.size();
        for(int row = 1 ; row < n ; ++row){
            for(int i=0 ; i<=row ; ++i){
                if(i == 0)
                    triangle[row][i] += triangle[row - 1][i];
                else if(i == row)
                    triangle[row][i] += triangle[row - 1][i - 1];
                else
                    triangle[row][i] += min(triangle[row - 1][i], triangle[row - 1][i - 1]);
            }
        }
        int minPath = INT_MAX;
        for(int i=0 ; i<n ; ++i)
            minPath = min(minPath, triangle[n - 1][i]);
        return minPath;
    }
};
