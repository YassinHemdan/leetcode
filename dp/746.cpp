static const auto _ = []() {
  std::ios::sync_with_stdio(false);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
  std::cin.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
int dp[1002];

int climb(int idx, const vector<int>& cost){
	if(idx < 0)
		return 0;
	if(dp[idx] != -1)
		return dp[idx];
	
	dp[idx] = cost[idx];
	int choice1 = climb(idx - 1, cost);
	int choice2 = climb(idx - 2, cost);
	
	dp[idx] += min(choice1, choice2);
	return dp[idx];
}
int minCostClimbingStairs(vector<int>& cost) {
    memset(dp, -1, sizeof(dp));
    cost.push_back(0);
    return climb((int)cost.size() - 1, cost);
}
};
