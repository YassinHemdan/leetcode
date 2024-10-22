class Solution {
public:
    long long maxKelements(const vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> pq;

        for(const int& val : nums)
            pq.push(val);

        while(k--){
            int num = pq.top();
            score += num;
            pq.pop();
            pq.push((num + 3 - 1) / 3);
        }
        return score;
    }
};
