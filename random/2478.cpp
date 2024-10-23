static const auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
private:
    int dp[1001][1001];
    string str;
    int mod = 1e9 + 7;
    
    bool isPrime(char c){
        return c == '2' || c == '3' || c == '5' || c == '7';
    }
    bool canTake(int start, int end, int minLength){
        if(start == end || isPrime(str[end]) || (end - start + 1 < minLength))
            return false;
        return true;
    }
    int count(int start, int k, int minLength){
        if(start >= (int)str.size() && k == 0)
            return 1;
        if(k == 0 || start >= (int)str.size())
            return 0;
        if(!isPrime(str[start]))
            return 0;
        if(dp[start][k] != -1)
            return dp[start][k];
        
        dp[start][k] = 0;
        for(int end = start ; end < (int)str.size() ; ++end){
            if(canTake(start, end, minLength)){
                int rec = count(end + 1, k - 1, minLength);
                dp[start][k] = ((dp[start][k] % mod) + (rec % mod)) % mod;
            }
        }
        return dp[start][k];
    }
public:
    int beautifulPartitions(const string& s, int k, int minLength) {
        memset(dp, -1, sizeof(dp));
        str = s;
        return count(0, k, minLength);
    }
};
