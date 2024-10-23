class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> inter;

        for(vector<int>& interval : intervals){
            if(inter.empty())
                inter.push_back(interval);
            else{
                if(interval[0] <= inter.back()[1]){
                    vector<int> merged {inter.back()[0], max(inter.back()[1], interval[1])};
                    inter.pop_back();
                    inter.push_back(merged);
                }
                else
                    inter.push_back(interval);
            }
        }
        return inter;
    }
};
