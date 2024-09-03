class Solution {
public:
int dp[102];

bool valid(int pre, int cur, const vector<vector<int>>& cuboids){
	int xpre = cuboids[pre][1];
	int ypre = cuboids[pre][2];
	int xcur = cuboids[cur][1];
	int ycur = cuboids[cur][2];

	if(xpre <= xcur && ypre <= ycur)
		return true;
	if(xpre <= ycur && ypre <= xcur)
		return true;

	return false;
}

int lis(int pre, const vector<vector<int>>& cuboids){
	if(pre >= (int)cuboids.size())
		return 0;
	if(dp[pre] != -1)
		return dp[pre];

	dp[pre] = 0;
	for(int cur = pre + 1 ; cur < (int)cuboids.size() ; ++cur){
		if(valid(pre, cur, cuboids))
			dp[pre] = max(dp[pre], lis(cur, cuboids));
	}
	dp[pre] += cuboids[pre][0];
	return dp[pre];
}
int maxHeight(vector<vector<int>>& cuboids) {
    for(vector<int>& cuboid : cuboids)
    	sort(cuboid.rbegin(), cuboid.rend()); // making sure that the height

    cuboids.push_back({0,0,0});
    sort(cuboids.begin(), cuboids.end());
    memset(dp, -1, sizeof(dp));
    return lis(0, cuboids);
}

};
