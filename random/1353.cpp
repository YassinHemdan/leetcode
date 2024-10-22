class Solution {
public:
bool inRange(int day,  vector<int>& event){
    return event[0] <= day && event[1] >= day;
}
int maxEvents(vector<vector<int>>& events) {
    int n = events.size();
    sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int attended = 0;
    int eventIdx = 0;

    for(int day = 1 ; !minHeap.empty() || eventIdx < n ; ++day){ // o(nlogn)
        // remove the invalid events
        while(!minHeap.empty() && minHeap.top() < day)
            minHeap.pop();

        // get the valid events;
        while(eventIdx < n && inRange(day, events[eventIdx]))
            minHeap.push(events[eventIdx][1]), ++eventIdx;
        
        if(!minHeap.empty())
            ++attended, minHeap.pop();
    }

    return attended;
}
};
