class Solution {
public:
int dp[303][303];
int best_split(int start, int end, const vector<int>& nums){
    if(start == end - 1)
		return 0;
	if(dp[start][end] != -1)
		return dp[start][end];
	
	for(int split = start + 1 ; split < end ; ++split){
		int block_cost = nums[start] * nums[split] * nums[end];
		int sub1 = best_split(start, split, nums);
		int sub2 = best_split(split, end, nums);
		
		dp[start][end] = max(dp[start][end], block_cost + sub1 + sub2);
	}
	
	return dp[start][end];
}
int maxCoins(vector<int>& nums) {
	nums.push_back(1);
	nums.insert(nums.begin(), 1);
	
	memset(dp, -1 , sizeof(dp));
	return best_split(0, (int)nums.size() - 1, nums);
}
};
