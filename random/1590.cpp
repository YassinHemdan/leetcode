class Solution {
public:
    int minSubarray(const vector<int>& nums, int p) {
        int sum = 0;
        int n = nums.size();
        for(const int& val : nums)
            sum = (sum + val) % p;
        
        int target = sum % p;
        if(target == 0)
            return 0;
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int length = n;
        sum = 0;
        for(int i=0 ; i<n ; ++i){
            sum = (sum + nums[i]) % p;
            int toEliminate = (sum - target + p) % p;

            if(mp.find(toEliminate) != mp.end())
                length = min(length, i - mp[toEliminate]);
            
            mp[sum] = i;
        }
        return length == n ? -1 : length;
    }
};
