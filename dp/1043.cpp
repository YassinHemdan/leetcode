class Solution {
public:
int dp[501];

int best_split(int idx, const vector<int>& arr, int k){
    if(idx >= (int)arr.size())
		return 0;
	if(dp[idx] != -1)
		return dp[idx];
	
	int block_max = 0;
	int block_sum = 0;
	for(int end = idx ; end < (int)arr.size() && end - idx < k; ++end){
		block_max = max(block_max, arr[end]);
		block_sum = block_max * (end - idx + 1);
		
		dp[idx] = max(dp[idx], block_sum + best_split(end + 1, arr, k));
	}
	return dp[idx];
}
int maxSumAfterPartitioning(vector<int>& arr, int k) {
    memset(dp, -1, sizeof(dp));
    return best_split(0, arr, k);
}
};
