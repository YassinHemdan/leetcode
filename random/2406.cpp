class Solution {
private:
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        int groups = 0;
        for(vector<int>& interval : intervals){
            if(minHeap.empty()){
                minHeap.push({interval[1], interval[0]});
                ++groups;
            }
            else{
                if(minHeap.top().first < interval[0])
                    minHeap.pop();
                else
                    ++groups;
                minHeap.push({interval[1], interval[0]});
            }
        }
        return groups;
    }
};
