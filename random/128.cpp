class Solution {
public:
int getLength(vector<int>& lengths, unordered_map<int, int>& mp, int i, int num){
    if(lengths[i] != 0)
        return lengths[i];
    
    int next = 0;
    if(mp.find(num + 1) != mp.end())
        next = getLength(lengths, mp, mp[num + 1], num + 1);
    
    return lengths[i] = 1 + next;
        
}
int longestConsecutive(const vector<int>& nums) {
    int n = nums.size();
    if(n <= 1)
        return n;
    vector<int> lengths(n);

    unordered_map<int, int> mp;
    int maxLength = 0;
    for(int i=0; i<n ; ++i){
        if(mp.find(nums[i]) == mp.end())
            mp[nums[i]] = i;
    }

    for(int i=0 ; i<n ; ++i){
        getLength(lengths, mp, mp[nums[i]], nums[i]);
        maxLength = max(maxLength, lengths[i]);
    }

    return maxLength;
}
};
