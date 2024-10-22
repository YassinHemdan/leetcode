class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = 0;
        priority_queue<int> pq;
        for(int& val : piles){
            sum += val;
            pq.push(val);
        }
        while(k-- && pq.top() != 1){
            int val = pq.top();
            pq.pop();
            sum = sum - (val / 2);
            pq.push(val - (val / 2));
        }
        return sum;
    }
};
