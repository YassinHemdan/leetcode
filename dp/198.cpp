class Solution {
public:
int memo[101];

int pickOrLeave(int idx, const vector<int>& nums){
	if(idx >= (int)nums.size())
		return 0;
	if(memo[idx] != -1)
		return memo[idx];
	int leave = pickOrLeave(idx + 1, nums);
	int pick = nums[idx] + pickOrLeave(idx + 2, nums);
	
	return memo[idx] = max(leave, pick);
}
int rob(const vector<int>& nums) {
    memset(memo, -1, sizeof(memo));
    return pickOrLeave(0, nums);
}
};
