class Solution {
public:
int dp[60];

int intBreak(int n){
	if(n <= 1)
		return 1;
	if(dp[n] != -1)
		return dp[n];
	
	for(int i=1 ; i<=n ; ++i)
		dp[n] = max(dp[n], i * intBreak(n - i));
	return dp[n];
}
int integerBreak(int n) {
	if(n <= 3)
		return n - 1;
    memset(dp, -1 ,sizeof(dp));
    return intBreak(n);
}
};
