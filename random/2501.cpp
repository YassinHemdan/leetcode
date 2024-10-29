class Solution {
private:
    int limit = 1e5 + 1;
    int dp[100001];
    int squareLength(int num, vector<bool>& values){
        if(dp[num] != -1)
            return dp[num];
        
        int len = 1;
        long long next = (long long)num * (long long)num;
        if(next > limit)
            return len;
        
        if(values[next])
            len += squareLength(next, values);
        
        dp[num] = len;
        return len;
    }
public:
    int longestSquareStreak(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        vector<bool> values(limit);

        
        for(int& val : nums)
            values[val] = true;
        
        int length = 0;
        for(int &val : nums)
            length = max(length, squareLength(val, values));
        return length == 1 ? -1 : length;
    }
};
