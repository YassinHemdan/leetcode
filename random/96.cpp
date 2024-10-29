class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for(int nodes = 2 ; nodes <= n ; ++nodes){
            int total = 0;
            for(int roots = 1 ; roots <= nodes ; ++roots){
                int left = roots - 1;
                int right = nodes - roots;
                total += dp[left] * dp[right];
            }
            dp[nodes] = total;
        }
        return dp[n];
    }
};
