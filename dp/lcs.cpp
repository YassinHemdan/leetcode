//https://leetcode.com/problems/longest-common-subsequence/

int dp[1001][1001];

int lcs(const string& text1,const string& text2, int idx1, int idx2){ // o(n^2) time and space
	if(idx1 >= (int)text1.size())
		return 0;
	if(idx2 >= (int)text2.size())
		return 0;
	if(dp[idx1][idx2] != -1)
		return dp[idx1][idx2];
	if(text1[idx1] == text2[idx2])
		return 1 + lcs(text1, text2, idx1 + 1, idx2 + 1);
	
	int choice1 = lcs(text1, text2, idx1 + 1, idx2);
	int choice2 = lcs(text1, text2, idx1, idx2 + 1);
	return dp[idx1][idx2] = max(dp[idx1][idx2], max(choice1, choice2));
}
int longestCommonSubsequence(const string& text1,const string& text2) {
   memset(dp, -1, sizeof(dp));
   
   return lcs(text1, text2, 0, 0);
}
