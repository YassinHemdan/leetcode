class Solution {
public:
int dp[501][501];
int rec(int idx1, int idx2, const string& s){
	if(idx1 >= idx2)
		return 0;
	if(dp[idx1][idx2] != -1)
		return dp[idx1][idx2];
	if(s[idx1] == s[idx2])
		return dp[idx1][idx2] = rec(idx1 + 1, idx2 - 1, s);
	
	int choice1 = 1 + rec(idx1 + 1, idx2, s);
	int choice2 = 1 + rec(idx1, idx2 - 1, s);
	
	return dp[idx1][idx2] = min(choice1, choice2);
}
int minInsertions(const string& s) {
    memset(dp, -1, sizeof(dp));
    return rec(0, (int)s.size() - 1, s);
}
};
