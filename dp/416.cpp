// https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
int dp[200][10000];
bool subsetSum(const vector<int>& nums, int remain, int idx){
    if(remain == 0)
		return true;
	if(idx >= (int)nums.size())
		return false;
	
	if(dp[idx][remain] != -1)
		return dp[idx][remain];
	
	int leave = subsetSum(nums, remain, idx + 1);
	int pick = 0;
	
	if(remain - nums[idx] >= 0)
		pick = subsetSum(nums, remain - nums[idx], idx + 1);
	
	return dp[idx][remain] = pick || leave;
}
bool canPartition(const vector<int>& nums) {
    if(nums.size() == 1)
    	return false;
    int sum = 0;
    for(const int& val : nums)
    	sum += val;
    if(sum % 2 != 0)
        return false;
    memset(dp, -1, sizeof(dp));
    return subsetSum(nums, sum / 2, 0);
}
};
