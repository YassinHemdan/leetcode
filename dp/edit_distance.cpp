class Solution {
public:
int dp[501][501];
int edit_distance(const string& s1, const string& s2, int idx1, int idx2){
	if(idx1 >= (int)s1.size())
		return (int)s2.size() - idx2;
	if(idx2 >= (int)s2.size())
		return (int)s1.size() - idx1;
	if(dp[idx1][idx2] != -1)
		return dp[idx1][idx2];
	if(s1[idx1] == s2[idx2])
		return dp[idx1][idx2] = edit_distance(s1, s2, idx1 + 1, idx2 + 1);
	int remove = 1 + edit_distance(s1, s2, idx1 + 1, idx2);
	int insert = 1 + edit_distance(s1, s2, idx1, idx2 + 1);
	int change = 1 + edit_distance(s1, s2, idx1 + 1, idx2 + 1);

	return dp[idx1][idx2] = min(change, min(remove, insert));
}
int minDistance(const string& word1, const string& word2) {
	memset(dp, -1, sizeof(dp));
	return edit_distance(word1, word2, 0, 0);
}
};
