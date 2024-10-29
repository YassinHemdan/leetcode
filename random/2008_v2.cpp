class Solution {
public:
    long long maxTaxiEarnings(int n, const vector<vector<int>>& rides) {
        unordered_map<int, vector<vector<int>>> mp;
        for(const vector<int>& ride : rides)
            mp[ride[0]].push_back(ride);
        
        long long dp[n + 2];
        memset(dp, 0, sizeof(dp));
        long long ans = 0;
        for(int start = n ; start > 0 ; --start){
            if(mp.find(start) != mp.end()){
                vector<vector<int>>& startRides = mp[start];
                long long maxCost = 0;
                for(const vector<int>& ride : startRides){
                    long long cost = ride[1] - ride[0] + ride[2] + dp[ride[1]];
                    maxCost = max(maxCost, cost);
                }
                dp[start] = max(maxCost, dp[start + 1]);
            }
            else
                dp[start] = dp[start + 1];
            ans = max(ans, dp[start]);
        }
        return ans;
    }
};
