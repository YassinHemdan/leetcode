class Solution {
public:
int dp[201][1001];
int cnt(int idx, int remain, const vector<int>& nums){
	if(remain == 0)
		return 1;
	if(remain < 0 || idx >=(int)nums.size())
		return 0;
	if(dp[idx][remain] != -1)
		return dp[idx][remain];
	
	dp[idx][remain] = cnt(0, remain - nums[idx], nums);
	dp[idx][remain] += cnt(idx + 1, remain, nums);
	
	return dp[idx][remain];
}
int combinationSum4(const vector<int>& nums, int target) {
    memset(dp, -1, sizeof(dp));
    return cnt(0, target, nums);
}
};

class Solution {
public:
int dpV2[1001];
int cntV2(int remain, const vector<int>& nums){
	if(remain == 0)
		return 1;
	if(dpV2[remain] != -1)
		return dpV2[remain];
	dpV2[remain] = 0;
	
	for(int idx = 0 ; idx<(int)nums.size() ; ++idx)
		if(remain >= nums[idx])
			dpV2[remain] += cntV2(remain - nums[idx], nums);
	return dpV2[remain];
}
int combinationSum4(const vector<int>& nums, int target) {
    memset(dpV2, -1, sizeof(dpV2));
    return cntV2(target, nums);
}
};
