class Solution {
public:
int memo[51][51];
int best_splt(int start, int end, const vector<int>& nums){
    if(start == end - 1)
        return 0;
	if(memo[start][end] != -1)
		return memo[start][end];
	
	memo[start][end] = INT_MAX;
	for(int split = start + 1; split < end ; ++split){
		int block_cost = nums[start] * nums[split] * nums[end];
		int sub1 = best_splt(start, split, nums);
		int sub2 = best_splt(split, end, nums);
		int total = block_cost + sub1 + sub2;
		
		memo[start][end] = min(memo[start][end], total);
	}
	return memo[start][end];
}
int minScoreTriangulation(const vector<int>& values) {
    memset(memo, -1, sizeof(memo));
    return best_splt(0, (int)values.size() - 1, values);
}
};
