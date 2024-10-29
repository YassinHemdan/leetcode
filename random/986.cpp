class Solution {
private:
    bool intersected(vector<int>& interval1, vector<int>& interval2){
        int x1 = interval1[0], x2 = interval2[0];
        int y1 = interval1[1], y2 = interval2[1];

        return (x1 >= x2 && x1 <= y2) || (x2 >= x1 && x2 <= y1);
    }
    vector<int> getIntersection(vector<int>& interval1, vector<int>& interval2){
        int x1 = interval1[0], x2 = interval2[0];
        int y1 = interval1[1], y2 = interval2[1];

        return {max(x1, x2), min(y1, y2)};
    }
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n1 = firstList.size();
        int n2 = secondList.size();
        if(!n1 || !n2)
            return {};
        
        int idx1 = 0, idx2 = 0;
        vector<vector<int>> intersections;
        while(idx1 < n1 && idx2 < n2){
            if(intersected(firstList[idx1], secondList[idx2]))
                intersections.push_back(getIntersection(firstList[idx1], secondList[idx2]));
            if(firstList[idx1][1] > secondList[idx2][1])
                ++idx2;
            else
                ++idx1;
        }
        return intersections;
    }
};
