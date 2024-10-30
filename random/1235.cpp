class Solution {
private:
    int binarySearch(vector<vector<int>>& jobs, int idx){
        int s = idx + 1, e = (int)jobs.size() - 1;
        int end = jobs[idx][1];
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            int start = jobs[mid][0];
            if(start >= end)
                ans = mid, e = mid - 1;
            else
                s = mid + 1;
        }
        return ans;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for(int i=0 ; i<n ; ++i)
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        sort(jobs.begin(), jobs.end());

        vector<int> rightMax(n);
        rightMax[n - 1] = jobs[n - 1][2];

        int maxProfit = rightMax[n - 1];
        for(int i = n - 2 ; i > -1 ; --i){
            int idx = binarySearch(jobs, i);
            int profit = jobs[i][2];
            if(idx != -1)
                profit += rightMax[idx];
            rightMax[i] = max(rightMax[i + 1], profit);
            maxProfit = max(maxProfit, rightMax[i]);
        }
        return maxProfit;
    }
};
