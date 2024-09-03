class Solution {
public:
int dp[104][104];

int mcm(int start, int end, const vector<int>& cuts){
	if(start == end - 1)
		return 0;
	if(dp[start][end] != -1)
		return dp[start][end];
	
	dp[start][end] = INT_MAX;
	for(int split = start + 1 ; split < end ; ++split){
		int block_cost = cuts[end] - cuts[start];
		int sub1 = mcm(start, split, cuts);
		int sub2 = mcm(split, end, cuts);
		
		int total = block_cost + sub1 + sub2;
		dp[start][end] = min(dp[start][end], total);
	}
	return dp[start][end];
}
int minCost(int n, vector<int>& cuts) {
    memset(dp, -1, sizeof(dp));
    cuts.push_back(0);
    cuts.push_back(n);
    
    sort(cuts.begin(), cuts.end());
    
    return mcm(0, (int)cuts.size() - 1, cuts);
}
};
