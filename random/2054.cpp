class Solution {
private:
    int binarySearch(const vector<vector<int>>& events,
                     const vector<int>& rightMax, int end, int s, int e){
        
        int ans = 0;
        while(s <= e){
            int mid = s + (e - s) / 2;
            int start = events[mid][0];
            if(start > end)
                ans = rightMax[mid], e = mid - 1;
            else
                s = mid + 1;
        }
        return ans;
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());

        vector<int> rightMax(n);
        rightMax[n - 1] = events[n - 1][2];

        int maxSum = rightMax[n - 1];
        for(int i = n - 2 ; i > -1 ; --i){
            int sum = events[i][2] + binarySearch(events, rightMax, events[i][1], i, n - 1);
            rightMax[i] = max(events[i][2], rightMax[i + 1]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
