class Solution {
public:
vector<int> smallestSubarrays(const vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    vector<int> bits(33, -1);
    int maxOR = 0;
    
    for(int i = n - 1 ; i > -1 ; --i){
        maxOR = maxOR | nums[i];

        // update the bits
        int bit = 0;
        int value = nums[i];
        while(value){
            if((value & 1) == 1)
                bits[bit] = i;
            
            ++bit;
            value = value >> 1;
        }
        int idx = *max_element(bits.begin(), bits.end());
        ans[i] = idx == -1 ?  : idx - i + 1;
    }
    return ans;
}
};  
