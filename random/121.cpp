	static const auto _ = []() {
	  std::ios::sync_with_stdio(false);
	  std::cout.tie(nullptr);
	  std::cerr.tie(nullptr);
	  std::cin.tie(nullptr);
	  return nullptr;
	}();
class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int stockPrice = INT_MAX;
        int maxProfit = INT_MIN;
        for(int val : prices){
            stockPrice = min(stockPrice, val);
            maxProfit = max(maxProfit, val - stockPrice);
        }
        return maxProfit;
    }
};
