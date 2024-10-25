
class Solution {
private:
    long long lowerBound(vector<vector<int>>& rides, vector<long long>& dp, int idx){
        int s = idx + 1, e = (int)rides.size() - 1;
        long long ans = 0;
        int end = rides[idx][1];
        while(s <= e){
            int mid = s + (e - s) / 2;
            int start = rides[mid][0];
            if(start >= end){
                ans = dp[mid];
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int sz = (int)rides.size();
        vector<long long> rightMax(sz);
        sort(rides.begin(), rides.end());
        
        rightMax[sz - 1] = rides[sz - 1][1] - rides[sz - 1][0] + rides[sz - 1][2];

        long long maxCost = rightMax[sz - 1];
        for(int i=sz - 2 ; i>-1 ; --i){
            long long rideCost = rides[i][1] - rides[i][0] + rides[i][2];
            long long totalCost = rideCost + lowerBound(rides, rightMax, i);
            maxCost = max(maxCost, totalCost);
            rightMax[i] = max(totalCost, rightMax[i + 1]);
        }
        return maxCost;
    }
};
