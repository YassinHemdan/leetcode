class Solution {
private:
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        // Hash the first element
        size_t hash1 = hash<T1>{}(p.first);
        // Hash the second element
        size_t hash2 = hash<T2>{}(p.second);
        // Combine the two hash values
        return hash1
               ^ (hash2 + 0x9e3779b9 + (hash1 << 6)
                  + (hash1 >> 2));
    }
};
int getMaxOR(const vector<int>& nums){
    int maxOR = 0;
    for(const int &val : nums)
        maxOR = (maxOR | val);
    return maxOR;
}
int count(unordered_map<pair<int, int>, int, hash_pair>& dp,
          const vector<int>& nums,
          int maxOR, int val, int idx){
    
    if(idx >= (int)nums.size())
        return val == maxOR;
    if(dp.find({idx, val}) != dp.end())
        return dp[{idx, val}];
    int pick = count(dp, nums, maxOR, val | nums[idx], idx + 1);
    int leave = count(dp, nums, maxOR, val, idx + 1);

    dp[{idx, val}] += pick + leave;
    return dp[{idx, val}];
}
public:
    int countMaxOrSubsets(const vector<int>& nums) {
        int maxOR = getMaxOR(nums);
        unordered_map<pair<int, int>, int, hash_pair> dp;
        return count(dp, nums, maxOR, 0, 0);
    }
};
