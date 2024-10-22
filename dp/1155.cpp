class Solution {
public:
int dp[31][1001];
int mod = 1e9 + 7;
int cnt(int dice, int remain, int k){ // O(n*k*target) time complexity. O(n*target) space complexity
	if(dice == 0 && remain ==0 )
		return 1;
	if(remain == 0 && dice > 0)
		return 0;
	if(remain > 0 && dice == 0)
		return 0;
	if(dp[dice][remain] != -1)
		return dp[dice][remain];
	
	dp[dice][remain] = 0;
	for(int face = 1; face <= k ; ++face)
		if(remain >= face){
			dp[dice][remain] += cnt(dice - 1, remain - face, k);
			dp[dice][remain] %= mod;
		}
	return dp[dice][remain];
}
int numRollsToTarget(int n, int k, int target) {
    memset(dp, -1, sizeof(dp));
    return cnt(n, target, k);
}
};
