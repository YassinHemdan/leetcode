class Solution {
private:
    vector<vector<int>> dp;
    int next(int s, vector<vector<int>>& events){
        int e = (int)events.size() - 1;
        int ans = e + 1;
        int end = events[s - 1][1];
        while(s <= e){
            int mid = s + (e - s) / 2;
            int start = events[mid][0];

            if(start > end)
                ans = mid, e = mid - 1;
            else
                s = mid + 1;
        }
        return ans;
    }
    int rec(int idx, int k, vector<vector<int>>& events){
        if(idx >= (int)events.size())
            return 0;
        if(k <= 0)
            return 0;
        if(dp[idx][k] != -1)
            return dp[idx][k];
        int leave = rec(idx + 1, k, events);
        int pick = events[idx][2] + rec(next(idx + 1, events), k - 1, events);

        return dp[idx][k] = max(pick, leave);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));

        return rec(0, k, events);
    }
};
