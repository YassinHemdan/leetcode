class Solution {
public:
int dp[301][5001];
int cnt(int idx, int remain, const vector<int>& coins){
    if(idx >= (int)coins.size())
		return 0;
	if(remain == 0)
		return 1;
	if(remain < 0)
		return 0;
	if(dp[idx][remain] != -1)
		return dp[idx][remain];
	dp[idx][remain] = cnt(idx, remain - coins[idx], coins);
	dp[idx][remain] += cnt(idx + 1, remain, coins);
	
	return dp[idx][remain];
}
int change(int amount, const vector<int>& coins) {
    memset(dp, -1, sizeof(dp));
    return cnt(0, amount, coins);
}
};
