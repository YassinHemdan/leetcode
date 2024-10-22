class Solution {
public:
int maxSubArray(const vector<int>& nums) {
    int maxSum = -1e9;
    int curSum = -1e9;
    for(int val : nums){
        curSum = max(val, curSum + val);
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}
};
