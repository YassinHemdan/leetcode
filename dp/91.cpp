class Solution {
public:
int dp[101];

bool isValid(char d1, char d2){
	if(d1 == '1' && d2 >= '0' && d2 <= '9')
		return true;
	if(d1 == '2' && d2 >= '0' && d2 <= '6')
		return true;
	return false;
}
int cnt(int idx, const string& s){
	if(idx == (int)s.size())
		return 1;
	if(dp[idx] != -1)
		return dp[idx];
	
	dp[idx] = 0;
	if(s[idx] >= '1' && s[idx] <= '9')
		dp[idx] += cnt(idx + 1, s);
	if(idx + 1 < (int)s.size() && isValid(s[idx], s[idx + 1]))
		dp[idx] += cnt(idx + 2, s);
	
	return dp[idx];
}
int numDecodings(const string& s) {
    memset(dp, -1, sizeof(dp));
    return cnt(0, s);
}
};
