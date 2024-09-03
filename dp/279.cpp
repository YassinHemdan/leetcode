static const auto _ = []() {
  std::ios::sync_with_stdio(false);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
  std::cin.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
int dp[10001];
int integer_break(int remain){
	if(remain <= 0)
		return 0;
	if(dp[remain] != -1)
		return dp[remain];

	dp[remain] = INT_MAX;
	for(int i=1 ; i * i <= remain ; ++i)
		dp[remain] = min(dp[remain], 1 + integer_break(remain - i * i));
	return dp[remain];
}
int numSquares(int n) {
    memset(dp, -1, sizeof(dp));
    return integer_break(n);
}
};
