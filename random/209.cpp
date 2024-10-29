class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0;
        int len = INT_MAX;
        while(l <= r && r < n){
            sum += nums[r];
            while(sum >= target){
                len = min(len, r - l + 1);
                sum -= nums[l];
                ++l;
            }
            ++r;
        }
        return len == INT_MAX ? 0 : len;
    }
};
