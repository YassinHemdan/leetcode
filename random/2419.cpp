class Solution {
public:
// suppose we have two numbers num1 and num2
// let num1 >= num2
// ANDing the two numbers will produce a new num that is either equals to
// num1 which is the max or will be a number smaller than num1
int longestSubarray(const vector<int>& nums) {
    int maxNumber = *max_element(nums.begin(), nums.end());
    int n = nums.size();
    int length = 1;
    int prev = -1;
    for(int i=0 ; i<n ; ++i){
        if((maxNumber & nums[i]) == maxNumber)
            length = max(length, i - prev);
        else
            prev = i;
    }
    return length;
}
};
