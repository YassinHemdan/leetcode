class Solution {
public:
int dp[1001];

int best_split(int idx, const vector<vector<int>>& books, int shelfWidth){
	if(idx >= (int)books.size())
		return 0;
	if(dp[idx] != -1)
		return dp[idx];
	
	dp[idx] = INT_MAX;
	int block_height = 0;
	int block_width = 0;
	for(int end=idx ; end<(int)books.size() && books[end][0] + block_width <= shelfWidth; ++end){
		block_height = max(block_height, books[end][1]);
		block_width += books[end][0];
		int total = block_height + best_split(end + 1, books, shelfWidth);
		dp[idx] = min(total, dp[idx]);
	}
	return dp[idx];
}
int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    memset(dp, -1, sizeof(dp));
    return best_split(0, books, shelfWidth);
}
};
