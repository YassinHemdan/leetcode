class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> availableRooms;
         priority_queue<pair<long long, int>, 
                        vector<pair<long long, int>>, 
                        greater<pair<long long, int>>> endRooms;
        vector<int> visited(n);
        sort(meetings.begin(), meetings.end());
        for(int i=0 ; i<n ; ++i)
            endRooms.push({0, i});
        
        int visitedRoom = 0;
        for(int i=0; i<(int)meetings.size() ; ++i){
            while(!endRooms.empty() && meetings[i][0] >= endRooms.top().first){
                availableRooms.push(endRooms.top().second);
                endRooms.pop();
            }
            int room = 0;
            if(!availableRooms.empty()){
                room = availableRooms.top();
                availableRooms.pop();

                endRooms.push({meetings[i][1], room});
                visited[room]++;
            }
            else{
                pair<long long, int> p = endRooms.top();
                endRooms.pop();

                int period = meetings[i][1] - meetings[i][0];
                long long end = p.first + period;
                room = p.second;
                endRooms.push({end, room});
                visited[room]++;
            }
            if(visited[room] > visited[visitedRoom])
                visitedRoom = room;
            else if(visited[room] == visited[visitedRoom])
                visitedRoom = min(room, visitedRoom);
        }
        return visitedRoom;
    }
};
