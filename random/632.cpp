class Solution {
public:
struct Num{
    int val;
    int idx;
    int kIdx;
    Num(int val, int idx, int kIdx) : val(val), idx(idx), kIdx(kIdx) {}
    bool operator <(const Num& n) const{
        return val > n.val;
    }
};

void mergeKSortedLists(const vector<vector<int>>& lists, vector<pair<int, int>>& merged){
    int k = (int)lists.size();
    priority_queue<Num> pq;
    for(int i=0 ; i<k ; ++i)
        pq.push(Num(lists[i][0], 0, i));
    
    while(!pq.empty()){
        Num num = pq.top();
        pq.pop();

        merged.push_back({num.val, num.kIdx});
        if(num.idx + 1 < (int)lists[num.kIdx].size())
            pq.push(Num(lists[num.kIdx][num.idx + 1], num.idx + 1, num.kIdx));
    }
}
void compareRanges(vector<int>& prev, const vector<int>& cur){
    int prevDifference = prev[1] - prev[0];
    int curDifference = cur[1] - cur[0];

    if(prevDifference <= curDifference)
        return;
    prev = cur;
}
vector<int> smallestRange(const vector<vector<int>>& lists) {
    vector<pair<int, int>> nums;
    int k = lists.size();

    mergeKSortedLists(lists, nums);

    vector<int> smallestRange {(int)-2e5, (int)2e5};
    int n = nums.size();
    int l = 0, r = 0;

    vector<int> visited(k);
    int count = 1;
    visited[nums[0].second] = 1; 

    while(l <= r){
        if(count == k){
            compareRanges(smallestRange, {nums[l].first, nums[r].first});
            if(--visited[nums[l].second] == 0)
                --count;
            ++l;
            continue;
        }
        ++r;
        if(r >= n)
            break;
        if(++visited[nums[r].second] == 1)
            ++count;
    }
    return smallestRange;
}
};
